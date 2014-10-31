#include<iostream>
using namespace std;



int main()
{
  srand ( time(NULL) );
	  
	cout << 1 << endl;
	cout << 100 << endl;
	for(int i=0;i<100;i++){  cout << roll(1,100000) << " ";}
	cout << endl;
	return 0;
}
