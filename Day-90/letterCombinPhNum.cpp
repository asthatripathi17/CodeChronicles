// Recursive Solution
class Solution {
public:
    void helperFunc(int index, unordered_map<char, vector<char>> &letterNum,vector<string> &output,string tempStr,string &digits){
        if(index>=digits.length()){
            if(tempStr != "")
                output.push_back(tempStr);
            return;
        }
        else{
            for(int i = 0;i<letterNum[digits[index]].size();i++){
                helperFunc(index+1,letterNum,output,tempStr+letterNum[digits[index]][i],digits);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> letterNum;
        letterNum['2'] = {'a','b','c'};
        letterNum['3'] = {'d','e','f'};
        letterNum['4'] = {'g','h','i'};
        letterNum['5'] = {'j','k','l'};
        letterNum['6'] = {'m','n','o'};
        letterNum['7'] = {'p','q','r','s'};
        letterNum['8'] = {'t','u','v'};
        letterNum['9'] = {'w','x','y','z'};
        
        vector<string> output;
        helperFunc(0,letterNum,output,"",digits);

        return output;

    }
};
