#include<bits/stdc++.h>
using namespace std;


int main(){
	std::vector<int> v;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int temp; cin >> temp;
		v.push_back(temp);
	}	
	for(auto i : v){
		cout << i << " " ;
	}
}

