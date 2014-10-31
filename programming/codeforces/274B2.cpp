#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	vector< pair<int,int> > info,ans;
	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		info.push_back(make_pair(temp,i+1));
	}
	sort(info.begin(),info.end());
	while(k!=0){
		if(info[n-1].first - info[0].first < 2) break;
	  ans.push_back(make_pair(info[n-1].second,info[0].second));
		info[n-1].first -= 1;
		info[0].first += 1;
		k--;
		sort(info.begin(),info.end());
	}
	sort(info.begin(),info.end());
	cout << info[n-1].first - info[0].first << " " << ans.size() << endl; 
	for(auto i : ans){
		cout << i.first << " " << i.second << endl;
	}
}