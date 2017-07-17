#include <stdio.h>
#include <string.h>
#define N 4096
#define unknown -1
int i=0,j,w;
int k,l;
int count=0;
int p,m=0;
int n[N][N];
char c[N][N];
int diagonal(int a,int b,int k,int l){
    // printf("a:%db:%d",a,b);
    if(c[k][a-1]==c[l][b-1]){
        return 0;
    }
     // printf("a:%db:%d",a,b);
    return 1;
}

int min(int k,int j){//小さい値を返す関数
    if(k>j){
        return j;
    } else {
        return k;
    }
}
int dp(int a,int q,int k,int l){
    int ddp;
    printf("%d  %d  %d\n",diagonal(a,q,k,l)+n[a-1][q-1],n[a-1][q]+1,n[a][q-1]+1);
  //  printf("a:%dq:%d",a,q);
     ddp=min(n[a-1][q]+1,min(n[a][q-1]+1,n[a-1][q-1]+diagonal(a,q,k,l)));
 //printf("%d\n",ddp);
 return ddp;
}
int main(void){
    int pre=0;
    int tail=0;
    scanf("%d",&p);
    //printf("%d\n",p);
    for(i=1;i<=1000;i++){
        n[i][0]=i;
    }
    for(j=1;j<=1000;j++){
        n[0][j]=j;
    }
    for(i=1;i<=1000-9;i++){
        n[i][i+9]=9;
    }
    for(j=1;j<=1000-9;j++){
        n[j][j+9]=9;
    }

    while(m<p){
        scanf("%s",c[m]);//文字列の標準入力
    m++;
    }
    m=0;
    for(k=0;k<p-1;k++){
        for(l=k+1;l<p;l++){
           // m=k;
   //printf("%s\n",c[k]);
   // printf("%s\n",c[l]);
   // printf("%lu\n",strlen(c[l]));
    //printf("%lu\n",strlen(c[k]));
        tail=0;
        pre=0;
    
  //  if(strlen(c[k])-strlen(c[l])>9||strlen(c[l])-strlen(c[k])>9){
    //    printf("無理");
      //  continue;
    //}
    //初期化
    // for(i=1;i<=strlen(c[k]);i++){
      // for(j=1;j<strlen(c[l]);j++){
        // n[i][j]=unknown;
       //}
     //}
    //n[0][0]=0;//起点
    //各辺に配列のインデックスの大きさだけ代入する
    //すべての要素に判定しながら全て入れていく
    for(i=1;i<=strlen(c[k]);i++){
      for(j=1;j<=9+tail;j++){
      if(j>strlen(c[l])){
        continue;
      }
      w=j;
      printf("i:%dj:%dtail:%d\n",i,j,tail);
        //printf("%d\n",j);
        if(tail>=9){
            w=tail-7;
        }
      //  printf("i:%dj:%dtail:%d",i,j,tail);
        n[i][w]=dp(i,w,k,l);
        printf("%d\n",n[i][w]);
        if(n[i][i]>9){
     //     printf("%d\n",n[i][i]);
            pre=1;
            break;
        }
        tail++;
    }
      }
     // printf("%d\n",n[strlen(c[k])-1][strlen(c[l])-1]);
       //printf("%d\n",pre);
    if(!pre&&n[strlen(c[k])-1][strlen(c[l])-1]<10){
      count++; 
   // printf("%d\n",count);
        }
        
    }
}
    printf("%d\n",count);
    return 0;
}

