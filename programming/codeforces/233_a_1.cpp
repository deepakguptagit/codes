#include <iostream>
using namespace std;

#define MAX 100000

int main()
{
    int ugly[MAX];
    memset(ugly,0,sizeof(ugly));
    
    for(int i=2;i<MAX;i+=2){
        ugly[i]++;
    }
    
    for(int i=3;i<MAX;i+=3){
        ugly[i]++;
    }
    
    for(int i=5;i<MAX;i+=5){
        ugly[i]++;
    }
    
    for(int i=1;i<MAX;i++){
        if(ugly[i] == 3) ugly[i] = ugly[i-1] + 1;
        else ugly[i] = ugly[i-1];
    }
    
    int t;
    cin >> t;
    
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        cout << ugly[i] << endl;
    }
}
