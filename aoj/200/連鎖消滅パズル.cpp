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
typedef pair<int, int> P;
typedef pair<P, int> PPI;

#define INF INT_MAX/3
#define MAX_N 1000
#define M_INF 1000000000
int n,m,i,j,k;
int v[12][8];

void solve(){
   cin.tie(0);
  ios::sync_with_stdio(false);
  while(cin>>n,n){
    rep(i,12)rep(j,5) v[i][j] = 0;
    rep(i,n)rep(j,5) cin>>v[n-1-i][j];
    // rep(i,10)rep(j,5) cout<<v[i][j];
    int ans = 0;
  //連鎖チェック
    int flg = 1;
    while(flg){
      flg = 0;
      rep(i,n){
        if(v[i][0] != 0 && (v[i][0] == v[i][1]) && (v[i][1] == v[i][2]) && (v[i][2] == v[i][3]) && (v[i][3] == v[i][4])){
          ans += v[i][0] * 5;
          rep(j,5) v[i][j] = 0;
          flg++;
        }
        // cout<<ans<<endl;
        rep(j,2){
          if(v[i][3] != 0 && (v[i][0+j] == v[i][1+j]) && (v[i][1+j] == v[i][2+j]) && (v[i][2+j] == v[i][3+j])){
            ans += v[i][0+j] * 4;
            repl(k,j,j+4) v[i][k] = 0;
             flg++;
          }
        }
        // cout<<ans<<endl;
        rep(j,3){
          if(v[i][2] != 0 && (v[i][0+j] == v[i][1+j]) && (v[i][1+j] == v[i][2+j])){
            ans += v[i][0+j] * 3;
            repl(k,j,j+3) v[i][k] = 0;
             flg++;
          }
        }
      }
      if( flg > 0){ 
      rep(i,n){
       rep(j,5){
        if(v[i][j] == 0) {
          int flg=  i;
          while(v[flg][j] == 0) flg++;
          if(flg < n) {
            v[i][j]  = v[flg][j];
            v[flg][j] = 0;
          }
        }
       } 
      }
    }

  }
  cout<<ans<<endl;
  }

}
int main(){
  solve();
  return 0;
}
