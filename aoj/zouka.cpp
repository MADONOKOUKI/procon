#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll; 
#define rep(i,n) for(int i=0;i<n;i++)
const  int  MAX_N=100000001;
const int  INF=1000000001;
int i,n;
int w[MAX_N+5];
int dp[MAX_N+5];
int res=0;
int main(){
  cin>>n;
  rep(i,n){
    cin>>w[i];
  }
  fill(dp,dp+n,INF);
  for(i=0;i<n;i++){
    *lower_bound(dp,dp+n,w[i])=w[i];
  }
  cout << lower_bound(dp,dp+n,INF)-dp << endl;

  return 0;
}