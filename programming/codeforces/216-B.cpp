#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n,k,l,r,sall,sk;
	cin >> n >> k >> l >> r >> sall >> sk;
	
	int var = sk/k;
	int rem = sk - var;

	for(int i=0;i<rem;i++) cout << sk-var << " ";
	for(int i=0;i<var-rem;i++) cout << var << " ";
	
	

}