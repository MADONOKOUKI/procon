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

#define INF 100000000000
#define MAX_N 1000
ll a[MAX_N+1];
ll n;
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  ll previous,ans=INF;
  ll ans_num=1;
  for(ll i=0;i<n;i++){
    previous=0;
    for(ll j=0;j<n;j++){
      previous+=abs(a[j]-a[i]);
    }
    if(previous<ans&&previous>=0){
      ans=previous;
      ans_num=a[i];
    }
  }
  cout<<ans_num<<endl;
  return 0;
}