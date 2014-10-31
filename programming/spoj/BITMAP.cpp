#include<bits/stdc++.h>
using namespace std;

#define MAX 1000002

int main(){
  
  while(true){
    int n;
    cin >> n;
    if(n == 0) break;
    int arr[MAX],hash[MAX];
    for(int i=0;i<n;i++){
      cin >> arr[i]; arr[i]--; hash[arr[i]] = i;
    }
    int flag = 1;
    for(int i=0;i<n;i++){
      if(arr[i] != hash[i]) flag = 0;
    }
    if(flag) cout << "ambiguous" << endl;
    else cout << "not ambiguous" << endl;
  }

  return 0;
}