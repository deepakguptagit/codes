#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;
int a[maxn],b[maxn],n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=n;i++)	if(i<=(n>>1) || a[i]<b[n-i+1])putchar('1');else putchar('0');cout << endl;
	for(int i=1;i<=n;i++)	if(i<=(n>>1) || b[i]<a[n-i+1])putchar('1');else putchar('0');cout << endl;
	return 0;
}