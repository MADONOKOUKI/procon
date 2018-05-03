#include <bits/stdc++.h>
#define int long long
using namespace std;

int R, B, x, y;

bool check(int cnt){

  int R2 = R, B2 = B;
  int x2 = x, y2 = y;

  R2 -= cnt, B2 -= cnt;

  if( R2 < 0 || B2 < 0 ) return false;

  return R2 / (x2-1) + B2 / (y2-1) >= cnt;
}

signed main(){

  cin>>R>>B>>x>>y;

  int l = 0, r = 1e18;

  while( l + 1 < r ){

    int m = ( l + r ) / 2;

    if( check(m) ) l = m;
    else r = m;

  }

  cout<<l<<endl;

  return 0;
}
