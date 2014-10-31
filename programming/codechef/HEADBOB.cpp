#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i=0;i<n;i++){
		if(s[i] == 'Y'){
			cout << "NOT INDIAN\n"; 
			return;
		}
		else if(s[i] == 'I'){
			cout << "INDIAN\n";
			return;
		}
	}
	cout << "NOT SURE\n";
	return; 
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}