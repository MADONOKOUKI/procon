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
template <class T>
struct fenwick_tree {
    int n;
    std::vector<T> x;
    fenwick_tree(int n_ = 0) : n(n_), x(n + 1, 0) {}
    int size() const { return n; }
    T sum(int r) const {
        T S = 0;
        for (r = r - 1; r >= 0; r = (r & (r + 1)) - 1) S += x[r];
        return S;
    }
    T sum(int l, int r) const { return sum(r) - sum(l); }
    void add(int k, const T &a) {
        for (; k < n; k |= k + 1) x[k] += a;
    }
    void set(int k, const T &a) { add(k, a - sum(k, k + 1)); }
};

template <class T>
struct fenwick_tree_range {
    fenwick_tree<T> a, b;
    fenwick_tree_range(int n = 0) : a(n), b(n) {}
    int size() const { return a.size(); }
    T sum(int r) const { return a.sum(r) + b.sum(r) * r; }
    T sum(int l, int r) const { return sum(r) - sum(l); }
    void add(int r, const T &x) {
        a.add(r, x * r);
        b.add(r, -x);
    }
    void add(int l, int r, const T &x) {
        add(l, -x);
        add(r, x);
    }
};
pair<pair<double,int>,int> cd[100001];
ll n,i;
int ans[100001] = {0};
void solve(){
   cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>n;
  ll xi , yi;
  rep(i,n) {
    cin>>xi>>yi;
    cd[i]={{(double)yi/xi,xi},i};
  }
  sort(cd,cd+n);
  fenwick_tree<ll> b(100001);
  rep(i,n){
      int a=b.sum(cd[i].first.second);
      ans[cd[i].second]=a;
      b.add(cd[i].first.second,1);
  }
  rep(i,n) cout<<ans[i]<<endl;
  return ;

}
int main(){
  solve();
  return 0;
}
