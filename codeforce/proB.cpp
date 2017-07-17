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

#define INF 100000001
#define MAX_N 10000
ll dp[MAX_N+1][MAX_N+1];
ll K[MAX_N+1];
void solve(){
  int n,m,k;
  int a,b;
  cin>>n>>m>>k;
  for(int i=0;i<n+1;i++){
    fill(dp[i],dp[i]+n+2,INF);
  }
  for(int i=0;i<m;i++){
    cin>>a>>b;
    cin>>dp[a][b];
    dp[b][a]=dp[a][b];
  }
  if(k>0){
    int ans=INF;
    for(int i=0;i<k;i++){
      cin>>K[i];
    }
    for(int i=0;i<k;i++){
      for(int j=1;j<=n;j++){
        ans=min(ans,(int)dp[j][K[i]]);
      }
    }
    if(ans==INF){
      cout<<-1<<endl;
    } else {
      cout<<ans<<endl;
    }
  } else {
    cout<<-1<<endl;
  }
  return ;
}
int main(){
  solve();
  return 0;
}