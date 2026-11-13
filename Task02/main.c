
#include <stdio.h>

#define MAX 10000

typedef struct
{
    unsigned long long comparisons;
    unsigned long long swaps;
    unsigned long long shifts;
} Stats;

// 1. Bubble Sort with Early Exit
Stats bubble_sort(int a[], int n)
{
    Stats s = {0, 0, 0};

    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++)
        {
            s.comparisons++;

            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                s.swaps++;
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }

    return s;
}

// 2. Selection Sort
Stats selection_sort(int a[], int n)
{
    Stats s = {0, 0, 0};

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            s.comparisons++;

            if (a[j] < a[min])
                min = j;
        }

        if (min != i)
        {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;

            s.swaps++;
        }
    }

    return s;
}

// 3. Insertion Sort
Stats insertion_sort(int a[], int n)
{
    Stats s = {0, 0, 0};

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0)
        {
            s.comparisons++;

            if (a[j] > key)
            {
                a[j + 1] = a[j];
                s.shifts++;
                j--;
            }
            else
                break;
        }

        a[j + 1] = key;
    }

    return s;
}

// Generate sorted array
void make_sorted(int a[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = 1000 + i * 10;
}

// Generate nearly sorted array
// Reverse only the last 20 elements
void make_nearly_sorted(int a[], int n)
{
    make_sorted(a, n);

    int start = n - 20;

    for (int i = 0; i < 10; i++)
    {
        int temp = a[start + i];
        a[start + i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
}

// Generate reverse-sorted array
void make_reverse(int a[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = 1000 + (n - 1 - i) * 10;
}

// Generate random array using fixed seed
void make_random(int a[], int n)
{
    make_sorted(a, n);

    unsigned int seed = 123456789u + (unsigned int)n;

    for (int i = n - 1; i > 0; i--)
    {
        seed = 1664525u * seed + 1013904223u;

        int j = (int)(seed % (unsigned int)(i + 1));

        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

int main(void)
{
    static int original[MAX];
    static int work[MAX];

    int sizes[] = {100, 1000, 10000};

    const char *orders[] = {
        "Sorted",
        "NearlySorted",
        "Reverse",
        "Random"
    };

    for (int si = 0; si < 3; si++)
    {
        int n = sizes[si];

        printf("\nN = %d\n", n);

        printf("Input          Algorithm   Comparisons   Swaps   Shifts\n");

        for (int order = 0; order < 4; order++)
        {
            if (order == 0)
                make_sorted(original, n);

            else if (order == 1)
                make_nearly_sorted(original, n);

            else if (order == 2)
                make_reverse(original, n);

            else
                make_random(original, n);

            for (int alg = 0; alg < 3; alg++)
            {
                // Copy original input before sorting
                for (int i = 0; i < n; i++)
                    work[i] = original[i];

                Stats s;

                const char *name;

                if (alg == 0)
                {
                    s = bubble_sort(work, n);
                    name = "Bubble";
                }
                else if (alg == 1)
                {
                    s = selection_sort(work, n);
                    name = "Selection";
                }
                else
                {
                    s = insertion_sort(work, n);
                    name = "Insertion";
                }

                printf("%-14s %-10s %12llu %7llu %7llu\n",
                       orders[order], name,
                       s.comparisons, s.swaps, s.shifts);
            }
        }
    }

    return 0;
}
