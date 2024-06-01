int scoreOfString(string s) {
    int prev = s[0], sum = 0;
    for(int i = 1; i<s.length(); i++){
        sum += abs(prev-s[i]);
        prev = s[i];
    }
    return sum;
}
