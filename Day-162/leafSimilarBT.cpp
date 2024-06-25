void leafGetter(vector<int>& arr,TreeNode* root){
    if(root->right == NULL && root->left == NULL){
        arr.push_back(root->val);
        return;
    }
    if(root->left!=NULL){
        leafGetter(arr,root->left);
    }
    if(root->right!=NULL){
        leafGetter(arr,root->right);
    }
}
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> arr1,arr2;
    leafGetter(arr1,root1);
    leafGetter(arr2,root2);

    return arr1==arr2;
}
