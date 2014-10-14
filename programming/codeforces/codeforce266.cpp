#include<bits/stdc++.h>
using namespace std;

#define MAX 100002

int main(){
	int n;
	cin >> n;
	int arr[MAX];
	long long sum = 0,p1 =0,p2= 0,p3=0;
	for(int i=0;i<n;i++) { cin >> arr[i]; sum += arr[i]; }
	int j = n-2, i= 1;
	p1 = arr[0]; p2 = sum - arr[0] - arr[n-1]; p3 = arr[n-1];
	long long ways = 0;
	long long x = 1,y =1,flag =1;
	while(j > i){
		if(flag && p1==p2 && p2 == p3){
			x = y = 1;
		while(arr[i] == 0 && i < j) {x++; i++; }
		while(arr[j] == 0 && j > i) {y++; j--; }
		if(p1==p2 && p2 == p3) ways = ways + x*y;
		flag = 0;
		}
		int minpart=5;
		if( p1 < p2 && p1 < p3) minpart = 1;
		if( p2 > p3 && p3 < p1) minpart = 3;
		if(minpart == 1){
			p1 += arr[i];
			p2 -= arr[i];
			i++;
		}
		else{
			p3 += arr[j];
			p2 -= arr[j];
			j--;
		}
		x = y = 1;
		while(arr[i] == 0 && i < j) {x++; i++; }
		while(arr[j] == 0 && j > i) {y++; j--; }
		if(p1==p2 && p2 == p3) ways = ways + x*y;

	}
	cout << ways << endl;
	return 0; 
}