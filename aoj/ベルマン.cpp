#include <iostream>
#include <algorithm>

using namespace std;
#define INF 1<<30
#define MAX_E 500000
#define MAX_V 100000
int v,e,r;
int s,t,d;
int ans=0;
bool update=false;
struct edge{
  int from,to,cost;
};
edge es[MAX_E+1];
int dist[MAX_V+1];


void shortest_path(int n){
  fill(dist,dist+v,INF);
  dist[n]=0;
  while(true){
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
}
int main(){
  cin>>v;
  cin>>e;
  cin>>r;
  for(int i=0;i<e;i++){
    cin>>es[i].from;
    cin>>es[i].to;
    cin>>es[i].cost;
   }
   shortest_path(r);
  if(ans>v){
    cout<<"NEGATIVE CYCLE"<<endl;
    return 0;
  } else {
  for(int i=0;i<v;i++){
    if(dist[i]==INF){
      cout<<"INF"<<endl;
    } else {
      cout<<dist[i]<<endl;
    }
  }
}
  return 0;
}