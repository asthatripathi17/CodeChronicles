class Solution {
public:
    bool check_palindrome(string str){
        int i = 0, j = str.length()-1;
        while(i<=j){
            if(str[i]==str[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0, j = s.length()-1;
        int chance = 1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else if(s[i]!=s[j]){
                if(check_palindrome(s.substr(i,j-i)) || check_palindrome(s.substr(i+1,j-i))){
                    chance--;
                    if(chance>=0) return true;
                    else return false;
                }
                else return false;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
