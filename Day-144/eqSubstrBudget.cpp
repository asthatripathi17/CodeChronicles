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
int equalSubstring(string s, string t, int maxCost) {
    int i = 0, j = 0, sum = 0;
    int window = 0;
    while(i<=j && j<s.length() && i<s.length()){
        sum += abs(s[j]-t[j]);
        while(sum>maxCost){
            sum -= abs(s[i]-t[i]);
            i++;
        }
        window = max(window,j-i+1);
        j++;
    }
    return window;
}
