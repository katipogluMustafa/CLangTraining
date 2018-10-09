#include <stdio.h>
#include <string.h>
	
	/* Return the position of the string2 in string1
	 * Return -1 if not found
	 */

int pattern_match(char* str1, char* str2){

	int j,k;
	int length1,length2 = strlen(str1),strlen(str2);
	for(j = 0; j < length1; ++j){

		for(k = 0; k < length2; k++ ){
			if(str2[k] != str1[k+j]){
				break;
			}
		}

		if(k == length2){
			return j;
		}	
	}
	return -1;
}