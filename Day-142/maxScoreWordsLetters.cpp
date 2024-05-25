// Using backtracking

class Solution {
public:
    int wordValue(string st, vector<int>& score){
        int sum = 0;
        for(char ch: st){
            sum += score[ch-'a'];
        }
        return sum;
    }

    void storeDecrement(string st, unordered_map<char, int>& store) {
        for(char ch: st){
            store[ch]--;
        }
    }

    void storeRestore(string st, unordered_map<char, int>& store) {
        for(char ch: st){
            store[ch]++;
        }
    }

    bool storeChecker(string st, unordered_map<char, int>& store) {
        unordered_map<char, int> temp_store = store; // Create a copy of the store
        for(char ch: st){
            if(temp_store[ch] == 0){
                return false; // so that when returns false it doesn't change the store
            }
            temp_store[ch]--;
        }
        return true;
    }

    void calcScore(vector<string>& words, unordered_map<char,int>& store, vector<int>& score, int index,int& max_value, int temp){
        if(index>=words.size()){
            max_value = max(max_value,temp);
            return;
        }

        // exclude
        calcScore(words,store,score,index+1,max_value,temp);

        // include only if in store
        if(storeChecker(words[index],store)){
            storeDecrement(words[index], store); // to update the store for next word
            calcScore(words, store, score, index + 1, max_value, temp + wordValue(words[index], score));
            storeRestore(words[index], store); // backtrack the store
        }
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int> store;
        for(int i = 0; i<letters.size(); i++){
            store[letters[i]]++;
        }

        int max_value = 0;
        calcScore(words,store,score,0,max_value,0);
        return max_value;
    }
};
