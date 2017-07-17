#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstdio>
#define MAXN 10000
using namespace std;
int n,M;
int a[MAXN+1];
int b[MAXN+1];
int num[MAXN+1];
int ans=0;
bool dp[MAXN+1][MAXN+1];
int main(){
  //cin.sync_with_stdio(false);
  while(true){
  cin>>n>>M;
  ans=0;
  if(n==0&&M==0){
    break; 
  }
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    cin>>b[i];
  }
  dp[0][0]=true;
  for(int i=0;i<n;i++){
    for(int j=0;j<=M;j++){
      for(int k=0;k<=b[i]&&k*a[i]<=j;k++){
      dp[i+1][j]|=dp[i][j-k*a[i]];
    }
  }
}
printf("%d\n",accumulate(dp[n]+1,dp[n]+M+1,0));
/*for(int i=1;i<=M;i++){
  if(dp[n][i]){
    ans++;
    }
  }
  cout<<ans<<endl;
}
*/
}
  return 0;
}