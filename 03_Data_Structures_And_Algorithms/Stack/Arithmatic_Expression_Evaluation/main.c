#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define SIZE 250

typedef int boolean;
#define true  (1)
#define false (0)

typedef struct {
	int* item;
	unsigned int top;
	unsigned int size;
}STACK;

// Stack Functions
STACK* stackFactory(int size);
boolean peek(STACK* stack, int* out);
boolean pop(STACK* stack, int* out);
boolean push(STACK* stack, int in);
boolean isFull(STACK* stack);
boolean isEmpty(STACK* stack);
boolean isInitialized(STACK* stack);

// Arithmatic Expression Evaluation Functions
boolean isOperator(char x);
boolean isNumber(char x);
boolean isEmptyChar(char x);

int getPrecedence(char op);
boolean isLowerPrecedence(char x, char y);


int calculateExpression(char* in);
boolean processOperator(char temp);
boolean handleOperator(int operator);
boolean handleOperation();

boolean printIntStack(STACK* stack);
boolean printCharStack(STACK* stack);

STACK* operandStack;
STACK* operatorStack;

int main() {

  /* Initialize global stacks */

  operandStack = stackFactory(100);
  if (operandStack == NULL)
    return 1;

  operatorStack = stackFactory(100);
  if (operatorStack == NULL)
    return 1;
  
  /* Take Mathematical Expression to Parse*/

  char s[SIZE];

  printf("Matematiksel islem:\n");
  scanf("%[^\n]", s);

  printf("\nAlgılanan islem: %s\n", s);
  int out = calculateExpression(s);
  
  /* If calculation returns INT_MIN this means there exists an error */
  if (out != INT_MIN)
    printf("Sonuc: %d\n", out);
  else
    printf("\nSyntax Error...\n");
  
return 0;
}


/**
 * Calculates the result of given expression
 * @param char* String consists of ( ) + * / - and numbers
 * @return int  The result of the arithmatic expression, if error returns INT_MIN
 */
int calculateExpression(char* in) {
  char* temp = malloc( (strlen(in) + 1) * sizeof(char));
  strcpy(temp, in);
  printf("Temp = %s\n",temp);
  int n = 0; int out;
  boolean takingNumber = false;

  while ( true ) {
      if (takingNumber == false)
	n = 0;

      // Take number if not operator and is a number
      if (!isOperator(*temp) && isNumber(*temp)) {
	n *= 10;
	n += (*temp - '0');
	takingNumber = true;
        printf("Taking number... Current n : %d\n", n);
      }
      // Have we reached to the end of the given expression ? 
      else  if (*temp == '\0') {
          // If we were taking number in the last iteration, push the number you got the stack
          if (takingNumber == true) {
		push(operandStack, n);
		takingNumber = false;
	  }    

          printf("Temp is NULL ending procedure is started...\n");
	  // We found the result, return the result after handling all the things left on the stack
	  while (isEmpty(operatorStack) != true)
              if (handleOperation() != true) {
		fprintf(stderr, "NULL Char: Operator handling Error\n");
		return INT_MIN;                    // error while handling operation
              }
	
	   // if Stacks are not empty after we popped result, then there is error
	  if ( pop(operandStack, &out) && isEmpty(operandStack) )
	    return out;
 	  else{
            fprintf(stderr, "Operand stack is not Empty while exiting\n");
            return INT_MIN;
           }
      } 
      else {
	  if (isOperator(*temp) == true) {
	    if (takingNumber == true) {
              printf("We were taking number, lets push it\n");
	      // if found operator when taking number, then we finished getting number
	      push(operandStack, n);
	      takingNumber = false;
	    }
            printf("Lets Process the operator\n");
	    // Now we process the operator
            printf("Processing the operator %c \n", *temp);

	    if (processOperator(*temp) == false)
              return INT_MIN;      // if error, return INT_MIN, else continue        

	  }
	  // if not operator after taking number, not empty char then it is wrong input or wrong syntax
	  else if (isEmptyChar(*temp) == false)
	    return INT_MIN;
      }

      if(takingNumber == false){
        printf("Current Operator Stack: ");
        printCharStack(operatorStack);
        printf("\n");
        printf("Current Operand Stack: ");
        printIntStack(operandStack);
        printf("\n");
      } 
              
      printf("incrementing temp...\n");
  temp++;
  }

return INT_MIN;
}

