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
ll R,C,i,j,k,flg =0;
void solve(){
   cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>R>>C;
  std::vector<string> s(R+1);
  rep(i,R) cin>>s[i];
  ll dx[4] = {-1,0,1,0};
  ll dy[4] = {0,-1,0,1};
  rep(i,R)rep(j,C){
    // cout<<i<<" "<<j<<endl;
    if(s[i][j] == 'S') {
      rep(k,4) {
        ll y = i+dy[k];
        ll x = j+dx[k];

        if(x>-1&&y>-1&&x<C&&y<R){
          if(s[y][x] == 'W') flg=1;
        }
      }
    }
  }
  if(flg) {
    cout<<"No"<<endl;
    return;
  }
  rep(i,R)rep(j,C) if(s[i][j] != 'S' && s[i][j] != 'W')  s[i][j] = 'D';
  cout<<"Yes"<<endl;
  rep(i,R) cout<<s[i]<<endl;

}
int main(){
  solve();
  return 0;
}
