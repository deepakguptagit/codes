#include <bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	int t;
	t =  2;
	int n;
	while(cin >> n){
		string s;
		cin >> s;
		for(int i=0;i<n;i++){
			string temp;
			cin >> temp;
			int start_position_to_erase = s.find(temp);
			while(start_position_to_erase != -1){
			 s.erase(start_position_to_erase, temp.length());
			 start_position_to_erase = s.find(temp);
			}
		}
		if(s == "") s = "0";
		cout << s << endl;
	}
}