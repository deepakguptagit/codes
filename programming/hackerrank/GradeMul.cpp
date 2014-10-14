#include<bits/stdc++.h>
using namespace std;

int countDig(long long a){
	int count = 0;
	while(a!=0){
		count++;
		a/=10;
	}
	return count;
}

string reverses(string a){
	string ans  = "";
	for(int i=a.size() -1; i>=0 ;i--){
		ans += a[i];
	}
	return ans;
}

string itoa(long long a){
	string ans = "";
	while(a!=0){
		ans = ans.append(" ");
		a/=10;
	}
	return reverses(ans);
}

int main(){
	long long a,b;
	cin >> a >> b;
	while(a!=0 && b!=0){
		
		long long mul = a*b;
		int digmul = countDig(mul);
		int diga = countDig(a), digb = countDig(b);
		string dash = "",as = itoa(a), bs= itoa(b), muls = itoa(mul);
		for(int i=0;i<digmul-diga;i++){
			as = " " + as;
		}
		for(int i=0;i<digmul-digb;i++){
			bs = " " + bs;
		}

		for(int i=0;i<digmul;i++){
			dash += " ";
		}
		cout << as << endl << bs <<  endl << dash << endl;
	}	
	return 0;
}