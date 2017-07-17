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
#define MAX_N 50
ll A[MAX_N+1];

void init(int n){
  for(int i=0;i<n;i++){ 
      A[i]=n-i;
     // cout<<A[i]<<endl;
  }
}
void func(int a,int b){
  ll B[MAX_N+1];
  for(int i=0;i<a;i++){
    B[i]=A[i];
    //cout<<B[i]<<endl;
  }
  for(int i=0;i<b;i++){
    A[i]=A[a+i];
   // cout<<A[i]<<endl;
  }
  for(int i=0;i<a;i++){
    A[b+i]=B[i];
 //   cout<<A[a+i]<<endl;
  }
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,r;
  while(true){
  cin>>n>>r;
  if(n==0&&r==0) break;
  int p,c;
  init(n);
  for(int i=0;i<r;i++){
    cin>>p>>c;
    func(p-1,c);
    //for(int j=0;j<n;j++){
     // cout<<A[j]<<endl;
    //}
   }
    cout<<A[0]<<endl;
  }

  return 0;
}