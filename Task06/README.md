Aim
To develop a C program that stores hostel residents' names, sorts them alphabetically, searches for a particular name using binary search, and identifies duplicate entries.
Concepts Used
- Two-dimensional character arrays.
- fgets() for safe string input.
- strcmp() for comparing strings.
- strcpy() for copying and swapping strings.
- Binary search.
- Duplicate detection.
- Array of indices for efficient sorting.
A. String Comparison using strcmp()
strcmp() compares two strings character by character using ASCII values.
- Returns 0 if both strings are equal.
- Returns a negative value if the first string comes before the second.
- Returns a positive value if the first string comes after the second.
For example, "Apple" and "apple" are ordered differently because uppercase and lowercase letters have different ASCII values.
B. Safe String Input
fgets() reads a string safely by limiting the number of characters entered.

The newline character is removed using strcspn() or by manually checking the final character.

For char names[30], a maximum of 29 characters can be stored because one position is required for the null character '\0'.
C. Sorting and Searching
- Sorting: Arrange resident names in alphabetical order using strcmp() and strcpy().
- Binary Search: Search for a name by repeatedly dividing the sorted list into two halves.
- Duplicate Detection: Compare adjacent names after sorting. Identical names will appear next to each other.
D. Complexity Analysis
Operation	Time Complexity
Bubble sort	O(n²)
Binary search	O(log n)
Duplicate detection	O(n)
Sorting indices	O(n²) with bubble sort

E. Sorting Names vs Sorting Indices
Sorting the actual names requires copying characters whenever two names are swapped.

Sorting an array of indices only swaps integer values. Therefore, it reduces character-copying operations.

The trade-off is that an additional integer array of O(n) space is required.
F. String Length Limitation
The array names[500][30] stores a maximum of 29 characters per name.
- 29-character names are accepted.
- 30-character names cannot be stored completely.
- Longer input must be rejected or handled using a larger array.
G. Duplicate Detection
After alphabetical sorting, duplicate names appear next to each other. Therefore, checking adjacent elements is sufficient to identify duplicates.
H. Pointer-Based Sorting
An alternative is to use an array of pointers and qsort().
- Sorting requires O(n log n) comparisons on average.
- Each comparison may examine up to L characters.
- Swapping pointers is cheaper than copying complete strings.
- Extra space is required for the pointer array.
