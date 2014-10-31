#include<bits/stdc++.h>
using namespace std;

#define MAX 100002

map<int,int> graph[MAX];

map<string,int> nametoindex;
map<int,string> indextoname;

int visited[MAX];
int dist[MAX];

class comp{
	public:
		bool compare(int a,int b){
			if(a>b) return true;
			else return false;
		}
};

int dijkstra(int a,int b){
	memset(visited,0,sizeof(visited));
	for(int i=0;i<MAX;i++) dist[i] = 200002;
	visited[a] = 1;
	priority_queue<int,comp> queue;
	return 0;

}

int main(){
	int t;
	cin >> t;
	while(t--){
		for(int i=0;i<MAX;i++) graph[i].clear();
		int n;
		cin >> n;
		for(int i=0;i<n;i++){
			string name;
			cin >> name;
			nametoindex.insert(make_pair(name,i+1));
			indextoname.insert(make_pair(i+1,name));
			int p;
			cin >> p;
			for(int i=0;i<p;i++){
				int nr,cost;
				cin >> nr >> cost;
				graph[i+1].insert(make_pair(nr,cost));
			}
		}
		int r;
		cin >> r;
		for(int i=0;i<r;i++){
		    string a,b;
		    cin >> a >> b;
		    cout << dijkstra(nametoindex[a],nametoindex[b]) << endl;
		}

	}
}