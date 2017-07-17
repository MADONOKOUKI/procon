#include <stdio.h>
#define BOF 1000
#define N 20

int start=0;
int min,num;
int u[N];
int dist[N];
int w[N][N];
int n;

int judge(int u[]){
    int i;
    for(i=0;i<n;i++){
        if(u[i]==1){
            return 1;
        }
    }
    return 0;
}
int main(void){
    int i,j,k;
    scanf("%d",&n);
    while(scanf("%d %d %d",&i,&j,&k)!=BOF){
        w[i][j]=k;
        k=BOF;
    }
    for(i=0;i<N;i++){
        dist[i]=BOF;
        u[i]=1;
        for(j=0;j<N;j++){
            w[i][j]=BOF;
        }
    }
    dist[0]=0;
    u[0]=0;
    while(judge(u)){
        min=BOF;
        for(i=0;i<n;i++){
            if(w[start][i]!=BOF){
                if(dist[i]==BOF){
                    dist[i]=0;
                    dist[i]=w[start][i]+dist[start];
                }
                if(dist[start]+w[start][i]<dist[i]){
                    dist[i]=dist[start]+w[start][i];
                }
            }else if(w[i][start]!=BOF){
                if(dist[i]==BOF){
                    dist[i]=0;
                    dist[i]=w[i][start];
                }
                if(dist[start]+w[i][start]<dist[i]){
                    dist[i]=dist[start]+w[i][start];
                }
            }
        }
        for(i=0;i<n;i++){
            if(u[i]==1){
                if(min>dist[i]){
                    min=dist[i];
                    num=i;
                }
            }
        }
        start=num;
        u[start]=0;
    }
    printf("%d\n",dist[1]);
    return 0;
}