class Solution {
public:
    bool isSubseq(string str, string order){

        if(str.size() > order.size()) 
            return false;
        
        int i = 0, j = 0;
        int max_size = max(str.size(),order.size()); 
        
        while(i<max_size && j<max_size){
            if(str[i] == order[j]){
                i++;
            }
            j++;
        }

        return i == str.size();
    }

    string findLongestWord(string s, vector<string>& dictionary) {

        string result = "";

        for(int i = 0; i<dictionary.size(); i++){

            if(isSubseq(dictionary[i], s)){

                if(result.length()<dictionary[i].length() || (result.length()==dictionary[i].length() && dictionary[i].compare(result) < 0)){
                    
                    result = dictionary[i];
                }
            } 
        }

        return result;
    }
};
