#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#define MAXV 100
#define MAXE 1000

using namespace std;
vector<int> G[MAXV+1];
int v,e,s,t;
int ans=0;
bool visiting[MAXV+1];
int visited[MAXV+1];
void dfs(int n){
  visited[n]=1;
  visiting[n]=true;
  for(int i=0;i<G[n].size();i++){
    int es=G[n][i];
    if(!visited[es]){
      dfs(es);
    } else if(visiting[es]==true) {
      ans=1;
      return ;
    }
  }
  visiting[n]=false;
  return ;
}


int main(){
  cin>>v>>e;
  for(int i=0;i<e;i++){
    cin>>s>>t;
    G[s].push_back(t);
  }
  memset(visited,0,sizeof(visited));
  memset(visiting,0,sizeof(visiting));
  for(int i=0;i<v;i++){
    if(!visited[i]){
      dfs(i);
    }
  }
  cout<<ans<<endl;
  return 0;
}