// g++ temp.cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <climits>
using namespace std;

#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,n) FOR(i,0,n)
//#define REP(i,n) FOR(i,1,n)
#define EACH(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
const unsigned long long MOD = 100000000000000000;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;

#define INF INT_MAX/3
#define MAX_N 1000
void solve(){
   string s;
   cin.tie(0);
   //sync_with_stdio(false);
   cin>>s;
   int ans=0;
   for(int i=0;i<s.size();i++){
    if(s[i]=='m'&&i+1<s.size()){
      if(s[i+1]=='i'){
        ans++;
      }
    }
   }
   cout<<ans<<endl;
}
int main(){
  solve();
  return 0;
}