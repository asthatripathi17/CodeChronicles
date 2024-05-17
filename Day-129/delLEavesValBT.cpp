TreeNode* removeLeafNodes(TreeNode* root, int target) {
    
    if(root==NULL){
        return root;
    }

    root->left = removeLeafNodes(root->left,target);
    root->right = removeLeafNodes(root->right,target);

    if(root->right == NULL && root->left == NULL){
        // leaf node found with target value
        if(root->val == target){
            return NULL;
        } 
    }

    return root;
}
