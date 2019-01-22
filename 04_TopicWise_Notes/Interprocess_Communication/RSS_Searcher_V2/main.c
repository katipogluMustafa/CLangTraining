#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/wait.h> // for waitpid()

void error(const char* msg);

int main(int argc, char* argv[]){
  char* phrase = argv[1];
  char* vars[] = { "RSS_FEED=http://rss.cnn.com/rss/edition_world.rss", NULL };
  FILE* f = fopen("stories.txt", "w");
  if(!f){
    error("Can't open stories.txt");
  }

  pid_t pid = fork();
  if(pid == -1){
    error("Can't fork process");
  }
  
  /* Remember, 
   * fork() return 0 to child function
   * fork() return non-zero id to main to parent process
   */
  if(!pid){
    if( dup2( fileno(f), fileno(stdout) ) == -1){
      error("Can't redirect Standard Output");
    }
    
    if( execle( "/usr/bin/python", "/usr/bin/python", "./rssgossip.py", phrase, NULL, vars  ) == -1 ){
      error("Can't run script");
    }

  }

  int pid_status;
  
 
  if( waitpid(pid, &pid_status, 0) == -1 ){
    error("Error while waiting for child process");
  }

  return 0;
}

void error(const char* msg){
  fprintf(stderr,"%s: %s\n", msg, strerror(errno) );
  exit(1);
}
