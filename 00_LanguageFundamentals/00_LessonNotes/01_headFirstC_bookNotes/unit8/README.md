# Static And Dynamic Libraries

```c

void encrypt(char* message){
	
	while(*message){
		*message = *message + 31;
		message++;
	}

}

int checksum(char* message){
	int c = 0;
	
	while(*message){
		c += c ^ (int)(*message);
		message++;
	}

	return c;
}

```