int findKthLargest(vector<int>& nums, int k) {

    vector<int> v1 = nums;

    make_heap(v1.begin(),v1.end());

    while(k>1){
        pop_heap(v1.begin(), v1.end());
        v1.pop_back();
        k--;
    }

    return v1.front();
    
}
