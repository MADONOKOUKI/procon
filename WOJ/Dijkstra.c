#include <stdio.h>
#define BOF 1000
#define N 20

int start=0;//始点（順次変わる)
int min,num;//最小の距離とその番号を確保しておく
int u[N];//すでに走査済みかを判断
int dist[N];//距離の確保
int pre[N];//前の接点の番号を確保
int w[N][N];//長さ確保
int n;//要素数確保

int main(void){
    int i,j,k;
    scanf("%d",&n);
    //初期化
    for(i=0;i<n;i++){
        dist[i]=BOF;
        u[i]=1;
        pre[i]=0;
        for(j=0;j<N;j++){
            w[i][j]=BOF;
        }
    }
    //枝の長さの標準入力
    while(scanf("%d %d %d",&i,&j,&k)!=EOF){
        w[i][j]=k;
    }
    dist[0]=0;
    u[0]=0;
    int m=n;
    //要素数だけループ
   while(m--){
       min=BOF;
        for(i=0;i<n;i++){
          //もし長さが入力されていて逆走するものでなければ処理
        if(w[start][i]!=BOF&&pre[start]!=i){
            if(dist[i]==BOF){//初回は0に初期化してから代入
                dist[i]=0;
                dist[i]=w[start][i]+dist[start];
                //枝の長さとそれまでに通った枝の長さ
                pre[i]=start;
            }
           if(dist[start]+w[start][i]<dist[i]){
              dist[i]=dist[start]+w[start][i];
              pre[i]=start;
           }
        }else if(w[i][start]!=BOF&&pre[start]!=i){
            if(dist[i]==BOF){
                dist[i]=0;
                dist[i]=w[i][start]+dist[start];
            pre[i]=start;
            }
            if(dist[start]+w[i][start]<dist[i]){
              dist[i]=dist[start]+w[i][start];
            pre[i]=start;
           }

        }
        }
        u[start]=0;//使用済みの事実更新
        for(i=0;i<n;i++){
            if(u[i]==1){
                if(min>dist[i]){
                 min=dist[i];
                 num=i;
                }
            }
        }
        start=num;//次の始点を確保する
     /*   for(i=0;i<n;i++){
            printf("%d ",dist[i]);
        }
        printf("\n");
        for(i=0;i<n;i++){
            printf("%d ",pre[i]);
        }
        printf("\n");
        for(i=0;i<n;i++){
            printf("%d ",u[i]);
        }
        printf("\n");
        printf("%d\n",num);
        */
    }
    printf("%d\n",dist[1]);//出力
    return 0;
}