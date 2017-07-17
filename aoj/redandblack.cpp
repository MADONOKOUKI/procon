#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int w,h,i,j;
int ans=1;
int x,y;
char dp[21][21];
void dfs(int i,int j){
  for(int k=-1;k<2;k++){
    for(int l=-1;l<2;l++){
      if(k!=0&&l!=0){
        continue;
      }
      if(0<=i+k&&i+k<h&&0<=j+l&&j+l<w){
      if(dp[i+k][j+l]=='.'){
        ans++;
        dp[i+k][j+l]='#';
        dfs(i+k,j+l);
        }
      }
    }
  }
}

int main(){
  while(1){
  cin>>w;
  cin>>h;
  if(w==0&&h==0){
    break;
  }
  ans=1;
  rep(i,h){
    rep(j,w){
      cin>>dp[i][j];
      if(dp[i][j]=='@'){
        x=i;
        y=j;
      }
    }
  }
  dfs(x,y);
  cout<<ans<<endl;
}
  return 0;
}