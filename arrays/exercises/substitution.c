#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int crypto(char *plaintext, char *key)
{
  int length = strlen(plaintext);
  char *ciphertext = malloc(length + 1);

  for (int i = 0; i < length; i++)
  {
    if (isalpha(plaintext[i]))
    {
      char base = isupper(plaintext[i]) ? 'A' : 'a';
      int index = tolower(plaintext[i]) - 'a';
      ciphertext[i] = isupper(plaintext[i]) ? toupper(key[index]) : tolower(key[index]);
    }
    else
    {
      ciphertext[i] = plaintext[i];
    }
  }

  ciphertext[length] = '\0';
  printf("ciphertext: %s", ciphertext);

  free(ciphertext);

  return 0;
}

int main(int argc, char *argv[])
{
  char *key = argv[1];

  if (argc != 2 || strlen(key) != 26)
  {
    printf("Usage: ./substitution key\n");
    return 1;
  }

  for (int i = 0; i < 26; i++)
  {
    if (!isalpha(key[i]))
    {
      printf("Key must contain only alphabetic characters.\n");
      return 1;
    }
  }

  char *plaintext = NULL;
  size_t bufsize = 0;
  printf("plaintext: ");
  getline(&plaintext, &bufsize, stdin);

  crypto(plaintext, key);

  free(plaintext);

  return 0;
}