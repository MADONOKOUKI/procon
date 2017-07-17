#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAX_N 40
#define INF 100000
typedef long long ll;

int n;
ll w[MAX_N+1],v[MAX_N+1];
ll W;

pair<ll,ll> ps[1<<(MAX_N/2)];//(重さ,価値)

int main(){
  //前半部を全列挙
  int n2 = n/2;
  for(int i=0;i<1<<n2;i++){
    ll sw=0,sv=0;
    for(int j=0;j<n2;j++){
      if(i>>j&1){
        sw += w[j];
        sv += v[j];
      }
    }
    ps[i] = make_pair(sw,sv);
  }
  //無駄な要素を取り除く
  sort(ps,ps+(1<<n2));
  int m = 1;
  for(int i = 1;i<1<<n2;i++){
    if(ps[m-1].second < ps[i].second){
      ps[m++] = ps[i];
    }
  }
  //後ろ半分を全列挙し解を求める
  ll res=0;
  for(int i=0;i<1<<(n-n2);i++){
    ll sw = 0,sv = 0;
    for(int j=0;j<n-n2;j++){
      if(i>>j&1){
        sw += w[n2+j];
        sv += v[n2+j];
      }
    }
    if(sw <= W){
      ll tv = (lower_bound(ps,ps+m,make_pair(W-sw,INF))-1)->second;
      res = max(res , sv+tv);
    }
  }
  printf("%lld\n",res);
  return 0;
}