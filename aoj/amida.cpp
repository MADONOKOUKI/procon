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
#define MAX_HEIGHT 1000
int dp[MAX_HEIGHT+1][MAX_N+1];
void solve(){

   cin.tie(0);
  ios::sync_with_stdio(false);

  int n,m,a;
  //ll dd[2]={-1,1};
  while(cin>>n>>m>>a,n||m||a){
    ll x,y,h,MAXH=0;
    memset(dp,0,sizeof(dp)); 
  for(int i=0;i<m;i++) {
      cin>>h>>x>>y;
      dp[h][x]=y;
      dp[h][y]=x;
        if(h>MAXH) MAXH=h;
      }
      for(int i=MAXH;i>0;i--){
       // cout<<i<<endl;
       // for(int j=0;j<2;j++){
          if(dp[i][a]){
            a=dp[i][a];
            //j+=2;
          }
        //}
      }
      cout<<a<<endl;
   }
}
int main(){
  solve();
  return 0;
}