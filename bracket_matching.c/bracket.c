#include <stdio.h>
#include "../stack/stack.h"

int isMatching(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

if (isEmpty(s))
    return 1;
else
    return 0;
}