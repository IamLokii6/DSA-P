#include <stdio.h>
#include "bracket.h"
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

int areBracketsBalanced(char exp[])
{
  int i = 0;
  stack *s = createStack();
  while (exp[i] != '\0')
  {
    if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
      push(s, exp[i]);

  if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
  {

    if (isEmpty(s))
    {
      return 0;
    }
    else if (!isMatching(pop(s), exp[i]))
    {
      return 0;
    }
  }
  i++;
  }


if (isEmpty(s))
    return 1;
else
    return 0;
}