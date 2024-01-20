#include <stdio.h>

int i = 0, totalCoins = 0;
float coins[4] = {0.25, 0.10, 0.05, 0.01}, changeOwed;

int countCoins(float changeOwed)
{
  while (i < 4)
  {
    if (changeOwed >= coins[i])
    {
      changeOwed -= coins[i];
      totalCoins++;
      countCoins(changeOwed);
    }
    else
    {
      i++;
      countCoins(changeOwed);
    }
  }
}

int main(void)
{
  printf("( 0.1 = 0.10$ | 0.01 = 0.01$ )\n\n");
  printf("change owed? ");
  scanf("%f", &changeOwed);

  countCoins(changeOwed);

  printf("total coins needed: %d\n", totalCoins);
}
