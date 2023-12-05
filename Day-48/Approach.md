# Code Explanation

The following C++ code defines a solution for [LeetCode Problem 394](https://leetcode.com/problems/decode-string/), which involves decoding a given string containing encoded information about repeated substrings. The solution utilizes a stack to perform the decoding process.
The code defines a `Solution` class with a `decodeString` function that decodes an encoded string and returns the decoded result.

## Approach

- **Stack Usage:** The code utilizes a stack (`st`) to process characters during decoding.
- **Iterative Decoding:** It iterates through each character in the input string `s`.
- **Handling '[' and ']':**
  - If the stack is empty, characters are directly pushed onto the stack.
  - When encountering ']', it signals the end of a repeated substring.
- **Extracting Substring and Repetition Count:**
   - **Type 1 Nested Brackets (Russian Dolls):**
      - The code extracts the substring and repetition count (k) from the stack.
      - It repeats the substring k times and pushes the result back onto the stack.
    - **Type 2 Nested Brackets (Inside one --> multiple side by side brackets):**
      - If '[' is encountered before ']', it represents sequential nesting.
      - The code extracts the innermost substring and repetition count (k).
      - It repeats the substring k times, and the result is used for further processing.
- **Building the Decoded String:**
  - Characters remaining in the stack after iteration are used to build the final decoded string.

## Complexity

- **Time Complexity:** O(N), where N is the length of the input string `s`.
  - The code processes each character once.
- **Space Complexity:** O(N), as the stack stores characters proportional to the input size.

In simpler terms, the code uses a clever strategy with a stack to unwind the encoded string, repeating substrings as needed, and reconstructs the decoded result.

## Future Approaches

- **Recursive Solution:**
  - A potential future approach could involve using recursion to handle nested brackets.
  - The function could be designed to call itself when encountering nested brackets, simplifying the overall structure.


