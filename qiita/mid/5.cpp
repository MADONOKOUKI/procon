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
ll n;
struct bal{
  double h;
  double s;
};
std::vector<bal> vec;

bool binary_search(ll val){
  std::vector<ll> t;
  rep(i,n) {
    if(val < vec[i].h) return false;
    t.pb((val-vec[i].h) / vec[i].s);
  }
  sort(all(t));
  rep(i,n) if(t[i] < i) return false;
  return true;
}
void solve(){
   cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>n;
  vec.resize(n);
  rep(i,n) cin>>vec[i].h>>vec[i].s;
  ll left = 0,right = 1e15;
  ll mid = 0;
  while(right - left > 1){
    mid = (left + right) / 2;
    if(binary_search(mid)) right = mid;
    else left = mid;
  }
  cout<<right<<endl;

}
int main(){
  solve();
  return 0;
}
