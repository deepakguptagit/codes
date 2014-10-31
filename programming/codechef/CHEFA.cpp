#include<iostream>
#include<cstring>
#include<random>
#include<map>
#include<bits/stdc++.h>
using namespace std;

#define MAX 1000005
int isprime[MAX/32+2];

#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31));

inline int gcd(int a, int b)
{
   int temp;    
   while(b)
   {
           temp=a;
           a=b;
           b=temp%b;
   }
   return a;
}

void sieve()
{
    int i,j;
    isprime[0]=0xA28A28AC;
    for(int i=1;i<=MAX/32+1;i+=3)
    {
            isprime[i]  =0x28A28A28;
            isprime[i+1]=0x8A28A28A;
            isprime[i+2]=0xA28A28A2;
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


map<int,int> st;

int ansVal[MAX];

long long pollard_r, pollard_n;
inline long long f(long long val) { return (val*val + pollard_r) % pollard_n; }
inline long long myabs(long long a) { return a >= 0 ? a : -a; }

long long pollard(long long n) {
    srand(unsigned(time(0)));
    pollard_n = n;

    long long d = 1;
    do {
        d = 1;
        pollard_r = rand() % n;

        long long x = 2, y = 2;
        while(d == 1)
            x = f(x), y = f(f(y)), d = __gcd(myabs(x-y), n);
    } while(d == n);

    return d;
}

map<int,int> factors;


void factorise(int n)
{
	while(!(n%2))
	{
			factors[2]++;
			n/=2;
	}
	
	if(n==1)
		return;
	else if(n==2263)
	{
		factors[31]++;
		factors[73]++;
	}
	else if(isSet(n))
	{
		factors[n]++;
	}
	else
	{
		
		int factor=pollard(n);
		factorise(factor);
		factorise(n/factor);
	}
}

int main()
{
	sieve();
	int t;
	cin>>t;
	while(t--)
	{	
		memset(ansVal,0,sizeof(ansVal));
		int n;
		cin>>n;
		for(int i =0 ;i<n;i++){
			int temp; 
			cin >> temp;
			factors.clear();
			factorise(temp);
			//cout << "factors of :" << temp << endl;
			for(auto i: factors){
				//cout << i.first << " " << i.second << endl;
				ansVal[i.first] = max(ansVal[i.first],i.second);
			}
	  }
		int count = 0;
		for(int i=2;i<MAX;i++){
			count += ansVal[i];
		}
		cout << count << endl;	
	}
}