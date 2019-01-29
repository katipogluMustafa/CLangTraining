#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<signal.h>
#include"include/def.h"

int listener_d;

int main(int argc, char* argv[]){
  
  // Set the interrupt handler
  if( catch_signal(SIGINT, handle_shutdown) == -1 )
    error("Can't set the interrupt handler");
  
  // Open Socket
  listener_d = open_listener_socket();
  
  // Bind to port 30000
  bind_to_port(listener_d, 30000);
  
  // Listen the socket with the queue of 10
  if( listen(listener_d, 10) == -1 )
    error("Can't listen, queue is fulll...");
  
  struct sockaddr_storage client_addr;
  unsigned int address_size = sizeof(client_addr);
  puts("Waiting for connection");
  char buf[255];

  while(1){
    // Connect to the client
    int connect_d = accept(listener_d, (struct sockaddr*)&client_addr, &address_size);
    if( connect_d == -1)
      error("Can't open secondary socket");
    // Protocol
    if( say( connect_d, 
	     "Internet Knock Knock Protocol Server \r\n Version 1.0 \r\n Knock! Knock!\r\n>") != -1 ){
       read_in(connect_d, buf, sizeof(buf));
       if( strncasecmp("Who's there?", buf, 12) )
         say(connect_d, "You should say 'Who's there?'!");
       else{
         if( say(connect_d, "Oscar\r\n>") != -1 ){
	   read_in(connect_d, buf, sizeof(buf));
	   if( strncasecmp("Oscar who?", buf, 10) )
	     say(connect_d, "You should say 'Oschar who?'!\r\n' ");
	   else
	     say(connect_d, "Oscar silly question, you get a silly answer\r\n");
	 }
       }
    }
    close(connect_d);
  }

return 0;
}


// Open a socket
int open_listener_socket(){
  int s = socket(PF_INET, SOCK_STREAM, 0);
  if( s == -1)
	error("Can't open socket");
  return s;
}

// Binds a socket to given port
void bind_to_port(int socket, int port){
  
  // Set the port
  struct sockaddr_in name;
  name.sin_family = PF_INET;
  name.sin_port = (in_port_t)htons(port);
  name.sin_addr.s_addr = htonl(INADDR_ANY);
  
  // Resue the same socket if networks restarts
  int reuse = 1;
  if( setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (char*)&reuse, sizeof(int) ) == -1 )
    error("Can't set the reuse option on the socket");
  
  // Bind socket to the port
  int c = bind(socket, (struct sockaddr*)&name, sizeof(name) );
  if(c == -1)
    error("Can't bind to socket");

}

// Send a string to a client
int say(int socket, char* s){
  int result = send(socket, s, strlen(s), 0);
  if(result == -1)
    fprintf(stderr, "%s: %s\n", "Error talking to the client", strerror(errno) );
  return result;
}

// Returns no. of chars we read.
int read_in(int socket, char* buf, int len){
  char* s = buf;
  int slen = len;
  int c = recv(socket, s, slen, 0);
  // Keep reading until there are no more characters or reach \n
  while((c > 0) && (s[c-1] != '\n')){
    s += c;
    slen -= c;
    c = recv(socket, s, slen, 0);
  }
  
  if(c < 0) 		// In case there is an error
    return c;
  else if( c == 0)  	// Nothing read; send empty string back
    buf[0] = '\0';
  else
    s[c-1] = '\0'; 	// Replace the '\r' char with '\0'

  return len - slen;
}

void error(char* msg){
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(1);
}

void handle_shutdown(int sig){
  if( listener_d )
    close(listener_d);
 
  fprintf(stderr,"\nServer is shutting down...\n");
  exit(0);
}

int catch_signal( int sig, void(*handler)(int) ){
  struct sigaction action;              // Create Action for Signal Handling
  action.sa_handler = handler;          // Wrap the handler
  sigemptyset(&action.sa_mask);         // Use empty mask
  action.sa_flags = 0;                  // No need to flag change
  return sigaction(sig, &action, NULL); // set the action as the default signal handler of the given signal.
}

