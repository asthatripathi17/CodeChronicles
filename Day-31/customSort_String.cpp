class Solution {
public:

    string customSortString(string order, string s) {
        unordered_map<char, int> map;
        for(int i = 0; i<s.size(); i++){
            map[s[i]]++; //incrementing the value every time the same key is encountered
        }
        string ans = "";
        for(int i = 0; i<order.size(); i++){
            if(map.find(order[i]) != map.end()){
                ans.append(map[order[i]], order[i]); //appending a character according to its frequency; map[c] = 1; ans = c
                //erase that key
                map.erase(order[i]);
            }
        }
        for(auto i: map){
            ans.append(i.second, i.first); //second = frequency of key; first = key(character left)
        }
        return ans;
    }
};
