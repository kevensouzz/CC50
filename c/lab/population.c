#include <stdio.h>

int populationCalc(int start_size, int end_size)
{
  int population = start_size, years = 0;

  while (population < end_size)
  {
    population = (population - population / 4) + (population / 3);
    years++;
  }

    printf("Years: %d\n", years);
}

int main(void)
{
  int start_size = 0, end_size;

  while (start_size < 9)
  {
    printf("Start Size: ");
    scanf("%d", &start_size);
  }

  while (end_size <= start_size)
  {
    printf("End Size: ");
    scanf("%d", &end_size);
  }

  populationCalc(start_size, end_size);
}