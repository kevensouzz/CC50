#include <stdio.h>

int defineHeight(void);

int main(void)
{
  int height = defineHeight();

  for (int i = 1; i <= height; i++)
  {
    for (int k = height; k > i; k--)
    {
      printf(".");
    }

    for (int j = 0; j < i; j++)
    {
      printf("#");
    }
    printf("\n");
  }
}

int defineHeight(void)
{
  int height;

  printf("how long do you want your pyramid? (1 - 8)\n");
  scanf("%d", &height);

  if (height > 8 || height < 1)
  {
    printf("this value isn't valid!\n\n");
    return defineHeight();
  }

  return height;
}