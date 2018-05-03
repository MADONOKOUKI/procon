#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;

#define INF INT_MAX/3
#define MAX_N 1000
ll n,m;
ll dp[20001][256];
ll c[16],x[20000];
ll rec(ll p,ll y){
  if(dp[p][y] >= 0) return dp[p][y];

  if(p == n) return 0;

  long ret=LONG_MAX;
    for(ll i=0; i<m; ++i){ //??????????????????????????¨????????????????????°????????????
        ll ny = y+c[i];
        if(ny<0) ny=0;
        else if(ny>255) ny=255;

        ret = MIN(ret, rec(p+1,ny)+(ny-x[p])*(ny-x[p]));
    }
    return dp[p][y]=ret;
}
void solve(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(1){
    cin>>n>>m;
    if(n==0) break;
    rep(i,m) cin>>c[i];
    rep(i,n) cin>>x[i];
    memset(dp,-1,sizeof(dp));
    printf("%lld\n",rec(0,128));
  }

}
int main(){
  solve();
  return 0;
}
