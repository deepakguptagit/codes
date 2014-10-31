#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cassert>
using namespace std;
 
#define DEBUG //on-off switch for prlling statements
 
// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
 
// Useful constants
#define EPS                         1e-10
 
// Useful hardware instructions
#define bitcount1                    __builtin_popcount1
#define gcd                         __gcd
 
// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(ll i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((ll)(a.size()))
 
// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
 
#define ll long long int
#define llu long long unsigned
#define ld long
#define INF 1000000000000000
#define mod 1000000007
 #define llu long long unsigned
#define ld long
#define F first
#define S second
ll dp[200001];			
ll sum[200001];

int main()
{
	int t;
	cin >> t;
	int k;
	cin >> k;
	dp[0]=1;
	fill(sum,0);
	for(int i=1;i<=100000;i++)
	{
		dp[i]=dp[i-1];
		if(i>=k)
		dp[i] = (dp[i]+dp[i-k])%mod;
	}
	sum[0]=1;
	for(int i=1;i<=100000;i++)
	sum[i] = (sum[i-1]+dp[i])%mod;
	int a,b;
	for(int i=0;i<t;i++)
	{
			cin >> a >> b;
			cout << ((sum[b]-sum[a-1])%mod+mod)%mod<< endl;
	}
}