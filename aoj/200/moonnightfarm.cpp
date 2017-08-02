#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
/*
//#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
*/

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
/*
//#if __cplusplus >= 201103L
#include <array>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
*/
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
typedef pair<double, string> P;
typedef pair<P, int> PPI;

#define INF INT_MAX/3
#define MAX_N 1000
#define M_INF 1000000000
ll n,m,v,i;

// struct seed {
//   double cost;
//   string name;

//   bool operator<(const seed& r) const{
//     if(cost == r.cost){
//         rep(i,name.size() > r.name.size() ? r.name.size() : name.size()){
//           if(name[i] == r.name[i]) continue;
//           else return name[i] < r.name[i];
//         }
//     } else {
//         return cost > r.cost;
//     }
//   }
// };

inline double calc(int p,int a,int b,int c,int d,int e,int f,int s,int m)
{
  int sum = a+b+c+d+e;
    return 1.*(f*s*m-p)/ ( sum + (d+e) * (m-1));
}

bool sorter(const P s1, const P s2) {
  if(s1.fi == s2.fi) return s1.se < s2.se;
  else return s1.fi > s2.fi;
}

void solve(){
   cin.tie(0);
  ios::sync_with_stdio(false);
  string name;
  ll p,a,b,c,d,e,f,s;
  while(cin>>n,n){
    // seed seeds[MAX_N];
    std::vector<P> vec;
    rep(i,n){
      cin>>name>>p>>a>>b>>c>>d>>e>>f>>s>>m;
      vec.pb(mp(calc(p,a,b,c,d,e,f,s,m),name));
    }
    // sort(seeds,seeds+n);
    sort(all(vec),sorter);
    rep(i,n){
      cout<<vec[i].se<<endl;
    }
    cout<<"#"<<endl;
  }
}

int main(){
  solve();
  return 0;
}
