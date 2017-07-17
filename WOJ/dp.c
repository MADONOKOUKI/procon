#include <stdio.h>
#include <string.h>
#define N 4096
#define unknown -1
int i=0,j;
int n[N][N];
char c[N],d[N];
int dp(int c,int d);
int diagonal(int a,int b);
int min(int k,int j){
    if(k>j){
        return j;
    } else {
        return k;
    }
}
int main(void){
    scanf("%s",c);
    scanf("%s",d);
    printf("%lu\n",strlen(c));
    printf("%lu\n",strlen(d));
     for(i=1;i<=strlen(c);i++){
       for(j=1;j<strlen(d);j++){
         n[i][j]=unknown;
       }
     }
    n[0][0]=0;
    for(i=1;i<=strlen(c);i++){
        n[i][0]=i;
    }
    for(j=1;j<=strlen(d);j++){
        n[0][j]=j;
    }
    for(i=1;i<=strlen(c);i++){
      for(j=1;j<=strlen(d);j++){
        n[i][j]=dp(i,j);
      }
    }
    printf("%d\n",n[strlen(c)][strlen(d)]);
    return 0;
}

int dp(int a,int b){
    if(n[a][b]!=unknown){
      return n[a][b];
    }
    int ddp;
    ddp=min(dp(a-1,b)+1,min(dp(a,b-1)+1,dp(a-1,b-1)+diagonal(a,b)));
    return ddp;
}
int diagonal(int a,int b){
    if(c[a-1]==d[b-1]){
        return 0;
    }
    return 1;
}
