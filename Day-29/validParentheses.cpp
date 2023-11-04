class Solution {
public:
    char close_brack(char ch){
        if(ch == ')') return '(';
        else if(ch == '}') return '{';
        else if(ch == ']') return '[';
        else return 'e';
    }
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i<s.size(); i++){
            if(!st.empty() && st.top() == close_brack(s[i])){
                st.pop();
                continue;
            }
            else{
                st.push(s[i]);
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};
