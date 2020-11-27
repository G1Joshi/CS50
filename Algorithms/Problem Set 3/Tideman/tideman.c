#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 9

typedef struct
{
    int winner;
    int loser;
}
pair;
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;
string candidates[MAX];
int preferences[MAX][MAX];
bool locked[MAX][MAX];

bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }
    pair_count = 0;
    int voter_count = get_int("Number of voters: ");
    for (int i = 0; i < voter_count; i++)
    {
        int ranks[candidate_count];
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);
            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }
        record_preferences(ranks);
        printf("\n");
    }
    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!strcmp(name, candidates[i]))
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = (1 + i); j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (!(i == j) && (preferences[i][j] > preferences[j][i]))
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
}

int comparator(const void *a, const void *b)
{
    pair *A = (pair *)a;
    pair *B = (pair *)b;
    return (preferences[B->winner][B->loser] - preferences[A->winner][A->loser]);
}
void sort_pairs(void)
{
    qsort(pairs, pair_count, sizeof(pair), comparator);
}

bool cycle(int end, int cycle_start)
{
    if (end == cycle_start)
    {
        return true;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[end][i])
        {
            if (cycle(i, cycle_start))
            {
                return true;
            }
        }
    }
    return false;
}
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!cycle(pairs[i].loser, pairs[i].winner))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
}

void print_winner(void)
{
    int rank;
    for (int i = 0; i < candidate_count; i++)
    {
        rank = 0;
        for (int k = 0; k < candidate_count; k++)
        {
            if (locked[k][i] == false)
            {
                rank++;
            }
        }
        if (rank == candidate_count)
        {
            printf("%s\n", candidates[i]);
        }
    }
}
