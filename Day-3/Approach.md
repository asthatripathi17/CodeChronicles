## Code Explanation

The provided code offers two distinct approaches for solving the "Sort Colors" problem on  [LeetCode Problem 75](https://leetcode.com/problems/sort-colors/), these approaches are designed to sort an array containing three colors: red (0), white (1), and blue (2).

### Approach 1: Three Pointer Approach (In-Place Algorithm)

#### Function Reference

- **Function Name:** `sortColors`
- **Usage:** This function sorts an input array `nums` in-place.

#### Explanation

The three-pointer approach employs a three-pointer technique: `l`, `m`, and `h`. These pointers work together to partition and sort the array efficiently. The algorithm iterates through the array, examining each element at index `m`. Based on the color indicated by `nums[m]`, the pointers `l`, `m`, and `h` are adjusted as follows:

- If `nums[m]` is 0 (red), it is swapped with the element at `nums[l]`, and both `m` and `l` are incremented. This operation moves all red elements to the beginning of the array.
- If `nums[m]` is 1 (white), `m` is simply incremented, leaving white elements in the middle.
- If `nums[m]` is 2 (blue), it is swapped with the element at `nums[h]`, and `h` is decremented. This operation moves all blue elements to the end of the array.

This process continues until `m` is no longer less than or equal to `h`, effectively partitioning the array into three regions: all reds on the left, all whites in the middle, and all blues on the right. The array is then sorted in-place according to the requirements of the problem.

### Approach 2: Counting Approach

#### Function Reference

- **Function Name:** `sortColors`
- **Usage:** This function sorts an input array `nums` using counting and reinsertion.

#### Explanation

The counting approach provides a straightforward way to solve the "Sort Colors" problem. It starts by counting the occurrences of each color (0, 1, and 2) in the input array `nums`. It uses three counters: `z` for red (0), `o` for white (1), and `t` for blue (2). The algorithm then reinserts the colors in a sorted order based on the counts:

- It first reinserts red (0) `z` times at the beginning of the array.
- It then reinserts white (1) `o` times.
- Finally, it reinserts blue (2) `t` times.

While this counting-based approach provides a simple way to sort the array, it does not perform an in-place sort. It requires additional space for counting and reinsertion.
