#include<stdio.h>
#define MAX_LENGTH 250

int main(){
	char ch[MAX_LENGTH],s[MAX_LENGTH], sen[MAX_LENGTH];
	
	// take ch
	scanf("%[^\n]%*c",ch);
	scanf("\n");

	// take s
	scanf("%[^\n]%*c",s);	
	scanf("\n");				// Take the new line character so that we won't save it when taking "sen" string.

	// take sen
	scanf("%[^\n]%*c",sen);

	printf("%s\n%s\n%s\n",ch,s,sen);	

	


return 0;
}


/* Take Line Input

 * You can take a line as input
 
 * You can use scanf("[^\n]%*c",s); 
	* where s is s[MAX_SIZE]
	* [] is scanset character
	* ^\n stands for taking input until a newline isn't encountered.
	* %*c  reads a new line character,  * is used because the new line character is discarded.
 
 *After inputting the character and the string, inputting the sentence by the above mentioned statement won't work. 
	* This is because, at the end of each line, a new line character (\n) is present. 
	* So, the statement: scanf("%[^\n]%*c", s); will not work because the last statement will read a newline character from the previous line. 
	* This can be handled in a variety of ways and one of them being: scanf("\n"); before the last statement.
 
 */
