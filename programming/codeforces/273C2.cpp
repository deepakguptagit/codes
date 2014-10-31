#include <bits/stdc++.h>
using namespace std;

/*
    @author deepakgupta
*/

long long rec(long long a[]){
  sort(a,a+3);
  if(a[0] == 0 && a[1] == 0) return 0;
  if(a[1] == 1 && a[2] == 1) return 0;
  cout << a[0] << " " << a[1] << " " << a[2] << endl;
  long long ans1 = 0;
  if(a[0] != 0){
    ans1 += a[0];
    long long temp = a[0];
    a[1] -= a[0];
    a[2] -= a[0];
    a[0] = 0;
    ans1 += rec(a);
    a[1] += temp;
    a[2] += temp;
    a[0] = temp;
  }
  long long ans2 = min(a[1],a[2]/2);
  a[1] -= min(a[1],a[2]/2);
  a[2] -= 2*min(a[1],a[2]/2);
  ans2 += rec(a);
  return max(ans1,ans2);

}

int main(){
    ios_base::sync_with_stdio(false);
    long long arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    cout << rec(arr) << endl;

}