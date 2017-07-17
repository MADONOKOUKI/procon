#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_M 50000
#define MAX_V 50000
using namespace std;
int V;
int N,M;
int A[MAX_M+1],B[MAX_M+1];
bool used[MAX_V];
//グラフの隣接リスト表現
vector<int> G[MAX_V];
//辺の向きを逆にしたグラフ
vector<int> rG[MAX_V];
//属する強連結成分のトポロジカル順序
int cmp[MAX_V];
//帰りがけの並び
vector<int> vs;

void add_edge(int from,int to){
  G[from].push_back(to);
  rG[to].push_back(from);
}


void dfs(int v){
  //①使った
  used[v]=true;
  for(int i=0;i<G[v].size();i++){
    if(!used[G[v][i]]){
      dfs(G[v][i]);
    }
  }
  //辿り着いたノードから離れるタイミングでpush_backを行う
  vs.push_back(v);
}

void rdfs(int v,int k){
  //使った証明
  used[v]=true;
  //
  cmp[v]=k;
  for(int i=0;i<rG[v].size();i++){
    if(!used[rG[v][i]]){
      rdfs(rG[v][i],k);
    }
  }
}


int scc(){
  //メモリ0を入れることによってfalseを実現することが出来る
  memset(used,0,sizeof(used));
  vs.clear();
  //
  //まだたどり着いてないところから順に深さ優先探索
  for(int v=0;v<V;v++){
    if(!used[v]){
      dfs(v);
    }
  }
  //もっかい深さ優先探索をするからメモリをセットし直す
  memset(used,0,sizeof(used));
  int k=0;
  //調整で-1してi>=0にしている
  for(int i=vs.size()-1;i>=0;i--){
    if(!used[vs[i]]){
      rdfs(vs[i],k++);
    }
  }
  return k;
}

void solve(){
  V=N;
  //たまたま今回のものが一番小さい成分が1であるため-1している
  for(int i=0;i<M;i++){
    add_edge(A[i]-1,B[i]-1);
  }
  int n = scc();
  //候補となる点の数を調べる
  int u=0,num=0;
  for(int v=0;v<V;v++){
    if(cmp[v]==n-1){
      u=v;
      num++;
    }
  }
  //すべての点から到達可能か調べる
  memset(used,0,sizeof(used));
  rdfs(u,0);//強連結成分分解のコードを再利用
  for(int v=0;v<V;v++){
    if(!used[v]){
      //コンテンから到達不可能
      num=0;
      break;
    }
  }
  printf("%d\n",num);
}

int a,b;

int main(){
  cin>>N;
  cin>>M;
  //連結成分を配列でそれぞれ確保
  for(int i=0;i<M;i++){
    cin>>A[i];
    cin>>B[i];
  }
  solve();
  return 0;
}