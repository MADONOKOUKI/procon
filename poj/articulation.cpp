//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>


using namespace std;

vector<int> adjList[100005];

int num[100005],par[100005],low[100005],cnt=1,root,child;
bool vis[100005],art[100005];

void findArt(int u){
  //訪問したためにチェックを付ける
  vis[u]=true;
  //時間をつける
  low[u]=num[u]=cnt++;
  for(int i=0;i<adjList[u].size();i++){
    int v = adjList[u][i];
    if(!vis[v]){
      par[v]=u;//もしまだ訪れていない場所であったらそこに親のノードを挿入する
      if(u==root){//もしuと最初に入れた暫定親が一致していたら、子が一人いるということなのでインクリメントする
        child++;
      }
      findArt(v);//隣接していたノード番号を入れて深さ優先探索
      //この時に
      if(low[v]>=num[u]){
        art[u]=true;
      }
      low[u]=min(low[u],low[v]);
    } else if(par[u] != v){
      low[u]=min(low[u],num[v]);
    }
  }
}

int main(){

  ios_base::sync_with_stdio(0);

  int N,E;
  cin>>N>>E;

  int u,v;
  for(int i=0;i<E;i++){
    cin>>u>>v;

    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  //0をセットする
  memset(num,0,sizeof(num));
  memset(par,0,sizeof(par));
  memset(low,0,sizeof(low));
  memset(vis,0,sizeof(vis));
  memset(art,0,sizeof(art));

  for(int i=0;i<N;i++){
    if(vis[i])continue;
    root = i;
    child=0;
    findArt(i);
    art[root]=(child>1);
  }
  for(int i=0;i<N;i++){
    if(art[i]){
      cout<<i<<endl;
    }
  }
  return 0;
}