//Using the stacks
//can be done using simple string
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> ans;
        string str;
        for(int i = 0; i<s.length(); i++){
            if(!ans.empty() && ans.top() == s[i]){
                ans.pop();
            }
            else{
                ans.push(s[i]);
            }
        }
        if(ans.empty()) return "";
        else{
            while(!ans.empty()){
                str.push_back(ans.top());
                ans.pop();
            }
            reverse(str.begin(),str.end());
        }
        return str;
    }
};
