#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<signal.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define true 1
#define false 0

void error(char* msg);
int catch_signal( int sig, void(*handler)(int) );
void kill_server(int sig);

#define CHECK(var, msg)   \
  if ( (var) == -1)       \
    error( (msg) )   

int main(){
  int dummy; 			// We'll use it for return values of functions.
  char* advice[] = {
    "Take smaller bites\r\n",
    "Don't go for tight jeans\r\n",
    "One word: inappropriate\r\n",
    "Just for today, be hones. Tell your boss what you *really* think\r\n",
    "You might want to rethink that haircut\r\n",
  		   };
  int listener_d = socket(PF_INET, SOCK_STREAM, 0);
  CHECK(listener_d, "Can't create socket!");

  struct sockaddr_in name;
  name.sin_family = PF_INET;
  name.sin_port = (in_port_t)htons(30000);
  name.sin_addr.s_addr = htonl(INADDR_ANY);
  
  int reuse = 1;
  dummy = setsockopt( listener_d, SOL_SOCKET, SO_REUSEADDR, (char*)&reuse, sizeof(int)); 
  CHECK(dummy, "Can't set the reuse option on the socket");

  dummy = bind(listener_d, (struct sockaddr*)&name, sizeof(name) );
  CHECK(dummy,"Can't bind");
  
  dummy = listen(listener_d, 10);
  CHECK(dummy,"Server is bussy...");
  
  puts("Waiting for connection");
  while(true){
	// Capture Interrupt Signal.
	if( catch_signal(SIGINT, kill_server) == -1 ){
	fprintf(stderr,"Can't map the handler");
	exit(2);
	}
	struct sockaddr_storage client_addr;
	unsigned int address_size = sizeof(client_addr);
	int connect_d = accept( listener_d, (struct sockaddr*)&client_addr, &address_size );  
	
	char* msg = advice[ rand() % 5 ];
	send(connect_d, msg, strlen(msg), 0);
	close(connect_d);
	printf("Connected to a client!\n");
  }
  
return 0;
}

// Returns no. of unread character
int read_in(int socket, char* buf, int len){
  char* s = buf;
  int slen = len;
  int c = recv(socket, s, slen, 0);
  while( (c > 0) && ( s[c-1] != '\n')){
    s += c;
    slen -= c;
    c = recv(socket, s, slen, 0);
  }
  if(c < 0) 
    return c; 			// There is an error.
  else if( c == 0)
    buf[0] = '\0'; 		// Nothing read; send back an emptry string.
  else
    s[c-1] = '\0'; 		// Replace \r with \0
  
  return len - slen;
}


void error(char* msg){
  fprintf(stderr, "%s: %s\n", msg, strerror(errno) );
  exit(1);
}

void kill_server(int sig){
  puts("\n\nServer Closing down normally...\n");
  exit(1);
}

int catch_signal( int sig, void(*handler)(int) ){
  struct sigaction action; 		// Create Action for Signal Handling
  action.sa_handler = handler; 		// Wrap the handler
  sigemptyset(&action.sa_mask);  	// Use empty mask
  action.sa_flags = 0; 			// No need to flag change
  return sigaction(sig, &action, NULL); // set the action as the default signal handler of the given signal.
}
