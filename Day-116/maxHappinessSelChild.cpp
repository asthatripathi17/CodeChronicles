long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        sort(happiness.begin(),happiness.end());
        int dec = 0, i = happiness.size()-1;
        long long ans = 0;
        while(k>0){
            int temp = happiness[i] - dec;
            ans += temp>0?temp:0;
            dec++;
            i--;
            k--; 
        }
        return ans;
    }
