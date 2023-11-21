//Approach 1 - Using sorting
class Solution {
public:
    string sort_str(string s){
        sort(s.begin(),s.end());
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(int i = 0; i<strs.size(); i++){
            string sorstr = sort_str(strs[i]);
            map[sort_str(strs[i])].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto i:map){
            ans.push_back(i.second);
        }
        return ans;
    }
};

//Approach 2 - Using hashmap
class Solution {
public:
    
    array<int,128> makeMap(string s){
        array<int,128> hash = {0};
        for(int i = 0; i<s.size(); i++){
            hash[s[i]]++;
        }
        return hash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<std::array<int,128>,vector<string>>hash_anagrams;
        //not using umap as it requires hashing function
        //for keys like array<int,256> we need custom hashing function
        
        for(int i = 0; i<strs.size(); i++){
            hash_anagrams[makeMap(strs[i])].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto i:hash_anagrams){
            ans.push_back(i.second);
        }
        return ans;
    }
};
