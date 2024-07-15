TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    set<int> store;
    for(int i = 0; i<descriptions.size(); i++){
        store.insert(descriptions[i][0]);
    }
    for(int i = 0; i<descriptions.size(); i++){
        if(store.find(descriptions[i][1]) != store.end()){
            store.erase(descriptions[i][1]);
        }
    }
    int val = *store.begin();
    
    unordered_map<int, TreeNode*> map;
    for(vector<int>& vec:descriptions){
        int parent = vec[0];
        int child = vec[1];
        int isleft = vec[2];

        if(map.find(parent) == map.end()){
            map[parent] = new TreeNode(parent);
        }
        if(map.find(child) == map.end()){
            map[child] = new TreeNode(child);
        }
        if(isleft == 1){
            map[parent]->left = map[child];
        }else{
            map[parent]->right = map[child];
        }
    }

    return map[val];
}
