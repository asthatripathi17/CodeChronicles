vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(root == NULL){
        return {};
    }

    deque<TreeNode*> store;
    vector<vector<int>> output;
    store.push_back(root);

    bool flag = true; // R to L

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
        if(!flag)
            reverse(temp.begin(),temp.end());
        output.push_back(temp);
        flag = !flag;
    }

    return output;
}
