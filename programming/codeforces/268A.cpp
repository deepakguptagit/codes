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

int main(){
	int p,q,l,r;
	cin >> p >> q >> l >> r;
	int timeHash[MAX] = {0};
	for(int i=0;i<p;i++){
		int a,b;
		cin >> a >> b;
		for(int i=a;i<=b;i++){
			timeHash[i] = 1;
		}
	}
	set<int> s;
	for(int i=0;i<q;i++){
		int a,b;
		cin >> a >> b;
		for(int t =l;t<=r;t++){
			if(a+t > 1000) break;
			for(int i=a+t;i<=b+t;i++){
				if(i > 1000) break;
				if(timeHash[i]) s.insert(i);
			 }
			}
	}
	cout << s.size() << endl;
	return 0;
}