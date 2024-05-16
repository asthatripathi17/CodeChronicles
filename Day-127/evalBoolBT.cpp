bool evaluateTree(TreeNode* root) {
    if(root->val < 2){
        // return as it is
        return root->val;
    }
    else if(root->val == 2){
        // OR case
        return evaluateTree(root->left) || evaluateTree(root->right);
    }
    // AND case
    return evaluateTree(root->left) && evaluateTree(root->right);
}
