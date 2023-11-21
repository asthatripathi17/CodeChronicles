class Solution {
public:
    string check_palindrome(string s, bool even){
        
        //using odd and even length strategy for palindrome
        pair<int,int> index;
        int i,j;
        for(int a = 0; a<s.size(); a++){
            i = a;
            if(even == true) j = a+1;
            else j = a;
            while(i>=0 && j<=s.size()-1){
                if(s[i]==s[j]){
                    if(index.second - index.first <= j-i)
                        index = make_pair(i,j);
                    i--; j++;
                }
                else break;
            }
        }
        string substring = s.substr(index.first,index.second-index.first+1);
        return substring;
    }

    string longestPalindrome(string s) {
        string ans;
        if(check_palindrome(s,false).size()>check_palindrome(s,true).size())
            ans = check_palindrome(s,false);
        else ans = check_palindrome(s,true);
        //comparing odd and even length longest palindromic substring
        return ans;
    }
};
