#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int cnt = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if((i+j)%2 == 0) {cnt++;}
		}
	}
	cout << cnt << endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if((i+j)%2 == 0) {cout << "C"; cnt++;}
			else cout << ".";
		}
		cout << endl;
	}
} 