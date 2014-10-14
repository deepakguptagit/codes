#include <iostream>
using namespace std;


#define MAX 1002
char mat[MAX][MAX];

void pro(){
  for(int i=0;i<MAX;i++){
  	if(i%2 == 0)
  		mat[i][0] = 'L';
  	else mat[i][0] = 'W';	
  }	
  for(int i=0;i<MAX;i++){
  	if(i%2 == 0)
  		mat[0][i] = 'L';
  	else mat[0][i] = 'W';	
  }	
  for(int i=1;i<MAX;i++){
  	for(int j=1;j<MAX;j++){
  		if(mat[i-1][j] == 'L' || mat[i][j-1] == 'L' || mat[i-1][j-1] == 'L'){
  			mat[i][j] = 'W';
  		}
  		else mat[i][j] = 'L';
  	}
  }
	
}
int main()
{
    pro();
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++){
        cout << mat[i][j] << " ";
      }
      cout << endl;
    }
    int q;
    cin >> q;
    while(q--){
    	int a,b;
    	cin >> a >> b;
    	if(mat[a][b] == 'W'){
    		cout << "Ashima" << endl;
    	}
    	else cout << "Aishwarya" << endl;
    } 
    return 0;
}
