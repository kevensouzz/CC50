#include <stdio.h>

int countCoins(float changeOwed);
int i = 0, totalCoins = 0;
float coins[4] = {0.25, 0.10, 0.5, 0.1}, changeOwed;

int main(void)
{
  printf("Change Owed? ");
  scanf("%f", &changeOwed);

  countCoins(changeOwed);

  printf("Total Coins Used: %d\n", totalCoins);
}

int countCoins(float changeOwed)
{
  if (i <= 4)
  {
    if (changeOwed >= coins[i])
    {
      changeOwed -= coins[i];
      totalCoins++;
      i++;
      countCoins(changeOwed);
    }
    else
    {
      i++;
      countCoins(changeOwed);
    }
  }
}