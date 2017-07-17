#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int MAX_N=10000;
int N,W,i;
int v[1005],w[1005];
int dp[105][MAX_N+5];
int main(){
  cin>>N;
  cin>>W;
  rep(i,N){
    cin>>v[i];
    cin>>w[i];
  }
  for(int i=0;i<=N;i++){
    for(int j=0;j<=W;j++){
      if(j>=w[i]){
      dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
      } else {
      dp[i+1][j]=dp[i][j];
      }
    }
  }
  cout<<dp[N][W]<<endl;
  return 0;
}