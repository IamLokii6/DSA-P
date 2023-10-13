#include <stdio.h>
#include <ctype.h>
#include "../stack/stack.h"

int evaluatePostfix(char *exp)
{
    stack *s = createStack();
    for (int i = 0; exp[i]; i++)
    {
        if (isdigit(exp[i]))
            push(s, exp[i] - '0');

        else
        {
            int val1 = pop(s);
            int val2 = pop(s);
            switch (exp[i])
            {
            case '+':
                push(s, val2 + val1);
                break;
            case '-':
                push(s, val2 - val1);
                break;
            case '*':
                push(s, val2 * val1);
                break;
            case '/':
                push(s, val2 / val1);
                break;
            }
        }
    }
    return pop(s);
}