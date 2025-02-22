TreeNode* recoverFromPreorder(string traversal) {
        std::stack<TreeNode*> nodesStack;
        int currentDepth = 0;
        int currentValue = 0;

        for (int i = 0; i < traversal.length(); ++i) {
            if (traversal[i] == '-') {
                // Increment the depth for every '-' character encountered
                currentDepth++;
            } else {
                // Calculate the node's value
                currentValue = 10 * currentValue + (traversal[i] - '0');
            }

            // Check for end of number or end of string
            if (i + 1 == traversal.length() || (isdigit(traversal[i]) && traversal[i + 1] == '-')) {
                TreeNode* newNode = new TreeNode(currentValue);

                // If the stack size is greater than the current depth, pop until the sizes match
                while (nodesStack.size() > currentDepth) {
                    nodesStack.pop();
                }

                // If stack is not empty, assign the newNode to the appropriate child of the top node
                if (!nodesStack.empty()) {
                    if (nodesStack.top()->left == nullptr) {
                        nodesStack.top()->left = newNode;
                    } else {
                        nodesStack.top()->right = newNode;
                    }
                }

                // Push the new node onto the stack
                nodesStack.push(newNode);

                // Reset current depth and value for the next node
                currentDepth = 0;
                currentValue = 0;
            }
        }

        // The result is the root of the tree. It's the bottommost node in the stack.
        TreeNode* result = nullptr;
        while (!nodesStack.empty()) {
            result = nodesStack.top();
            nodesStack.pop();
        }

        // Return the recovered binary tree
        return result;
    }
