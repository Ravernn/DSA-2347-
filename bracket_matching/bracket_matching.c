#include <stdio.h>
#include "bracket_matching.h"
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

// fucntion to check if the brackets are balanced . 
//  if not then Returns 0 or 1 if brackets are balanced
int areBrcktsBalanced(char exp[])
{
  int j = 0;
  stack *s = createStack();
  while (exp[j] != '\0')
  {
    // checks for starting brackets and push in stack
    if (exp[j] == '{' || exp[j] == '(' || exp[j] == '[')
      push(s, exp[j]);

        // checks for ending bracket
  if (exp[j] == '}' || exp[j] == ')' || exp[j] == ']')
  {

    // checking if stack if empty if empty return 0
    if (isEmpty(s))
    {
      return 0;
    }
    else if (!isMatching(pop(s), exp[j]))
    {
      return 0;
    }
  }
  j++;
  }



  // Checking if stack is empty , if empty return true else return false
  if (isEmpty(s))
    return 1;
  else
    return 0;
}