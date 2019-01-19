#include<stdio.h>

// First inside archiveMaking directory
//ar -rcs libhfsecurity.a encrypt.o checksum.o

// Then in this directory
//gcc main.c -L ./archiveMaking/ -lhfsecurity -o main

extern int encrypt(char*);
extern int checksum(char*);

int main(){

	char s[] = "Speak friend and enter";

	encrypt(s);

	printf("Encrypted To:%s\n",s);
	printf("Checksum is:%x\n", checksum(s));

	encrypt(s);


	printf("Decrypted Back To:%s\n",s);
	printf("Checksum is:%x\n", checksum(s));

	return 0;
}
