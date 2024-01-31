//Using Segmented Sieve
vector<long long> vecPrime(long long r){
      vector<long long> primes;
      vector<bool> sieve(r+1,true);
      for(int i = 2;i*i<=r;i++){
          for(int j = i*i;j<=r;j+=i){
              if(sieve[j]){
                  sieve[j] = false;
              }
          }
      }
      for(int i = 2;i<=r;i++){
          if(sieve[i]){
              primes.push_back(i);
          }
      }
      return primes;
  }
  long long primeProduct(long long L, long long R){
      // code here
      vector<bool> sieve(R-L+1,true);
      vector<long long> primes = vecPrime(sqrt(R));
      
      for(int i = 0;i<primes.size();i++){
          int j = (L/primes[i])*primes[i];
          if(j<L) j+=primes[i];
          if(j == primes[i])  j+=primes[i];
          for(;j<=R;j+=primes[i]){
              sieve[j-L] = false;
          }
      }
      
      long long product = 1;
      
      for(int i = 0; i<(R-L+1); i++){
          if(sieve[i]){
              product=(product*(i+L))%(1000000007);
          }
      }
      
      return product;
  }
