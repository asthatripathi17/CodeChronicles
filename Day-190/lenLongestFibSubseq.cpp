int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> check(arr.begin(),arr.end());
        int prev, curr, nxt;
        int maxLen = 0;
        for(int i = 0; i<arr.size(); i++){
            for(int j = i+1; j<arr.size(); j++){
                prev = arr[i];
                curr = arr[j];
                nxt = prev + curr;
                int temp = 2;
                while(check.find(nxt)!=check.end()){
                    temp++;
                    prev = curr;
                    curr = nxt;
                    nxt = prev + curr;
                }
                maxLen = max(maxLen,temp);
            }
        }

        if(maxLen <=2) return 0;

        return maxLen;
    }
