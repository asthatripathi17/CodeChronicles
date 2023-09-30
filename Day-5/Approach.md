## Code Explanation

The provided code offers an approach for solving the "Check if N and its Double Exist" problem on [LeetCode Problem 1346](https://leetcode.com/problems/check-if-n-and-its-double-exist/). The problem requires checking whether there exist two distinct indices `i` and `j` in the given integer array `arr` such that `arr[i] == 2 * arr[j]`.

### Approach

1. Sort the given array `arr` in ascending order using `sort(arr.begin(), arr.end())`.

2. Iterate through the sorted array using a loop with index `i`. For each element `arr[i]`:
   - Initialize two pointers, `s` and `e`, to the beginning and end of the array, respectively. These pointers will help us search for a pair.
   
   - Enter a while loop as long as `s` is less than or equal to `e`. This loop performs a binary search within the subarray defined by `s` and `e`.

   - Inside the while loop, calculate the middle index `mid` as `s + (e - s) / 2`.

   - Depending on the sign of `arr[i]`, perform one of the following checks:
     - If `arr[i]` is negative:
       - Check if `arr[i]` is equal to `arr[mid] * 2`. If they are equal, return `true` (we found a pair).
       - If `arr[i]` is less than `arr[mid] * 2`, update `e` to `mid - 1`.
       - If `arr[i]` is greater than `arr[mid] * 2`, update `s` to `mid + 1`.
     - If `arr[i]` is non-negative:
       - Check if `arr[mid]` is equal to `arr[i] * 2`. If they are equal, return `true` (we found a pair).
       - If `arr[mid]` is less than `arr[i] * 2`, update `s` to `mid + 1`.
       - If `arr[mid]` is greater than `arr[i] * 2`, update `e` to `mid - 1`.

3. If no pairs are found after iterating through the entire array, return `false`.

## Complexity Analysis

- Time complexity: **O(n log n)**, where n is the number of elements in the input array `arr`. This complexity arises due to the sorting step.
- Space complexity: O(1), as we use a constant amount of extra space for variables.
