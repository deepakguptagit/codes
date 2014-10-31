#include<bits/stdc++.h>
using namespace std;

#include<string.h>
#define MAX 65000
int isprime[MAX/32+2];

#define isSet(n) (isprime[n>>5]&(1<<(n&31)))
#define unset(n) (isprime[n>>5] &= ~(1<<(n&31)))

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


vector<int> primes;

void genprimes(){
   sieve();
   primes.push_back(2);
   for(int i=3;i<MAX;i++){
   	  if(isSet(i)) primes.push_back(i);
   }
}

int main(){
	genprimes();
	int t;
	t  = 1;
	while(t--){
		int n;
		cin >> n;
		cout << primes[n-1] << endl;
	}
	return 0;
}