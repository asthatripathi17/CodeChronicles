class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> umap;
        for(int i = 0; i<26; i++){
            umap[order[i]] = i+1;
        }
        for(int i = 0; i<words.size()-1; i++){
            if(umap[words[i][0]] > umap[words[i+1][0]]){
                return false;
            }
            else if(umap[words[i][0]] < umap[words[i+1][0]]){
                continue;
            }
            else if(umap[words[i][0]] == umap[words[i+1][0]]){
                int s1 = words[i].size(), s2 = words[i+1].size();
                for(int j = 1; j<max(s1,s2); j++){
                    if(j<s1 && j<s2){
                       if(umap[words[i][j]] > umap[words[i+1][j]]){
                            return false;
                        }
                        else if(umap[words[i][j]] < umap[words[i+1][j]]){
                            break;
                        }
                    }
                    else{
                        if(j==s2){ 
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
