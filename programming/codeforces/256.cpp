#include<bits/stdc++.h>
using namespace std;


int main(){
	std::vector< pair<int,int> > index;
	
	int n,freq[2002] = {0};
	cin >> n;
	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		index.push_back(make_pair(temp,i+1));
		freq[temp]++;
	}
	sort(index.begin(),index.end());

	int count = 0,ans = 0;
	std::vector<int> v;
	int case1 = 0;
	for(int i=2001;i>=0;i--){
		if(freq[i] >= 4){
			case1 = 1;
			v.clear();
			v.push_back(i);
			break;
		}
		if(freq[i] >= 2){
			v.push_back(i);
		}
		if(v.size() == 2) break;
	}


	if(case1 == 0 && v.size() < 2){
		cout << "NO" << endl;
		return 0;
	}

	v.push_back(v[0]);

	int x=0,y = 0,z=0,k = 0;
	for(int i=0;i<n;i++){
		if(y==0 && index[i].first == v[0]){
			if(x == 0) x = index[i].second;
			else y = index[i].second;
			continue;
		}
		if(index[i].first == v[1]){
			if(z == 0) z = index[i].second;
			else k = index[i].second;
		}
	}

	//cout << x << " " << y << " " << z << " "  << k << endl; 

	cout << "YES" << endl;

	for(int i=0;i<n;i++){
		cout << index[i].second << " ";
	}
	cout << endl;

	for(int i=0;i<n;i++){
		if(index[i].second == x) cout << y << " ";
		else if(index[i].second == y) cout << x << " ";
		else cout << index[i].second << " ";
	}
	cout << endl;
	

	for(int i=0;i<n;i++){
		if(index[i].second == z) cout << k << " ";
		else if(index[i].second == k) cout << z << " ";
		else cout << index[i].second << " ";
	}
	cout << endl;
	



}