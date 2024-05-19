void helperFunc(TreeNode* root, int &res, int ans){
    if(root->left == NULL && root->right == NULL){
        ans = ans*10 + root->val;
        res += ans;
        return;
    }

    ans = ans*10 + root->val;
    if(root->left!=NULL)
        helperFunc(root->left,res,ans);
    if(root->right!=NULL)
        helperFunc(root->right,res,ans);
}
int sumNumbers(TreeNode* root) {
    int res = 0;
    helperFunc(root,res,0);
    return res;
}
