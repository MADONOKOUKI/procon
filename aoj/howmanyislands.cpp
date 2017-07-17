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
#define MAX_N 50
int dp[MAX_N+5][MAX_N+5];
int dx[3]={-1,0,1};
int w,h;
int ans=0;
void dfs(int a,int b){
  //高速化①
  if(a<0||b<0||b>=w||a>=h) return;
  //八方向探索→マス埋め作業
  for(int i=-1;i<=1;i++){
    for(int j=-1;j<=1;j++){
      if(i==0&&j==0) continue;
        int nx=a+i;
        int ny=b+j;
    if(0<=nx&&0<=ny&&ny<w&&nx<h&&dp[nx][ny]){
       dp[nx][ny]=0; 
       dfs(nx,ny);
      }
    }
  }
}
void solve(){
  //高速化②
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  while(cin>>w>>h,w||h){
  ans=0;
  if(w==0&&h==0) break;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>dp[i][j];
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(dp[i][j]) {
        dp[i][j]=0;
        dfs(i,j); 
        ans++;
      }
    }
  }
  cout<<ans<<endl;
  }
}
int main(){
  solve();
  return 0;
}