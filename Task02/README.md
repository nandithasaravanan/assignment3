# Q2 – Sorting the Examination Hall Seating Register

## 1. Problem Understanding

The examination cell maintains a seating register arranged in ascending order of student register numbers.

The input data may be:

- Already sorted.
- Nearly sorted with a few late registrations.
- Reverse sorted.
- Randomly arranged.

Three sorting algorithms are implemented and compared:

1. Bubble Sort
2. Selection Sort
3. Insertion Sort

The number of comparisons and swaps or shifts is counted to evaluate their performance.

## 2. Bubble Sort

Bubble sort compares adjacent elements and swaps them if they are in the wrong order.

An early-exit flag is used to detect whether any swapping occurred during a pass.

If no swapping occurs, the array is already sorted and the algorithm stops.

### Pseudocode

```text
START

FOR i = 0 to n-2

    Set swapped = false

    FOR j = 0 to n-i-2

        Increase comparisons

        IF a[j] > a[j+1]
            Swap elements
            Increase swaps
            Set swapped = true

    IF swapped = false
        BREAK

STOP
```

### Purpose of Early-Exit Flag

The early-exit flag avoids unnecessary passes when the array is already sorted.

Without this flag, bubble sort continues checking all remaining passes even when the data is sorted.

## 3. Selection Sort

Selection sort finds the smallest element from the unsorted portion and places it at the beginning.

### Pseudocode

```text
START

FOR i = 0 to n-2

    Set min = i

    FOR j = i+1 to n-1

        Increase comparisons

        IF a[j] < a[min]
            min = j

    IF min != i
        Swap a[i] and a[min]
        Increase swaps

STOP
```

Selection sort always performs n(n-1)/2 comparisons, regardless of the input arrangement.

## 4. Insertion Sort

Insertion sort builds a sorted portion of the array by inserting each new element into its correct position.

### Pseudocode

```text
START

FOR i = 1 to n-1

    Set key = a[i]
    Set j = i-1

    WHILE j >= 0 AND a[j] > key

        Shift a[j] to a[j+1]
        Increase shifts
        Decrease j

    Insert key at a[j+1]

STOP
```

### Why Is Insertion Sort Fast on Nearly Sorted Data?

Insertion sort performs very few shifts when elements are already close to their correct positions.

Therefore, it is efficient for nearly sorted arrays and small amounts of late-arriving data.

## 5. Hand Tracing of Algorithms

Consider the following six register numbers:

`34, 12, 25, 12, 40, 18`

### Bubble Sort

Initial: 34, 12, 25, 12, 40, 18

- Pass 1: 12, 25, 12, 34, 18, 40
- Pass 2: 12, 12, 25, 18, 34, 40
- Pass 3: 12, 12, 18, 25, 34, 40

Final sorted array:

`12, 12, 18, 25, 34, 40`

### Selection Sort

Initial: 34, 12, 25, 12, 40, 18

- Pass 1: 12, 34, 25, 12, 40, 18
- Pass 2: 12, 12, 25, 34, 40, 18
- Pass 3: 12, 12, 18, 34, 40, 25
- Pass 4: 12, 12, 18, 25, 40, 34
- Pass 5: 12, 12, 18, 25, 34, 40

### Insertion Sort

Initial: 34, 12, 25, 12, 40, 18

- Insert 12: 12, 34, 25, 12, 40, 18
- Insert 25: 12, 25, 34, 12, 40, 18
- Insert 12: 12, 12, 25, 34, 40, 18
- Insert 40: 12, 12, 25, 34, 40, 18
- Insert 18: 12, 12, 18, 25, 34, 40

Final sorted array:

`12, 12, 18, 25, 34, 40`

## 6. Stability of Sorting Algorithms

A stable sorting algorithm preserves the original relative order of elements having equal keys.

| Algorithm | Stability |
|---|---|
| Bubble Sort | Stable |
| Selection Sort | Not stable in general |
| Insertion Sort | Stable |

Stability matters when two students have equal marks or equal sorting keys because their original relative order can be preserved.

Bubble sort and insertion sort are stable when they swap or shift only strictly greater elements.

Selection sort may change the relative order of equal elements during swapping.

## 7. Experimental Investigation

The algorithms are tested using four types of input:

1. Sorted array.
2. Nearly sorted array with the final 20 elements reversed.
3. Reverse-sorted array.
4. Random array generated using a fixed seed.

The experiment uses:

- n = 100
- n = 1,000
- n = 10,000

For each experiment, the following are recorded:

- Number of comparisons.
- Number of swaps for bubble and selection sort.
- Number of shifts for insertion sort.

The same original input is copied before each sorting algorithm is executed to ensure a fair comparison.

## 8. Comparative Analysis

### Time Complexity

| Algorithm | Best Case | Average Case | Worst Case |
|---|---|---|---|
| Bubble Sort with early exit | O(n) | O(n²) | O(n²) |
| Selection Sort | O(n²) | O(n²) | O(n²) |
| Insertion Sort | O(n) | O(n²) | O(n²) |

### Best Algorithm for Each Input

| Input Type | Recommended Algorithm | Reason |
|---|---|---|
| Sorted | Bubble or Insertion | Both require O(n) comparisons |
| Nearly sorted | Insertion | Very few shifts are required |
| Reverse sorted | No strong advantage among the three | All have O(n²) time |
| Random | Depends on measurements | All have O(n²) time |

## 9. Joint Conclusion – 20 Late Registrations

Insertion sort is recommended when the seating register is already sorted except for 20 late registrations.

The original sorted portion does not require major rearrangement.

Only the late registrations need to be inserted into their correct positions.

Insertion sort performs relatively few shifts compared with bubble sort and selection sort.

Therefore, insertion sort is the most suitable choice for this situation.

## 10. Alternative Concept – Counting Sort

If register numbers belong to a known and limited range, counting sort can be used instead of comparison-based sorting.

### Working Principle

1. Create a counting array for the possible register numbers.
2. Count how many times each number occurs.
3. Reconstruct the sorted array using the recorded frequencies.

### Complexity Analysis

| Algorithm | Time Complexity | Extra Space |
|---|---|---|
| Bubble Sort | O(n²) | O(1) |
| Selection Sort | O(n²) | O(1) |
| Insertion Sort | O(n²) | O(1) |
| Counting Sort | O(n+k) | O(k) |

Here, n represents the number of students and k represents the range of possible register numbers.

Counting sort is unsuitable when the register-number range is extremely large compared with the number of students or when keys are not suitable discrete integers.

## 11. Conclusion

Bubble sort, selection sort and insertion sort were implemented and compared using different input arrangements.

The experiment shows that insertion sort performs efficiently on nearly sorted data, bubble sort benefits from its early-exit flag on sorted data, and selection sort performs a fixed number of comparisons regardless of input order.

For a seating register containing only 20 late registrations, insertion sort is recommended because it requires fewer shifts and efficiently maintains the sorted order.
