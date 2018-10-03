#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

	const char search = "Mustafa Katipoglu";
	int lookingFor = 'g';
	char *ptr;
	ptr = (char *)memchr(search, lookingFor, strlen(search));

	if (ptr == NULL) {
		printf("%c is NOT FOUND!",lookingFor);
		return 1;
	}

	printf("Found %d at position %ld",lookingFor , 1+(ptr-search) );
	printf("Found 'N' at position %ld.\n", 1+(ptr-search));

	return 0;
}

/* Fix The Issues*/