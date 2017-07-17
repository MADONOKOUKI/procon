#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000000
#define INF 10000000
int N,ML,MD;
int AL[MAX_N+1],BL[MAX_N+1],DL[MAX_N+1];
int AD[MAX_N+1],BD[MAX_N+1],DD[MAX_N+1];

int d[MAX_N];//最短距離
bool updated;//更新されたか

void update(int& x,int y){
  if(x>y){
    x=y;
    updated=true;
  }
}

//ベルマンフォード法により、dを計算する

void bellmanford(){
  for(int k=0;k<=N;k++){
    updated=false;
    //i+1からiへのコスト
    for(int i=0;i+1<N;i++){
      if(d[i+1]<INF){
        update(d[i],d[i+1]);
      }
    }
    //ALからBLへコストDL
      for(int i=0;i<ML;i++){
        if(d[AL[i]-1]<INF){
          update(d[BL[i]-1],d[AL[i]-1]+DL[i]);
        }
      }
        //BDからADへのコスト-DD
        for(int i=0;i<MD;i++){
          if(d[BD[i]-1]<INF){
            update(d[AD[i]-1],d[BD[i]-1]-DD[i]);
          }
        }
      }
    }

void solve(){
  //負の閉路のチェック
  fill(d,d+N,0);
  bellmanford();
  if(updated){
    cout<<"-1"<<endl;
    return ;
  }

  fill(d,d+N,INF);
  d[0]=0;
  bellmanford();
  int res=d[N-1];
  if(res==INF){
    res=-2;
  }
  cout<<res<<endl;
}

int main(){
  cin>>N;
  cin>>ML;
  cin>>MD;
  for(int i=0;i<ML;i++){
    cin>>AL[i];
    cin>>BL[i];
    cin>>DL[i];
  }
  for(int i=0;i<MD;i++){
    cin>>AD[i];
    cin>>BD[i];
    cin>>DD[i];
  }
  solve();
  return 0;
}

