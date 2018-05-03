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
string s;
ll dp[MAX_N+1] = {0};
ll h,w;
char c[MAX_N+1];
ll dx[4] = {-1,0,1,0};
ll dy[4] = {0,1,0,-1};
void dfs(int x,int y){
  if(x==0||y==0||x==h-1||y==w-1){
    rep(i,4){
      ll dh =
    }
  }
}
void solve(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>h>>w;
  ll s1,s2;
  cin>>s1>>s2;
  rep(i,h)rep(j,w) cin>>dp[i][j];
  dfs(s1,s2);
  rep(i,h)rep(j,w){
    cout<<c[i][j];
    if(j==w-1) cout<<endl;
  }

}
int main(){
  solve();
  return 0;
}
