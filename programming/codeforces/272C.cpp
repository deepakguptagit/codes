#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n,req,tab;
	cin >> n >> req >> tab;
	int x = req*tab;
	int arr[1002];
	for(int i=0;i<n;i++) cin >> arr[i];
	sort(arr,arr+n);
	reverse(arr,arr+n);
	int i;
	for(i=0;i<n;i++){
		if(x > arr[i]) {
			x -= arr[i];
		}
		else if(x != 0){
			x = 0;
			break;
		}
		else {
			i--;
			break;
		}
	}	
	cout << i+1 << endl;

}