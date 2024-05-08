vector<string> findRelativeRanks(vector<int>& score) {
        
        unordered_map<int,int> store;
        for(int i = 0; i<score.size(); i++){
            store[score[i]] = i;
        }
        sort(score.begin(),score.end(),greater<int>());
        vector<string> result(score.size());
        for(int i = 0;i<score.size();i++){
            int temp = store[score[i]];
            if(i == 0){
                result[temp] = "Gold Medal";
            }
            else if(i == 1){
                result[temp] = "Silver Medal";
            }
            else if(i == 2){
                result[temp] = "Bronze Medal";
            }
            else{
                result[temp] = to_string(i+1);
            }
        }
        
        return result;
        }
