
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* 1. Word count without string.h */
int word_count(const char s[])
{
    int count = 0;
    int inside = 0;
    int i = 0;

    while (s[i] != '\0')
    {
        if (isspace((unsigned char)s[i]))
        {
            inside = 0;
        }
        else if (inside == 0)
        {
            count++;
            inside = 1;
        }

        i++;
    }

    return count;
}

/* 2. Uppercase without string.h */
void uppercase_custom(char s[])
{
    int i = 0;

    while (s[i] != '\0')
    {
        s[i] = (char)toupper((unsigned char)s[i]);
        i++;
    }
}

/* 3. Reverse without string.h */
void reverse_custom(char s[])
{
    int left = 0;
    int right = 0;
    char temp;

    while (s[right] != '\0')
    {
        right++;
    }

    right--;

    while (left < right)
    {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

/* 4. Palindrome without string.h */
int palindrome_custom(const char s[])
{
    int left = 0;
    int right = 0;

    while (s[right] != '\0')
    {
        right++;
    }

    right--;

    while (left < right)
    {
        while (left < right &&
               !isalpha((unsigned char)s[left]))
        {
            left++;
        }

        while (left < right &&
               !isalpha((unsigned char)s[right]))
        {
            right--;
        }

        if (tolower((unsigned char)s[left]) !=
            tolower((unsigned char)s[right]))
        {
            return 0;
        }

        left++;
        right--;
    }

    return 1;
}

/* 5. Word count using library functions */
int word_count_library(const char s[])
{
    int count = 0;
    int inside = 0;
    size_t i;

    for (i = 0; i < strlen(s); i++)
    {
        if (isspace((unsigned char)s[i]))
        {
            inside = 0;
        }
        else if (inside == 0)
        {
            count++;
            inside = 1;
        }
    }

    return count;
}

/* 6. Uppercase using library functions */
void uppercase_library(char s[])
{
    size_t i;

    for (i = 0; i < strlen(s); i++)
    {
        s[i] = (char)toupper((unsigned char)s[i]);
    }
}

/* 7. Reverse using strlen() */
void reverse_library(char s[])
{
    int left = 0;
    int right = (int)strlen(s) - 1;
    char temp;

    while (left < right)
    {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

/* 8. Palindrome using string.h */
int palindrome_library(const char s[])
{
    char clean[200];
    char reversed[200];
    int i, j = 0;

    for (i = 0; s[i] != '\0' && j < 199; i++)
    {
        if (isalpha((unsigned char)s[i]))
        {
            clean[j++] =
                (char)tolower((unsigned char)s[i]);
        }
    }

    clean[j] = '\0';

    for (i = 0; i < j; i++)
    {
        reversed[i] = clean[j - 1 - i];
    }

    reversed[j] = '\0';

    return strcmp(clean, reversed) == 0;
}

int main(void)
{
    char message[] = "Meet at the library at 5 PM";
    char upper1[] = "hello world";
    char upper2[] = "hello world";
    char reverse1[] = "HELLO";
    char reverse2[] = "HELLO";

    char empty[] = "";
    char spaces[] = "Hello   World";
    char tab[] = "Hello\tWorld";

    printf("TEXT PROCESSING PROGRAM\n");

    printf("\nWITHOUT STRING.H\n");

    printf("Word count = %d\n", word_count(message));

    printf("Uppercase = ");
    uppercase_custom(upper1);
    printf("%s\n", upper1);

    reverse_custom(reverse1);
    printf("Reversed string = %s\n", reverse1);

    printf("Madam, I'm Adam = %d\n",
           palindrome_custom("Madam, I'm Adam"));

    printf("Hello = %d\n",
           palindrome_custom("Hello"));

    printf("\nWITH STRING.H\n");

    printf("Word count = %d\n",
           word_count_library(message));

    uppercase_library(upper2);
    printf("Uppercase = %s\n", upper2);

    reverse_library(reverse2);
    printf("Reversed string = %s\n", reverse2);

    printf("Madam, I'm Adam = %d\n",
           palindrome_library("Madam, I'm Adam"));

    printf("Hello = %d\n",
           palindrome_library("Hello"));

    printf("\nADDITIONAL TEST CASES\n");

    printf("Empty string words = %d\n",
           word_count(empty));

    printf("Multiple spaces words = %d\n",
           word_count(spaces));

    printf("Tab separated words = %d\n",
           word_count(tab));

    /* Safe string copying */
    char destination[20];

    snprintf(destination, sizeof(destination), "%s", "Hello");

    printf("Safe copied string = %s\n", destination);

    return 0;
}
