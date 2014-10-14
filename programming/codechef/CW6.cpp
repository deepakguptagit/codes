#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000

int isprime[MAX/32+2],coprime[MAX],ans[MAX];

#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31));

void sieve()
{
    int i,j;
    memset(isprime,-1,sizeof(isprime));
    unset(0);
    unset(1);
    unset(4);

    for(i=6;i<=MAX;i+=6)
    {

            unset(i);
            unset(i+2);
            unset(i+3);
            unset(i+4);
    }
    for(i=5;i*i<=MAX;i+=2)
                           if(isSet(i))
                             {
                                        for(j=i*i;j<=MAX;j+=i)
                                                unset(j);
                             }
}

std::vector<int> primes;

void genprimes(){
	sieve();
	for(int i=2;i<MAX;i++){
		if(isSet(i)) primes.push_back(i);
	}
}

int phi(const int n)
{
  // Base case
  if ( n < 2 )
    return 0;
 
  // Lehmer's conjecture
  if ( isSet(n) )
    return n-1;
 
  // Even number?
  if ( n & 1 == 0 ) {
    int m = n >> 1;
    return !(m & 1) ? phi(m)<<1 : phi(m);
  }
 
  // For all primes ...
  for ( std::vector<int>::iterator p = primes.begin();
        p != primes.end() && *p <= n;
        ++p )
  {
    int m = *p;
    if ( n % m  ) continue;
 
    // phi is multiplicative
    int o = n/m;
    int d = __gcd(m, o);
    return d==1? phi(m)*phi(o) : phi(m)*phi(o)*d/phi(d);
  }
}

int main()
{
	
	genprimes();
	
	
	for(int i=0;i<primes.size();i++){
		for(int j=primes[i];j<MAX;j+=primes[i]){
			coprime[j]++;
		}
	}
	
	for(int i=0;i<10;i++) ans[i] = 1;
	
	ans[10] = 1;
	
	for(int i=11;i<MAX;i++){
		if(ans[i-coprime[i]] == 1 || ans[i - phi(i)] == 1) ans[i] = 2;
		else ans[i] = 1;
	}
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(ans[n] == 1) cout << "Bob\n";
		else cout << "Alice\n";
	}
	
}