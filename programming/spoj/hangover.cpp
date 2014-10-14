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

#define MAX 100002

int main(){
	double hash[MAX];
	for(int i=1;i<MAX;i++){
		hash[i] = hash[i-1] + (1.0/(i+1));
		if(hash[i] > 5.3) break;
	}
	double n = 1;
	cin >> n;
	while(n!=0){
		int ans = 1;
		while(hash[ans] < n) ans++;
		cout << ans << " card(s)" <<endl;
		cin >> n;
	}

}