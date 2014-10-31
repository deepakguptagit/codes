#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int d = 0,maxVal = INT_MIN;
	
	for(int i=0;i<n;i++){
		int temp; cin >> temp;
		if(i == 0) d = temp;
		else d = __gcd(temp,d);
		maxVal = max(maxVal,temp);
	}

	int count = maxVal/d - n;
	if(count%2==0) cout << "Bob\n";
	else cout << "Alice\n";
}