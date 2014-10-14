#include <random>
#include <iostream>
#include<string>
using namespace std;

class random_gen{

	public:
	random_gen(){
	}

	int random32(int min,int max){
		std::uniform_int_distribution<int> dis;
		std::random_device rd;
		std::mt19937_64 gen(rd());
  	return dis(gen)%(max-min) + min;
	}

	long long random64(long long min,long long max){
		std::uniform_int_distribution<long long> dis;
		std::random_device rd;
		std::mt19937_64 gen(rd());
  	return dis(gen)%(max-min) + min;
	}

	string randomString(string chars,int minlen,int maxlen){
		std::uniform_int_distribution<int> dis;
		std::random_device rd;
		std::mt19937_64 gen(rd());
		int sz = chars.size();
		int len = random32(minlen,maxlen);
		string temp;
		for(int i=0;i<len;i++){
			temp += chars[random32(0,sz-1)];
		}
		return temp;
	}

	double randomDouble(long long min,long long max){
		double lower_bound = min;
	  double upper_bound = max;
	  std::uniform_real_distribution<double> unif(lower_bound, upper_bound);
	  std::random_device rd;
		std::mt19937_64 gen(rd());     
	  double a_random_double = unif(gen);
	  return a_random_double;
	}

};


int main()
{
	random_gen rd;
  cout << rd.randomDouble(5,100) << endl;
  return 0;
}