bool countHappyStrings(string &ans, int &cnt, vector<char> &happyChar, int &k, int &n, string &happyString){
    if(happyString.length() == n){
        cnt++;
        if(cnt == k){
            ans = happyString;
            return true;
        }
        return false;
    }

    for(char ch: happyChar){
        if(!happyString.empty() && happyString.back()==ch){
            continue;
        }

        happyString.push_back(ch);
        if(countHappyStrings(ans,cnt,happyChar,k,n,happyString))
            return true;

        happyString.pop_back();
    }

    return false;
}
string getHappyString(int n, int k) {
    string ans = "";
    int cnt = 0;
    string happyString = "";

    vector<char> happyChar = {'a','b','c'};
    countHappyStrings(ans, cnt, happyChar, k, n, happyString);

    return ans;
}
