# Code Explanation

The following C++ code defines a solution for [LeetCode Problem 28](https://leetcode.com/problems/implement-strstr/), which involves finding the index of the first occurrence of a substring (needle) within a given string (haystack). The solution uses a simple linear search approach.

## Approach
- Linear Search: The code implements a simple linear search through the given string haystack. It iterates through each possible starting index for the substring needle in haystack.
- Substring Checking: For each starting index, it checks if the substring starting from that index matches the target substring needle.
- Return Index: If a match is found, the function returns the index of the first occurrence; otherwise, it returns -1.
## Complexity
- Time Complexity: O((len_hay - len_needl + 1) * len_needl), where len_hay is the length of the haystack and len_needl is the length of the needle. The code checks each possible starting index and compares substrings.
- Space Complexity: O(1), as the code uses a constant amount of additional space.

This solution employs a straightforward approach to find the index of the first occurrence of the target substring within the given string.
