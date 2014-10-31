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

string essay[MAX],orig[MAX];
map<string, pair<string,int> > hashMap;
map<string, string> rev;
map<string,int> proc;

vector<string> x;

void opti(string a){
	string curString = a;
	int curCount = hashMap[curString].second;
		//cout << "old " << curString << " " << curCount << endl;
	while(hashMap.find(curString) != hashMap.end()){
		if(hashMap[curString].second < curCount){
			curCount = hashMap[curString].second;
			curString = hashMap[curString].first;
		}
	}
	//cout << "new " << curString << " " << curCount << endl;
	hashMap[a].first = curString;
	hashMap[a].second = curCount;
}

void opt(){
	map<string, pair<string,int> >::iterator it = hashMap.begin();
	for(;it!=hashMap.end();it++){
		if(proc[it->first] == 1) continue;
		string curString = (it->first);
		////cout << "finding for: " << hashMap[curString].first << endl;
		set<string> s;
		while(hashMap.find(hashMap[curString].first) != hashMap.end()){
			if(s.find(curString) != s.end())  break;
			x.push_back(curString);
			s.insert(curString);
			curString = hashMap[curString].first;
		}
		if(x.size() == 0) continue;
		int minVal = hashMap[x[x.size()-1]].second;
		string si  = hashMap[x[x.size()-1]].first;
		for(int i=x.size()-1;i>=0;i--){
			if(hashMap[hashMap[x[i]].first].second< minVal || hashMap[hashMap[x[i]].first].first.size() < si.size() ){
				minVal  = hashMap[hashMap[x[i]].first].second;
				si = hashMap[hashMap[x[i]].first].first;
		  }
			hashMap[x[i]].second = minVal;
			hashMap[x[i]].first = si;
			proc[x[i]] = 1;
		}
		x.clear();
	}
}

void printMap(){
	map<string, pair<string,int> >::iterator it = hashMap.begin();
	for(;it!=hashMap.end();it++){
		cout << it->first << " " << (it->second).first << " " << (it->second).second << endl;
	}
}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> essay[i]; orig[i] = essay[i];
		std::transform(essay[i].begin(), essay[i].end(), essay[i].begin(), ::tolower);
	}
	int m;
	cin >> m;
	for(int i=0;i<m;i++){
		string a,b;
		cin >> a >> b;
		std::transform(a.begin(), a.end(), a.begin(), ::tolower);
		std::transform(b.begin(), b.end(), b.begin(), ::tolower);
		int count = 0;
		for(int j=0;j<b.size();j++) if(b[j] == 'R' || b[j] =='r') count++;
		//cout << "madepair: " << a << " " << b << " " << count << endl;
		hashMap[a] = make_pair(b,count);
		proc[a] = 0;
		proc[b] = 0;
	}
	int countr = 0,countt = 0;
	opt();
	//printMap();
	for(int i=0;i<n;i++){
		int count = 0;
		for(int j=0;j<essay[i].size();j++) if(essay[i][j] == 'R' || essay[i][j] =='r') count++;
		if(hashMap.find(essay[i]) == hashMap.end()){
			 countt += essay[i].size(); countr += count; 
			 continue;
		}
		//cout << essay[i] << " " << hashMap[essay[i]].first << " " << hashMap[essay[i]].second << endl;
		//cout << count << endl;
		if(count > hashMap[essay[i]].second) { countr+=hashMap[essay[i]].second; countt+=hashMap[essay[i]].first.size(); continue;}
		if(count == hashMap[essay[i]].second) {
			if(essay[i].size() > hashMap[essay[i]].first.size()) {	countt += hashMap[essay[i]].first.size(); countr +=hashMap[essay[i]].second; continue;}
		}
		countt += essay[i].size(); countr += count; 
	}
	cout << countr << " " << countt << endl;
}