#include <iostream>
#include <algorithm>
#define INF 1000000
#define MAX_N 10000
using namespace std;
int n,k;
int v[MAX_N];
int w[MAX_N];
double y[MAX_N]; //v-x*w;

bool C(double x){
  for(int i=0;i<n;i++){
    y[i]=v[i]-w[i]*x;
  }
  sort(y,y+n,greater<double>());
  //yの大きい方からk個の和を計算
  double sum = 0;
  for(int i=0;i<k;i++){
    sum+=y[i];
  }

  return sum>=0;
}


int main(){
  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>w[i];
    cin>>v[i];
  }
  double lb=0,ub=INF;
  //100回で大体の値が出るからいい
  //100回やると0.75。while文で時間気にせずにやると0.95となる
  for(int i=0;i<100;i++){
    double mid=(ub+lb)/2;
    if(C(mid)){
      lb=mid;
    } else {
      ub=mid;
    }
  }
  printf("%.2f\n",ub); 
  return 0;
}