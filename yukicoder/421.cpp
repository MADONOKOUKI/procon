
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;

int N, M;
string field[55];

#define MAX_V 2505
int V;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void init_graph(){
  for(int i=0; i<MAX_V; i++){
    G[i].clear();
    match[i] = -1;
    used[i] = false;
  }
}
void add_edge(int u, int v){
  G[u].push_back(v);
  G[v].push_back(u);
}
bool dfs(int v){
  used[v] = true;
  for(int i=0; i<G[v].size(); i++){
    int u = G[v][i], w = match[u];
    if(w<0||(!used[w]&&dfs(w))){
      match[v] = u;
      match[u] = v;
      return true;
    }
  }
  return false;
}
int bipartite_matching(){
  int res = 0;
  rep(i,MAX_V) match[i] = -1;
  for(int v=0; v<V; v++){
    if(match[v] < 0){
      rep(i,MAX_V) used[i] = false;
      if(dfs(v)){
        res++;
      }
    }
  }
  return res;
}

int vx[4] = {0,0,1,-1};
int vy[4] = {1,-1,0,0};

int main(){
  ios::sync_with_stdio(false);

  int b_cnt = 0;
  int w_cnt = 0;
  map< pair<int,int>, int> b_memo, w_memo;
  init_graph();

  cin >> N >> M;
  rep(i,N){
    cin >> field[i];
    rep(j,M){
      if(field[i][j] == 'b'){
        b_memo[make_pair(i,j)] = b_cnt++;
      }
      if(field[i][j] == 'w'){
        w_memo[make_pair(i,j)] = w_cnt++;
      }
    }
  }
  
  V = b_cnt + w_cnt;
  
  rep(i,N){
    rep(j,M){
      if(field[i][j] == 'b'){
        rep(k,4){
          int nx = j + vx[k];
          int ny = i + vy[k];
          if(0<=nx && nx<M && 0<=ny && ny<N){
            if(field[ny][nx] == 'w'){
              int bn = b_memo[make_pair(i,j)];
              int wn = w_memo[make_pair(ny,nx)];

              add_edge(bn, b_cnt+wn);
            }
          }
        }
      }
    }
  }

  ll ret = 0;
  
  int bm = bipartite_matching();
  ret = bm * 100;

  b_cnt -= bm;
  w_cnt -= bm;
  
  int mn = min(b_cnt,w_cnt);
  ret += mn * 10;

  b_cnt -= mn;
  w_cnt -= mn;
  ret += b_cnt + w_cnt;

  cout << ret << endl;
  
  return 0;
}