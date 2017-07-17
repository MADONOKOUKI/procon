#include  <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_V=10000;
vector<int> G[MAX_V];//グラフ
int V;
int color[MAX_V];//頂点iの色(1or0)
//頂点を1と-1で塗っていく
bool dfs(int v,int c){
  color[v]=c;//頂点vをcで塗る
  for(int i=0;i<G[v].size();i++){
    //隣接している頂点が同じ色ならfalse
    if(color[G[v][i]]==c){
      return false;
    }
    //隣接している頂点がまだ塗られていないなら-cで塗る
    if(color[G[v][i]]==0&&!dfs(G[v][i],-c)){
      return false;
    }
  }
    return true;
}

int main(){
  cin>>V;
  for(int i=0;i<V;i++){
    if(color[i]==0){
      if(!dfs(i,1)){
        cout<<"NO"<<endl;
        return 0;
      }
    }
  }
  cout<<"YES"<<endl;
  return 0;
}
