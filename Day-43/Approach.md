# Code Explanation

The provided C++ code addresses the problem of compressing a vector of characters in [LeetCode Problem 443 - String Compression](https://leetcode.com/problems/string-compression/). The function encodes and returns the run-length encoded string for the given string. _**Run-length encoding** is a form of lossless data compression in which runs of data are stored as a single data value and count, rather than as the original run._

Two different approaches are presented to achieve the desired compression, and potential optimizations are discussed -

## Approach 1: Vector Copy and Modification

### Explanation
The first approach involves creating a separate vector vec, copying the input vector chars into it, and then processing vec to achieve compression. This approach uses a pair to keep track of the current character and its count. The processed characters are then added to the original vector chars.

### Pros
- Clarity: The code structure is straightforward and easy to understand.
- Separation of Concerns: The original vector chars is not modified directly, and a separate vector vec is used for processing.

### Cons
- Additional Space: The use of an additional vector vec increases space complexity.

### Complexity
- **Time Complexity**: O(N), where N is the number of elements in the input vector chars.
- **Space Complexity**: O(N), due to the creation of the additional vector vec.


## Approach 2: In-Place Modification

### Explanation
The second approach focuses on in-place modification of the original vector chars. It uses a pair to track the current character and its count, and iterates through the vector to compress consecutive characters. The compression results are written back to the original vector without the need for an additional vector.

### Pros
- In-Place Modification: The original vector is modified directly, reducing space complexity.
- No Additional Space: The algorithm avoids using extra vectors, minimizing memory usage.

### Cons
- Erase/Insert Operations: he use of erase and insert operations within a loop might lead to less efficient code due to repeated resizing of the vector. These operations have a time complexity of O(N), where N is the number of elements in the vector.

### Complexity
- **Time Complexity**: O(N), where N is the number of elements in the input vector chars.
- **Space Complexity**: O(1), as the algorithm modifies the original vector in-place without using additional space.


## Further Optimization: Avoiding Erase/Insert Operations
To further optimize the in-place approach, consider using a separate index (_write_index_) to keep track of the position where compressed characters should be written. This eliminates the need for repeated erase and insert operations, improving efficiency.
### Explanation
By using a separate index, the code avoids the inefficiency introduced by frequent resizing of the vector during the compression process. This optimization enhances the overall performance of the in-place approach.
### Complexity
- **Time Complexity**: O(N), where N is the number of elements in the input vector chars.
- **Space Complexity**: O(1), as the algorithm modifies the original vector in-place without using additional space.

