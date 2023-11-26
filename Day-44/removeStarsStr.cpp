class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i = 1; i<s.size(); i++){
            if(s[i] == '*'){
                st.pop();
                continue;
            }
            else{
                st.push(s[i]);
            }
        }
        s = "";
        while(!st.empty()){
            s+= st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
