#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

int preferences[MAX_VOTERS][MAX_CANDIDATES];

typedef struct
{
    char name[16];
    int votes;
    bool eliminated;
} candidate;

candidate candidates[MAX_CANDIDATES];

int voter_count;
int candidate_count;

bool vote(int voter, int rank, char name[16]);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        strcpy(candidates[i].name, argv[i + 1]);
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = 0;
    printf("Number of voters: ");
    scanf("%d", &voter_count);

    while (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            char name[16];
            printf("Rank %i: ", j + 1);
            scanf("%15s", name);

            while (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                printf("Rank %i: ", j + 1);
                scanf("%15s", name);
            }
        }

        printf("\n");
    }

    while (true)
    {
        tabulate();

        bool won = print_winner();

        if (won)
        {
            break;
        }

        int min = find_min();
        bool tie = is_tie(min);

        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        eliminate(min);

        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

bool vote(int voter, int rank, char name[16])
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

void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        if (!candidates[preferences[i][0]].eliminated)
        {
            candidates[preferences[i][0]].eliminated++;
        }
        else
        {
            for (int j = 0; j < candidate_count; j++)
            {
                if (!candidates[preferences[i][j]].eliminated)
                {
                    !candidates[preferences[i][j]].eliminated++;
                    break;
                }
            }
        }
    }
}

bool print_winner(void)
{
    int votesNeededToWin = voter_count / 2;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes >= votesNeededToWin)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

int find_min(void)
{
    int minVotes = voter_count;

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes < minVotes)
        {
            minVotes = candidates[i].votes;
        }
    }
    return minVotes;
}

bool is_tie(int min)
{
    min = find_min();

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

void eliminate(int min)
{
    min = find_min();

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes <= min)
        {
            candidates[i].eliminated == true;
        }
    }
}