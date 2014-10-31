#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n,m,k;
	cin >> n >> m >> k;
	cout << (m*(m-1))/2 << endl;
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			int temp; cin >> temp;
			if(k == 0){
				cout << i << " " << j << endl;
			}
			else cout << j << " " << i << endl;
		}
	}
}