class Solution {
public:
    bool checkDig(char c){
        return c>='0' && c<='9';
    }
    int checkCase(long int num, int sign){
        num = num*sign;
        if(num<INT_MIN) return INT_MIN;
        else if(num>INT_MAX) return INT_MAX;
        
        return int(num);
    }
    int myAtoi(string s) {
        int i = 0, sign = 1, once = 0, space = 0;
        long int num = 0;
        while(i<s.size()){
            if(s[i] == ' ' && space!=1 && once!=1){
                i++;
                //can't have space after a number and sign
            }
            else if((s[i] == '+' || s[i] == '-') && once!=1){
                if(s[i] == '-')
                    sign = -1;
                i++;
                once = 1; //use sign one time only
            }
            else if(!checkDig(s[i])){
                return checkCase(num,sign);
            }
            else{
                if(num*sign<INT_MIN) return INT_MIN;
                else if(num*sign>INT_MAX) return INT_MAX;
                
                num = num*10 + s[i] - '0';
                i++;
                once = 1;
                space = 1;
            }
        }
        return checkCase(num,sign);
    }
};
