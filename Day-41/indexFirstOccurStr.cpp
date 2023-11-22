class Solution {
public:
    bool checkOcc(int index, string hay, string subpart){
        string substr = hay.substr(index,subpart.size());
        if(substr == subpart) return true;
        else return false;
    }
    int strStr(string haystack, string needle) {
        int len_hay = haystack.size(), len_needl =needle.size();
        if(len_hay<len_needl) return -1;

        for(int i = 0; i<len_hay-len_needl+1; i++){
            if(haystack[i]!=needle[0]) continue;
            if(checkOcc(i,haystack,needle)) return i;
        }
        return -1;
    }
};
