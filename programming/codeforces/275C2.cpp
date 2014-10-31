#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n,k,temp;
	cin >> n >> k;
	temp = k;
	vector<int> f,r;
	for(int i=1;i<=n;i++){
		f.push_back(i);
	}
	r = f;
	reverse(r.begin(),r.end());
	int flag = 0,valf = 0, valr = 0, last = 0;
	while(k--){
		if(!flag){
			last = f[valf];
			cout << f[valf++] << " ";
			flag = 1;
		}
		else{
			last = r[valr];
			cout << r[valr++] << " ";
			flag = 0;
		}
	}
	for(int i=1;i<=n-temp;i++){
		if(!flag) --last;
		else ++last;
		cout << last <<" ";
	}
	return 0;
}