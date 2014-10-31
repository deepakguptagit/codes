#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int a,b,c;
	cin >> a >> b >> c;
	int d = max(a*b*c, (a*b)+c);
	int e = max((a+b)*c,a+b+c);
	int f = max(a*(b+c),a+(b*c));
	cout << max(d,max(e,f)) << endl;
}