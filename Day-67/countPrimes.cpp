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
// 
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
