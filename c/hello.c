#include <stdio.h>

int sayMyName()
{
  char name[50];

  printf("what is your name? ");
  scanf("%49s", name);

  printf("hello, %s!\n", name);
  return 0;
}

int main(void)
{
  sayMyName();
}