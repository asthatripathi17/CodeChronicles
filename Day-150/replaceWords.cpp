string rootChecker(const string& word, const vector<string>& dictionary){
    int minLen = INT_MAX;
    string ans = "";
    for(string root:dictionary){
        if(root[0] == word[0] && word.substr(0,root.length()) == root){
            if(root.length()<minLen){
                ans = root;
                minLen = root.length();
            }
        }
    }
    return ans;
}

string replaceWords(vector<string>& dictionary, string sentence) {
    // for replacing using stl just determining when next string end or blank space aayega
    string word = "";
    int firstL = 0;
    for (int i = 0; i <= sentence.length(); i++) {
        if (i == sentence.length() || sentence[i] == ' ') {
            word = sentence.substr(firstL, i - firstL);
            string temp = rootChecker(word, dictionary);
            if (!temp.empty()) {
                sentence.replace(firstL, word.length(), temp);
                i = firstL + temp.length() - 1;  // Adjust `i` to account for the new length
            }
            firstL = i + 1;
        }
    }
    return sentence;
}
