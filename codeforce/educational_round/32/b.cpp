#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl

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
#define M_INF 1000000000
int n,m,v,i;
void solve(){
   cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>n;
  string s;
  cin>>s;
  ll r_ans=0,l_ans=0;
  rep(i,s.size()){
    //LDUR
    if(s[i]=='L'){
      l_ans--;
    } else if(s[i]=='D'){
      r_ans--;
    } else if(s[i]=='U'){
      r_ans++;
    } else if(s[i]=='R'){
      l_ans++;
    }
  }
  cout<<n-abs(r_ans)-abs(l_ans)<<endl;

}

int main(){
  solve();
  return 0;
}
