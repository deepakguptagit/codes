#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
#define VAL 100
double dp[MAX][MAX];

int main(){
	
	string orig,rec;
	cin >> orig;
	cin >> rec;
	int pos = VAL;
	for(int i=0;i<orig.size();i++){
		if(orig[i] == '+') pos++;
		else pos--;
	}

	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++) dp[i][j] = 0;
	}

	if(rec[0] == '+'){
		dp[0][VAL+1] = 1.0;

	}
	else if(rec[0] == '-'){
		dp[0][VAL-1] = 1.0;
	}
	else{
		dp[0][VAL+1] = 0.5;
		dp[0][VAL-1] = 0.5;
	}


	for(int i=1;i<rec.size();i++){
		for(int j=0;j<3*VAL;j++){
			if(dp[i-1][j] !=0){
				if(rec[i] == '+'){
					dp[i][j+1] += dp[i-1][j];
				}
				else if(rec[i] == '-'){
					dp[i][j-1] += dp[i-1][j];
				}
				else{
					dp[i][j+1] += dp[i-1][j]*0.5;
					dp[i][j-1] += dp[i-1][j]*0.5;
				}
			}
		}
	}


	printf("%0.100f\n",dp[rec.size()-1][pos]);



}