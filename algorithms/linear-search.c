#include <stdio.h>

int linear_search(int numbers[5], int search)
{
  int quantity = 0;
  int positions[5];
  int index_position = 0;

  for (int i = 0; i < 5; i++)
  {
    if (numbers[i] == search)
    {
      quantity++;
      positions[index_position++] = i + 1;
    }
  }

  printf("number %d was founded %dx\n", search, quantity);

  if (quantity > 0)
  {
    printf("Positions: ");
    for (int i = 0; i < quantity; i++)
    {
      printf("%d", positions[i]);
      if (i < quantity - 1)
      {
        printf(", ");
      }
    }
    printf("\n");
  }
}

int main(void)
{
  int numbers[5], search;
  printf("Enter 5 numbers below.\n\n");

  for (int i = 0; i < 5; i++)
  {
    printf("Number %d: ", i + 1);
    scanf("%d", &numbers[i]);

    if (numbers[i] > 9 || numbers[i] < 0)
    {
      printf("Please enter numbers from 0 to 9.\n");
      return 1;
    }
  }

  printf("Enter the number that you want to search: ");
  scanf("%d", &search);

  if (search > 9 || search < 0)
  {
    printf("Please enter a number from 0 to 9.\n");
    return 1;
  }

  linear_search(numbers, search);

  return 0;
}