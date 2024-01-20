#include <stdio.h>
#include <string.h>

int isDigit(char c)
{
  return c >= '0' && c <= '9';
}

int luhnAlgorithm(const char *cardNumber)
{
  int len = strlen(cardNumber);

  if (len < 2)
    return 0;

  int sum = 0;
  int alternate = 0;

  for (int i = len - 1; i >= 0; i--)
  {
    char c = cardNumber[i];

    if (!isDigit(c))
      return 0;

    int digit = c - '0';

    if (alternate)
    {
      digit *= 2;
      if (digit > 9)
        digit -= 9;
    }

    sum += digit;
    alternate = !alternate;
  }

  return (sum % 10 == 0);
}

int main(void)
{
  char cardNumber[20];
  printf("Card Number: ");
  scanf("%19s", cardNumber);

  if (luhnAlgorithm(cardNumber))
    printf("Valid card number.\n");
  else
    printf("Invalid card number.\n");

  return 0;
}