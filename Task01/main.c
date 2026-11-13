
#include <stdio.h>

#define MAX 100000

int steps;

// Linear Search
int linear_search(const int a[], int n, int key)
{
    int i;
    steps = 0;

    for (i = 0; i < n; i++)
    {
        steps++;

        if (a[i] == key)
            return i;
    }

    return -1;
}

// Binary Search
int binary_search(const int a[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int mid;

    steps = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        steps++;

        if (a[mid] == key)
            return mid;

        else if (a[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main(void)
{
    // Given 10-book catalogue
    int accession[] = {
        1021, 1048, 1103, 1190, 1222,
        1305, 1377, 1402, 1460, 1533
    };

    int keys[] = {1021, 1305, 1533, 1400};

    int n = sizeof(accession) / sizeof(accession[0]);

    int i, pos;

    printf("----- BINARY SEARCH TEST -----\n");

    for (i = 0; i < 4; i++)
    {
        pos = binary_search(accession, n, keys[i]);

        printf("Book %d -> index %d, comparisons = %d\n",
               keys[i], pos, steps);
    }

    // Large catalogue experiments
    int sorted[MAX];
    int unsorted[MAX];

    int sizes[] = {1000, 10000, 100000};
    int s, j;

    printf("\n----- LARGE CATALOGUE EXPERIMENT -----\n");

    printf("Size       Test       Linear    Binary\n");

    for (s = 0; s < 3; s++)
    {
        n = sizes[s];

        // Generate sorted accession numbers
        for (i = 0; i < n; i++)
        {
            sorted[i] = 1000 + i * 3;
        }

        // Create an unsorted array in reverse order
        for (i = 0; i < n; i++)
        {
            unsorted[i] = sorted[n - 1 - i];
        }

        int test_keys[4];

        // Beginning, middle, end and missing
        test_keys[0] = unsorted[0];
        test_keys[1] = unsorted[n / 2];
        test_keys[2] = unsorted[n - 1];
        test_keys[3] = 999;

        char *labels[] = {
            "Beginning", "Middle", "End", "Missing"
        };

        for (j = 0; j < 4; j++)
        {
            linear_search(unsorted, n, test_keys[j]);
            int linear_steps = steps;

            binary_search(sorted, n, test_keys[j]);
            int binary_steps = steps;

            printf("%-10d %-10s %-9d %d\n",
                   n, labels[j],
                   linear_steps, binary_steps);
        }
    }

    return 0;
}
