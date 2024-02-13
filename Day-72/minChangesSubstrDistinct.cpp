int minChange(string S) { 
     //complete the function here
    set<char> myset;
    for(int i = 0; i<S.length(); i++){
        myset.insert(S[i]);
    }
    
    return (S.length() - myset.size());
}
