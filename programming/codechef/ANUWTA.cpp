#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long t,n,ans;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		ans=(((n)*(n+1))/2)+n;
		printf("%lld\n",ans);
	}
	return 0;
}