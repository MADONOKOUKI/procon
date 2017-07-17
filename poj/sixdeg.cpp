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
#define MAX_N 300
struct edge{
  int from,to;
};
ll dp[MAX_N+1][MAX_N+1];
bool used[MAX_N+1];
ll x[MAX_N+1];
void solve(){
   ll n,m,a,b;
   ll deka=-1;
   //vector<edge> v[MAX_N+1];
   
   cin>>n>>m;
   for(int i=0;i<MAX_N+1;i++){
    fill(dp[i],dp[i]+MAX_N+1,INF);
    dp[i][i]=0;
   }
   for(ll i=0;i<m;i++){
    cin>>a;
    for(ll j=0;j<a;j++){
      cin>>x[j];
      --x[j];
      //v[i].push_back(cin>>b);
     // if(used[x[j]]==false) used[x[j]] =true;
    }
  //  cout<<"true"<<endl;
    for(int k=0;k<a;k++){
      for(int j=k+1;j<a;j++){
        dp[x[k]][x[j]]=1;
        dp[x[j]][x[k]]=1;
      }
    }
   }
   for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
      }
    }
   }
   /*
   REP(i,n){
    REP(j,n){
      cout<<dp[i][j]<<" ";
    }
    cout<<" "<<endl;
   }
   */
  int  ans=INF,pre;
   for(int i=0;i<n;i++){
    pre=0;
    for(int j=0;j<n;j++){
      pre+=dp[i][j];
    }
     ans=min(ans,pre);
 }
   cout<<ans/(n-1)*100<<endl;
}
int main(){
  solve();
  return 0;
}