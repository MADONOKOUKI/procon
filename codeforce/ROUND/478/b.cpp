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
std::vector<ll> a(14);
void solve(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll cnt = 0;
  rep(i,14) cin>>a[i];
  rep(i,14){
    std::vector<ll> f(14);
    rep(j,14) f[j] = a[j];
    f[i] = 0;
    if(i+1 < 14) repl(j,i+1,14) f[j] += (a[i] - (j-i-1)) / 14 + ((a[i] - (j-i-1)) % 14 >= 1 ? 1 : 0);
    rep(j,i+1) f[j] += (a[i] - (14-i+j-1)) / 14 + ((a[i] - (14-i+j-1)) % 14 >= 1 ? 1 : 0);
    ll ans = 0;
    // rep(j,14) cout<<f[j]<<" ";
    // cout<<endl;
    rep(j,14) if(f[j] % 2 == 0) ans += f[j];
    maxch(cnt,ans);
  }
  cout<<cnt<<endl;

}
int main(){
  solve();
  return 0;
}
