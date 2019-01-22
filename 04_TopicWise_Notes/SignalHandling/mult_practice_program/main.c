#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<signal.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>

int score = 0;

void end_game(int sig){
  printf("\nFinal score: %d\n", score);
  exit(0);
}

int catch_signal(int sig, void (*handler)(int) ){
  struct sigaction action;
  action.sa_handler = handler;
  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;
  
  return sigaction(sig, &action, NULL);
}

void times_up(int sig){
  puts("\nTIME'S UP!");
  raise(SIGINT);   		// Raising SIGINT will make the program display the final score in end_game()
}

void error(char* msg){
  fprintf(stderr,"%s: %s\n", msg, strerror(errno));
  exit(1);
}

int main(){
  catch_signal(SIGALRM,times_up);
  catch_signal(SIGINT,end_game);
  srandom(time(0));
  
  while(1){
    int a = random() % 11;
    int b = random() % 11;
    char txt[4];
    alarm(5); 					// Set the alam to fire in 5 seconds.
    /* As long as user goes through the loop in less than 5 seconds, the timer will be reset and it will never fire.*/    
    printf("\nWhat is %d times %d: ", a, b);
    fgets(txt,4,stdin);
    int answer = atoi(txt);
    if( answer == a * b){
      score++;
    }else{
      printf("\nWrong! Score:%d\n",score);
    }

  }

  return 0;
}
