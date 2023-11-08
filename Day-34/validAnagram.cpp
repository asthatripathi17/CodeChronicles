//Approach 1
//Using sorting
class Solution {
public:
    bool isAnagram(string s, string t) {
          sort(s.begin(),s.end());
          sort(t.begin(),t.end());
          return s==t;
    }
};

//Approach 2
//Using Unordered Map
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char,int> umap;
        for(int i = 0; i<s.length(); i++)
            umap[s[i]]++;
        for(int i = 0; i<t.length(); i++)
            umap[t[i]]--;
        
        for(auto i:umap){
            if(i.second != 0)
                return false;
        }
        return true;
    }
};
