int numOfSubarrays(vector<int>& arr) {
    int cnt = 0, curr = 0, odd = 0, even = 0;
    int mod = 1000000007;
    for(int i = 0; i<arr.size();i++){
        curr = curr + arr[i];
        if(curr%2==0){
            even++;
            cnt += odd;
        }
        else{
            odd++;
            cnt = (cnt + even + 1)%mod;
        }
    }

    return cnt;
}
