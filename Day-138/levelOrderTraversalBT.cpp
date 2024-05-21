// Using Queue(BFS) to level wise traversal
vector<vector<int>> levelOrder(TreeNode* root) {
    
    if(root == NULL){
        return {};
    }
    vector<vector<int>> output;
    deque<TreeNode*> store;
    store.push_back(root);

    while(!store.empty()){
        int size = store.size();
        // For each level
        vector<int> temp;
        for(int i = 0; i<size ; i++){
            TreeNode *node = store.front();
            temp.push_back(node->val);
            store.pop_front();
            if(node->left != NULL){
                store.push_back(node->left);
            }
            if(node->right != NULL){
                store.push_back(node->right);
            }
        }
        output.push_back(temp);
    }

    return output;
}
