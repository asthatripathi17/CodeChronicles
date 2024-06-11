vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    
    map<int,int> freqStore;
    for(int x:arr1){
        freqStore[x]++;
    }
    vector<int> ans;
    for(int i = 0; i<arr2.size(); i++){
        int freq = freqStore[arr2[i]];
        ans.insert(ans.end(),freq,arr2[i]);
        freqStore.erase(arr2[i]);
    }

    auto it = freqStore.begin();
    while(it != freqStore.end()) {
        ans.insert(ans.end(), it->second, it->first);
        it = freqStore.erase(it); // Erase and move to the next element
    }

    return ans;
}