/**
 * Takes required action for given operator, 
    if opening parantheses just puts the operator in to the operator stack
    else if closing parentheses calls handleOperation() for the operators inside the parantheses in the stack
    else {+ - * /} then iteratively calls handleOperator() until the operator finds its space inside the operator stack
 * @param char The operator to take care of
 * @return boolean if operator succesfully handled returns true otherwise false
 */
boolean processOperator(char x) {
  int operator = (int)x;
  int dummy;

  if (operator == '(')										           // if opening parentheses
    push(operatorStack, operator);
   
  else if (operator == ')') {									           // if closing parentheses

      while ( peek(operatorStack, &dummy) && dummy != '(')	                                           // While operator exists, handle operations
	  if (handleOperation() != true)						                   // handles one operator from the stack
	    return false;                                                                                  // error while handling operation
		
      if (dummy == '(')
	pop(operatorStack, &dummy);							                   // throw opening parentheses away
      else											           // this means stack is empty we can't peek
	return false;                                                                                      // snytax error, no '(' found before ')'

  }else													   // if operator like + - * /
      while ( !handleOperator(operator) );
      // loop through until we found place for operator in the stack


return true;
}

/**
 * Takes the required process for handling Operator{* - / +}
 * @param int The operator to take care of
 * @return boolean if the operation is done returns true if the operation is not yet complete returns false 
 *   so that in the caller function it needs to be iteratively called. In case of error returns false as well as printing to stderr
 */
boolean handleOperator(int operator) {
  int dummy;
  printf("Operator is one of the * - / + so we handleOperator\n");

  if ( peek(operatorStack, &dummy) ) {
    printf("Operator %c (%d) exists at the top of the stack\n", (char)dummy, dummy);
  
      if (dummy == '(') {
        printf("There exists ( inside stack so we push the new operator %c to the stack", operator);
  	push(operatorStack, operator);
        return true;
      }
  
      else if ( isOperator(dummy) && isLowerPrecedence((char)dummy, operator)) { // is dummy has lower precedence then operator
        printf("%c has lower precedence than %c so we'll push it onto the stack\n", dummy, operator);
  	push(operatorStack, operator);
        return true;
      }
  
      else {
        printf("At the top of the stack there is no ( and there is no operator lower precedence then %c so we handleOperation\n", operator);
  	// we just handle operation don't push the operator
  	handleOperation();
        return false;                            
      }
  
  }
  else if( isEmpty(operatorStack) ) {                            // operand stack free, put the operator
      printf("Operator Stack is empty, lets push the first operator %c to the stack\n", operator);
      push(operatorStack, operator);
    return true;
  }
	

  fprintf(stderr, "handleOperator: Undefined Behaviour");
return false;
}

/**
 * Handles one operation, takes one operator and 2 value and puts the result back into operand stack.
 * @return if no error while handling then returns true, otherwise returns false
 */
boolean handleOperation() {
  int val1, val2;
  int operator;
  int result;

  if ( pop(operatorStack, &operator) && pop(operandStack, &val2) && pop(operandStack, &val1) ) {
    switch (operator) {
	case '-':
	  result = val1 - val2;
	  break;
	case '+':
	  result = val1 + val2;
	  break;
	case '*':
	  result = val1 * val2;
	  break;
	case '/':
	  result = val1 / val2;
	  break;
	default:
	  fprintf(stderr, " Undefined operator found on the operator stack\n");
	  return false;                                                                  // can't process the operator
    }
  }

  if (!push(operandStack, result)) {
    fprintf(stderr, "handleOperation: Pushing Error: Can't push to the stack\n");
      return false;                                                            // error while pushing to the stack
  }

return true;
}


/**
 * if x has lower precedence then y returns true otherwise false
 * @param x operand
 * @param y operand
 */
boolean isLowerPrecedence(char x, char y) {

  if ( getPrecedence(x) < getPrecedence(y) ) {
    printf("%c has lower precedence than %c", x, y);
    return true;
  }
 
  return false;
}
/**
 * Gets the equivalent precedence value
 * @param char the operator to get its precedence
 * @return int The precedence value of the given operator  
 */
