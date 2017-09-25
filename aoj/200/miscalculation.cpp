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

void solve(){
   cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  ll l;
  cin>>s>>l;
  if(s.size() == 1){
    if((int)s[0] - '0' == l) cout<<"U"<<endl;
    else cout<<"I"<<endl;
    return ;
  }
  std::vector<int> vec(2);
  int ans = INF;
  rep(i,s.size()-1){
    if(i%2==0){
      if(ans==INF){
        ans = (int)s[i]-'0';
      }
    } else {
      if(s[i] == '+') ans+=(int)s[i+1]-'0';
      else if(s[i] == '*') ans*=(int)s[i+1]-'0';
    }
  }
  vec[0] = ans;
  ans =  0;
  repl(i,1,s.size()){
    if(s[i] == '*'){
      ll cnt = 0;
      ll val = 0;
      while(s[i] == '*' && i < s.size()){
        if(cnt==0){
          val = ((int)s[i-1]-'0') * ((int)s[i+1]-'0');
          cnt++;
        } else {
          val = val * ((int)s[i+1]-'0');
        }
        i+=2;
      }
      ans += val;
    }
  }
  // cout<<ans<<endl;
  if(ans>=INF) ans = 0;
  if(s[1] == '+') ans += (int) s[0]-'0';
  // cout<<ans<<endl;
  repl(i,1,s.size()){
    if(s[i] == '+' && (s[i+2] != '*' || i + 1 >= s.size())){
      ans += (int)s[i+1]-'0';
    }
  }
  vec[1] = ans;
  // cout<<vec[0]<<" "<<vec[1]<<endl;
  if(vec[0] == l){
    if(vec[1] == l ){
      cout<<"U"<<endl;
      return ;
    } else {
      cout<<"L"<<endl;
      return ;
    }
  }
  if(vec[1] == l){
    cout<<"M"<<endl;
  } else {
    cout<<"I"<<endl;
  }

}
int main(){
  solve();
  return 0;
}
