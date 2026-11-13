
#include <stdio.h>
#include <time.h>

#define MAX_CANDIDATES 12
#define MAX_VOTES 500000

int main(void)
{
    int votes[MAX_VOTES];
    int count[MAX_CANDIDATES] = {0};
    int order[MAX_CANDIDATES];

    int candidates, total;
    int valid = 0, invalid = 0;
    int i, j, temp;

    clock_t start, end;
    double time_taken;

    printf("STUDENT COUNCIL ELECTION\n");

    printf("Enter number of candidates: ");
    scanf("%d", &candidates);

    if (candidates < 1 || candidates > MAX_CANDIDATES)
    {
        printf("Invalid number of candidates.\n");
        return 1;
    }

    printf("Enter total number of votes: ");
    scanf("%d", &total);

    if (total < 0 || total > MAX_VOTES)
    {
        printf("Invalid number of votes.\n");
        return 1;
    }

    printf("\nEnter candidate numbers for each vote:\n");

    for (i = 0; i < total; i++)
    {
        scanf("%d", &votes[i]);
    }

    /* Start measuring election processing time */
    start = clock();

    /* Count valid and invalid votes */
    for (i = 0; i < total; i++)
    {
        if (votes[i] >= 1 && votes[i] <= candidates)
        {
            count[votes[i] - 1]++;
            valid++;
        }
        else
        {
            invalid++;
        }
    }

    /* Initialize candidate positions */
    for (i = 0; i < candidates; i++)
    {
        order[i] = i;
    }

    /* Selection sort in descending order */
    for (i = 0; i < candidates - 1; i++)
    {
        int max = i;

        for (j = i + 1; j < candidates; j++)
        {
            if (count[order[j]] > count[order[max]] ||
               (count[order[j]] == count[order[max]] &&
                order[j] < order[max]))
            {
                max = j;
            }
        }

        temp = order[i];
        order[i] = order[max];
        order[max] = temp;
    }

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    /* Display results */
    printf("\n----- ELECTION RESULTS -----\n");

    printf("Valid votes   : %d\n", valid);
    printf("Invalid votes : %d\n", invalid);

    printf("\nCandidate\tVotes\n");

    for (i = 0; i < candidates; i++)
    {
        printf("%d\t\t%d\n",
               order[i] + 1, count[order[i]]);
    }

    /* Check whether the highest votes are tied */
    printf("\n----- WINNER RESULT -----\n");

    if (candidates > 1 &&
        count[order[0]] == count[order[1]])
    {
        printf("Election Result: TIE\n");
        printf("Candidates with highest votes: ");

        for (i = 0; i < candidates; i++)
        {
            if (count[order[i]] == count[order[0]])
                printf("%d ", order[i] + 1);
        }

        printf("\nVotes received: %d\n", count[order[0]]);
    }
    else
    {
        printf("Winner: Candidate %d\n", order[0] + 1);
        printf("Votes received: %d\n", count[order[0]]);
    }

    printf("\nProcessing Time: %.6f seconds\n", time_taken);

    return 0;
}
