# Q1 – Searching a Library Catalogue

## 1. Problem Understanding

A college central library stores book accession numbers in an array.

Students search for books using their accession numbers.

Two searching techniques are implemented:

1. Linear Search – Searches each element sequentially in an unsorted array.
2. Binary Search – Searches by repeatedly dividing a sorted array into two halves.

The trial catalogue contains 10 books, while the fully loaded catalogue may contain 100,000 books.

The number of comparisons performed by each method is counted to compare their efficiency.

## 2. Linear Search

Linear search checks each element one by one until the required accession number is found or the array ends.

### Pseudocode

```text
START

Set steps = 0

FOR i = 0 to n-1
    Increase steps by 1

    IF array[i] equals key
        RETURN i

RETURN -1

STOP
```

Linear search works on both sorted and unsorted arrays.

## 3. Binary Search

Binary search works only on sorted data.

It compares the search key with the middle element and eliminates half of the remaining search range after each comparison.

### Pseudocode

```text
START

Set low = 0
Set high = n-1
Set steps = 0

WHILE low <= high

    mid = low + (high-low)/2

    Increase steps by 1

    IF array[mid] equals key
        RETURN mid

    ELSE IF key is greater than array[mid]
        low = mid + 1

    ELSE
        high = mid - 1

RETURN -1

STOP
```

## 4. Mathematical Analysis

### Linear Search

Best Case:

The required book is at the beginning of the array.

Comparisons = 1

Time Complexity = O(1)

Worst Case:

The required book is at the end or is missing.

Comparisons = n

Time Complexity = O(n)

Average Case:

For a successful search, assuming every position is equally likely:

Average comparisons = (n+1)/2

Time Complexity = O(n)

### Binary Search

Best Case:

The required book is at the middle.

Comparisons = 1

Time Complexity = O(1)

Worst Case:

The search continues until the range becomes empty or the key is found at the last possible level.

Maximum comparisons = ceil(log2(n+1))

Time Complexity = O(log n)

Average Case:

The number of comparisons grows logarithmically with the array size.

Time Complexity = O(log n)

## 5. Why Binary Search Requires Sorted Data

Binary search compares the search key with the middle element.

If the key is smaller, it searches the left half. If the key is greater, it searches the right half.

This decision is possible only when the array is sorted.

For unsorted data, eliminating half of the array may remove the required book.

Therefore, binary search requires ascending or descending sorted data.

## 6. Why mid = low + (high-low)/2 Is Preferred

The expression:

`mid = (low + high) / 2`

may cause integer overflow when low and high are very large.

The safer expression is:

`mid = low + (high - low) / 2`

It calculates the middle index without adding the two large index values directly.

## 7. Prediction for 100,000 Books

For a catalogue containing 100,000 books:

| Searching Method | Maximum Comparisons |
|---|---:|
| Linear Search | 100,000 |
| Binary Search | 17 |

Binary search requires at most 17 midpoint checks because:

ceil(log2(100001)) = 17.

This demonstrates that binary search is much more efficient for large sorted catalogues.

## 8. Experimental Investigation

Arrays are generated with 1,000, 10,000 and 100,000 accession numbers.

The linear search uses an unsorted array, while binary search uses the corresponding sorted array.

The following searches are tested:

- Beginning: First element of the unsorted array.
- Middle: Middle element of the unsorted array.
- End: Last element of the unsorted array.
- Missing: A key that does not exist in the catalogue.

The number of comparisons is recorded for successful and unsuccessful searches.

## 9. Missing Book Search

A missing book requires the search algorithm to establish that no matching accession number exists.

In linear search, every element must be checked.

Therefore, the number of comparisons is n.

In binary search, the search range is repeatedly reduced by half until it becomes empty.

The missing search requires approximately the same number of comparisons as the worst successful search, although the exact count depends on the array size and search path.

## 10. Joint Design Question – Daily Book Additions

If new books are added every day, maintaining a sorted array may require additional work.

When a new book is inserted, elements may need to be shifted to preserve sorted order.

The decision depends on:

- Number of daily book additions.
- Number of daily searches.
- Frequency of catalogue updates.
- Cost of sorting and maintaining the array.
- Required search speed.

If searches are frequent and additions are relatively few, maintaining a sorted array for binary search is beneficial.

If additions are frequent and searches are less frequent, linear search or a different data structure may be preferable.

## 11. Alternative Concepts – Hash Table and Interpolation Search

### Hash Table

A hash table calculates an index from the accession number.

Average search complexity = O(1).

However, collisions may occur when multiple accession numbers map to the same index.

With linear probing, additional positions are checked until the key is found or an empty position is reached.

Extra space = O(n).

### Interpolation Search

Interpolation search estimates the likely position of the search key based on its value.

Average complexity = O(log log n) for approximately uniformly distributed sorted data.

Worst-case complexity = O(n).

It is suitable when accession numbers are sorted and relatively uniformly distributed.

Extra space = O(1) for the iterative implementation.

## 12. Conclusion

Linear search is simple and works with unsorted data, but its number of comparisons increases linearly with the catalogue size.

Binary search requires sorted data but reduces the search range by half after every comparison.

For a catalogue containing 100,000 books, binary search requires at most 17 midpoint checks, while linear search may require 100,000 comparisons.

Therefore, binary search is more suitable for a large, frequently searched catalogue when the cost of maintaining sorted data is acceptable.
