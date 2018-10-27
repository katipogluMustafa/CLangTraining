#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

char* timeConversion(char* s) {

    /* sign contains the time stamp*/

    char *sign = malloc(3);
    sign[0] = s[8];
    sign[1] = s[9];
    sign[2] = s[10];

    /* s contains time as AM format*/
    s[8] = '\0';

    // if PM convert subtract 12 from hour and return it
   if(sign[0] == 'P' && sign[1] == 'M'){
        char *hour = malloc(3);
        hour[0] = s[0];
        hour[1] = s[1];
        hour[3] = '\0';

        int tmp = atoi(hour);
        if(tmp != 12){
            tmp += 12;
            sprintf(hour, "%d",tmp); // convert integer tmp to string
            s[0] = hour[0];
            s[1] = hour[1];
        }

        return s;

   }else{
   // if time is between 12-12.59AM make it 00-00:59
    char *hour = malloc(3);
        hour[0] = s[0];
        hour[1] = s[1];
        hour[3] = '\0';
    int tmp = atoi(hour);
    if(tmp == 12){
        s[0] = '0';
        s[1] = '0';
    }
       return s;
   }

}
/*
 * Complete the timeConversion function above.
 */

/*
 * Please either make the string static or allocate on the heap. For example,
 * static char str[] = "hello world";
 * return str;
 *
 * OR
 *
 * char* str = "hello world";
 * return str;
 *
 */


int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = timeConversion(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
