#include <bits/stdc++.h>
using namespace std; 
/* Helper function that multiplies 2 matricies F and M of size 2*2, and
  puts the multiplication result back to F[][] */
void multiply(long long F[2][2], long long M[2][2]);
 
/* Helper function that calculates F[][] raise to the power n and puts the
  result in F[][]
  Note that this function is desinged only for fib() and won't work as general
  power function */

#define MOD 1000000007

void power(long long F[2][2], long long n);
 
long long fib(long long n,long long x,long long y)
{
  long long F[2][2] = {{0,1},{-x,y}};
  if (n == 0)
      return 0;
  power(F, n-1);
 
  return F[1][1]%MOD;
}
 
void multiply(long long F[2][2], long long M[2][2])
{
  long long x =  ((F[0][0]*M[0][0])%MOD + (F[0][1]*M[1][0])%MOD)%MOD;
  long long y =  ((F[0][0]*M[0][1])%MOD + (F[0][1]*M[1][1])%MOD)%MOD;
  long long z =  ((F[1][0]*M[0][0])%MOD + (F[1][1]*M[1][0])%MOD)%MOD;
  long long w =  ((F[1][0]*M[0][1])%MOD + (F[1][1]*M[1][1])%MOD)%MOD;
 
  F[0][0] = (x)%MOD;
  F[0][1] = (y)%MOD;
  F[1][0] = (z)%MOD;
  F[1][1] = (w)%MOD;
}
 
void power(long long F[2][2], long long n)
{
  long long i;
  long long M[2][2] = {{0,1},{-1,1}};
 
  // n - 1 times multiply the matrix to {{1,0},{0,1}}
  for (i = 2; i <= n; i++)
      multiply(F, M);
}
 
/* Driver program to test above function */
int main()
{
  long long x,y;
  cin >> x >> y;
  long long n;
  cin >> n;
  switch((n-1)%6){
    case 0: cout << (MOD+x)%MOD << endl; break;
    case 1: cout << (MOD+y)%MOD << endl; break;
    case 2: cout << (MOD-x+y)%MOD << endl; break;
    case 3: cout << (MOD-x)%MOD << endl; break;
    case 4: cout << (MOD-y)%MOD << endl; break;
    case 5: cout << (MOD-x-y)%MOD << endl; break;
  }
  return 0;
}