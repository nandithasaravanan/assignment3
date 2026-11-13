
#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

long long merge_comparisons = 0;
long long qsort_comparisons = 0;

/* Merge two descending-order arrays */
int merge(const int a[], int na,
          const int b[], int nb, int out[])
{
    int i = 0, j = 0, k = 0;

    merge_comparisons = 0;

    /* Compare elements from both arrays */
    while (i < na && j < nb)
    {
        merge_comparisons++;

        if (a[i] >= b[j])
        {
            out[k] = a[i];
            i++;
        }
        else
        {
            out[k] = b[j];
            j++;
        }

        k++;
    }

    /* Copy remaining elements from A */
    while (i < na)
    {
        out[k] = a[i];
        i++;
        k++;
    }

    /* Copy remaining elements from B */
    while (j < nb)
    {
        out[k] = b[j];
        j++;
        k++;
    }

    return k;
}

/* Verify descending order */
int is_sorted(const int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < a[i + 1])
            return 0;
    }

    return 1;
}

/* qsort comparison function */
int compare_desc(const void *x, const void *y)
{
    int a = *(const int *)x;
    int b = *(const int *)y;

    qsort_comparisons++;

    if (a > b)
        return -1;

    if (a < b)
        return 1;

    return 0;
}

int main(void)
{
    /* Sample merit lists */
    int campusA[] = {98, 91, 85, 72};
    int campusB[] = {95, 91, 80};

    int merged[7];

    int na = sizeof(campusA) / sizeof(campusA[0]);
    int nb = sizeof(campusB) / sizeof(campusB[0]);

    printf("MERGING TWO MERIT LISTS\n\n");

    int total = merge(campusA, na, campusB, nb, merged);

    printf("Campus A: ");
    for (int i = 0; i < na; i++)
        printf("%d ", campusA[i]);

    printf("\nCampus B: ");
    for (int i = 0; i < nb; i++)
        printf("%d ", campusB[i]);

    printf("\n\nMerged List: ");

    for (int i = 0; i < total; i++)
        printf("%d ", merged[i]);

    printf("\nComparisons: %lld", merge_comparisons);

    printf("\nSorted verification: %s\n",
           is_sorted(merged, total) ? "PASS" : "FAIL");

    /* Test with one empty list */
    int empty_result[3];
    int empty_count = merge(NULL, 0, campusB, nb, empty_result);

    printf("\nEMPTY LIST TEST\n");
    printf("Merged List: ");

    for (int i = 0; i < empty_count; i++)
        printf("%d ", empty_result[i]);

    printf("\nComparisons: %lld\n", merge_comparisons);

    /* Test with all equal scores */
    int equalA[] = {90, 90, 90};
    int equalB[] = {90, 90};

    int equal_result[5];

    int equal_count = merge(equalA, 3, equalB, 2, equal_result);

    printf("\nEQUAL SCORES TEST\n");
    printf("Merged List: ");

    for (int i = 0; i < equal_count; i++)
        printf("%d ", equal_result[i]);

    printf("\nComparisons: %lld\n", merge_comparisons);

    /* Large-scale comparison */
    int a[MAX], b[MAX];
    int out[MAX * 2];
    int combined[MAX * 2];

    int sizes[] = {1000, 10000};

    printf("\nLARGE-SCALE COMPARISON\n");
    printf("Size\tMerge Comparisons\tqsort Comparisons\n");

    for (int s = 0; s < 2; s++)
    {
        int n = sizes[s];

        /* Generate two interleaved descending lists */
        for (int i = 0; i < n; i++)
        {
            a[i] = 2 * (n - i);
            b[i] = 2 * (n - i) - 1;
        }

        /* Merge method */
        int count = merge(a, n, b, n, out);

        long long mc = merge_comparisons;

        /* Join both arrays */
        for (int i = 0; i < n; i++)
        {
            combined[i] = a[i];
            combined[n + i] = b[i];
        }

        /* Sort combined array */
        qsort_comparisons = 0;

        qsort(combined, count, sizeof(int), compare_desc);

        printf("%d\t%lld\t\t\t%lld\n",
               n, mc, qsort_comparisons);
    }

    return 0;
}
