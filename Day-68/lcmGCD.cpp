class Solution {
  public:
    long long gcdFunc(long long a, long long b){
        // defining the base case
        if(a == 0 || b == 0){
            if(a==0)
                return b;
            else
                return a;
        }
        
        if(a>b){
            return gcdFunc(a-b,b);
        }
        
        return gcdFunc(b-a,a);
    }
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        vector<long long> lcmGCD (2);
        long long gcd = gcdFunc(A,B);
        long long lcm = (A/gcd) * B;
        
        lcmGCD[0] = lcm;
        lcmGCD[1] = gcd;
        
        return lcmGCD;
    }
};
