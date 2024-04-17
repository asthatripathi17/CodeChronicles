bool wordPattern(string pattern, string s) {

        int i = 0, countSpace = 0; // iterator for pattern

        //hashmaps for bijection functions
        unordered_map<char,string> hash;
        unordered_map<string,char> hash1;
        string word = "";

        for(int j = 0; j<s.length(); j++){
            
            if(s[j] == ' '){
                countSpace++;
                if(countSpace >= pattern.length()){ 
                    return false;
                }
            }
            if(word != "" && (s[j] == ' ' || j == s.length()-1) && i<pattern.length()){
                
                if(j == s.length()-1){
                    word += s[j];
                }
                if(hash.count(pattern[i]) == 0 && hash1.count(word) == 0){
                    hash[pattern[i]] = word;
                    hash1[word] = pattern[i];
                }
                else if((hash.count(pattern[i]) > 0 && hash[pattern[i]] != word) || (hash1.count(word) > 0 && hash1[word] != pattern[i])){
                    return false;
                }
                word = "";
                i++;
            }
            else{
                word += s[j];
            }
        }
        if(countSpace == 0 && pattern.length()>1){
            return false;
        }
        return true;
    }
