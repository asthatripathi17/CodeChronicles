class FindElements {  
public:
    unordered_set<int> store;
    void dfs(TreeNode* root, int x){
        if(root==NULL){
            return;
        }
        root->val = x;
        store.insert(x);
        dfs(root->left,2*x + 1);
        dfs(root->right,2*x + 2);
    }
    FindElements(TreeNode* root) {
        store.clear();
        /* store is a global or class-level variable, meaning it retains values from previous function calls. If clear() is not used, it may contain old values from a previous dfs() traversal, leading to incorrect lookups in find(int target).*/
        dfs(root,0); // just tree traversal
    }
    
    bool find(int target) {
        // check in unordered set and return bool value
        if(store.find(target)!=store.end())
            return true;
        return false;
    }
};
