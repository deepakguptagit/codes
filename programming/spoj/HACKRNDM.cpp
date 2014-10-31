#include<bits/stdc++.h>
using namespace std;


int main(){

	set<int> s;
	int n,temp,k,c=0;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		int temp; cin >> temp;
		if(s.find(temp-k) != s.end()) c++;
		if(s.find(temp+k) != s.end()) c++;
		s.insert(temp);
	}
	cout << c << endl;

}