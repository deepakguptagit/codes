#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
   int g,b;
   cin >> g >> b;
   while(true)
   {
       if(g == 0 || b == 0) break;
       cout << "GB"; g--; b--;
   }
   while(g-- > 0){
       cout << "G";
   }
   while(b-- > 0) cout << "B";
   cout << endl;
}