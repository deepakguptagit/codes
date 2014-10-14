#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		
		int n, d[10002];
		std::vector<int> vil,din;
		cin >> n;

		for(int i=0;i<n;i++) 
		{
			cin >> d[i];
			if(d[i] > 0) vil.push_back(i);
			else din.push_back(i);
		}

		int curVil = 0,ans = 0;
		for(int i=0;i<din.size();i++){
			while(d[din[i]] != 0){
				if(d[vil[curVil]] <= abs(d[din[i]])){
					ans += d[vil[curVil]]*abs(vil[curVil] - din[i]);
					d[din[i]] += d[vil[curVil]];
					curVil++;
				}
				else{
					d[vil[curVil]] += d[din[i]];
					ans += abs(d[din[i]])*abs(curVil - din[i]); 
					d[din[i]] = 0;
				}
			}
		}
		cout << ans << endl;
	}
}