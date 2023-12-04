class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(char ch:s){
            if(st.empty()){
                st.push(ch);
            }
            else{
                if(ch == ']'){
                    string str;
                    while(st.top()!='[' && !st.empty()){
                        str.push_back(st.top());
                        st.pop();
                    }
                    st.pop(); //for '['
                    //to extract the k
                    string k;
                    while(!st.empty() && st.top()>='0' && st.top()<='9'){
                        //check st.empty before other conditions
                        k.push_back(st.top());
                        st.pop();
                    }
                    int num;
                    reverse(k.begin(),k.end());
                    num = stoi(k);
                    reverse(str.begin(),str.end());

                    while(num!=0){
                        for(char i:str){
                            st.push(i);
                        }
                        num--;
                    }
                }
                else{
                    st.push(ch);
                }
            }
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
