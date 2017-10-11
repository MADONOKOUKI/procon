#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <bitset>
using namespace std;

#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define fi first
#define se second

#define INF 2147483600

vector<vector<int> > mat(10, vector<int>(10));

inline int digit(int a, int b, int c, int d){
  return mat[mat[mat[mat[0][a]][b]][c]][d];
}

int main(){
  rep(i,10) rep(j,10) scanf("%d", &mat[i][j]);
  int res=0;
  rep(a,10)rep(b,10)rep(c,10)rep(d,10){
    int cnt=0;
    int dig = digit(a,b,c,d);

    rep(j,10) if(j!=a){
      if(mat[digit(j,b,c,d)][dig]==0) cnt++;
    }
    rep(j,10) if(j!=b){
      if(mat[digit(a,j,c,d)][dig]==0) cnt++;
    }
    rep(j,10) if(j!=c){
      if(mat[digit(a,b,j,d)][dig]==0) cnt++;
    }
    rep(j,10) if(j!=d){
      if(mat[digit(a,b,c,j)][dig]==0) cnt++;
    }
    rep(j,10) if(j!=dig){
      if(mat[dig][j]==0) cnt++;
    }
    if(a!=b && mat[digit(b,a,c,d)][dig]==0) cnt++;
    if(c!=b && mat[digit(a,c,b,d)][dig]==0) cnt++;
    if(c!=d && mat[digit(a,b,d,c)][dig]==0) cnt++;
    if(dig!=d && mat[digit(a,b,c,dig)][d]==0) cnt++;

    if(cnt>0) res++;
  }

  cout<<res<<endl;

  return 0;
}
