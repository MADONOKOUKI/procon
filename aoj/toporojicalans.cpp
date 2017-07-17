#include <cstdio>
#include <vector>
using namespace std;

#define MAX_V 10000

typedef int int32_t;


int main(){
  int v,e;
  vector<int> g[MAX_V];
  int n_in[MAX_V]={};
  scanf("%d %d",&v,&e);
  for(int i=0;i<e;i++){
    int t,u;
    scanf("%d %d",&t,&u);
    g[t].push_back(u);
    n_in[u]++;
  }

  //topological sort
  vector<int> s;
  for(int i=0;i<v;i++){
    if(n_in[i]==0){
      s.push_back(i);
    }
  }

  vector<int> done;
  while(!s.empty()){
    int t = s.back();
    s.pop_back();
    done.push_back(t);
    while(!g[t].empty()){
      int u=g[t].back();
      g[t].pop_back();//末尾から先頭要素を取り除く
      if(--n_in[u]==0){
        s.push_back(u);
      }
    }
  }

  for(int i=0;i<v;i++){
    printf("%d\n",done[i]);
  }
  return 0;
}