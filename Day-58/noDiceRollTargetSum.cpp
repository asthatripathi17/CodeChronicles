class Solution {
public:
    //Used recursion first (encountered TLE) --> Then used Dynamic Programming with Memoization

    // int solve(int n, int k, int target){

    //     //base cases
    //     if(target<0) return 0;
    //     if(n == 0 && target!=0) return 0;
    //     if(target == 0 && n!=0) return 0; //as faces are numbered from 1
    //     if(n == 0 && target == 0) return 1; //do nothing so that is the only way
    //     //utilize all faces of a dice
    //     int sum = 0;
    //     for(int i=1;i<=k;i++){
    //         sum = sum+solve(n-1,k,target-i);
    //     }

    //     return sum;
    // }
    
    int solve_dp(int n, int k, int target, vector<vector<int>>& dp){

        //base cases
        if(target<0) return 0;
        if(n == 0 && target!=0) return 0;
        if(target == 0 && n!=0) return 0; //as faces are numbered from 1
        if(n == 0 && target == 0) return 1; //do nothing so that is the only way

        if(dp[n][target] != -1) return dp[n][target]; //do not compute again

        //utilize all faces of a dice
        long long sum = 0;
        for(int i=1;i<=k;i++){
            sum = (sum+solve_dp(n-1,k,target-i,dp))%1000000007;
        }
        return dp[n][target] = sum;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solve_dp(n, k, target, dp);
    }
};
