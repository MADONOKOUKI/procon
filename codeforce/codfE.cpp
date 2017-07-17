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
#define MAX_N 1000000000

ll n,x,y;
ll dfs(ll n){
  ll ans2,ans3,ans1;
  if(n==0) return 0;
  if(n==1) return x;
  if(!(n&1)){
    ans1 = dfs(n/2);
    return min(ans1+y,ans1+(ll)x*(n/2));
  } else {
    ans2 = dfs(n+1);
    ans3 = dfs(n-1);
    return min(ans2,ans3) + x;
  }
}

int main(){
  scanf("%lld %lld %lld",&n,&x,&y);
  ll ans= dfs(n);
  printf("%lld\n",ans);
  return 0;
}