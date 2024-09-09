class Solution {
public:
    vector<string> output = {};
    void generation (string str, int open, int close){
        if(open == 0 && close == 0){
            output.push_back(str);
            return;
        }
        // include the open bracket
        if(open>0){
            generation(str+"(",open-1,close);
        }
        
        // include the close bracket
        if(open<close && close>0){
            generation(str+")",open,close-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        int open = n, close = n;
        generation(str,open,close);
        return output;
    }
};
