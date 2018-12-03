# The Magic XOR

## Swap

```c
#define swap(x,y) (x ^= y ^= x ^= y) 

```
* But this doesn’t work with floating point values. It also doesn’t work when we send values as
SWAP (a, a) .

## Crypting with XOR

Some people use complementary operator ( ~ ) for easy crypting. Since such technique doesn’t
have any ‘key’ values, it is easy to decrypt the file. XOR provides an easy way to crypt and
decrypt with ‘key’ support.

```c
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
```

‘key’ value should not be 0. If key value is 0, the line will not be crypted
because N^0=N.



