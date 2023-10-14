#ifndef INFIX_TO_POSTFIX
#define INFIX_TO_POSTFIX

int precedence(char operator);  
int isOperator(char c);        
char* infixToPostfix(char * infix);

#endif