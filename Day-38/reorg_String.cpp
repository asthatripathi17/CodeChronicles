class Solution {
public:
    string reorganizeString(string s) {
        
        vector<int> occur(26,0);
        for(int i = 0; i<s.size(); i++){
            occur[s[i] - 'a']++; //to get index from 0 to 26
        }

        int max_occur = *max_element(occur.begin(),occur.end());
        if(s.size()<max_occur*2 - 1) return "";
        int index = find(occur.begin(), occur.end(),max_occur) - occur.begin();
        char most_occur = index + 'a';
        
        int j = 0;
        //Placing most frequent letter
        for(; j<s.size() && max_occur>0 ; j = j+2){
            s[j] = most_occur;
            max_occur--;

        }
        occur[index] = 0;

        //Placing other letters
        for(int i = 0; i<26; i++){
            if(occur[i]!=0){
                while(occur[i]>0){
                    j = j<s.size()?j:1;
                    s[j] = i+'a';
                    occur[i]--;
                    j = j+2;
                }
            }
        }
        return s;
    }
};
