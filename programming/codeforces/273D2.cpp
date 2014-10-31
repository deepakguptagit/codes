#include <bits/stdc++.h>
using namespace std;


long long rec(int r,int g,int cur){
	cout << "called with : " << r << " " << g << endl;
	if(r >= cur && g>=cur) return rec(r-cur,g,cur+1)*rec(r,g-cur,cur+1);
	else if(r >=cur) return rec(r-cur,g,cur+1);
	else if(g >=cur) return rec(r,g-cur,cur+1);
	else return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	int r,g;
	cin >> r >> g;
	if(r == 0 || g == 0){
		cout << 1 << endl;
	}
	cout << rec(r,g,1) <<  endl;
	
}