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
#define MAX_N 100000
string s;
ll dp[MAX_N+1] = {0},a[10],b[10];
ll i,j,p;
ll n,m;
void solve(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>n;
  rep(i,n) cin>>a[i];
  ll can[10] = {0};
  rep(i,n) repl(j,1,10) if(a[i]%j==0) {
    can[j]++;
    can[a[i]/j]++;
  }
  cin>>m;
  rep(i,n) cin>>b[i];
  rep(i,n) if(can[b[i]] == 0) {
    cout<<"No"<<endl;
    return;
  } else {
    can[b[i]]--;
  }

  cout<<"Yes"<<endl;

}
int main(){
  solve();
  return 0;
}
