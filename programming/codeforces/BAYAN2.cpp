#include <bits/stdc++.h>
using namespace std;

string row;
string col;


int mat[22][22],n,m,visited[22][22];


int check(int a,int b){
	if(a<0 ||  a>=n || b<0 || b>=m) return 0;
	mat[a][b] = 1;
	visited[a][b] = 1;

	if(row[a] == '>') { 
		if(a<0 ||  a>=n || b+1<0 || b+1>=m) {

		}
		else{

			mat[a][b+1] = 1;
			if(!visited[a][b+1])
				check(a,b+1);
		}
	}

	else{
		if(a<0 ||  a>=n || b-1<0 || b-1>=m){ 
			
		}
		else{
			mat[a][b-1] = 1;
			if(!visited[a][b-1])
				check(a,b-1);
		}
	}

	if(col[b] == '^') {

	   if(a-1<0 ||  a-1>=n || b<0 || b>=m) {
	   		
		 }
		 else{
		 	mat[a-1][b] = 1;
			if(!visited[a-1][b])
			 check(a-1,b);
		 }

	}

	else{

		if(a+1<0 ||  a+1>=n || b<0 || b>=m) {
		
		}
		else
		{
			mat[a+1][b] = 1;
			if(!visited[a+1][b])
				check(a+1,b);
		}
	}
}

int isMatOne(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mat[i][j] == 0) return 0;
		}
	}
	return 1;
}

int main(){
	
	cin >> n >> m;

	cin >> row;
	cin >> col;

	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			memset(mat,0,sizeof(mat));
			memset(visited,0,sizeof(visited));
			check(a,b);
			if(!isMatOne()){
				cout << "NO\n"; 
				return 0;
			}
		}
	}

	cout << "YES\n";
	return 0;

}