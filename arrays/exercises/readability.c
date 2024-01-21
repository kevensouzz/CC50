#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int colemanLiau(char *text)
{
  int letters = 0, words = 1, sentences = 0;

  for (int i = 0; i < strlen(text); i++)
  {
    char currentChar = text[i];

    if (isalpha(currentChar))
      letters++;
    else if (isblank(currentChar))
      words++;
    else if (currentChar == '.' || currentChar == '?' || currentChar == '!')
      sentences++;
  }

  int grade = 0.0588 * letters / words * 100 - 0.296 * sentences / words * 100 - 15.8;

  if (grade > 16)
    printf("After Grade 16\n");
  else if (grade < 1)
    printf("Before Grade 1\n");
  else
    printf("Grade: %d\n", grade);
}

int main(void)
{
  char *text = NULL;
  size_t bufsize = 0;

  printf("Text: ");
  getline(&text, &bufsize, stdin);

  colemanLiau(text);

  free(text);
}