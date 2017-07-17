#include <iostream>
#include <algorithm>
#include <math.h>
#define MAX_N  10000
#define INF  100000000

using namespace std;
int n,k;
double L[MAX_N+1];

//条件をみたすかどうか判定
bool C(double x){
  int num=0;
  for(int i=0;i<n;i++){
    num += (int)(L[i]/x);
  }
  return num>=k;
}

void solve(){
  //解の存在範囲を初期化
  double lb=0,ub=INF;
  //解の存在範囲が十分狭くなるまで繰り返す
  for(int i=0;i<100;i++){
    double mid = (lb+ub)/2;
    if(C(mid)){
      lb=mid;
    } else {
      ub=mid;
    }
  }

  printf("%.2f\n",floor(ub*100)/100);
}

int main(){
  cin>>n;
  cin>>k;
  for(int i=0;i<n;i++){
    cin>>L[i];
  }
  solve();
  return 0;
}