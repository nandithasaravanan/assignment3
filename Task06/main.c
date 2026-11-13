
#include <stdio.h>
#include <string.h>

#define MAX 500
#define SIZE 30

int comparisons = 0;
int char_copies = 0;

/* Compare two names and count comparisons */
int compare_names(char a[], char b[])
{
    comparisons++;
    return strcmp(a, b);
}

/* Copy a string and count copied characters */
void copy_name(char dest[], char src[])
{
    strcpy(dest, src);
    char_copies += strlen(src) + 1;
}

/* Bubble sort */
void bubble_sort(char names[][SIZE], int n)
{
    int i, j;
    char temp[SIZE];

    comparisons = 0;
    char_copies = 0;

    for (i = 0; i < n - 1; i++)
    {
        int swapped = 0;

        for (j = 0; j < n - i - 1; j++)
        {
            if (compare_names(names[j], names[j + 1]) > 0)
            {
                copy_name(temp, names[j]);
                copy_name(names[j], names[j + 1]);
                copy_name(names[j + 1], temp);
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
}

/* Binary search */
int binary_search(char names[][SIZE], int n, char key[])
{
    int low = 0, high = n - 1;

    comparisons = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (compare_names(names[mid], key) == 0)
            return mid;

        if (strcmp(names[mid], key) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

/* Detect duplicate names */
void find_duplicates(char names[][SIZE], int n)
{
    int found = 0;

    printf("\nDuplicate names:\n");

    for (int i = 0; i < n - 1; i++)
    {
        if (strcmp(names[i], names[i + 1]) == 0)
        {
            if (i == 0 || strcmp(names[i], names[i - 1]) != 0)
                printf("%s\n", names[i]);

            found = 1;
        }
    }

    if (!found)
        printf("No duplicates found.\n");
}

/* Sort indices instead of copying names */
void sort_indices(char names[][SIZE], int index[], int n)
{
    int i, j, temp;

    comparisons = 0;

    for (i = 0; i < n - 1; i++)
    {
        int swapped = 0;

        for (j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            if (strcmp(names[index[j]],
                       names[index[j + 1]]) > 0)
            {
                temp = index[j];
                index[j] = index[j + 1];
                index[j + 1] = temp;
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
}

int main(void)
{
    char names[MAX][SIZE];
    char key[SIZE];
    int index[MAX];
    int n, pos;

    printf("HOSTEL RESIDENT DIRECTORY\n");

    printf("Enter number of residents (1-%d): ", MAX);
    scanf("%d", &n);
    getchar();

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of residents.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        while (1)
        {
            printf("Enter name %d: ", i + 1);

            if (fgets(names[i], SIZE, stdin) == NULL)
                return 1;

            int len = strlen(names[i]);

            if (len > 0 && names[i][len - 1] == '\n')
            {
                names[i][len - 1] = '\0';
            }
            else
            {
                int ch = getchar();

                if (ch != '\n' && ch != EOF)
                {
                    while (ch != '\n' && ch != EOF)
                        ch = getchar();

                    printf("Name too long. Maximum 29 characters.\n");
                    continue;
                }
            }

            if (strlen(names[i]) == 0)
            {
                printf("Name cannot be empty.\n");
                continue;
            }

            break;
        }
    }

    bubble_sort(names, n);

    printf("\nAlphabetical Order:\n");

    for (int i = 0; i < n; i++)
        printf("%s\n", names[i]);

    printf("\nSorting Comparisons = %d\n", comparisons);
    printf("Character Copies = %d\n", char_copies);

    printf("\nEnter name to search: ");
    fgets(key, SIZE, stdin);
    key[strcspn(key, "\n")] = '\0';

    pos = binary_search(names, n, key);

    if (pos != -1)
        printf("%s found at index %d\n", key, pos);
    else
        printf("%s not found\n", key);

    printf("Search Comparisons = %d\n", comparisons);

    find_duplicates(names, n);

    for (int i = 0; i < n; i++)
        index[i] = i;

    sort_indices(names, index, n);

    printf("\nIndex Sorting Comparisons = %d\n", comparisons);
    printf("Character Copies = 0\n");

    return 0;
}
