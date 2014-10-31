#include <bits/stdc++.h>
using namespace std;



class css{
	public:
		int id,attr;

	bool operator <(const css& rhs) const
  {
  		if(id == rhs.id) return  attr < rhs.attr; 
      return id < rhs.id;
  }	

  bool operator ==(const css& rhs) const
  {
      return id == rhs.id && attr==rhs.attr;
  }	
};


map<css,pair<int,int>> code;

int main(){
	ios_base::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		css tempcss;
		tempcss.id = a;
		tempcss.attr = b;
		if(code.find(tempcss) != code.end() && (code.find(tempcss)->second).second <= d){
			code[tempcss] = make_pair(c,d);
			//cout << i << " in 1\n";
		}
		else if(code.find(tempcss) == code.end()){
		//	cout << i << " in 2\n";
			code[tempcss] = make_pair(c,d);
		}
		else {
			//cout << "deb: " << code.find(tempcss)->first.attr << endl;
		}
	}


	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		css tempcss;
		tempcss.id = a;
		tempcss.attr = b;
		cout << (code.find(tempcss)->second).first << endl;
	}

}