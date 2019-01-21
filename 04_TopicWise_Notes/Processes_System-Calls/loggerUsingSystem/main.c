#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Returns a string containing the current date and time */
char* now(){
  time_t t;
  time(&t);
  return asctime(localtime(&t));
}

/* Master Control Program utility.*/
int main(){
  char comment[80];
  char cmd[120];
  fgets(comment, 80, stdin);
  sprintf(cmd, "echo '%s %s' >> repots.log", now(), comment);
  system(cmd);

}


