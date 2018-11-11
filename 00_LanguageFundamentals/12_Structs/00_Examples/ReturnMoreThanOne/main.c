#include<stdio.h>
#include<math.h>        // include for trig functions
#define TOO_LARGE 1e6   // differs from one machine to another

typedef struct{
    double sine,cosine;
} TRIG;

TRIG* getTrigValues(double radian){
    static TRIG result;

    if(radian > TOO_LARGE){
        printf("Input value too large -- cannot return"
                "meaningful results\n");
        return NULL;
    }

    result.sine = sin(radian);
    result.cosine = cos(radian);

    return &result;
}

int main(){

	TRIG *myTrig = getTrigValues( 5 ); 

	printf("%f", myTrig->sine );

	printf("%f", myTrig->cosine );

	return 0;
}