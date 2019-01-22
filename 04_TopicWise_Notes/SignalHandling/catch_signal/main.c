#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

// Signal handler function
void let_me_die( int sig ){ 		// Signal Handlers have void return types.
  // OS passes the signal to the handler.

  // this is the function that will be called before any process is killed.
  puts("\nLa ilahe illallah Muhammedun Resulullah\n");
  exit(1);
}

// Let's make our own catch function which wraps handler functions.
int catch_signal(int sig, void (*handler)(int) ){
  struct sigaction action; 		// Create Action
  action.sa_handler = handler; 		// Set the action's handler to the handler function that was passed in.
  sigemptyset(&action.sa_mask);		// Use empty mask
  action.sa_flags = 0;
  return sigaction(sig, &action, NULL); // signal_number, wrapped handler which is action, pointer to old handler in this case NULL
}

int main(){
  
  // SIGINT means we are capturing the interrupt signal.
  // let_me_die in this program is the interrupt handler function's func pointer.
  if( catch_signal(SIGINT, let_me_die ) == -1 ){
  	fprintf(stderr,"Can't map the handler");
	exit(2);
  }

  char name[30];
  printf("Enter your name: ");
  fgets(name, 30, stdin);
  printf("Hello %s\n", name);

return 0;
}
