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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;

#define INF INT_MAX/3
#define MAX_N 1000
int a[MAX_N+1];
int T,A,S,B;
int dp[MAX_N+1][MAX_N+1];//DPテーブル

int main(){
  cin>>T>>A>>S>>B;
  for(int i=0;i<A;i++){
    int jud;
    cin>>jud;
    a[jud]++;
  }
  REP(i,T+1){dp[i][0]=1;}
  REP(i,T+1){
    REP(j,A){
      if(j-1-a[i]>=0){
        dp[i+1][j]=dp[i+1][j-1]+dp[i][j]-dp[i][j-1-a[i]];
      } else {
        dp[i+1][j]=dp[i+1][j-1]+dp[i][j];
      }
    }
  }
  int ans=0;
  for(int i=S;i<=B;i++){
    ans+=dp[T][i];
  }
  cout<<ans<<endl;

  return 0;
}