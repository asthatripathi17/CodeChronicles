class Solution {
public:
    bool checkLetter(char a){
        if(a>='a' && a<='z' || a>='A' && a<='Z')
            return true;
        return false;
    }
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size()-1;
        while(i<j){
            if(checkLetter(s[i])){
                if(checkLetter(s[j])){
                    swap(s[i],s[j]);
                    i++;
                    j--;
                }
                else{
                    j--;
                }
            }
            else{
                i++;
            }
        }
        return s;
    }
};
