#ifdef INFIXTOPOSTFIX_H
#define INFIXTOPOSTFIX_H

int precedence(char operator);
int isOperator(char c);
char *infixToPostfix(char *infix);

#endif