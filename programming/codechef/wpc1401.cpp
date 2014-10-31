#include<bits/stdc++.h>
using namespace std;

#define MOD n

long long n;

long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
    		if(b%2 == 1){
    		x = (x+y)%c;
    		}
    		y = (y*2)%c;
    		b /= 2;
    		}
    	return x%c;
   	 }

long long modulo(long long a,long long b,long long c){
    long long x=1,y=a;
    while(b > 0){
    	if(b%2 == 1){
   	      x = mulmod(x,y,c);
    	}
    	y =mulmod(y,y,c);
    	b /= 2;
    	}
    return x%c;
    }

    
long long modulo_inverse(long long f){
  return modulo(f,MOD-2,MOD);
}    


long long ans(long long x,long long m){
	if( m == 0) return 1;
	if( x < 1) return 0;
	if( m == 1 ) return (1+x)%n;
	if( x== 1) return (m+1)%n; 
	long long sub = 0;
	if(m%2 == 0 ){
		m++;
		sub = modulo(x,m,n);
	}
	long long sol  = (mulmod(1+x,ans((x*x)%n,m/2),n) - sub);
	if(sol < 0) sol = sol*(1-n);
	return sol%n;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		long long m,x;
		cin >> x >> m >> n;
		cout << ans(x,m) << endl;

 	}

}