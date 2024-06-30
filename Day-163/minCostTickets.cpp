// Recursive Solution

int solve(vector<int>& days, vector<int>& costs, int index){
    // Base Case
    if(index>=days.size()){
        return 0;
    }

    int op1 = costs[0] + solve(days,costs,index+1);

    int i = index;
    for(;i<days.size()&& days[i]<days[index]+7; i++);
    int op2 = costs[1] + solve(days,costs,i);

    i = index;
    for(;i<days.size()&& days[i]<days[index]+30; i++);
    int op3 = costs[2] + solve(days,costs,i);

    return min(op1,min(op2,op3));
}
int mincostTickets(vector<int>& days, vector<int>& costs) {
    return solve(days,costs,0);
}

// Memoization Solution

int solveMem(vector<int>& days, vector<int>& costs, int index, vector<int>& dp){
    // Base Case
    if(index>=days.size()){
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }

    int op1 = costs[0] + solveMem(days,costs,index+1,dp);

    int i = index;
    for(;i<days.size()&& days[i]<days[index]+7; i++);
    int op2 = costs[1] + solveMem(days,costs,i,dp);

    i = index;
    for(;i<days.size()&& days[i]<days[index]+30; i++);
    int op3 = costs[2] + solveMem(days,costs,i,dp);

    dp[index] = min(op1,min(op2,op3));
    return dp[index];
}
int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> dp(days.size()+1,-1);
    return solveMem(days,costs,0,dp);
}
