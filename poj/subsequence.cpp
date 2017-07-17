#include <iostream>
#include <algorithm>
#define MAXE 100000
using namespace std;
int n,S;
int a[MAXE+1];
int sum[MAXE+1];
int main(){
  int l;
  cin>>l;
  for(int j=0;j<l;j++){
  cin>>n>>S;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int res=n+1;
  int s=0,t=0,sum=0;
  for(;;){
    while(t<n&&sum<S){
      sum += a[t++];
    }
    if(sum < S){
      break;
    }
    res = min(res,t-s);
    sum -= a[s++];
  }
  if(res > n){
    //解が存在しない
    res=0;
  }
  printf("%d\n",res);
  }
  return 0;
}