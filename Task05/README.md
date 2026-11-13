
# Task 05 – Processing Text Without the Library

## 1. Aim
To perform string operations in C, including word counting, uppercase conversion, string reversal and palindrome checking, first using loops and character arrays and then using string.h library functions.

## 2. Concepts Used
- Character arrays
- Null character ('\0')
- Loops and conditional statements
- Character handling using ctype.h
- String handling using string.h
- strlen(), strcpy(), strcmp() and toupper()
- Safe input using fgets()
- Safe copying using snprintf()

## 3. Algorithm

### A. Word Counting
1. Initialize count = 0 and inside = 0.
2. Traverse the string until '\0'.
3. If a whitespace character is found, set inside = 0.
4. If a non-whitespace character is found and inside = 0, increment count.
5. Set inside = 1.
6. Return the word count.

### B. Uppercase Conversion
1. Traverse each character.
2. Convert lowercase letters into uppercase.
3. Display the converted string.

### C. String Reversal
1. Find the length of the string.
2. Exchange the first and last characters.
3. Continue exchanging characters until the middle is reached.
4. Display the reversed string.

### D. Palindrome Checking
1. Initialize left and right positions.
2. Skip non-alphabetic characters.
3. Convert both characters to lowercase.
4. Compare the characters.
5. If they differ, return 0.
6. If all characters match, return 1.

## 4. Importance of Null Character

The null character '\0' indicates the end of a string in C.

It allows loops and string functions to identify where a character array ends.

## 5. Difference Between Character Array and Pointer

char s[] = "OK" creates a modifiable character array.

char *s = "OK" points to a string literal, which must not be modified.

## 6. Library Functions

| Function | Purpose |
|---|---|
| strlen() | Finds string length |
| strcpy() | Copies a string |
| strcmp() | Compares two strings |
| toupper() | Converts a character to uppercase |
| snprintf() | Performs bounded formatted copying |

## 7. Test Cases

| Input | Expected Result |
|---|---|
| "Meet at the library at 5 PM" | 7 words |
| "Madam, I'm Adam" | Palindrome |
| "Hello" | Not a palindrome |
| "Hello   World" | 2 words |
| Empty string | 0 words |
| "Hello\tWorld" | 2 words |

## 8. Complexity Analysis

Let n represent the number of characters.

| Operation | Time Complexity | Space Complexity |
|---|---|---|
| Word counting | O(n) | O(1) |
| Uppercase conversion | O(n) | O(1) |
| Reversal | O(n) | O(1) |
| Palindrome checking | O(n) | O(1) |

Repeatedly calling strlen() inside a loop can increase the time complexity to O(n²).

Recursive reversal takes O(n) time and O(n) stack space.

## 9. Safety Analysis

- strcpy() can cause buffer overflow if the destination array is too small.
- snprintf() provides bounded formatted copying.
- fgets() safely limits the number of input characters.
- gets() was removed from the C standard because it cannot prevent buffer overflow.

## 10. Conclusion

The program successfully performs string operations using both manual loops and standard library functions. The experiment demonstrates the importance of string handling, null termination, time complexity and safe memory management.
