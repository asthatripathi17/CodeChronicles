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
