#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		int temp = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int x; cin >> x;
				temp ^= x;
			}
		}
		if(temp) cout << "FIRST\n";
		else cout << "SECOND\n"; 
	}
}