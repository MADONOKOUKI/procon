#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_E 100000
#define MAX_V 10000
int v,e,a,b;
vector<int> G[MAX_V+1];
int keika[MAX_V+1];
int spent=1;
int level[MAX_V+1];
int visited[MAX_V+1];
void toporogicalsort(int n){
  keika[n]=spent;
  spent++;
  for(int i=0;i<G[n].size();i++){
    toporogicalsort(G[n][i]);
  }
}

int main(){
  cin>>v>>e;
  for(int i=0;i<e;i++){
    cin>>a>>b;
    G[a].push_back(b);
  }
  for(int i=0;i<v;i++){
    toporogicalsort(i);
  }
  int pos=0;
  for(int i=0;i<v;i++){
    pos=0;
    for(int j=0;j<v;j++){
      if(i==j){
        continue;
      }
      if(keika[i]>keika[j]){
        pos++;
      }
    }
    level[pos]=i;
  }
  for(int i=0;i<v;i++){
    cout<<level[i]<<endl;
  }

  return 0;
}