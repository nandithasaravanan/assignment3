
#include <stdio.h>

#define MAX_SIZE 100000

int steps = 0;

/* Linear Search */
int linear_search(const int a[], int n, int key)
{
    steps = 0;

    for (int i = 0; i < n; i++)
    {
        steps++;

        if (a[i] == key)
            return i;
    }

    return -1;
}

/* Binary Search */
int binary_search(const int a[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    steps = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

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
    /* Sample catalogue */
    int sorted[] =
    {
        1021, 1048, 1103, 1190, 1222,
        1305, 1377, 1402, 1460, 1533
    };

    int unsorted[] =
    {
        1533, 1460, 1402, 1377, 1305,
        1222, 1190, 1103, 1048, 1021
    };

    int keys[] = {1021, 1305, 1533, 1400};

    int n = 10;

    printf("LINEAR SEARCH RESULTS\n");

    for (int i = 0; i < 4; i++)
    {
        int pos = linear_search(unsorted, n, keys[i]);

        printf("Book %d -> index %d, comparisons = %d\n",
               keys[i], pos, steps);
    }

    printf("\nBINARY SEARCH RESULTS\n");

    for (int i = 0; i < 4; i++)
    {
        int pos = binary_search(sorted, n, keys[i]);

        printf("Book %d -> index %d, comparisons = %d\n",
               keys[i], pos, steps);
    }

    /* Experimental investigation */
    int data[MAX_SIZE];
    int reverse[MAX_SIZE];

    int sizes[] = {1000, 10000, 100000};

    printf("\nEXPERIMENTAL COMPARISON\n");
    printf("Size\tLinear Success\tLinear Missing");
    printf("\tBinary Success\tBinary Missing\n");

    for (int k = 0; k < 3; k++)
    {
        int size = sizes[k];

        for (int i = 0; i < size; i++)
        {
            data[i] = 1000 + (i * 2);
            reverse[i] = data[size - 1 - i];
        }

        int key = data[size / 2];
        int missing = data[size - 1] + 1;

        linear_search(reverse, size, key);
        int ls = steps;

        linear_search(reverse, size, missing);
        int lm = steps;

        binary_search(data, size, key);
        int bs = steps;

        binary_search(data, size, missing);
        int bm = steps;

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",
               size, ls, lm, bs, bm);
    }

    return 0;
}
