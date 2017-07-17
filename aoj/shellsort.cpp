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
typedef pair<string, int> P;
typedef pair<P, int> PPI;

#define INF INT_MAX/3
#define MAX_N 1000
int n,m;
int since=0;
P temp[100001];
int main(){
  cin>>n>>m;
  queue<P> que;
  for(int i=0;i<n;i++){
    cin>>temp[i].first>>temp[i].second;
    que.push(P(temp[i].first,temp[i].second));
  }

  while(!que.empty()){
    P p = que.front();
    que.pop();
    int v=p.second;
    if(v<=m){
      cout<<p.first<<" "<<since+v<<endl;
      since+=v;
    } else {
      que.push(P(p.first,p.second-m));
      since+=m;
    }
  }
  
  return 0;
}