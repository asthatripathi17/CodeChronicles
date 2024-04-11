bool isSubsequence(string s, string t) {
    int index = 0;
    for(int i = 0; i<t.length(); i++){
        if(index<s.length()){
            if(t[i] == s[index]){
                index++;
            }
        }
    }
    return index == s.length();
}
