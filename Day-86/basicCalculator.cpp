class Solution {
public:
    int calculate(string s) {
        stack<int> store;
        int num = 0, result = 0, sign = 1;
        for(int i = 0; i<s.length(); i++){
            if(isdigit(s[i])){ // s[i] >= '0' && s[i] <= '9'
                num = num*10 + (s[i] - '0'); // converting into digit
            }
            else if(s[i] == '+' || s[i] == '-'){
                result += sign*num;
                num = 0;
                if(s[i] == '+'){
                    sign = 1;
                }
                else{
                    sign = -1;
                } 
            }
            else if(s[i] == '('){
                store.push(result); // clearing the slate for new operations so storing result into stack
                result = 0;
                num = 0;
                store.push(sign); // storing the sign also to keep the track of what sign was before bracket started
                sign = 1;
            }
            else if(s[i] == ')'){
                result += sign*num;
                num = 0;
                result = result*store.top(); // multiply with sign 
                store.pop();
                result += store.top(); // adding in the result stored in stack
                store.pop();
                sign = 1;
            }
        }

        if(num!=0){ // for leftover digit in the end
            result+=sign*num;
        }
        return result;
    }
};
