int extraCoins(TreeNode* root, int& moves){
    if(root==NULL){
        return 0;
    }
    int l = extraCoins(root->left,moves);
    int r = extraCoins(root->right,moves);

    moves += abs(l) + abs(r); // if value is negative --> direction of flow of coin is opp but moves will be same
    return (root->val+l+r)-1; 
}

int distributeCoins(TreeNode* root) {
    int moves = 0;
    extraCoins(root,moves); // not storing the return value as it is not needed
    return moves;
}
