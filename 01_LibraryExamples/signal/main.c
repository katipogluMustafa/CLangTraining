//SANIRIM ERROR HANDLINGDE KULLANILIYOR
#include <stdio.h>      /* printf */
#include <signal.h>     /* signal, raise, sig_atomic_t */
/*
SIGABRT: Signal Abort
SIGFBE: Signal Floating Point Exceptiob
SIGILL: Signal Illegal Instruction
SIGINT: Signal interrupt
SIGSEGV: Signal Segmentation Violation
SIGTERM: Signal Terminate*/
sig_atomic_t signaled = 0;

void my_handler (int param)
{
	printf("gumo");
  signaled = 1;
}

int main ()
{
  void (*prev_handler)(int);

  prev_handler = signal (SIGINT, my_handler);

  /* ... */
  raise(SIGINT);
  /* ... */
  
  printf ("signaled is %d.\n",signaled);
  

  return 0;
}
