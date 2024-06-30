bool dfs(TreeNode* left, TreeNode* right){
    if(left == NULL && right == NULL){
        return true;
    }
    if(left == NULL || right == NULL){
        return false;
    }

    return (left->val == right->val && dfs(left->left,right->right) && dfs(left->right,right->left));
}
bool isSymmetric(TreeNode* root) {
    return dfs(root->left,root->right);
}
