#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	t = 1;
	while(t--){
 		int n,k;
 		cin >> n >> k;
        int count = 0 ;
 		for(int i =0;i<n;i++){
 			int a; 
 			cin >> a;
 			if(5-a >= k) count++;
 		}
 		cout << count/3 << endl;
	}
	return 0;
}