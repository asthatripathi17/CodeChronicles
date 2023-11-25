class Solution {
public:
    bool checkDig(char c){

        return c>='0' && c<='9';
    }
    int checkCase(long long int num, int sign){
        num = num*sign;
        if(num<INT_MIN) return INT_MIN;
        else if(num>INT_MAX) return INT_MAX;
        
        int ans = num;
        return ans;
    }
    int myAtoi(string s) {
        int i = 0, sign = 1, once = 0, space = 0;
        long long int num = 0;
        while(i<s.size()){
            if(s[i] == ' ' && space!=1){
                i++;
            }
            else if((s[i] == '+' || s[i] == '-') && once!=1){
                if(s[i] == '-')
                    sign = -1;
                i++;
                once = 1;
            }
            else if(!checkDig(s[i])){
                return checkCase(num,sign);
            }
            else{
                once = 1;
                space = 1;
                if(num<)
                num = num*10 + s[i] - '0';
                i++;
            }
        }
        return checkCase(num,sign);
    }
};
