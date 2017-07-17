#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int w,h,i,j;
int ans=11;
int x,y;
int dp[21][21];
void dfs(int n,int i,int j){
  if(n>=ans){
    return;
  }
  int nx,ny;
  for(int k=-1;k<2;k++){
    for(int l=-1;l<2;l++){
      if(k!=0&&l!=0){
        continue;
      }
      if(k==0&&l==0){
        continue;
      }
      nx=i+k;
      ny=j+l;
      if(0>nx||nx>=h||0>ny||ny>=w){
        continue;
      }
      if(dp[nx][ny]==1){
        continue; 
        }
  while(1){
    if(dp[nx][ny]==3){
      ans=n;
      return ;
    }
    nx+=k;
    ny+=l;
    if(nx<0||nx>=h||ny<0||ny>=w){
      break;
    }
    if(dp[nx][ny]==1){
        dp[nx][ny]=0;
        dfs(n+1,nx-k,ny-l);
        dp[nx][ny]=1;
        break;
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
  ans=11;
  rep(i,h){
    rep(j,w){
      cin>>dp[i][j];
      if(dp[i][j]==2){
        x=i;
        y=j;
      }
    }
  }
  dfs(1,x,y);
  if(ans<11){
  cout<<ans<<endl;
} else {
  cout<<-1<<endl;
}
}
  return 0;
}