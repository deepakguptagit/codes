#include <bits/stdc++.h>
using namespace std;

#define EPS 0.000001

double roundOff(double n){
    return std::floor(n * 1000000 + 0.5)/1000000;    
}


class Line{
   public:
       pair<int,int> a;
       pair<int,int> b;
};

vector<pair<int,int> > points;

multimap<double, Line> slopes;

double dist(pair<int,int> a,pair<int,int> b){
    return abs(pow((b.second - a.second),2)-pow((b.first - a.first),2));
}

double findSlope(pair<int,int> a,pair<int,int> b){
    if(b.first == a.first) return 1000002;
    return (double(b.second - a.second))/(b.first - a.first);    
}


bool checkSquare(Line line1,Line line2){
    double side1  = dist(line1.a,line2.a);
    double side2  = dist(line1.a,line2.b);
    double side3  = dist(line1.b,line2.a);
    double side4  = dist(line1.b,line2.b);
    //cout << side1 << " " << side2 << " " << side3 <<  " " << side4 << endl;  
    if(side1 == side2 && side2 == side3 && side3 == side4) return true;
    else return false;
}

int main()
{
    int n,flag = 0;
    cin >> n;
    
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        points.push_back(make_pair(x,y));
    }
    
    for(int i=0;i<points.size();i++){
        for(int j=i+1;j<points.size();j++){
            
            Line line1; line1.a = points[i]; line1.b = points[j];
            
            double slope = findSlope(points[i],points[j]);
            
            //cout << i << " " << j << ": " << slope << endl;
            
            double origSlope = slope;
            
            
            if(slope == 1000002) slope = 0;
            else if(slope == 0) slope = 1000002;
            else slope = -1/slope;
            
            auto iterPair= slopes.equal_range(slope);
            
            auto iter = iterPair.first;
            for(;iter!=iterPair.second;iter++){
                if(iter != slopes.end()){
                    Line line2 = iter->second;
                    if(checkSquare(line1,line2)){
                        cout << 0 << endl;
                        return 0;
                    }
                    if(line1.a == line2.a || line1.a==line2.b 
                       || line1.b == line2.a || line1.b == line2.b){
                        flag = 1;   
                    }
                }
            }
            slopes.insert(make_pair(origSlope,line1));
        }
    }
    
    if(flag) cout << 1 << endl;
    else cout << 2 << endl;
        
    return 0;
}
