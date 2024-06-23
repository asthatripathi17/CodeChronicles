void helperFunc(TreeNode* root, int max, int& count){
    if(root == NULL){
        return;
    }
    if(root->val>=max){
        count++;
        max = root->val;
    }
    helperFunc(root->left,max,count);
    helperFunc(root->right,max,count);

}
int goodNodes(TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    int count = 0;
    helperFunc(root,root->val,count);
    return count;
}
