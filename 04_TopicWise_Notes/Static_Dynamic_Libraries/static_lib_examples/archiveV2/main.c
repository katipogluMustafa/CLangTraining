#include<stdio.h>
#include<hfsecurity.h>

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
