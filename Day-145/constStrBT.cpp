void traverseTree(TreeNode* root,string& str){
    str+="("+to_string(root->val);
    if(root->left==NULL && root->right==NULL){
        str+=")";
        return;
    }
    if(root->left==NULL){
        str+="()";
    }
    else{
        traverseTree(root->left,str);
    }
    if(root->right!=NULL){
        traverseTree(root->right,str);
    }
    str+=")";
}
string tree2str(TreeNode* root) {
    if(root==NULL){
        return "";
    }
    string str = "";
    traverseTree(root,str);
    str.erase(str.end()-1);
    str.erase(str.begin());
    return str;
}
