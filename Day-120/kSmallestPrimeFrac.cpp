// Using Map and Pairs
vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        map<double,pair<int,int>> store;
        for(int i = 0; i<arr.size(); i++){
            for(int j = i+1; j<arr.size(); j++){
                double ans = ((double)arr[i])/((double)arr[j]); // using double for more precision
                store[ans] = {i,j};
            }
        }

        vector<int> output;
        for(auto i:store){
            if(k==1){
                output.push_back(arr[(i.second).first]);
                output.push_back(arr[(i.second).second]);
                return output;
            }
            k--;
        }

        return output;
    }
