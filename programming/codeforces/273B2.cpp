#include <bits/stdc++.h>
using namespace std;

/*
	@author deepakgupta

*/

long long find(long long n){
	if(n == 0 || n == 1) return 0;
	long long x = n-1;
	if(n%2 == 0) n/=2;
	else x/=2 ;
	return n*x;
}


int main(){
	ios_base::sync_with_stdio(false);
	long long n,m;
	cin >> n >> m;
	long long kmax = INT_MIN, kmin = 0;
	kmax = find(n-m+1);
	long long minPlayer = n/m;
	long long extra = n%m;
	long long i;
  kmin += extra*find(minPlayer+1);
	kmin += (m-extra)*find(minPlayer);
	
	cout << kmin << " " << kmax << endl;
}