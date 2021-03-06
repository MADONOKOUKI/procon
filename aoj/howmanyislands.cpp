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
ll w,h;
ll c[55][55]={0};
bool reached[55][55] = {false};
void dfs(int x,int y){
  if(x<0||y<0||x>=h||y>=w) return;
  if(c[x][y] == 0) return;
  if(reached[x][y]) return;
  reached[x][y] = true;
  c[x][y] = 0;
  dfs(x-1,y-1);
  dfs(x-1,y);
  dfs(x-1,y+1);
  dfs(x,y-1);
  dfs(x,y+1);
  dfs(x+1,y-1);
  dfs(x+1,y);
  dfs(x+1,y+1);
}
void solve(){
   cin.tie(0);
  ios::sync_with_stdio(false);
  while(true){
    cin>>w>>h;
    ll cnt = 0;
    if(w==0&&h==0) return;
    rep(i,h)rep(j,w) cin>>c[i][j];
    rep(i,h)rep(j,w) reached[i][j] = false;
    rep(i,h)rep(j,w) if(c[i][j] == 1) {
      dfs(i,j);
      cnt++;
    }
    cout<<cnt<<endl;

  }
}
int main(){
  solve();
  return 0;
}
