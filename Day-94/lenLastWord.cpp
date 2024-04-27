int lengthOfLastWord(string s) {
        
        string temp;
        for(int i = s.length()-1; i>=0; i--){
            if(s[i] == ' ' && temp == ""){
                continue;
            }
            else if(s[i] == ' ' && temp != ""){
                return temp.length();
            }
            else if(s[i] != ' '){
                temp += s[i];
            }
        }
        return temp.length();
    }
