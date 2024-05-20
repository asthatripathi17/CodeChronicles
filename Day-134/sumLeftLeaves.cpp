void helperFunc(TreeNode* root, int& sum){
    if(root == NULL){
        return;
    }
    else if(root->left != NULL && (root->left->left == NULL && root->left->right == NULL)){
      // For left leaves only
        sum += root->left->val;
    }
    else{
        helperFunc(root->left,sum);
    }
    helperFunc(root->right,sum);
}

int sumOfLeftLeaves(TreeNode* root) {
    int sum = 0;
    helperFunc(root,sum);
    return sum;
}
