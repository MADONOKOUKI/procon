// g++ temp.cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <climits>
using namespace std;

#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,n) FOR(i,0,n)
#define EACH(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
const unsigned long long MOD = 100000000000000000;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;

#define INF INT_MAX/3
#define MAX_N 1000
typedef vector<int> vec;
typedef vector<vec> mat;
mat A;
int n,k,M;
mat mul(mat &A, mat &B){
  mat C(A.size(),vec(B[0].size()));
  for(int i=0;i<A.size();i++){
    for(int k=0;k<B.size();k++){
      for(int j=0;j<B[0].size();j++){
        C[i][j]=(C[i][j]+A[i][k]*B[k][j])%M;
      }
    }
  }
  return C;
}

//A^nの計算logn回かかる
mat POW(mat A,ll n){
  mat B(A.size(),vec(A.size()));
  for(int i=0;i<A.size();i++){
    B[i][i]=1;
  }
  while(n>0){
    if(n&1){
      B=mul(B,A);
    }
    A=mul(A,A);
    n>>=1;
  }
  return  B;
}


void solve(){
  mat B(n*2,vec(n*2));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      B[i][j]=A[i][j];
    }
    B[n+i][i]=B[n+i][n+i]=1;
  }
  B = POW(B,k+1);//I+A+A^2+A^3
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int a  = B[n+i][j]%M;
      //Iを引く
      if(i==j){
        a=(a+M-1)%M;
      }
      printf("%d%c",a,j+1==n ? '\n' : ' ');
    }
  }
}
int main(){
  cin>>n>>k>>M;
  int p;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>p;
      A[i].push_back(p);
    }
  }
  solve();
  return 0;
}

