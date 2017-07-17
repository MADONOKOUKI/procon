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
#define MAX_N 40000

int ans;
int n,m;
int dp[MAX_N+1];
int a[MAX_N+1];

//最大番号・インデックス、合計
void dfs(int k,int t,int o){
// cout<<k<<t<<o<<endl;
  if(ans<o){
    ans=o;
  }
  if(t>m){
    return ;
  }
  if(k<dp[t]){
    dfs(dp[t],t+1,o+1);
  }
 dfs(k,t+1,o);
 return ;
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>m;
    ans=0;
    for(int j=0;j<m;j++){
      cin>>a[j];
    }
    fill(dp,dp+m,INF);
    for(int j=0;j<m;j++){
      *lower_bound(dp,dp+m,a[j])=a[j];
    }
    cout<<lower_bound(dp,dp+m,INF)-dp<<endl;
    }
  return 0;
}