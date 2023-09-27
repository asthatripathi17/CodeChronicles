## Code Explanation

The provided code offers an approach for solving the "Find the Middle Index in Array" problem on  [LeetCode Problem 1991](https://leetcode.com/problems/find-the-middle-index-in-array/). The approach explains an algorithm to find the middle index in an integer array `nums`. The middle index is defined as the index `p` where `0 <= p < nums.length` and `nums[0] + nums[1] + ... + nums[p-1] == nums[p+1] + nums[p+2] + ... + nums[nums.length-1]`.

### Approach

The algorithm employs a straightforward approach to find the middle index efficiently:

1. **Calculate Total Sum:** Calculate the total sum of all elements in the array, denoted as `tot_sum`, using the `accumulate` function. This step has a time complexity of O(n), where n is the number of elements in the array.

2. **Initialize Variables:** Initialize the following variables:
   - `p`: To track the current index, initially set to 0.
   - `lsum`: To represent the sum of elements to the left of index `p`, initially set to 0.
   - `rsum`: To represent the sum of elements to the right of index `p`, initially set to `tot_sum - lsum - nums[p]`.

3. **Iterate Through the Array:** Enter a `while` loop that continues as long as `p` is less than the size of the `nums` array.

4. **Check and Update Sums:** Inside the loop, check if `lsum` is not equal to `rsum`. If they are not equal:
   - Increment `lsum` by adding `nums[p]`.
   - Increment `p`.
   - Check if `p` has reached the end of the array. If so, return -1, as no middle index is found.
   - Otherwise, update `rsum` by subtracting `nums[p]`.

5. **Middle Index Found:** If `lsum` becomes equal to `rsum`, it indicates that the current index `p` is the middle index, so return `p`.

6. **No Middle Index Found:** After the loop, if no middle index is found, return -1.

## Complexity Analysis

- **Time Complexity:** O(n), where n is the number of elements in the input array `nums`. The algorithm performs a single pass through the array to calculate the total sum and find the middle index.
- **Space Complexity:** O(1), as the algorithm uses a constant amount of extra space for variables `p`, `lsum`, and `rsum`.

