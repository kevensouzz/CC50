#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int crypto(char *plaintext, int key)
{

  char ciphertext[strlen(plaintext) + 1];

  for (int i = 0; i < strlen(plaintext); i++)
  {

    char currentChar = plaintext[i];

    if (isalpha(currentChar))
    {
      char base = islower(currentChar) ? 'a' : 'A';
      ciphertext[i] = (currentChar - base + key) % 26 + base;
    }
    else
    {
      ciphertext[i] = currentChar;
    }
  }

  ciphertext[strlen(plaintext)] = '\0';
  printf("ciphertext: %s", ciphertext);
}

int main(int argc, char *argv[])
{

  if (argc != 2)
  {
    printf("Usage: ./caesar key\n");
    return 1;
  }

  int key = atoi(argv[1]);

  if (key <= 0 || key == 0 && argv[1][0] != '0')
  {
    printf("Invalid input for key. Please provide a valid integer.\n");
    return 1;
  }

  char *plaintext = NULL;
  size_t bufsize = 0;
  printf("plaintext: ");
  getline(&plaintext, &bufsize, stdin);

  crypto(plaintext, key);

  free(plaintext);

  return 0;
}