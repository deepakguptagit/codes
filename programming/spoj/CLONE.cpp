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

int main(){
	map<string,int> mp;
	int n,m;
	cin >> n >> m;
	while(n!=0){
		mp.clear();
		for(int i=0;i<n;i++){
			string s;
			cin >> s;
			if(mp.find(s) != mp.end()) mp[s]++;
			else mp[s] = 1;
		}
		int hash[20002] = {0};
		std::map<string, int>::iterator it = mp.begin();
		for(;it != mp.end();it++){
			pair<string,int> k = *it;
			//cout << k.first << " " << k.second << endl;
			hash[k.second]++;
		}
		for(int i=1;i<=n;i++) cout  << hash[i] << endl;
		cin >> n >> m;
	}

}