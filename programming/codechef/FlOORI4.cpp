#include<iostream>
#include<cmath>
using namespace std;

inline long long iterativePower(long long a, int power, long long MOD){
	/*
		find long power
	*/
	long long ans=1;
	while(power--){
		ans*=a;
		ans%=MOD;
	}
	return ans;
}

long long sum(long long n,long long MOD){
	/*
		get all sum in map
		first _ number
		second - answer corresponding to that number
	*/
	pair<long long, long long> powers[6];
	
	powers[1]=make_pair(0,n);
	for(int i=2;i<=5;i++)
	{
			powers[i].second = (powers[i-1].second*(n%30));
  		powers[i].first  = ((30*(n/30)*powers[i-1].first + (n/30)*powers[i-1].second + (n%30)*powers[i-1].first + powers[i].second/30))%MOD;
  		powers[i].second %= 30;
	}
	
	long long result = 6*powers[5].first + 15*powers[4].first + 10*powers[3].first - powers[1].first;
	long long remainder = 6*powers[5].second + 15*powers[4].second + 10*powers[3].second - powers[1].second;
	return (result+remainder/30)%MOD;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,m;
		cin>>n>>m;
		
		long long solution = 0;
		long long last = n;

		long long sqrtN = sqrt(n);

		for(long long i = 2;i<=sqrtN;i++)
		{
			long long first = n/i+1;
			solution+= (i-1)*(m+sum(last,m)-sum(first-1,m));
			solution%=m;
			last = first-1;
		}
		
		for(long long i=1;i<=last;i++){
			solution+=iterativePower(i,4,m)*(n/i);
			solution%=m;
		}
		cout<<solution<<endl;
	}
}