int getPrecedence(char op) {
  int precedence;

  switch (op) {
    case '+':
    case '-':
	precedence = 1;
	break;
   case '*':
   case '/':
	precedence = 2;
	break;
   default:
	precedence = 0;
	break;
   }

return precedence;
}


/**
 * Checks whether given char is an acceptable operator or not
 * @param char The char value to check
 * @return boolean if operator return true otherwise false
 */
boolean isOperator(char x) {
  switch (x) {
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

boolean isEmptyChar(char x) {
  switch (x) {
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


boolean isNumber(char x) {
  if (x > '9' || x < '0')
    return false;

  return true;
}

/* Stack Functions */ 


/**
 * Factory Function for Stack
 * @return STACK* Newly Allocated Int based STACK Address
 */
STACK* stackFactory(int size) {
	STACK* stack = (STACK*)malloc(sizeof(STACK));
	if (stack == NULL) {
		fprintf(stderr, "stackFactory: Allocation Error\n");
		return NULL;
	}

	stack->size = size;
	stack->top = 0;
	stack->item = (int*)malloc( sizeof(int) * size );

	return stack;
}

/**
 * Prints the given Int based stack without mutating the stack
 * @param STACK* The stack to print out
 * @return boolean if the stack is NULL returns false otherwise true
 */
boolean printIntStack(STACK* stack){
  if( isInitialized(STACK* stack) != true )
    return false;

  int top = stack->top; 
  while( top != 0)
    printf("%d ", stack->item[--top]);

return true;
}

/**
 * Prints the given Char based stack without mutating the stack
 * @param STACK* The stack to print out
 * @return boolean if the stack is NULL returns false otherwise true
 */
boolean printCharStack(STACK* stack){
  if( isInitialized(STACK* stack) != true )
    return false;


  int top = stack->top; 
  while( top != 0)
    printf("%c ", stack->item[--top]);

return true;
}


/**
 * Checks whether given stack is initialized or not
 * @param STACK* stack to check 
 * @return true if stack is NULL otherwise false
 */
boolean isInitialized(STACK* stack){
  if( stack != NULL )
    return false;
  
  fprintf(stderr, "Uninitialized Stack Error: Encountered NULL Stack Can't Continue\n");

  return true;
}

/**
 * Check is the given stack empty or not
 * @param STACK* Stack to check
 * @return boolean true for empty, false otherwise
 */
boolean isEmpty(STACK* stack) {
  if( isInitialized(STACK* stack) != true )
    return false;

  if (stack->top == 0)
    return true;
                
return false;
}

/**
 * Check is the given stack full or not
 * @param STACK* Stack to check
 * @return boolean true for full, false otherwise
 * @constant MAX defined as macro
 */
boolean isFull(STACK* stack) {
  if( isInitialized(STACK* stack) != true )
    return false;

  if (stack->top == stack->size)
    return true;

return false;
}

/**
 * Peek the value at the top of the stack
 * @param STACK* Stack to peek
 * @param int* the value you get after peeking
 * @return boolean true if the peeking process is successfull, false otherwise
 */
boolean peek(STACK* stack, int* out) {
  if( isInitialized(STACK* stack) != true )
    return false;

  if ( isEmpty(stack) )
    return false;

  *out = stack->item[stack->top - 1];

return true;
}

/**
 * Push the value given as parameter to the given stack
 * @param STACK* Stack to push element
 * @param int* the value you want to push to stack
 * @return boolean true if the pushing process is successfull, false otherwise
 */
boolean push(STACK* stack, int in) {
  if( isInitialized(STACK* stack) != true )
    return false;
	
  if (isFull(stack))
    return false;

  stack->item[stack->top] = in;
  stack->top += 1;
        
  printf("The number %d pushed to stack\n", in);
        
	return true;
}

/**
 * Pop element from the top of the given stack
 * @param STACK* Stack to pop element
 * @param int* the element you popped from the given stackstack
 * @return boolean true if the popping process is successfull, false otherwise
 */
boolean pop(STACK* stack, int* out) {
  if( isInitialized(STACK* stack) != true )
    return false;	

  if (isEmpty(stack))
    return false;

  stack->top -= 1;
  *out = stack->item[stack->top];
  printf("The number %d popped out of stack\n", *out);

  return true;
}
