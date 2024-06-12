// Iterative Solution with array
int climbStairs(int n) {
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }

    vector<int> arr(n+1,0);
    arr[0] = 1;
    arr[1] = 1;
    int ans = 0;
    for(int i = 2; i<n+1; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}
