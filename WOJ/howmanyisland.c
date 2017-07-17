#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int **matrix,**a;
int n,m,w,h,l;
int count=0;
void dp(int i,int j){
  if(i<1||j<1||i>w||j>h){
    return ;
  }printf("%d%d",i,j);
  if(matrix[i][j]==1){
  if(matrix[i][j-1]==1||matrix[i+1][j-1]==1||matrix[i+1][j]==1||matrix[i+1][j+1]==1||matrix[i][j+1]==1||matrix[i-1][j+1]==1||matrix[i-1][j]==1||matrix[i-1][j-1]==1){
    matrix[i][j]=2;
    count--;
    }
  }
  dp(i-1,j);
  dp(i-1,j-1);
  dp(i-1,j+1);
  dp(i,j-1);
  dp(i,j+1);
  dp(i+1,j-1);
  dp(i+1,j);
  dp(i+1,j+1);
  return ;
}

int main(){
  int i,j;
  while(1){
    scanf("%d %d",&w,&h);
    if(w==0&&h==0){
      break;
    }
    matrix = (int **)malloc(sizeof(int *)*(h+2));
    a = (int **)malloc(sizeof(int *)*(h+2));
    for(i=0;i<h;i++){
      matrix[i]=(int*)malloc(sizeof(int)*(w+2));
      a[i]=(int*)malloc(sizeof(int)*(w+2));
    }
    for(i=1;i<=h;i++){
      for(j=1;j<=w;j++){
        scanf("%d",&l);
        matrix[i][j]=l;
        if(l==1){
          count++;
        }
      }
    }
    dp(1,1);
    for(i=h+1;i>=0;i--){
      free(matrix[i]);
    }
    free(matrix);
    printf("%d\n",count);
    count=0;
  }
  return 0;
}