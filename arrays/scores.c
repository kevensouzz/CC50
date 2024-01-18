#include <stdio.h>

float average(int length, float array[]);

int main(void)
{
  int sessionQuantity;
  printf("session quantity: ");
  scanf("%d", &sessionQuantity);
  float scores[sessionQuantity], result;

  for (int i = 0; i != sessionQuantity; i++)
  {
    do
    {
      printf("%dª scores: ", i + 1);
      scanf("%f", &scores[i]);

      if (scores[i] < 0 || scores[i] > 10)
      {
        printf("invalid input; please enter a value between 0 and 10.\n");
      }

    } while (scores[i] < 0 || scores[i] > 10);
  }

  result = average(sessionQuantity, scores);
  printf("average: %.2f\n", result);
}

float average(int length, float array[])
{
  int sum = 0;
  for (int i = 0; i < length; i++)
  {
    sum += array[i];
  }
  return sum / length;
}
