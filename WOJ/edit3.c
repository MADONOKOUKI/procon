#include <stdio.h>
#include <string.h>
#define N 1010
char c[N][N];
int diagonal(int a,int b,int k,int l);

int min(int k,int j);

int main(void){
    int pre=1;
    int tail=0;
    int i=0,j,w;
    int k,l;
    int count=0;
    int p,m=0;
    scanf("%d",&p);
    while(m<p){
        scanf("%s",c[m]);//文字列の標準入力
    m++;
    }
    m=0;
    for(k=0;k<p-1;k++){
        for(l=k+1;l<p;l++){
          //printf("%s\n",c[k]);
   //printf("%s\n",c[l]);
   //printf("%lu\n",strlen(c[l]));
    //printf("%lu\n",strlen(c[k]));
          pre=1;
          int n[N][N];
          for(i=1;i<=strlen(c[k]);i++){
            n[0][i]=i;
          }
          for(i=1;i<=strlen(c[l]);i++){
            n[i][0]=i;
          }
          for(i=1;i<=strlen(c[k]);i++){
            if(i<=10){
            for(j=1;j<=10+tail&&j<=strlen(c[l]);j++){
              if(j==10+tail){
                n[i][j]=min(n[i][j-1]+1,n[i-1][j-1]+diagonal(i,j,k,l));
              } else {
              n[i][j]=min(n[i-1][j]+1,min(n[i][j-1]+1,n[i-1][j-1]+diagonal(i,j,k,l)));
            }
            if(n[i][j]<9){
              pre--;
             
            }
          // printf("i:%d j:%d n[i][j]%d\n",i,j,n[i][j]);
            if(strlen(c[k])==i&&strlen(c[l])==j&&n[strlen(c[k])][strlen(c[l])]<10){
              count++; 
        }
           
          }
        }
          if(i>10){
          for(j=i-9;j<=10+tail&&j<=strlen(c[l]);j++){
              if(j==10+tail){
                n[i][j]=min(n[i][j-1]+1,n[i-1][j-1]+diagonal(i,j,k,l));
              } else if(j==i-9){
                n[i][j]=min(n[i-1][j]+1,n[i-1][j-1]+diagonal(i,j,k,l));
              } else{
              n[i][j]=min(n[i-1][j]+1,min(n[i][j-1]+1,n[i-1][j-1]+diagonal(i,j,k,l)));
            }
         // printf("i:%d j:%d n[i][j]%d\n",i,j,n[i][j]);
            if(strlen(c[k])==i&&strlen(c[l])==j&&n[strlen(c[k])][strlen(c[l])]<10){
              count++; 
        }
            if(n[i][j]<10){
              pre--;
              
            }
          }
        }
          if(pre==1){
            break;
          }
          pre=1;
          tail++;
          }   
    }
}
    printf("%d\n",count);
    return 0;
}

int diagonal(int a,int b,int k,int l){
    if(c[k][a-1]==c[l][b-1]){
        return 0;
    } else {
    return 1;
  }
}

int min(int k,int j){//小さい値を返す関数
    if(k>j){
        return j;
    } else {
        return k;
    }
}

