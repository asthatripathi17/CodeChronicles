vector<int> rightSideView(TreeNode* root) {
    if(root == NULL){
        return {};
    }
    vector<int> rightNode;
    
    deque<TreeNode*> qStore;
    qStore.push_back(root);

    while(!qStore.empty()){

        rightNode.push_back(qStore.back()->val); // right most element added in that level
        int size = qStore.size();

        for(int i = 0; i<size; i++){
            TreeNode *temp = qStore.front();
            qStore.pop_front();
            if(temp->left != NULL){
                qStore.push_back(temp->left);
            }
            if(temp->right != NULL){
                qStore.push_back(temp->right);
            }
        }
    }
    
    return rightNode;
}
