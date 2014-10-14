#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,bowl,plate;
	cin >> n >> bowl >> plate;
	int count = 0;
	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		if(temp == 1){
			if(bowl > 0) bowl--;
			else count++;
		}
		else{
			if(plate > 0) plate--;
			else if(bowl > 0) bowl--;
			else count++;
		}
	}
	cout << count << endl;
}