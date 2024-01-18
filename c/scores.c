#include <stdio.h>

int main(void)
{
  float first, second, third, fourth, result;

  do
  {
    printf("first note: (0 - 10) ");
    scanf("%f", &first);

    if (first < 0 || first > 10)
    {
      printf("Invalid input. Please enter a value between 0 and 10.\n");
    }
  } while (first < 0 || first > 10);

  do
  {
    printf("second note: (0 - 10) ");
    scanf("%f", &second);

    if (second < 0 || second > 10)
    {
      printf("Invalid input. Please enter a value between 0 and 10.\n");
    }
  } while (second < 0 || second > 10);

  do
  {
    printf("third note: (0 - 10) ");
    scanf("%f", &third);

    if (third < 0 || third > 10)
    {
      printf("Invalid input. Please enter a value between 0 and 10.\n");
    }
  } while (third < 0 || third > 10);

  do
  {
    printf("fourth note: (0 - 10) ");
    scanf("%f", &fourth);

    if (fourth < 0 || fourth > 10)
    {
      printf("Invalid input. Please enter a value between 0 and 10.\n");
    }
  } while (fourth < 0 || fourth > 10);

  result = (first + second + third + fourth) / 4;
  printf("annual media: %.2f\n", result);

  return 0;
}
