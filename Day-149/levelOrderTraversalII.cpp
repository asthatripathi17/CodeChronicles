vector<vector<int>> levelOrderBottom(TreeNode* root) {
    
    if(root == NULL){
        return {};
    }
    vector<vector<int>> result;
    deque<TreeNode*> store;
    store.push_front(root);

    while(!store.empty()){
        int size = store.size();
        vector<int> temp;
        for(int i = 0; i<size; i++){
            TreeNode *node = store.front();
            temp.push_back(node->val);
            store.pop_front();
            if(node->left!=NULL){
                store.push_back(node->left);
            }
            if(node->right!=NULL){
                store.push_back(node->right);
            } 
        }
        result.insert(result.begin(),temp);
    }

    return result;
}
