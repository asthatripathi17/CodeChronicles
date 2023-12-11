class Solution {
public:
    bool isAlphanumeric(char a){
        return (a>='A' && a<='Z') || (a>='a' && a<='z') || (a>='0' && a<='9');
    }
    bool isPalindrome(string s) {
        if(s.size() == 1) return true;

        int i = 0, j = s.size()-1;
        while(i<=j){
            while(i<=j && !isAlphanumeric(s[i])){
                i++;
            }
            while(i<=j && !isAlphanumeric(s[j])){
                j--;
            }
            if(i<=j && tolower(s[i]) == tolower(s[j])){
                i++;
                j--;
            }
            else if(i<=j)
                return false;
        }
        return true;
    }
};
