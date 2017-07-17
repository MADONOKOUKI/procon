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
#define MAX_N 2000
#define MAX_RANGE (100*2000+2)

int dp[2][MAX_RANGE];
int N;
int S[MAX_N],F[MAX_N];

int max(int x,int y){
  return x>y?x:y;
}

int solve(){
  int ans=0;
  int cur,next;
  for(int i=0;i<MAX_RANGE;i++){
    dp[0][i]=-INF;
  }
  dp[0][100000]=0;
  for(int k=0;k<N;k++){
    cur=k&1,next=1-cur;
    for(int i=0;i<MAX_RANGE;i++){
      dp[next][i]=-INF;
    }
    for(int i=0;i<MAX_RANGE;i++){
      if(dp[cur][i]!=-INF){
        dp[next][i]=max(dp[next][i],dp[cur][i]);
        dp[next][i+S[k]]=max(dp[next][i+S[k]],dp[cur][i]+F[k]);
      }
    }
  }
  for(int i=100000;i<MAX_RANGE;i++){
    if(dp[N&1][i]>=0){
      ans=max(ans,(i-100000)+dp[N&1][i]);
    }
  }
  return ans;
}

int main(){
  int i;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d%d",S+i,F+i);
  }
  cout<<solve()<<endl;
  return 0;
}
