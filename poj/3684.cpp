#include <iostream>
#include <math.h>
#include <algorithm>
const double g = 10.0;
using namespace std;
#define MAX_N 100
//入力
int rep;
int n,h,r,T;
//最終的なボールの位置
double y[MAX_N+1];

double calc(int T){
  if(T<0){
    return h;
  }
  double t = sqrt(2*h/g);
  int k = (int)(T/t);
  if(k%2==0){
    double d = T - k * t;
    return h - g*d*d/2;
  } else {
    double d = T-k*t-t;
    return h-g*d*d/2;
  }
}
int main(){
  cin>>rep;
  for(int k=0;k<rep;k++){
    cin>>n>>h>>r>>T;
  for(int i=0;i<n;i++){
    y[i]=calc(T-i);
  }
  sort(y,y+n);
  for(int i=0;i<n;i++){
    printf("%.2f%c",y[i]+2*r*i/100.0,i+1==n ? '\n' : ' ');
  }
}
  return 0;
}