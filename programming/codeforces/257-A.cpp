#include<bits/stdc++.h>
using namespace std;

long long findCost(long long n,long long m,long long k){
	if(n>m) swap(n,m);
	if(n == 1) return (m-k);
	if(k==0) return m*n;
	if(k == 1) return n*(m/2);
	int isOdd = 0;
	if(m%2 == 1) isOdd = 1;
	return findCost(n,m/2  + isOdd,k-1);

}

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


long long findCost2(long long n,long long m,long long k){
	if(n>m) swap(n,m);
	if(k>m-1) return n/(k-m+1);
	return (m/(k+1))*n ; 

}

int main(){
	int t;
	t = 1;
	while(t--){
        long long n,m,k;
        cin >> n >> m >>  k;
        if(k<=(n+m -2)) {
           cout << findCost2(n,m,k) << endl;
        }
        else{
        	cout << -1 << endl;
        }
	}
	return 0;
}

/*
    if cuts > m :  (n/2**k)
    else ans = (m/(2**k))*n
*/