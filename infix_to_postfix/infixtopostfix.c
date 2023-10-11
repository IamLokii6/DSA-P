#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "infixtopostfix.h"
#include "../stack/stack.h"

// return postfix expression
char *infixToPostfix(char *infix)
{
    int j = 0;
    int len = strlen(infix);
    char *postfix = (char *)malloc(sizeof(char) * len);
    stack *s = createStack();

    while (!isEmpty(s))
    {
        if (peek(s) == '(')
        {
            return "Invalid Expression";
        }
        postfix[j++] = pop(s);
    }

    postfix[j] = '\0';
    return postfix;
}

int precedence(char operator)
{
    switch (operator)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}
