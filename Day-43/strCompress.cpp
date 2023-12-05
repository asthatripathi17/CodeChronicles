//Time-Optimized Approach
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

//Space-optimized solution using in-place modifications
class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() == 1){
            return chars.size();
        }
        //in place modifying
        pair<char,int> count;
        count.first = chars[0];
        count.second = 1;

        int i = 0;
        while(i<chars.size()){
            i++;
            while(count.first == chars[i] && i<chars.size()){
                count.second++;
                chars.erase(i+chars.begin());
            }
            if(i<chars.size() && count.second>1 && count.first != chars[i]){
                string str = to_string(count.second);
                for(int j = str.size()-1; j>=0; j--){
                    //if length >=10
                    chars.insert(i+chars.begin(),str[j]);
                }
                //for a new char
                i += str.size();
                count.first = chars[i];
                count.second = 1;
            }
            
            if(i<chars.size() && count.first != chars[i]){
                count.first = chars[i];
                count.second = 1;
            }
            
        }
        //insert the count for last char
        if(count.second>1){
            string str = to_string(count.second);
            for(int j = 0; j<str.size(); j++){
                //if length >=10
                chars.push_back(str[j]);
            }
        }
        
        return chars.size();
    }
};
