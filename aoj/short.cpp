#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define INF -100000*210
#define MAX_E 500000
#define MAX_V 100
typedef long long ll;
ll  v,e,r;
ll  s,t,d;
ll  ans=0;
//bool update=false;
ll  a,b;
//struct edge{
  //int from,to,cost;
//};
//edge es[MAX_E+1];
//int dist[MAX_V+1];
ll cost[MAX_V+1][MAX_V+1];

ll  minmin( int c,  int d){
  if(c>d){
  return c;
  }
  return d;
}

void dijikstra(){
  //fill(dist,dist+v,INF);
  //dist[n]=0;
  /*while(true){
    update=false;
    for(int i=0;i<e;i++){
      edge e = es[i];
      if(dist[e.from] != INF && dist[e.to] >dist[e.from]+e.cost){
        dist[e.to]=dist[e.from]+e.cost;
        update=true;
      }
    }
    ++ans;
    if(ans>v){
      break;
    }
    //updateされなくなったら終了
    if(!update){
      break;
    }
   }
   */
   for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
      for(int k=0;k<v;k++){
        if(i==j){
          continue;
        }
        cost[i][j]=minmin(INF,minmin(cost[i][j],cost[i][k]+cost[k][j]));
        }
    }
  }
}
int main(){
  cin>>v;
  cin>>e;
  //cin>>r;
  for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
      if(i==j){
        cost[i][j]=0;
      } else {
        cost[i][j]=INF;
     }
   }
  }
  for(int i=0;i<e;i++){
    cin>>a;
    cin>>b;
    cin>>cost[a][b];
   }
   dijikstra();
   dijikstra();
   for(int i=0;i<v;i++){
    if(cost[i][i]<0){
      cout<<"NEGATIVE CYCLE"<<endl;
      return 0;
    }
   }
   for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
      if(j==v-1){
      if(cost[i][j]==INF){
        printf("INF");
      } else{
        printf("%lld",cost[i][j]);
      }
    } else {
      if(cost[i][j]==INF){
        printf("INF ");
      } else{
        printf("%lld ",cost[i][j]);
      }
    }
  }
    printf("\n");
   }
  return 0;
}