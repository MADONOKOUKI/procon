#include <iostream>
#include <algorithm>
using namespace std;
int h,w;
int ans=0;
char dp[101][101];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
void dfs(char c,int i,int j){
  dp[i][j]='.';
  int nx,ny;
  for(int k=0;k<4;k++){
    nx=i+dx[k];
    ny=j+dy[k];
    if(nx<0||ny<0){
      continue;
    }
    if(nx>=h||ny>=w){
      continue;
    }
    if(dp[nx][ny]==c){
      dfs(c,nx,ny);
    }
  }
}
int main(){
  while(1){
  ans=0;
  cin>>h;
  cin>>w;
  if(h==0&&w==0){
    break;
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>dp[i][j];
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(dp[i][j]!='.'){
        dfs(dp[i][j],i,j);
        ans++;
      }
    }
  }
  cout<<ans<<endl;
}
  return 0;
}