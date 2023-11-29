class Solution {
public:
    bool oppSign(int top, int ele){
        //collision occurs when R--><--L; i.e. +ve then -ve
        if(top>=0 && ele<=0){
            return true;
        }
        return false;
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int i = 0; i<asteroids.size(); i++){
            if(st.empty()) 
                st.push(asteroids[i]);
            else if(oppSign(st.top(),asteroids[i])){
                if(abs(st.top())==abs(asteroids[i])){
                    st.pop();
                    continue;
                }
                else if(abs(st.top())<abs(asteroids[i])){
                    st.pop();
                    i--;
                }
                else{
                    continue;
                }
            }
            else{
                st.push(asteroids[i]);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
