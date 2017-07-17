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

ll func(int a,int b){
  return a*a+b*b;
}
void solve(){
  int h,w;//h<w<150;
  bool flag;
  int x,y;
  while(true){
  cin>>h>>w;
  if(h==0&&w==0) break;
  x=200;
  y=200;
  //両辺が整数で対角線が条件より少し長いものを考える
 // flag=true;
  for(int i=1;i<=150;i++){
    if(func(i,i)<func(h,w)){
      for(int j=i+1;j<=150;j++){
        if((func(i,j)==func(h,w)&&i>h)||func(i,j)>func(h,w)){
          if(func(i,j)<func(x,y)){
            x=i;
            y=j;
            } else if(func(i,j)==func(x,y)&&i<x){
              x=i;
            y=j;
            }
          }
        }
      }
    }
    cout<<x<<" "<<y<<endl;
  }
}
int main(){
  solve();
  return 0;
}