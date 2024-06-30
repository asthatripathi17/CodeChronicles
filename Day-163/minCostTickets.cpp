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
