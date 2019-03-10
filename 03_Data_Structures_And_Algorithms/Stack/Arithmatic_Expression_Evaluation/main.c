#include "def.h"
#include<limits.h>
#define SIZE 250


int calculateExpression(char* in);

boolean processOperator(char temp);

boolean isOperator(char x);
boolean isNumber(char x);
boolean isEmptyChar(char x);
boolean isLowerPrecedence(char x, char y);

boolean handleOperation();

STACK* operandStack;
STACK* operatorStack; 

int main(){
  STACK* operandStack = stackFactory();
  STACK* operatorStack = stackFactory();
 
  char s[SIZE];
  printf("Matematiksel islem:\n");
  scanf("%[^\n]",s);
  printf("\nAlgılanan islem: %s\n",s);
  int out = calculateExpression(s);
  if( out != INT_MIN ) 
        printf("Sonuc: %d\n", calculateExpression(s)  );
  else
        printf("Syntax Error...\n");
 

return 0;
}


/**
 * Calculates the result of given expression
 * @param char* String consists of expression with  ( ) + * / - and numbers
 * @return int  The result of the arithmatic expression, if error returns INT_MIN
 */

int calculateExpression(char* in){
 char* temp = malloc( strlen(in) * sizeof(char) );
  strcpy(temp, in);
  int n = 0;
  boolean takingNumber = false;

  while( true ){
     if(*temp != '\0'){
  
       if( takingNumber == false)
         n = 0;
   
       // Take number if not operator and is a number
       if( !isOperator(*temp) && isNumber(*temp) ){
         n *= 10;
         n += (*temp - '0');
         takingNumber = true;
       }else{
         
         if( isOperator(*temp) == true && takingNumber == true){
           // if found operator when taking number, then we finished getting number
           push(operandStack, &n);
           takingNumber = false;
           
           // Now we process the operator 
           if( processOperator(*temp) == false); 
             return INT_MIN;      // if error, return INT_MIN, else continue        
          
         }
         // if not operator after taking number, not empty char then it is wrong input or wrong syntax
         else if( isEmptyChar(*temp) == false)
           return INT_MIN;
          
       }
      

     }else{
        // We found the result, return the result
        int out;
        // if Stacks are not empty after we popped result, then there is error
        if( pop(operandStack, &out) && isEmpty(operandStack) && isEmpty(operandStack) )
           return out;
        else
             return INT_MIN;
        
     }

   temp++;
  }


return INT_MIN;
}

boolean processOperator(char x){
  int operator = (int)x;
  int dummy;
  boolean flag = true;

  // if opening parentheses
  if( operator == '(' )
    push(operatorStack, &operator);

  // if closing parentheses
  else if( operator == ')' ){
    while( peek(operatorStack, &dummy) && dummy != '('){      
       if( handleOperation() == false )                 // handles one operator from the stack
         return false;                                  // error while handling operation
    }
    if( dummy == '(')
      pop(operatorStack, &dummy);
    else  // this means stack is empty we can't peek
      return false;                                     // snytax error, no '(' found before ')'
  }
  // if operator like + - * /
  else{
   do{        // loop through until we found place for operator in the stack
    if( peek(operandStack, &dummy) ){
         if( dummy == '('){
           push(operatorStack, &operator);
           flag = false;
         }
         else if( isLowerPrecedence(dummy, operator) ){ // is dummy has lower precedence then operator
           push(operatorStack, &operator);
           flag = false;
         }
         else{
            // we just handle operation, check error and check the state in the next loop so no change for flag
            if(handleOperation() == false)
              return false;                            // error while handling operation
         }        
       }else{                            // operand stack free, put the operator
        push(operandStack, &operator);
        flag = false;
        }
    }while(flag);
  }

return true;
}

/**
 * Handles one operation, takes one operator and 2 value and puts the result back into operand stack.
 * @return if no error while handling then returns true, otherwise returns false
 */
boolean handleOperation(){
  int val1, val2;
  int operator;
  int result;

  if( pop(operatorStack, &operator) && pop(operandStack, &val2) && pop(operandStack, &val1) ){
    switch(operator){
      case '-':
        result = val1 - val2;
        break;
      case '+':
        result = val1 + val2;
        break;
      case '*':
        result =  val1 * val2;
        break;
      case '/':
        result = val1 / val2;
        break;
      default:
        return false;                 // can't process the operator
    } 
  }

  if( !push(operandStack, &result) )
    return false;                    // error while pushing to the stack

  return true;
}


/** 
 * if x has lower precedence then y returns true otherwise false
 * @param x operand 
 * @param y operand
 */
boolean isLowerPrecedence(char x, char y){
  if( (x == '+' || x == '-') && (y == '*' || y == '/' || y == '(' ) )
    return true;
  else if( (x == '*' || x == '/') && (y == '(') )
    return true;

return false;  
}



boolean isOperator(char x){
  switch(x){
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
      return true;
    default:
      return false;
  }
}

boolean isEmptyChar(char x){
  switch(x){
    case ' ':
    case '\n':
    case '\r':
    case '\t':
    case '\b':
      return true;
    default:
      return false;
  }
}


boolean isNumber(char x){
  
  if( x > '9' || x < '0' )
    return false;
  
return true;
}

