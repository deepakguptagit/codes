#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string bus[7];
    bus[0] = "+------------------------+";
    bus[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
  bus[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
  bus[3] = "|#.......................|";
  bus[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
  bus[5] = "+------------------------+";
  

  if(n==0){
  	for(int i=0;i<6;i++) cout << bus[i] << endl;
  	return 0;	
  }

    int curRow = 1;
  if(n==1){
    bus[1][1]  = 'O';
  }
  else if(n==2){
    bus[1][1]  = 'O';
    bus[2][1]  = 'O';
  }
  else if(n==3){
    bus[1][1]  = 'O';
    bus[2][1]  = 'O';
    bus[3][1]  = 'O';

  }
  else if(n==4){
    bus[1][1]  = 'O';
    bus[2][1]  = 'O';
    bus[3][1]  = 'O';
    bus[4][1]  = 'O';
  }
  else{
    bus[1][1]  = 'O';
    bus[2][1]  = 'O';
    bus[3][1]  = 'O';
    bus[4][1]  = 'O';
    n -= 4;
    while(n!=0){
        curRow += 2;
        if(n >= 3){
        bus[1][curRow]  = 'O';
        bus[2][curRow]  = 'O';
        bus[4][curRow]  = 'O';
        n -= 3;
      }
      else if(n == 2){
        bus[1][curRow]  = 'O';
        bus[2][curRow]  = 'O';
        n -= 2;
      }
      else if( n== 1){
        bus[1][curRow]  = 'O';
        n -= 1;
      }
      else{
        //nop;
      }

    }
  }
  for(int i=0;i<6;i++) cout << bus[i] << endl;
}