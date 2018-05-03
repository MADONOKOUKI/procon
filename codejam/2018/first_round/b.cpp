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
ll n,m,i;
void solve(){
   cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>n;
  while(n--){
    cin>>m;
    ll v[m];
    rep(i,m) {
      cin>>v[i];
    }
    bool flg = false;
    while(!flg){
      flg = true;
      rep(i,m-2){
        if(v[i] > v[i+2]) {
          flg = false;
          ll tmp = v[i];
          v[i] = v[i+2];
          v[i+2] = tmp;
        }
      }
    }
    rep(i,m-1) {
      if(v[i] > v[i+1]) {
        cout<<i<<endl;
        return ;
      }
    }
    cout<<"OK"<<endl;
  }
}
int main(){
  solve();
  return 0;
}
