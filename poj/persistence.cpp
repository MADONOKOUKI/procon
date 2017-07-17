#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100
const int INF=1<<24;
int m,n;
int a[MAXN+1];

bool C(double l){
  int i=0;
  int j=0;
  int s=0;
  while(i<n&&j<m){
    if(s+a[i]<=l){
      s+=a[i++];
    } else {
      s=0;
      j++;
    }
  }
  return j<m&&i==n;
}

int main(){
  while(true){
  int mid=0;
  cin>>m>>n;
  if(m==0&&n==0){
    break;
  }
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
 // sort(a,a+n);
  int lb=0,ub=INF;
  for(int i=0;i<100;i++){
    mid=(lb+ub)/2;
    if(C(mid)){
      ub=mid;
    } else {
      lb=mid;
    }
  }
  printf("%d\n",ub);
  }
  return 0;
}