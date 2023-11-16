class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char,char> umap;
        for(int i = 0; i<s.size(); i++){
            if(umap.find(s[i]) == umap.end() && umap.find(t[i]) == umap.end()){
                umap[s[i]] = t[i];
                if(s[i] != t[i]) 
                    umap[t[i]] = s[i];
            }
            else if(umap[s[i]] != t[i] || umap[t[i]] != s[i]){
                cout<<s[i]<<" "<<t[i];
                return false;
            }
        }
        return true;
    }
};
