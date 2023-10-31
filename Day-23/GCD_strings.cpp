//brute force approach using str.find(target)

class Solution {
public:
    string min_str(string str1, string str2){
        if(str1.length()<str2.length()) return str1;
        else return str2;
    }
    string max_str(string str1, string str2){
        if(str1.length()<str2.length()) return str2;
        else return str1;
    }
    bool check_sub(string str, string target){
        int len = 0;
        int found = str.find(target);
        if(found == -1)
            return false;
        for(int i = 0; i<(str.length()/target.length()) - 1; i++){
            found = str.find(target, found+target.length());
            len += target.length();
            if(found == -1)
                return false;
            else if(len == found){
                continue;
            }
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        
        string small_str = min_str(str1,str2);
        string big_str = max_str(str1,str2);
        int len_small = small_str.length(), len_big = big_str.length();
        string test;
        string ans = "";
        for(int i = 0; i<len_small; i++){
            test.push_back(small_str[i]);
            if(len_small%test.length() == 0 && len_big%test.length() == 0){
                if(check_sub(small_str,test)){
                    if(check_sub(big_str,test)){
                        ans = test;
                    }
                }
            }
            else{
                continue;
            }
        }
        return ans;
    }
};
