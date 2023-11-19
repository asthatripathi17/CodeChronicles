class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;

        vector<int> s_map(256,0);
        vector<bool> t_check(256,false);

        for(int i = 0; i<s.size(); i++){
            if(s_map[s[i]] == 0){
                s_map[s[i]] = t[i];
                if(t_check[t[i]] == false){
                    t_check[t[i]] = true;
                }
                else
                    return false;
            }
            else if(s_map[s[i]] != t[i]){
                return false;
            }
        }

        return true;
    }
};
