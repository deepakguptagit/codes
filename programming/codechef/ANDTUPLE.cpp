#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		long long n,k;
		cin >> k >> n;
		int count = 1;
		if(n%2 == 0) count++;
		if(n%3 == 0) count++;
		if( k == 4 && n%4 == 0) count++;
		cout << count << endl;
	}
}