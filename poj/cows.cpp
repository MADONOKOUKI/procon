#include <iostream>
#include <algorithm>

#define MAX_N 100000
#define INF 10000000
using namespace std;
int n,m;
int x[MAX_N+1];//10^9

bool C(int d){
  int last=0;
  for(int i=1;i<m;i++){
    int crt = last+1;
    while(crt<n&&x[crt]-x[last]<d){
      crt++;
    }
    if(crt==n){
      return false;
    } 
    last=crt;
  }
  return true;
}

int main(){
  
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>x[i];
  }

  //はじめにxをソートしておく
  sort(x,x+n);
  int lb=0,ub=INF;
  
  //解の存在範囲を初期化
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(C(mid)){
      lb=mid;
    } else {
      ub=mid;
    }
  }

  printf("%d\n",lb);
  return 0;
}