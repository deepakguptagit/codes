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

#define MAX 10002

int main(){
	int n;
	cin >> n;
	while(n!=-1){
		int arr[MAX];
		int ans = 0;
		long long sum = 0;
		for(int i=0;i<n;i++){
			cin >> arr[i];
			sum += arr[i];
		}
		if(sum%n != 0){
			cout << -1 << endl;
			goto something;
		}
		for(int i=0;i<n;i++){
			ans += abs((sum/n) - arr[i]);
		}
		cout << ans/2 << endl;
		something:
		cin >> n;
	}
}