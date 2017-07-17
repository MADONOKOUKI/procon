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
void solve(){
  int l;
  cin>>l;
  for(int i=1;i<=l;i++){
    for(int j=1;j<=i;j++){
    if((pow(i,2)-pow(j,2))==l){
      if((pow(pow(i,2)-pow(j,2),2)+pow(2*i*j,2))==(pow((pow(i,2)+pow(j,2)),2))){
        cout<<2*(i)*j<<" "<<pow(i,2)+pow(j,2)<<endl;
        return ;
        }
      }
    if(pow(2*i*j,2)==l){
      if((pow(pow(i,2)-pow(j,2),2)+pow(2*i*j,2))==(pow((pow(i,2)+pow(j,2)),2))){
        cout<<2*(i)*j<<" "<<pow(i,2)+pow(j,2)<<endl;
        return ;
        }
      }
    }
  }
  cout<<-1<<endl;
  return ;
}
int main(){
  solve();
  return 0;
}