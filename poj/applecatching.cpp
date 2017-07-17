#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 1000

int n,w;
int a[MAX_N+1];
int ans=0;
/*
struct edge {
  int number,count;
};
typedef pair <int,int> P; //今の番号・残り回数 

vector<edge> G[MAX_N+1];

void dfs(){
  //queue<pair> que;
  priority_queue< P,vector<P>,greater<P> > que;
  que.push(P(1,w));
  while(!que.empty()){
    P p = que.top();
    que.pop();
    int v = p.second;
  }
}
*/
int dp[1001][32][2];

int main(){
  cin>>n>>w;
  for(int i=0;i<n;i++){
    cin>>a[i];
    --a[i];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<w+1;j++){
      int tans=0;
      //元々入ってたやつと前の番号から移動または移動しないで入ってくるものを比較している
      //0から0にいったらプラスになる
      dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j][0]+(a[i]==0));
      //1から1に行ったらプラスになる
      dp[i+1][j][1]=max(dp[i+1][j][1],dp[i][j][1]+(a[i]==1));
      //前の座標までの最高回数に1足したもの
      dp[i+1][j+1][0]=max(dp[i+1][j+1][0],dp[i][j][1]+(a[i]==0));
      //d[i][j][1]+(a[i]==0)で移動するってことは反対側の暫定のものと今の座標の合計になるので
      dp[i+1][j+1][1]=max(dp[i+1][j+1][1],dp[i][j][0]+(a[i]==1));
      dp[i+1][j+1][0]=max(dp[i+1][j+1][0],dp[i][j+1][0]+(a[i]==0));
      dp[i+1][j+1][1]=max(dp[i+1][j+1][1],dp[i][j+1][1]+(a[i]==1));
      //
      //ans=max(max(ans,dp[i+1][j][0]),dp[i+1][j][1]);
      tans=max(tans,dp[i+1][j][0]);
      tans=max(tans,dp[i+1][j][1]);
      ans=max(ans,tans);
    }
  }
  //カウント数　今いる番号　残り移動回数
 // dp[1][1][w]=true;
  //dfs();
  cout<<ans<<endl;
  return 0;
}