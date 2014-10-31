#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	int arr[200002], cntl[200002] = {0},cntr[200002] = {0},cntl1[200002] = {0},cntr1[200002] = {0};
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	for(int i=0;i<n;i++){
		if(arr[i] == 0){
			cntl1[i] = cntl1[i-1] + 1;
 		}
	}
	for(int i=n-1;i>=0;i--){
		if(arr[i] == 1){
			cntr1[i] = cntr1[i+1] + 1;
 		}
	}
	long long ans = 0;
	int l = 0, r= n-1,cl = 0, cr = 0;
	while(l<n && arr[l] != 0) l++;
	while(r>=0 && arr[r] != 1) r--;
	while( l < n || r >= 0){
		if(l < n){
		ans += cntr1[l]-cntr[l];
		if(l!=0)
			cntl[l] += cntl[l-1] + 1;
	  }
	  if(r >= 0){
		ans += cntl1[r]- cntl[r];
		cntr[r] = cntr[r+1] + 1;
	  }
		while(l<n && arr[l] != 0) l++;
		while(r>=0 && arr[r] != 1) r--;
	}
	cout << ans << endl;
}