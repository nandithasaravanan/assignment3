# Q1 – Searching a Library Catalogue

**Marks:** 6  
**Bloom's Level:** K3 – Apply

## 1. Aim

To implement Linear Search and Binary Search in C, count the number of comparisons performed by each algorithm, and analyse their efficiency for different catalogue sizes.

## 2. Problem Statement

A college library stores accession numbers of books in an array. Students search for books using their accession numbers.

The catalogue initially contains 10 books and may expand to 100,000 books.

The following searching algorithms are implemented:

- Linear Search on an unsorted array.
- Binary Search on a sorted array.

## 3. Theory

### A. Linear Search

Linear Search checks each element sequentially until the required element is found or the array ends.

**Algorithm:**
1. Start from the first element.
2. Compare the current element with the search key.
3. If both are equal, return its index.
4. Otherwise, move to the next element.
5. If the element is not found, return -1.

**Time Complexity:**
- Best case: O(1)
- Average case: O(n)
- Worst case: O(n)

**Space Complexity:** O(1)

### B. Binary Search

Binary Search repeatedly divides a sorted array into two halves.

**Algorithm:**
1. Set low = 0 and high = n - 1.
2. Calculate mid = low + (high - low) / 2.
3. Compare a[mid] with the search key.
4. If equal, return the index.
5. If the key is smaller, search the left half.
6. Otherwise, search the right half.
7. Continue until the key is found or low exceeds high.

**Time Complexity:**
- Best case: O(1)
- Average case: O(log n)
- Worst case: O(log n)

**Space Complexity:** O(1)

### 4. Mathematical Analysis

| Case | Linear Search | Binary Search |
|---|---|---|
| Best | 1 comparison | 1 comparison |
| Average | (n+1)/2 for successful search | O(log n) |
| Worst | n comparisons | O(log n) |

For unsuccessful Linear Search, all n elements must be checked.

For Binary Search, the search interval is halved after every comparison.

### 5. Why Does Binary Search Require Sorted Data?

Binary Search needs sorted data because it decides which half can be discarded based on the middle element.

If the array is unsorted, this decision is not reliable and the required element may be skipped.

### 6. Why Is This Formula Preferred?

`mid = low + (high - low) / 2`

This formula is preferred over `(low + high) / 2` because adding low and high directly can cause integer overflow when their values are very large.

### 7. Prediction for 100,000 Books

**Linear Search:**
- Best case: 1 comparison.
- Average successful search: approximately 50,000 comparisons.
- Worst case: 100,000 comparisons.

**Binary Search:**
- Best case: 1 comparison.
- Worst case: approximately 17 comparisons.

Therefore, Binary Search is significantly more efficient for a large sorted catalogue.

### 8. Experimental Investigation

The program tests catalogue sizes of:

- 1,000 books
- 10,000 books
- 100,000 books

Successful and unsuccessful searches are performed, and the number of comparisons is recorded.

Linear Search is tested on an unsorted array, while Binary Search is tested on a sorted array.

### 9. Missing Book Analysis

When a book is missing, Linear Search checks every element before reporting that the book does not exist.

Binary Search repeatedly reduces the search interval until it becomes empty.

Therefore, an unsuccessful Binary Search requires logarithmic comparisons, whereas an unsuccessful Linear Search requires n comparisons.

### 10. Joint Design Question

If new books are added every day, maintaining a sorted array requires additional work during insertion.

Binary Search is suitable when searches are frequent and insertions are relatively uncommon.

To decide whether sorting is worthwhile, we must consider:

- Number of searches per day.
- Number of books added daily.
- Cost of inserting books into a sorted array.
- Frequency of catalogue updates.
- Whether the data can be sorted in batches.

If searches are frequent, maintaining sorted data is beneficial. If insertions are frequent, another data structure such as a balanced search tree may be more suitable.

### 11. Alternative Concepts

**Hash Table:**
- Average search time: O(1).
- Worst-case search time: O(n).
- Extra space: O(n).
- Linear probing is used to handle collisions.

**Interpolation Search:**
- Average time for uniformly distributed sorted data: O(log log n).
- Worst case: O(n).
- Extra space: O(1).

### 12. Result

Linear Search and Binary Search were implemented successfully. The comparison counts demonstrate that Binary Search performs significantly fewer comparisons for large sorted catalogues. Therefore, Binary Search is preferred when the catalogue is maintained in sorted order and frequent searching is required.
