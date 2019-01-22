#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/wait.h> // for waitpid()

void open_url(char* url);
void error(const char* msg);

int main(int argc, char* argv[]){
  char* phrase = argv[1];
  char* vars[] = { "RSS_FEED=http://rss.cnn.com/rss/edition_world.rss", NULL };
  int fd[2];
  if( pipe(fd) == -1 ){
    error("Can't create the pipe");
  }

  pid_t pid = fork();
  if(pid == -1){
    error("Can't fork process");
  }
 
  /* We're in the child process */ 
  if(!pid){
    // set the chil's stdout as the write end of the pipe	  
    dup2(fd[1], 1); 	        // close read end end since we won't reading from the pipe
    close(fd[0]);    
    if( execle( "/usr/bin/python", "/usr/bin/python", "./rssgossip.py", "-u", phrase, NULL, vars  ) == -1 ){
      error("Can't run script");
    }

  }
  
  /*  We're back in the parent process */

  // set the parent's stdin as the read and of the pipe.
  dup2(fd[0],0);
  close(fd[0]); 		// close write end since we won't be writing to  parent process
  char line[255];
  // We're reading input from stdin because that's connected to the pipe
  // But we could also put fd[0] here
  while( fgets(line, 255,  stdin) ){
    if( line[0] == '\t'){
      open_url(line + 1);
    }
  }

  return 0;
}

void error(const char* msg){
  fprintf(stderr,"%s: %s\n", msg, strerror(errno) );
  exit(1);
}

void open_url(char* url){
  char launch[255];
  
  /* Windows */
  sprintf(launch, "cmd /c start %s",url);
  system(launch);

  /* Unix */
  sprintf(launch, "x-www-browser '%s' &",url);
  system(launch);

  /* Mac */
  sprintf(launch, "open '%s'", url);
  system(launch);
}
