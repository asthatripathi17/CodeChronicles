TreeNode* pruneTree(TreeNode* root) {
    if(root==NULL){
        return root;
    }

    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);

    if(root->right == NULL && root->left == NULL){
        // leaf node found with target value = 0
        if(root->val == 0){
            return NULL;
        } 
    }

    return root;
}
