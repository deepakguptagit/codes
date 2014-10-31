#include <bits/stdc++.h>
using namespace std;

int find(int cnt,int prime){
	int i = prime;
	for(i=prime;i-(i/prime)<cnt;i+=prime);
	return i-(i-(i/prime)-cnt)-1;
}

int main(){
	ios_base::sync_with_stdio(false);
	int cnt1,cnt2,x,y;
	cin >> cnt1 >> cnt2 >> x >> y;
	int ans1 = find(cnt1,x);
	cnt2 = cnt2 + cnt1 - ans1/y;
 	int ans2 = find(cnt2,y);
  int ans3 =  max(ans1,ans2); 
  swap(x,y);
	swap(cnt1,cnt2);
	int ans4 = find(cnt1,x);
	cnt2 = cnt2 + cnt1 - ans1/y;
 	int ans5 = find(cnt2,y);
  int ans6 =  max(ans4,ans5);
  cout << min(ans3,ans6) << endl;

}