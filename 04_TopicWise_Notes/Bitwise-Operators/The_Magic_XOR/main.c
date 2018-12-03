#include<stdio.h>

int CryptOrDecrypt( int ch )
{	
	int key;
	key = 'a';
	return( ch^key );
}

int main( int argc, char* argv[] )
{
	int ch;
	FILE *fp = fopen("test.dat", "r+");

	while( !feof(fp) )
	{
		ch = fgetc(fp);			
		fseek(fp,-1, SEEK_CUR);
		ch = CryptOrDecrypt(ch);
		fputc(ch, fp);
		fgetc(fp);
	}	
	fclose(fp);
}

// First time you run, you'll get crypted version
// Second time you'll get decrypted version