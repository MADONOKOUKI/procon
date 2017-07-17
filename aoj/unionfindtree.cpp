#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N=10000;
int par[MAX_N];
int rank[MAX_N];
int N,K;
int T[MAX_N],X[MAX_N],Y[MAX_N];
//n要素で初期化
void init(int n){
  for(int i=0;i<n;i++){
    par[i]=i;
    rank[i]=0;
  }
}

//木の根を求める
int find(int x){
  if(par[x]==x){
    return x;
  } else {
    return par[x]=find(par[x]);
  }
}
//xとyの属する集合を併合
void unite(int x,int y){
  x=find(x);
  y=find(y);
  if(x==y){
    return ;
  }
  if(rank[x]<rank[y]){
    //xの親をyにする
    par[x]=y;
  } else {
    par[y]=x;
    if(rank[x]==rank[y]){
      rank[x]++;
    }
  }
}
//配列のindexが数の番号で格納されている数が親の根の数
//xとyが同じ集合に属するか否か
bool same(int x,int y){
  return find(x)==find(y);
}


int main(){
  cin>>N;
  cin>>K;
  
  init(N*3);

  int ans=0;
  for(int i=0;i<K;i++){
    int t=T[i];
    int x=X[i]-1;
    int y=Y[i]-1;
    //正しくない番号
    if(x<0||N<=x||y<0||N<=y){
      ans++;
      continue;
    }
    if(t==1){
      //xとyは同じ種類という情報
      if(same(x,y+N)||same(x,y+2*N)){
        ans++;
      } else {
        unite(x,y);
        unite(x+N,y+N);
        unite(x+N*2,y+N*2);
      }
    } else {
      //xはyを食べるという情報
      if(same(x,y)||same(x,y+2*N)){
        ans++;
      } else {
        unite(x,y+N);
        unite(x+N,y+2*N);
        unite(x+N*2,y);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}