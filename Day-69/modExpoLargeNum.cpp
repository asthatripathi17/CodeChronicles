long long int fastExpo(long long int a, long long int b, long long int mod){
    long long result = 1;
    while(b>0){
        if(b&1){
            //odd
            result = (result*a)%mod;
        }
        a = (a*a)%mod;
        b>>=1;
    }
    return result;
}
long long int PowMod(long long int x,long long int n,long long int M){
    // Code here
    long long int ans = fastExpo(x,n,M);
    ans =  ans%M;
    
    return ans;
}
