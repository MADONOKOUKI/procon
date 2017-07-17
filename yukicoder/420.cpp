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
typedef pair<ll, ll> P;
typedef pair<P, int> PPI;

#define INF INT_MAX/3
#define MAX_N 2147483647

//dp[bitのtから何番目が][bitの立てた数]:= 総数
P dp[40][40];

int main(){
  int x;
  cin>>x;
  if(x>31){
    puts("0 0");
    return 0;
  }
  dp[0][0]=P(1,0);
  dp[0][1]=P(1,1);
  REP(i,31){
    REP(j,x+1){
    REP(k,2){
      if(j+k <= x){
        //kが0か1で立てられるbit長が+1された時の処理
        dp[i+1][j+k].first += dp[i][j].first;
        //k==1の時
        if(k){
          dp[i+1][j+k].second += (dp[i][j].first +dp[i][j].second* 2LL);
          } else {
        //k==0の時
          dp[i+1][j+k].second += (dp[i][j].second * 2LL);
          }
        }
      }
    }
  }
  //x個立てたbitの
  cout << dp[30][x].first<<" "<<dp[30][x].second<<endl;
  return 0;
}