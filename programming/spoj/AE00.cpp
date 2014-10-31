#include<bits/stdc++.h>
using namespace std;

#define MAX 10002

int ans[MAX];

void pro(){
	memset(ans,0,sizeof(ans));
	ans[0] = 0;
	ans[1] = 1;
	for(int i=2;i<MAX;i++){
		int sq = sqrt(i);
		for(int j=1;j<=sq;j++){
			if(i%j == 0) ans[i]++;
		}
	}
	for(int i=1;i<MAX;i++)
	{
		ans[i] += ans[i-1];
	}
}

int main(){
	pro();
	int n;
	cin >> n;
	cout << ans[n] << endl;
	return 0;
}