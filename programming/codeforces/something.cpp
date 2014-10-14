#include <bits/stdc++.h>
using namespace std;

vector< pair<int,int> > points;
set <pair<int,int> > points_set;

pair<int,int> rotate(pair<int,int> origin,pair<int,int> point, float angle) {   
    float radian = angle*M_PI/180.0;
    float s = sin(radian);   
    float c = cos(radian);  

    // translate point back to origin:  
    point.first -= origin.first;   
    point.second -= origin.second;   

    // rotate point   
    float xnew = point.first * c - point.second * s;   
    float ynew = point.first * s + point.second * c; 

    // translate point back to global coords:
    pair<int,int> TranslatedPoint;
    TranslatedPoint.first = xnew + origin.second;  
    TranslatedPoint.second = ynew + origin.second; 

    return TranslatedPoint;
} 


double dist(pair<int,int> a,pair<int,int> b){
    return pow((a.first - b.first),2) +  
}

bool is_square(pair<int,int> a,pair<int,int> b,pair<int,int> c,pair<int,int> d){

}

int find_max_points(int point1,int point2){
    // code for side1
    pair<int,int> a = points[point1], b = points[point2], c = rotate(a,b,90), d = rotate(b,a,-90);

}

int main()
{
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        points.push_back(make_pair(a,b));
        points_set.insert(make_pair(a,b));
    }

    if(n == 0){
        cout << 4 << endl;
        return 0;
    }

    if(n == 1){
        cout << 3 << endl;
        return 0;
    }

    if(n == 2){
        cout << 2 << endl;
        return 0;
    }
    
    int sz = points.size();
    int val = 4;;
    for(int i=0;i<sz;i++){
        for(int j=i+1;j<sz;i++){
            val = min(val,find_max_points(i,j));
            if(val == 0){
                cout << val << endl;
                return 0;
            }
        }
    }
    cout << val << endl;
    return 0;
}
