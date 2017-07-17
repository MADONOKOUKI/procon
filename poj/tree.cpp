// g++ temp.cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <climits>
using namespace std;

#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,n) FOR(i,0,n)
#define EACH(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
const unsigned long long MOD = 100000000000000000;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;

#define INF INT_MAX/3
#define MAX_N 1000

struct edge {
  int to;
  int length;
  edge () {};
  edge(int _to,int _length) : to(_to),length(_length) {};
};

// 入力
int N,K;
vector<edge> G[MAX_N+1];

//その頂点がすでに分割に用いられているか
bool centroid[MAX_N+1];
//その頂点を寝とする部分木のサイズ
int subtree_size[MAX_N+1];

int ans;//答え

//部分木のサイズ(subtree_size)を計算する再帰関数
int compute_subtree_size(int v,int p){
  int c=1;
  for(int i=0;i<G[v].size();i++){
    int w = G[v][i].to;
    if(w==p||centroid[w]){
      continue;
    }
    c += compute_subtree_size(G[v][i].to,v);
  }
  subtree_size[v]=c;
  return c;
}

//重心となる頂点を探す再帰関数。tは連結成分全体の大きさ
//v以下で、削除により残る最大の部分木の頂点数が最小となる頂点の
//（残る最大の部分木の頂点数,頂点番号)のペアを返す
pair<int, int> search_centroid(int v,int p,int t){
  pair<int,int> res=make_pair(INT_MAX,-1);
  int s=1,m=0;
  for(int i=0;i<G[v].size();i++){
    int w = G[v][i].to;
    if(w==p||centroid[w]){
      continue;
    }
    res = min(res,search_centroid(w,v,t));
    m = max(m,subtree_size[w]);
    s += subtree_size[w];
  }
  m = max(m,t-s);
  res = min(res,make_pair(m,v));
  return res;
}

//部分木に含まれる頂点の重心までの距離を列挙する再帰関数
void enumerate_paths(int v,int p,int d,vector<int> &ds){
  ds.push_back(d);
  for(int i=0;i<G[v].size();i++){
    int w = G[v][i].to;
    if(w==p||centroid[w]){
      continue;
    }
    enumerate_paths(w,v,d+G[v][i].length,ds);
  }
}


//和がK以下と成る組の数を求める
int count_pairs(vector<int> &ds){
  int res = 0;
  sort(ds.begin(),ds.end());
  int j = ds.size();
  for(int i=0;i<ds.size();i++){
    while(j>0&&ds[i]+ds[j-1]>K){
      --j;
    }
    //自分自身とのペアは除く
    res += j - (j>i ? 1:0);
  }
  return res/2;
}

//頂点vが属する部分木に関して重心を探し、木を分割し問題を解く再帰関数
void solve_subproblem(int v){
  //重心となる頂点sを探す
  compute_subtree_size(v,-1);
  int s = search_centroid(v,-1,subtree_size[v]).second;
  centroid[s]=true;

  //(1)頂点により分割した部分木の中に関して数える
  for(int i=0;i<G[s].size();i++){
    if(centroid[G[s][i].to]){
      continue;
    }
    solve_subproblem(G[s][i].to);
  }
  //(2),(3)：頂点sを通る頂点の組に関して数える
  vector<int> ds;
  ds.push_back(0);//頂点sの分
  for(int i=0;i<G[s].size();i++){
    if(centroid[G[s][i].to]){
      continue;
    }
    vector<int> tds;
    enumerate_paths(G[s][i].to,s,G[s][i].length,tds);

    ans -= count_pairs(tds);//重複して数えてしまう分を予め引いておく
    ds.insert(ds.end(),tds.begin(),tds.end());
  }
  ans += count_pairs(ds);
  centroid[s]=false;
}
void solve(){
  ans = 0;
  solve_subproblem(0);
  printf("%d\n",ans);
}
int main(){
  while(1){
  cin>>N>>K;
  if(N==0&&K==0) break;
  int x,y,z;
  for(int i=0;i<K;i++){
    cin>>x>>y>>z;
    G[x].push_back(edge(y,z));
    G[y].push_back(edge(x,z));
  }
  solve();
  } 
  return 0;
}