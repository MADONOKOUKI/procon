#include <iostream>
#include <string>
using namespace std;
const int VMAX = 106;
const int EMAX = 10000;
const long long int INF = 100000000000;

long long int dist[VMAX][VMAX];

void init(int V){
  for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
      dist[i][j]=(i==j?0:INF);
    }
  }
}

void wf(int v){
  for(int k=0;k<v;k++){
    for(int i=0;i<v;i++){
      for(int j=0;j<v;j++){
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
      }
    }
  }
}

bool has_negcycle(int v){
  for(int i=0;i<v;i++){
    if(dist[i][i]<0){
      return true;
    }
  }
  return false;
}


int main(){
  int v,e;
  cin>>v>>e;

  init(v);
  for(int i=0;i<e;i++){
    int s,t,d;
    cin>>s>>t>>d;
    dist[s][t]=d;
  }
  wf(v);

  if(has_negcycle(v)){
    cout<<"NEGATIVE CYCLE"<<endl;
  } else {
    for(int i=0;i<v;i++){
      for(int j=0;j<v;j++){
        if(dist[i][j]>=INF/2){
          cout<<"INF";
        } else if(dist[i][j]==0){
          cout<<0;
        } else {
          cout << dist[i][j];
        }
        if(j<v-1){
          cout<<" ";
        }
      }
        cout<<endl;
    }
  }
}