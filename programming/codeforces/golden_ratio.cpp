#include<bits/stdc++.h>
using namespace std;


#define MAX 1001

double golden[MAX];

void pro(){
	golden[0] = 0;
	golden[1] = (1 + sqrt(5.0))/2;
	for(int i=2;i<MAX;i++) golden[i] = golden[i-1] + golden[i-2];
}

double convertToDecimal(string g){
	cout << "bug: " << g << endl;
	double ans  = 0;
	for(int i=g.size()-1;i>=0;i--){
		ans  = ans*10 + golden[g.size()-1-i]*(g[i]-48);
		cout << i << " : " << ans << endl;
		if(ans > 1000000000000000000) return -1;
	}
	return ans;
}

char method1(string a,string b){
	// if a > b return > else <
	if(a.size() < b.size()) swap(a,b);
	for(int i=0;i<a.size()-b.size();i++) b = "0" + b;
	for(int i=0;i<a.size();i++){
		if(a[i] > b[i]) return '>';
		if(a[i] < b[i]) return '<';
	}
	return '=';
}

char method2(string a,string b){
	double al = convertToDecimal(a);
	double bl = convertToDecimal(b);
	cout << al << " " << bl << endl;
	if(al == -1 || bl == -1) return ' ';
	if(al > bl) return '>';
	else if(al < bl) return '<';
	else return '=';
}

int main(){
	pro();
	for(int i=0;i<85;i++) cout << golden[i] << endl;
	return 0;
}