# Q2 – Sorting the Examination Hall Seating Register

**Marks:** 7  
**Bloom's Level:** K4 – Analyse

## 1. Aim

To implement Bubble Sort, Selection Sort and Insertion Sort in C, measure their comparisons and swaps or shifts, and compare their performance on different input arrangements.

## 2. Problem Statement

The examination cell maintains a seating register arranged according to student register numbers.

The input data may be:
- Already sorted
- Nearly sorted
- Reverse sorted
- Randomly arranged

The three sorting algorithms are implemented and tested for 100, 1,000 and 10,000 elements.

## 3. Theory

### A. Bubble Sort

Bubble Sort repeatedly compares adjacent elements and swaps them if they are in the wrong order.

An early-exit flag is used to stop the algorithm when no swaps occur during a complete pass.

**Time Complexity:**
- Best case: O(n)
- Average case: O(n²)
- Worst case: O(n²)

**Space Complexity:** O(1)

**Stability:** Stable.

### B. Selection Sort

Selection Sort repeatedly finds the smallest element in the unsorted portion and places it in the correct position.

**Time Complexity:**
- Best case: O(n²)
- Average case: O(n²)
- Worst case: O(n²)

**Space Complexity:** O(1)

**Stability:** Generally unstable.

### C. Insertion Sort

Insertion Sort takes one element at a time and inserts it into its correct position in the already sorted portion.

**Time Complexity:**
- Best case: O(n)
- Average case: O(n²)
- Worst case: O(n²)

**Space Complexity:** O(1)

**Stability:** Stable.

## 4. Algorithm Comparison

| Algorithm | Best Case | Average Case | Worst Case |
|---|---|---|---|
| Bubble Sort | O(n) | O(n²) | O(n²) |
| Selection Sort | O(n²) | O(n²) | O(n²) |
| Insertion Sort | O(n) | O(n²) | O(n²) |

## 5. Importance of Early-Exit Flag

The early-exit flag in Bubble Sort checks whether any swapping occurred during a pass.

If no swaps occur, the array is already sorted, and the algorithm terminates immediately.

This improves performance for already sorted data from O(n²) to O(n).

## 6. Why Is Insertion Sort Fast on Nearly Sorted Data?

Insertion Sort is efficient when only a few elements are out of order.

It moves only the elements that are greater than the current key instead of repeatedly processing the entire array.

Therefore, it performs fewer shifts when the input is nearly sorted.

## 7. Stability of Sorting Algorithms

- Bubble Sort is stable because it swaps only adjacent elements when the left element is strictly greater.
- Insertion Sort is stable because equal elements retain their original relative order.
- Selection Sort is generally unstable because exchanging the minimum element with another element can change the order of equal elements.

Stability is important when students have equal marks because their original order or secondary ranking information can be preserved.

## 8. Hand Tracing

Consider the following six register numbers:

**Initial Array:** 34, 12, 25, 10, 30, 18

### Bubble Sort

| Pass | Array |
|---|---|
| Initial | 34, 12, 25, 10, 30, 18 |
| 1 | 12, 25, 10, 30, 18, 34 |
| 2 | 12, 10, 25, 18, 30, 34 |
| 3 | 10, 12, 18, 25, 30, 34 |
| 4 | 10, 12, 18, 25, 30, 34 |

The fourth pass performs no swaps, so the algorithm stops.

### Selection Sort

| Pass | Array |
|---|---|
| Initial | 34, 12, 25, 10, 30, 18 |
| 1 | 10, 12, 25, 34, 30, 18 |
| 2 | 10, 12, 25, 34, 30, 18 |
| 3 | 10, 12, 18, 34, 30, 25 |
| 4 | 10, 12, 18, 25, 30, 34 |
| 5 | 10, 12, 18, 25, 30, 34 |

### Insertion Sort

| Pass | Array |
|---|---|
| Initial | 34, 12, 25, 10, 30, 18 |
| 1 | 12, 34, 25, 10, 30, 18 |
| 2 | 12, 25, 34, 10, 30, 18 |
| 3 | 10, 12, 25, 34, 30, 18 |
| 4 | 10, 12, 25, 30, 34, 18 |
| 5 | 10, 12, 18, 25, 30, 34 |

## 9. Joint Conclusion

For a seating register that is already sorted except for 20 late registrations, **Insertion Sort is recommended**.

It is efficient for nearly sorted data because it moves only the misplaced elements into their correct positions.

Bubble Sort with early exit is also suitable for nearly sorted data, but Insertion Sort generally performs fewer comparisons and movements for this situation.

## 10. Alternative Concept – Counting Sort

Counting Sort can be used when register numbers belong to a known, reasonably small integer range.

Instead of comparing elements, it counts the frequency of each value and reconstructs the sorted array.

**Time Complexity:** O(n + k)

**Space Complexity:** O(k)

Where:
- n = Number of elements
- k = Range of possible register numbers

Counting Sort is not suitable when the register-number range is extremely large compared with the number of students, because it requires a large counting array.

## 11. Result

Bubble Sort, Selection Sort and Insertion Sort were implemented successfully.

Their comparisons and swaps or shifts were measured for sorted, nearly sorted, reverse-sorted and random input arrays.

The experiment demonstrates that Insertion Sort performs efficiently on nearly sorted data, while Selection Sort performs a fixed number of comparisons regardless of input order.
