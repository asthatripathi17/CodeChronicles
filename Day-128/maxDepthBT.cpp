// Recursive DFS
int maxDepth(TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    return 1+max(maxDepth(root->left),maxDepth(root->right));
}

// Iterative BFS
int maxDepth(TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    int level = 0;
    deque<TreeNode*> qStore;
    qStore.push_back(root); // Push the root node to the queue
    
    while (!qStore.empty()) {
        int size = qStore.size(); // Get the size of the current level
        for(int i = 0; i < size; i++){
            TreeNode *node = qStore.front();
            qStore.pop_front();
            if(node->left != NULL){
                qStore.push_back(node->left);
            }
            if(node->right != NULL){
                qStore.push_back(node->right);
            }
        } 
        level++;
    }
    return level;
}
