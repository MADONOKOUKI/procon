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

int board[200][200];
 
int di[6]={1,1,0,0,-1,-1};
int dj[6]={0,1,-1,1,-1,0};

#define INF INT_MAX/3
#define MAX_N 1000
#define M_INF 1000000000
int t,n,m,v,i,j,turn;
void solve(){
   cin.tie(0);
  ios::sync_with_stdio(false);
  while(1){
    cin>>t>>n;
    if(t==0&&n==0) break;
    memset(board,0,sizeof(board));
    rep(i,n){
      int x,y;
      cin>>x>>y;
      x+=100;y+=100;
      board[y][x] = 1;
    }
    int sx,sy;
    cin>>sx>>sy;
    sx+=100;sy+=100;
    int res = 0;
    queue<PPI> que;
    que.push(PPI(P(sy,sx),0));
    board[sy][sx] = 2;
    while(!que.empty()){
      int i = que.front().fi.fi;j=que.front().fi.se,turn = que.front().se;que.pop();
      res++;
      rep(d,6){
        int ni=i+di[d],nj=j+dj[d];
        if(ni<0||nj<0||ni>=200||nj>=200||board[ni][nj]!=0)continue;
        if(turn<t && turn <= 30){
          board[ni][nj]=2;
          que.push(PPI(P(ni,nj),turn+1));
        }
      }
    }
    cout<<res<<endl;
  }
}

int main(){
  solve();
  return 0;
}
