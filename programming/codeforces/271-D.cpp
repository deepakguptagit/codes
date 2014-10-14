#include<bits/stdc++.h>
using namespace std;

#define MAX 2002

int mat[MAX][MAX];

int main(){
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> mat[i][j];
		}
	}

	for(int i=0;i<n;i++){
		if(mat[i][i] != 0){
			cout << "NO" << endl;
			return 0; 
		}
	}

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(mat[i][j] != mat[j][i] || mat[i][j] == 0){
				cout << "NO" << endl;
				return 0; 
			}
		}
	}

	cout << "YES" << endl;

}