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

double EPS = 1e-10;
int n;
P p[MAX_N+1],q[MAX_N+1];
int m;
int a[MAX_N+1],b[MAX_N+1];

//誤差を考慮して足し算を行う
bool g[MAX_N+1][MAX_N+1];

struct P{
  double x,y;
  P(){}
  P(double x,double y){
    x(x),y(y)
  }
  P operator + (P p){
    return P(add(x,p.x),add(y,p.y));
  }
  P operator - (P p){
    return P(add(x,-p.x),add(y,-p.y));
  }
  P operator * (double d){
    return P(x*d,y*d);
  }
  double dot(P p){ //内積
    return add(x*p.x,y*p.y);
  }
  double det(P p){ //外積
    return add(x*p.y,-y*p.x);
  }
};

//線分p1-p2上に点qがあるか判定
bool on_seg(P p1,P p2,P q){
  return (p1-q).det(p2-q)==0&&(p1-q).dot(p2-q)<=0;
}

//直線p1-p2のと直線q1-q2の交点
P intersection(P p1,P p2,P q1,P q2){
  return p1 + (p2-p1) * ((q2-q1).det(q1-p1)/(q2-q1).det(p2-p1));
}

int main(){
  int v,w;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>v>>w;
    p[i](v,w)
    cin>>v>>w;
    q[i](v,w);
  }
  for(int i=0;i<n;i++){
    cin>>v>>w;
    a[i]=v;
    b[i]=w;
  }
  for(int i=0;i<n;i++){
    g[i][i]=true;
    for(int j=0;j<n;j++){
      //棒iと棒jが共有点を持つか判定
      if((p[i]-q[i]).det(p[j]-q[j])==0){
        //平行な場合
        g[i][j]=g[j][i]=on_seg(p[i],q[i],p[j])
        ||on_seg(p[i],q[i],q[j])
        ||on_seg(p[j],q[j],p[i])
        ||on_seg(p[j],q[j],q[i]);
      } else {
        //平行でない場合
        P r = intersection(p[i],q[i],p[j],q[j]);
        g[i][j] = g[j][i] = on_seg(p[i],q[i],r) && on_seg(p[j],q[j],r);
      }
    }
  }
  //ワーシャルフロイド法で全点間の連結判定を行う
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        g[i][j] |= g[i][k] && g[k][j];
      }
    }
  }
  
  for(int i=0;i<m;i++){
    puts(g[a[i]-i][b[i]-1] ? "CONNECTED" : "NOT CONNECTED");
  }
  return 0;
}