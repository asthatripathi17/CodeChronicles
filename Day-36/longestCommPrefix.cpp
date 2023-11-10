class Solution {
public:
    string findPrefix(string s1, string s2){

        int i = 0;
        string result = "";
        while(i<min(s1.size(),s2.size())){
            if(s1[i]!=s2[i]) return result;
            result.push_back(s1[i]);
            i++;
        }
        return result;
    }

    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() == 1 || strs[0] == ""){
            return strs[0];
        }
        string ans = findPrefix(strs[0],strs[1]);
        int i = 2;
        while(i<strs.size()){
            ans = findPrefix(ans,strs[i]);
            if(ans == "") return "";
            i++;
        }
        
        return ans;

    }
};
