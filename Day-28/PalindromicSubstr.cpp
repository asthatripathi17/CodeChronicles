class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        
        //for odd length substrings
        for(int a = 0; a<s.size(); a++){
            int i = a, j = a;
            while(i>=0 && j<=s.size()-1){
                if(s[i]==s[j]){
                    count++;
                    i--; j++;
                }
                else break;
            }
        }
        
        //for even length substrings
        for(int a = 0; a<s.size(); a++){
            int i = a, j = a+1;
            while(i>=0 && j<=s.size()-1){
                if(s[i]==s[j]){
                    count++;
                    i--; j++;
                }
                else break;
            }
        }
        return count;
    }
};
