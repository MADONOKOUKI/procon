const int MAX_V=1000;

int d[MAX_V][MAX_V];

void warshall_floyd(){
  for(int i=0;i<V;i++){
    for(int k=0;k<V;k++){
      for(int j=0;j<V;j++){
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }
}

int prev[MAX_V];
//始点sから各頂点への最短経路を求める
void dijkstra(int s){
  fill(d,d+V,INF);
  fill(used,used+V,false);
  fill(prev,prev+V,-1);
  d[s]=0;

  while(true){
    int v = -1;
    for(int u=0;u<V;u++){
      if(!used[u]&&(v==-1||d[u]<d[v])){
        v=u;
      }
    }
    if(v==-1){
      break;
    }
    used[v]=true;
  for(int u=0;u<V;u++){
    if(d[u]>d[v]+cost[v][u]){
      d[u]=d[v]+cost[v][u];
      prev[u]=v;
      }
    }
  }

  vector<int> get_path(int t){
    vector<int> path;
    for(;t!=-1;t=prev[t]){
      path.push_back(t);
    }
      //tがsに成るまでprev[t]をたどっていく
      reverse(path.begin(),path.end());
    return path;
  }
}

int cost[MAX_V][MAX_V];//cost[u][v]は辺e=(u,v)のコスト（存在しない場合はINF)
int mincost[MAX_V]//集合Xからの辺の最小コスト
bool used[MAX_V]//頂点iがXに含まれているか
int V;


int prim(){
  for(int i=0;i<V;++i){
    mincost[i]=INF;
    used[i]=false;
  }

  mincost[0]=0;
  int res=0;

  while(true){
    int v=-1;
    //Xに属さない頂点のうちXからの辺のコストが最小になる頂点を探す
    for(int u=0;u<V;u++){
      //もし集合Xに含まれていないかつ、まだ最小コストの道を更新していないか
      //新たに小さい辺を見つけることができれば更新する
      if(!used[u]&&(v==-1||mincost[u]<mincost[v])){
        v=u;
      }
      //もしvが1であったら更新できないということなのでおわり、そんな最小全域木は作ることが出来ない
      if(v==-1){
        break;
      }
      //usedは集合Xに含まれているかどうかを判断するもの
      used[v]=true;//頂点vをXに追加
      res+=mincost[v];//辺のコストを加える

      for(int u=0;u<V;u++){
        mincost[u]=min(mincost[u],cost[v][u]);
      }
    }
    return res;
  }
}


struct edge{
  int u,v;
  int cost;
}

bool comp(const edge& e1,const edge& e2){
  return e1.cost<e2.cost;
}

edge[MAX_E];
int V,E;

int kruskal(){
  sort(es,es+E,comp)//edge.costが小さい順にソートする
  init_union_find(V)//Union-Findの初期化
  int res=0;
  for(int i=0;i<E;i++){
    edge e = es[i];
    if(!same(e.u,e.v)){
      unite(e.u,e.v);
      res += e.cost;
    }
  }
  return res;
}