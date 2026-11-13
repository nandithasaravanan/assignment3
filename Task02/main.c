
#include <stdio.h>

#define MAX 10000

long long comparisons;
long long movements;

/* Bubble Sort with Early Exit */
void bubble_sort(int a[], int n)
{
    comparisons = 0;
    movements = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < n - 1 - i; j++)
        {
            comparisons++;

            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                movements++;
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
}

/* Selection Sort */
void selection_sort(int a[], int n)
{
    comparisons = 0;
    movements = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            comparisons++;

            if (a[j] < a[min])
                min = j;
        }

        if (min != i)
        {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;

            movements++;
        }
    }
}

/* Insertion Sort */
void insertion_sort(int a[], int n)
{
    comparisons = 0;
    movements = 0;

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0)
        {
            comparisons++;

            if (a[j] > key)
            {
                a[j + 1] = a[j];
                movements++;
                j--;
            }
            else
                break;
        }

        a[j + 1] = key;
    }
}

/* Generate different input arrangements */
void generate(int a[], int n, int type)
{
    int i;

    if (type == 0)
    {
        /* Sorted */
        for (i = 0; i < n; i++)
            a[i] = i + 1;
    }

    else if (type == 1)
    {
        /* Nearly sorted: 20 late registrations */
        for (i = 0; i < n - 20; i++)
            a[i] = i + 21;

        for (i = 0; i < 20; i++)
            a[n - 20 + i] = i + 1;
    }

    else if (type == 2)
    {
        /* Reverse sorted */
        for (i = 0; i < n; i++)
            a[i] = n - i;
    }

    else
    {
        /* Deterministic random-like permutation */
        for (i = 0; i < n; i++)
            a[i] = ((i * 7919) % n) + 1;
    }
}

/* Copy original array */
void copy_array(int source[], int dest[], int n)
{
    for (int i = 0; i < n; i++)
        dest[i] = source[i];
}

int main(void)
{
    int original[MAX];
    int temp[MAX];

    int sizes[] = {100, 1000, 10000};

    char *types[] =
    {
        "Sorted",
        "Nearly Sorted",
        "Reverse Sorted",
        "Random"
    };

    printf("SORTING ALGORITHM PERFORMANCE\n");

    printf("\nSize\tInput Type\t\t"
           "Bubble C/S\tSelection C/S\tInsertion C/S\n");

    for (int s = 0; s < 3; s++)
    {
        int n = sizes[s];

        for (int t = 0; t < 4; t++)
        {
            generate(original, n, t);

            /* Bubble Sort */
            copy_array(original, temp, n);
            bubble_sort(temp, n);

            long long bc = comparisons;
            long long bs = movements;

            /* Selection Sort */
            copy_array(original, temp, n);
            selection_sort(temp, n);

            long long sc = comparisons;
            long long ss = movements;

            /* Insertion Sort */
            copy_array(original, temp, n);
            insertion_sort(temp, n);

            long long ic = comparisons;
            long long is = movements;

            printf("%d\t%-16s %lld/%lld\t"
                   "%lld/%lld\t%lld/%lld\n",
                   n, types[t],
                   bc, bs,
                   sc, ss,
                   ic, is);
        }

        printf("\n");
    }

    return 0;
}
