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
// #define MAX_N 1000
// template <typename T>
const int MAX_N = 1<<17;
template <typename T>

class BIT{
  public:
    ll M;
    std::vector<ll> bit;
    BIT(int M):
      bit(vector<ll>(M+1, 0)), M(M) {}
    int sum(int i) {
        if (!i) return 0;
        return bit[i] + sum(i-(i&-i));
    }
    void add(int i, int x) {
        if (i > M) return;
        bit[i] += x;
        add(i+(i&-i), x);
    }
};

void solve(){
   cin.tie(0);
  ios::sync_with_stdio(false);
  ll n , q;
  cin>>n>>q;
  BIT<ll> rsq(n);
  ll cm,x,y;
  rep(i,q){
    cin>>cm>>x>>y;
    // x--;
    if(cm == 0) rsq.add(x,y);
    else cout<<rsq.sum(y)-rsq.sum(x-1)<<endl;
  }


}
int main(){
  solve();
  return 0;
}
