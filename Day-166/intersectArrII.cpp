vector<int> helper(vector<int>& bigVec, vector<int>& smalVec){
    vector<int> ans;
    unordered_map<int,int> freq;
    for(int i = 0; i<bigVec.size(); i++){
        freq[bigVec[i]]++;
    }
    for(int i = 0; i<smalVec.size(); i++){
        if(freq.find(smalVec[i]) != freq.end()){
            // element present
            freq[smalVec[i]]--;
            ans.push_back(smalVec[i]);
            if(freq[smalVec[i]] == 0){
                // delete it
                freq.erase(smalVec[i]);
            }
        }
    }

    return ans;
}
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size()>nums2.size()){
        return helper(nums1,nums2);
    }
    return helper(nums2,nums1);
}
