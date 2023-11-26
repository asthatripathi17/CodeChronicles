//Space can be optimized by compressing the characters in-place within the original chars vector
class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> vec = chars;
        pair<char,int> count;
        chars.clear();

        count.first = vec[0];
        count.second = 1;
        if(vec.size() == 1){
            chars = vec;
            return vec.size();
        }
        
        for(int i = 1; i<vec.size(); i++){
            if(count.first == vec[i]){
                count.second++;
            }
            else if(count.first != vec[i]){
                chars.push_back(count.first);
                if(count.second>1){
                    string str = to_string(count.second);
                    for(char j: str){
                        chars.push_back(j);
                    }
                }
                count.first = vec[i];
                count.second = 1;
            }
            if(i == vec.size()-1){
                chars.push_back(count.first);
                if(count.second>1){
                    string str = to_string(count.second);
                    for(char j: str){
                        chars.push_back(j);
                    }
                }
            }
        }
        return chars.size();
    }
};
