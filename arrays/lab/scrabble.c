#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char *word)
{
  int score = 0;

  for (int i = 0; i < strlen(word); i++)
  {
    if (isalpha(word[i]))
    {
      char letter = tolower(word[i]);
      int index = letter - 'a';

      if (index >= 0 && index < 26)
      {
        score += POINTS[index];
      }
    }
  }

  return score;
}

int main(void)
{
  char *word1 = NULL, *word2 = NULL;
  size_t bufferSize = 0;

  printf("Payer 1: ");
  getline(&word1, &bufferSize, stdin);

  printf("Payer 2: ");
  getline(&word2, &bufferSize, stdin);

  int score1 = compute_score(word1);
  int score2 = compute_score(word2);

  score1 > score2 ? printf("PLAYER 1 WINS!\n") : printf("PLAYER 2 WINS!\n");

  free(word1);
  free(word2);

  return 0;
}