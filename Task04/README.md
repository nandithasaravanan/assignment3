
# Task 04 – Two-Dimensional Arrays: District Rainfall Records

## 1. Aim
To implement a two-dimensional array in C to store monthly rainfall records of 38 districts over 12 months and calculate annual rainfall, monthly averages, maximum rainfall and rainfall-deficient districts.

## 2. Concepts Used
- Two-dimensional arrays
- Nested for loops
- Array initialization and input
- Functions
- Conditional statements
- Row-major memory organization
- Basic performance measurement

## 3. Algorithm

1. Declare a two-dimensional array rain[38][12].
2. Initialize the rainfall values or read them from the user.
3. Calculate the annual rainfall total for every district.
4. Calculate the average rainfall for each month across all districts.
5. Find the maximum rainfall value and its district and month.
6. Calculate the state's average annual rainfall per district.
7. Identify districts receiving less than 60% of the state average.
8. Measure row-wise and column-wise traversal time.
9. Display all calculated results.

## 4. Memory Representation

C stores two-dimensional arrays in row-major order.

The elements of each row are stored continuously in memory before the next row.

Address formula:

Address of rain[i][j] = Base address + ((i × 12) + j) × sizeof(int)

Row-wise traversal is generally faster because consecutive elements are stored next to each other in memory.

## 5. Hand Calculation Verification

Consider the following 3 × 4 rainfall array:

10  20  30  40
20  30  40  50
5   10  15  20

Annual totals:
District 1 = 100 mm
District 2 = 140 mm
District 3 = 50 mm

Monthly averages:
Month 1 = 11.67 mm
Month 2 = 20 mm
Month 3 = 28.33 mm
Month 4 = 36.67 mm

Maximum rainfall = 50 mm
State average annual rainfall per district = 96.67 mm
60% of state average = 58 mm

Deficient district = District 3

## 6. Complexity Analysis

| Operation | Time Complexity |
|---|---|
| Annual rainfall calculation | O(38 × 12) |
| Monthly average calculation | O(38 × 12) |
| Maximum rainfall calculation | O(38 × 12) |
| Deficient district identification | O(38) |
| Overall calculations | O(38 × 12) |

Space Complexity: O(38 × 12) for the rainfall array.

## 7. Alternative Concepts

A one-dimensional array can store the same data using index = i × 12 + j.

An array of 38 pointers can also store separately allocated rows.

All three approaches provide O(1) element access. However, a normal two-dimensional array provides continuous memory storage and better cache locality.

The pointer-based approach requires additional memory for pointers and may have less predictable memory locality.

## 8. Conclusion

The program successfully demonstrates the use of two-dimensional arrays for rainfall analysis. It calculates district totals, monthly averages, maximum rainfall and deficient districts. Row-wise traversal generally provides better performance because of C's row-major memory organization.
