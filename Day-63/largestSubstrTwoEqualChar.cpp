class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int> index; //instead of map we can use array[26] to save S.C. = O(26)
        int max_dist = -1;
        for(int i = 0; i<s.size(); i++){

            if(index.find(s[i]) == index.end()){
                index[s[i]] = i;
            }
            else{
                int temp = i-index[s[i]]-1;
                if(temp>max_dist){
                    max_dist = temp;
                }
            }
        }
        return max_dist;
    }
};
