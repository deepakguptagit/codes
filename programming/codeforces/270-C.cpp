#include<bits/stdc++.h>
using namespace std;

string getCur(pair<string,string> p,int a){
	if(a == 1) return p.first;
	else return p.second;
}


int main(){
	int n;
	cin >> n;
	std::vector<pair<string,string> > f;
	
	for(int i=0;i<n;i++){
		string a,b;
		cin >> a >> b;
		f.push_back(make_pair(a,b));
	}
	
	int p = n;
	std::vector<pair<string,string> > v;
	
	for(int i=0;i<p;i++){
		int temp;
		cin >> temp;
		v.push_back(f[temp-1]);
		//cout << f[temp-1].first << " " << f[temp-1].second << endl;
	}

	int curSelected = -1;
	if(v[0].first < v[0].second) curSelected = 1;
	else curSelected = 2;
	for(int i=1;i<n;i++){
		if((v[i].first > getCur(v[i-1],curSelected)) 
			&& (v[i].second > getCur(v[i-1],curSelected))){
			if(v[i].first < v[i].second) curSelected = 1;
		  else curSelected = 2;
		}
		else if((v[i].first > getCur(v[i-1],curSelected))){
			curSelected = 1;
		}
		else if((v[i].second > getCur(v[i-1],curSelected))){
			curSelected = 2;
		}
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;

}