# Q3 – Merging Two Merit Lists

**Marks:** 7  
**Bloom's Level:** K4 – Analyse

## 1. Aim

To implement a merging algorithm in C that combines two merit lists sorted in descending order into a single descending-order list without performing another sorting operation.

## 2. Problem Statement

Two campuses independently prepare merit lists arranged in descending order of entrance scores.

The admissions office must combine both lists into one descending-order merit list.

The program must:
- Merge two sorted arrays into a third array.
- Handle arrays of different lengths.
- Handle equal scores.
- Handle an empty array.
- Verify that the final merged array is sorted.

## 3. Theory

### Merge Algorithm

The merge algorithm uses two pointers to compare elements from the two sorted arrays.

The larger score is copied into the output array.

**Algorithm:**
1. Initialize i = 0, j = 0 and k = 0.
2. Compare a[i] and b[j].
3. Copy the larger score into out[k].
4. Increment the pointer of the array from which the element was copied.
5. Continue until one array becomes empty.
6. Copy the remaining elements of the other array.
7. Return the total number of elements merged.

### 4. Pseudocode

```text
START

i = 0, j = 0, k = 0

WHILE i < m AND j < n
    IF A[i] >= B[j]
        OUT[k] = A[i]
        i = i + 1
    ELSE
        OUT[k] = B[j]
        j = j + 1
    END IF
    k = k + 1
END WHILE

WHILE i < m
    OUT[k] = A[i]
    i = i + 1
    k = k + 1
END WHILE

WHILE j < n
    OUT[k] = B[j]
    j = j + 1
    k = k + 1
END WHILE

RETURN k

STOP
```

## 5. Mathematical Analysis

Let:
- m = Number of elements in the first array.
- n = Number of elements in the second array.

The total number of elements in the merged array is:

**m + n**

Each element is copied exactly once.

The maximum number of comparisons is:

**m + n - 1**

This happens when elements from both arrays are interleaved until one array becomes empty.

### Time Complexity

- Best case: O(min(m,n)) comparisons.
- Worst case: O(m+n) comparisons.
- Overall merging time: O(m+n).

### Space Complexity

The algorithm uses a third array to store the merged result.

Extra space required: **O(m+n)**.

## 6. Why Is Each Element Compared at Most Once?

Each comparison removes one element from the front of one of the two arrays.

The corresponding pointer is incremented, so that element is never compared again.

Therefore, every element participates in at most one comparison.

## 7. Handling Remaining Elements

When one array becomes empty, the remaining elements of the other array are already sorted.

They can be copied directly into the output array without further comparisons.

## 8. Handling Equal Scores

The program uses:

`if (a[i] >= b[j])`

When both scores are equal, the element from Campus A is copied first.

This preserves the original order within each campus and establishes a clear tie-breaking rule between campuses.

## 9. Experimental Comparison

The merge algorithm is compared with joining both arrays and sorting the combined array using qsort().

For equal-sized arrays:

| Elements per array | Total elements | Maximum merge comparisons |
|---:|---:|---:|
| 1,000 | 2,000 | 1,999 |
| 10,000 | 20,000 | 19,999 |

### Complexity Comparison

| Method | Time Complexity | Extra Space |
|---|---|---|
| Merge using third array | O(m+n) | O(m+n) |
| Join and use qsort() | Typically O((m+n) log(m+n)) | O(m+n) for combined array |
| Simple in-place merge | O(m×n) worst case | O(1) auxiliary space |

The exact number of qsort() comparisons depends on the compiler's library implementation and input arrangement.

## 10. Joint Engineering Decision

An in-place merge may be preferred when memory is limited and the first array has enough unused capacity to accommodate the second array.

However, it requires moving existing elements to make space, which can increase the execution time.

Using a third array is simpler and more efficient when sufficient memory is available.

## 11. Result

Two descending-order merit lists were successfully merged into one descending-order list without sorting again.

The algorithm correctly handles different array lengths, equal scores and empty arrays.

The experiment demonstrates that merging two sorted arrays takes O(m+n) time and is more efficient than combining and sorting the arrays again for large datasets.
