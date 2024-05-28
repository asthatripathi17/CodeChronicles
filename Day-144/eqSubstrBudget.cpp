// Recursive Solution - Gives TLE
void helperFunc(string& s, string& t, int index, int cost, int count, int& maxCost,int& ans, int lp){
    if(index>=s.length()){
        ans = max(ans,count);
        return;
    }
    // exclude
    helperFunc(s,t,index+1,cost,count,maxCost,ans,lp);
    // include only if less than equal to maxCost
    if(cost+abs(s[index]-t[index])<=maxCost && (lp == -1 || lp == index - 1)){
        helperFunc(s,t,index+1,cost+abs(s[index]-t[index]),count+1,maxCost,ans,index);
    }
}
int equalSubstring(string s, string t, int maxCost) {
    int ans = 0;
    helperFunc(s,t,0,0,0,maxCost,ans,-1);
    return ans;
}

// Sliding Window Solution
