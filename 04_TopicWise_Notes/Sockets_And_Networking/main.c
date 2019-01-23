#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define true 1
#define false 0

void error(char* msg);
int catch_signal( int sig, void(*handler)(int) );
void kill_server(int sig);

int main(){
  char* advice[] = {
    "Take smaller bites\r\n",
    "Don't go for tight jeans\r\n",
    "One word: inappropriate\r\n",
    "Just for today, be hones. Tell your boss what you *really* think\r\n",
    "You might want to rethink that haircut\r\n",
  		   };
  int listener_d = socket(PF_INET, SOCK_STREAM, 0);
  

  struct sockaddr_in name;
  name.sin_family = PF_INET;
  name.sin_port = (in_port_t)htons(30000);
  name.sin_addr.s_addr = htonl(INADDR_ANY);
  int c = bind(listener_d, (struct sockaddr*)&name, sizeof(name) );
  if(c == -1)
    error("Can't bind");
  
  int l = listen(listener_d, 10);
  if( l == -1)
    error("Waiting for connection");
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
  }
  
return 0;
}

void error(char* msg){
  fprintf(stderr, "%s", msg);
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
