#include <stdio.h>
#include <stdlib.h>

#define MAXN 800
#define INF 2000000000

typedef struct {
  int n1,n2;//橋がかかっている島の番号
  int len;//橋の長さ
  int rm;//撤去済み
} edge_t;
edge_t e[MAXN-1];
//島のデータ構造
typedef struct {
  int ne;//橋の数(degree)
  int re;//degree1の島の橋撤去後の橋の数
  int eid[MAXN-1];//この島にかかっている橋のID
} node_t;
node_t nd[MAXN];

int n; //島の数(3<=n<=800)
int c1; //degreeが1の島にかかっている橋のコストの総和
int c2;//degreeが1以外の島にかかっている橋のコストの総和
int maxd; //島間の距離の最大値

//島間の距離の最大値を求める
//pn=直前の島、cn＝現在の島,d=現在の島までの距離
void find_maxd(int pn,int cn,int d){
  int i,edge;
  if(d>maxd){
    maxd=d;
  }
  for(i=0;i<nd[cn].ne;i++){
    edge = nd[cn].eid[i];//橋のID
    if(e[edge].rm){
      continue;
    }
    if(e[edge].n1 == pn || e[edge].n2 == pn){
      continue;
    }
    //この橋を渡り、島間距離の最大値を再帰的に更新
    if(e[edge].n1!=cn){
      find_maxd(cn,e[edge].n1,d+e[edge].len);
    } else {
      find_maxd(cn,e[edge].n2,d+e[edge].len);
    }
  }
}
int main(){
  int i,j,k;
  while(1){
    scanf("%d",&n);//島の数を入力
    if(n==0){//nが0なら終了
      break;
    }//島のデータの初期化
    for(i=0;i<n;i++){
      nd[i].ne=0;
    }
      c1=c2=maxd=0;
    for(i=0;i<n-1;i++){//橋のデータを読み込む
      int i1,i2;//橋のかかっている島のID(0~n-1)
      scanf("%d",&i1);
      i1--;//この橋がかかっている島のID
      e[i].n1=i1;
      e[i].n2=i2=i+1;//この橋がかかっているもう一つの島のID
      nd[i1].eid[nd[i1].ne++]=i;//2つの島に橋IDをセット
      nd[i2].eid[nd[i2].ne++]=i;
  }
  for(i=0;i<n-1;i++){//各橋の長さを読み込む
    scanf("%d",&e[i].len);
    e[i].rm=0;
  }

  //degreeが1の橋はその橋をわたることなく撤去できる
  for(i=0;i<n-1;i++){//各橋iに対して
    //この端が結ぶ島のどちらかを渡ることなく撤去できる
    if(nd[e[i].n1].ne==1||nd[e[i].n2].ne==1){
      e[i].rm=1;//橋を撤去
      c1+=e[i].len;//撤去費用をc1に加算
    } else {
      c2+=e[i].len;//そうでなければ撤去費用をc2に加算
    }
  }
  for(i=0;i<n;i++){
    if(nd[i].ne==1){
      continue;
    }
    find_maxd(-1,i,0);
  }
  printf("%d\n",c1+3*c2-maxd);  
}
  return 0;
}


/*
#include <stdio.h>
#define N 100000
int NODE[N][N];
int island[800];
//int dob[N]={0};

int max_long;
int count_;

int dps(int a,int distance,int pre,int pre_long,int n){
  //printf("a==%d distance==%d\n",a,distance);
  int test=0;
  int i,index=0,dis=0;
  for(i=2;i<=n;i++){
    if((island[i]==a&&pre!=i)||(i==a&&pre!=i)){
      test++;
    }
  }
  if(test>0){
  for(i=2;i<=n;i++){
    if(island[i]==a&&dis<NODE[i][island[i]]&&pre!=i&&pre!=island[i]){
        dis=NODE[i][island[i]];
        index=i;
      //  printf("入れました！");
    } if(i==a&&dis<NODE[i][island[i]]&&pre!=island[i]){
        dis=NODE[i][island[i]];
        index=island[i];
    //     printf("入れました！!!!!!!!!!!!!!!!");
    } 
  }
  if(index!=0){
  distance+=dis;
  dps(index,distance,a,dis,n);
  } 
}
  //  printf("何も入らなかった");
    if(max_long<distance-NODE[pre][a]){
    max_long=distance-NODE[pre][a];
  }
  return distance-NODE[pre][a];
  
}
int is(int m[],int n){
  int i,j;
  for(i=2;i<n;i++){
    for(j=i+1;j<=n;j++){
    if(m[i]==m[j]){
      return 1;
    }
  }
  }
  return 0;
}
int main(){
  int i,j,freq;
  int n,count;
  int box=0;
  int connect=0;
  while(1){
    connect=0;
    box=0;
    max_long=0;
    count=0;
    count_=0;
  scanf("%d",&n);
  if(n==0){
    break;
  }
  for(i=2;i<=n;i++){
    scanf("%d",&island[i]);
  //printf("%d\n",island[i]);
  }
  for(i=2;i<=n;i++){
    freq=0;
    scanf("%d",&NODE[i][island[i]]);
    NODE[island[i]][i]=NODE[i][island[i]];
    count+=NODE[i][island[i]];
    //printf("%d\n",count);
    for(j=2;j<=10;j++){
      if(island[j]==i){
        if(connect==0){
          connect=island[j];
        } else if(connect!=0&&connect!=-1&&connect!=island[j]){
          connect=-1;
        }
        freq++;
      }
    }
    if(freq>1){
      count_+=NODE[i][island[i]];
    }
    //printf("%d\n",NODE[i][island[i]]);
  }
  for(i=1;i<=n;i++){
      for(j=2;j<=10;j++){
        if(island[j]==i){
            box=dps(i,0,0,0,n);
      //printf("max_long==%d\n",max_long);
      break;
    }
  }
}
  //printf("%d\n",count);
  //printf("count_==%d\n",count_);
if(connect!=-1){
  //printf("%d\n",count);
  //printf("%d\n",count);
  printf("%d\n",count);
} else if(is(island,n)==0){
//printf("%d\n",count);
printf("%d\n",count);
} else {
printf("%d\n",count+count_*2-max_long);
}
  }
  return 0;
}*/