#include<bits/stdc++.h>
using namespace std;

#define MAX 2002

int main(){
	int n,k;
	cin >> n >> k;
	int arr[MAX];
	for(int i=0;i<n;i++) cin >> arr[i];
  sort(arr,arr+n);
  long long ans=0;
  int i = n-1;
  while (i>=0)
  {
      ans += (arr[i]-1)*2;
      i -= k;
  }
  cout<<ans << endl;;
}