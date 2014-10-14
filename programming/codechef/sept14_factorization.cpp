#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
#include <ctime>

using namespace std;

#define MOD 1000000007

class GoodSubset {
public:
	map<long long,long long> m;

	int numberOfSubsets(int goodValue, vector <int> d) {
			for(int i=0;i<d.size();i++){
				  cout << "processing " << i  << " " << d[i]<< " " << m.size() <<  endl;
					map<long long,long long>::iterator it = m.begin();
					int sz = m.size();
					while(sz > 0){
						if( m.find(((it->first)*d[i])%MOD)!=m.end()){ (it->second) = (it->second) + 1; cout << "incremented: " << ((it->first)*d[i]) << endl; }
						else { m[((it->first)*d[i])%MOD] = 1;	cout << "init : " << ((it->first)*d[i]) << endl;}
						it++;
						sz--;
					}
					cout << "incrementing:  " << d[i] << endl;
					m[d[i]]++;
			}
			if(m.find(goodValue) == m.end()) return 0;
			else return m[goodValue];
	}
};


int main(){
    GoodSubset gs;
    vector<int> v;
    for(int i=0;i<100;i++) v.push_back(i+200000);
    cout << gs.numberOfSubsets(1000000,v);
}
