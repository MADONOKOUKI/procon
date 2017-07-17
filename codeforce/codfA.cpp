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

int main(){
  string s;
  cin>>s;
  int a,b,ans=0;
  a=s[0]-'a'+1;
  b=s[1]-'0';
  for(int i=-1;i<2;i++){
    for(int j=-1;j<2;j++){
      if(i==0&&j==0){
        continue;
      }
      int nx=a+i;
      int ny=b+j;
      if(0<nx&&0<ny&&nx<9&&ny<9){
        ans++;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}