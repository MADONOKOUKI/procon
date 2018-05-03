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
ll n,q,k,tot=0;
std::vector<ll> a;
void solve(){
   cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>n>>q;
  a.resize(n+1);
  a[0] = 0;
  repl(i,1,n+1) {
    cin>>a[i];
    tot += a[i];
  }
  repl(i,2,n+1) a[i]+=a[i-1];
  ll dam = 0;
  rep(i,q){
    cin>>k;
    dam+=k;
    ll l = 0;
    ll r = n+1;
    // cout<<"dam="<<dam<<endl;
    while(r>l+1){
      ll mid = (l+r)/2;
      if(a[mid] > dam) r = mid;
      else l = mid;
    }
    if(l == n) cout<<n<<endl;
    else cout<<n-l<<endl;
    if(dam >= tot) dam = 0;
  }

}
int main(){
  solve();
  return 0;
}
