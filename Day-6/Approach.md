## Code Explanation

The provided code offers two approaches for solving the "K-diff Pairs in an Array" problem on [LeetCode Problem 532](https://leetcode.com/problems/k-diff-pairs-in-an-array/). The problem requires finding and counting **unique pairs (i, j)** in the given integer array nums with a specific absolute difference, k.

### Approach 1

- This approach uses a two-pointer technique along with sorting to efficiently find k-diff pairs.
- Sorting the array allows us to easily identify pairs with a difference of k.
- By maintaining two pointers i and j, we can iterate through the array to identify pairs that meet the criteria:
- i and j are distinct indices (i != j).
- The absolute difference between nums[i] and nums[j] is k.
- Using a set (pair) ensures that we count unique pairs only, as sets do not allow duplicates.
- The code then returns the size of the set, which represents the count of unique k-diff pairs.

## Complexity Analysis

- Time complexity: O(n * log(n)) due to the sorting step.
- Space complexity: O(n) for the pair set.

### Approach 2

- This approach uses binary search to efficiently find k-diff pairs in a sorted array.
- It also starts by sorting the input array nums.
- The code iterates through the sorted array and, for each element nums[i], searches for an element nums[i] + k using binary search.
- If such an element is found, it means we have a valid k-diff pair, and it is added to the set pair.
- As in Approach 1, the use of a set ensures that only unique pairs are counted.
- Finally, the code returns the size of the set, representing the count of unique k-diff pairs.

## Complexity Analysis

- Time complexity: O(n * log(n)) for sorting and O(n * log(n)) for binary search within the loop.
- Space complexity: O(n) for the pair set.
