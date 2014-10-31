#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[1001],p;
        for(int i=0;i<n;i++) cin >> arr[i];
        cin >> p;
        int i,j;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                int key = p-arr[i]-arr[j];
                int var1 = arr[i]; arr[i] = INT_MAX;
                int var2 = arr[j]; arr[j] = INT_MAX;
                bool pos = binary_search(arr,arr+n,key);
                if(pos){
                    cout << "YES" << endl;
                    break;
                }
                arr[i] = var1;
                arr[j] = var2;
            }
            if(j!=n) break;
        }
        if(i==n) cout << "NO" << endl;
    }
    return 0;
}
