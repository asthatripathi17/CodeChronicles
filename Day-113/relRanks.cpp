vector<string> findRelativeRanks(vector<int>& score) {
        map<int,string> store;
        vector<int> output = score;
        vector<string> res(score.size());
        sort(output.begin(), output.end(), greater<int>());

        for(int i = 0; i<score.size(); i++){
            if(i == 0){
                store[output[i]] = "Gold Medal";
            }
            else if(i == 1){
                store[output[i]] = "Silver Medal";
            }
            else if(i == 2){
                store[output[i]] = "Bronze Medal";
            }
            else{
                store[output[i]] = to_string(i+1);
            }
        }

        for(int i = 0; i<score.size(); i++){
            res[i] = store.find(score[i])->second;
        }
        
        return res;
    }
