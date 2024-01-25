#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 9

typedef struct
{
    char *name;
    int votes;
} candidate;

candidate candidates[MAX];

int candidate_count;

bool vote(char *name);

void print_winner(void);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;

    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count;
    printf("Number of voters: ");
    scanf("%d", &voter_count);

    for (int i = 0; i < voter_count; i++)
    {
        char name[20];
        printf("Vote: ");
        scanf("%s", name);

        while (!vote(name))
        {
            printf("Invalid vote.\n");
            printf("Vote: ");
            scanf("%s", name);
        }
    }

    print_winner();

    return 0;
}

bool vote(char *name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes += 1;
            return true;
        }
    }

    return false;
}

void print_winner(void)
{
    int max_votes = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    printf("Winner(s):\n");
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}