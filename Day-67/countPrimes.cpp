Approach 1

// Using the sqrt method
// TC = O(n^(1.5))
bool isPrime(int i){
    for(int num = 2; num*num<=i; num++){
        if(i%num == 0)  return false;
    }
    return true;
}
int countPrimes(int n) {
    int count = 0; //keep the count of primes encountered
    for(int i = 2; i<n; i++){
        if(isPrime(i))  count++;
    }
    return count;
}

Approach 2

// Using Sieve of Eratosthenes
// TC = O(n*log(log(n)))
int countPrimes(int n) {
    int count = 0; //keep the count of primes encountered
    
    if(n<=1)    
        return count;
    
    vector<bool> sieve(n,true);
    sieve[0] = false;
    sieve[1] = false;
    
    for(int i = 2; i<n; i++){
        if(sieve[i] == true){
            for(int j = 2; j*i<n; j++){
                sieve[j*i] = false;
            }
            count++;
        }
    }
    return count;
}

Approach 3

// Using Optimized Sieve of Eratosthenes
int countPrimes(int n) {
    int count = n-2; //keep the count of primes encountered
    
    if(n<=1)    
        return 0;
    
    vector<bool> sieve(n,true);
    sieve[0] = false;
    sieve[1] = false;
    //Optimization 1
    for(int i = 2; i*i<n; i++){
        if(sieve[i]){
            //Optimization 2
            for(int j = i*i; j<n; j+=i){
                if(sieve[j]){
                    count--;
                    sieve[j] = false;
                }
            }
        }
    }
    return count;
}
