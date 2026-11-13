
#include <stdio.h>
#include <time.h>

#define DISTRICTS 38
#define MONTHS 12
#define SIZE 2000
#define USE_SAMPLE_DATA 1

int rain[DISTRICTS][MONTHS];
int large[SIZE][SIZE];

/* 1. Calculate annual rainfall of each district */
void annual_total()
{
    int i, j, total;

    printf("\nANNUAL RAINFALL TOTALS\n");

    for (i = 0; i < DISTRICTS; i++)
    {
        total = 0;

        for (j = 0; j < MONTHS; j++)
        {
            total += rain[i][j];
        }

        printf("District %d = %d mm\n", i + 1, total);
    }
}

/* 2. Calculate monthly average rainfall */
void monthly_average()
{
    int i, j, total;

    printf("\nMONTHLY AVERAGE RAINFALL\n");

    for (j = 0; j < MONTHS; j++)
    {
        total = 0;

        for (i = 0; i < DISTRICTS; i++)
        {
            total += rain[i][j];
        }

        printf("Month %d = %.2f mm\n",
               j + 1, (float)total / DISTRICTS);
    }
}

/* 3. Find maximum rainfall */
void maximum_rainfall()
{
    int i, j;
    int max = rain[0][0];
    int district = 0, month = 0;

    for (i = 0; i < DISTRICTS; i++)
    {
        for (j = 0; j < MONTHS; j++)
        {
            if (rain[i][j] > max)
            {
                max = rain[i][j];
                district = i;
                month = j;
            }
        }
    }

    printf("\nWETTEST DISTRICT-MONTH\n");
    printf("District = %d\n", district + 1);
    printf("Month = %d\n", month + 1);
    printf("Maximum rainfall = %d mm\n", max);
}

/* 4. Find districts below 60% of state average */
void deficient_districts()
{
    int i, j, total;
    double state_total = 0;
    double state_average;

    for (i = 0; i < DISTRICTS; i++)
    {
        for (j = 0; j < MONTHS; j++)
        {
            state_total += rain[i][j];
        }
    }

    state_average = state_total / DISTRICTS;

    printf("\nSTATE AVERAGE ANNUAL RAINFALL = %.2f mm\n",
           state_average);

    printf("60%% OF STATE AVERAGE = %.2f mm\n",
           state_average * 0.60);

    printf("\nDEFICIENT DISTRICTS\n");

    for (i = 0; i < DISTRICTS; i++)
    {
        total = 0;

        for (j = 0; j < MONTHS; j++)
        {
            total += rain[i][j];
        }

        if (total < state_average * 0.60)
        {
            printf("District %d = %d mm\n", i + 1, total);
        }
    }
}

/* Measure row-wise traversal time */
void row_wise()
{
    int i, j;
    volatile long long sum = 0;
    clock_t start, end;

    start = clock();

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            sum += large[i][j];
        }
    }

    end = clock();

    printf("Row-wise time = %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);
}

/* Measure column-wise traversal time */
void column_wise()
{
    int i, j;
    volatile long long sum = 0;
    clock_t start, end;

    start = clock();

    for (j = 0; j < SIZE; j++)
    {
        for (i = 0; i < SIZE; i++)
        {
            sum += large[i][j];
        }
    }

    end = clock();

    printf("Column-wise time = %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);
}

int main()
{
    int i, j;

#if USE_SAMPLE_DATA

    /* Generate sample rainfall data */
    for (i = 0; i < DISTRICTS; i++)
    {
        for (j = 0; j < MONTHS; j++)
        {
            rain[i][j] = 80 + ((i * 7 + j * 11) % 120);
        }
    }

    printf("Using sample rainfall data.\n");

#else

    /* Read rainfall data from user */
    printf("Enter rainfall for 38 districts and 12 months:\n");

    for (i = 0; i < DISTRICTS; i++)
    {
        for (j = 0; j < MONTHS; j++)
        {
            printf("District %d, Month %d: ", i + 1, j + 1);
            scanf("%d", &rain[i][j]);
        }
    }

#endif

    annual_total();
    monthly_average();
    maximum_rainfall();
    deficient_districts();

    /* Initialize large array for timing */
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            large[i][j] = (i + j) % 100;
        }
    }

    printf("\nTRAVERSAL PERFORMANCE\n");

    row_wise();
    column_wise();

    return 0;
}
