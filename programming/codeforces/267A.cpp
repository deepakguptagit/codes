#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

#define MAX 1002

int differ(int a,int b){
	int count = 0;
	while( a!=0 && b!=0){
		if((a&1) != (b&1)) count++;
		a = a>>1;
		b = b>>1;
	}
	while(a!=0){
		if((a&1))count++;
		a = a>>1;
	}
	while(b != 0){
		if((b&1)) count++;
		b = b>>1;
	}
	return count;
}

int main(){
	int n,m,k,count = 0;
	cin >> n >> m >> k;
	int arr[MAX];
	for(int i=0;i<=m;i++){
		cin >> arr[i];
	}
	for(int i=0;i<m;i++){
		//cout << differ(arr[i],arr[m]) << endl;
		if(differ(arr[i],arr[m]) <= k) count++;
	}
	cout << count << endl;
}