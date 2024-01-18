#include <stdio.h>

int main(void)
{
  float scores[4], result;

  do
  {
    printf("first note: (0 - 10) ");
    scanf("%f", &scores[0]);

    if (scores[0] < 0 || scores[0] > 10)
    {
      printf("Invalid input. Please enter a value between 0 and 10.\n");
    }
  } while (scores[0] < 0 || scores[0] > 10);

  do
  {
    printf("second note: (0 - 10) ");
    scanf("%f", &scores[1]);

    if (scores[1] < 0 || scores[1] > 10)
    {
      printf("Invalid input. Please enter a value between 0 and 10.\n");
    }
  } while (scores[1] < 0 || scores[1] > 10);

  do
  {
    printf("third note: (0 - 10) ");
    scanf("%f", &scores[2]);

    if (scores[2] < 0 || scores[2] > 10)
    {
      printf("Invalid input. Please enter a value between 0 and 10.\n");
    }
  } while (scores[2] < 0 || scores[2] > 10);

  do
  {
    printf("fourth note: (0 - 10) ");
    scanf("%f", &scores[3]);

    if (scores[3] < 0 || scores[3] > 10)
    {
      printf("Invalid input. Please enter a value between 0 and 10.\n");
    }
  } while (scores[3] < 0 || scores[3] > 10);

  size_t lenght = sizeof(scores) / sizeof(scores[0]);
  result = (scores[0] + scores[1] + scores[2] + scores[3]) / lenght;
  printf("annual media: %.2f\n", result);

  return 0;
}
