#include <stdio.h>
#include <string.h>
#define N 10
int hina[N][N];
int puzzle[N][N];
int n,count,i,j,l,head,test=1;

int main(){
  while(1){
    count=0;
  scanf("%d",&n);
  if(n==0){
    break;
  }
  for(i=0;i<n;i++){
    for(j=0;j<5;j++){
      scanf("%d",&puzzle[i][j]);
    }
  }
  while(1){
    //strcpy(puzzle,hina);
    //count=0;
    test=0;
    //連鎖をチェックする関数
    for(i=0;i<n;i++){
      for(j=0;j<3;j++){
        if(puzzle[i][j]==puzzle[i][j+1]&&puzzle[i][j+1]==puzzle[i][j+2]&&puzzle[i][j]!=-1){
          if(j==0){
            if(puzzle[i][j+2]==puzzle[i][j+3]){
              if(puzzle[i][j+3]==puzzle[i][j+4]){
                for(l=0;l<5;l++){
                  test+=puzzle[i][l];
                  puzzle[i][l]=-1;
                }
              } else {
                for(l=0;l<4;l++){
                  test+=puzzle[i][l];
                  puzzle[i][l]=-1;
                }
              }
            } else {
              for(l=0;l<3;l++){
                test+=puzzle[i][l];
                  puzzle[i][l]=-1;
                }
            }
          } else if(j==1){
            if(puzzle[i][j+2]==puzzle[i][j+3]){
              test+=puzzle[i][j];
              puzzle[i][j+3]=-1;
            }
            for(l=1;l<4;l++){
              test+=puzzle[i][l];
                  puzzle[i][l]=-1;
                }
          } else if(j==2){
              for(l=2;l<5;l++){
                test+=puzzle[i][l];
                  puzzle[i][l]=-1;
                }
          }
        }
      }
    }

     for(l=0;l<n;l++){
        for(j=0;j<5;j++){
       printf("%d ",puzzle[l][j]);
        }
        printf("\n");
      }
      printf("%d\n",test);
      printf("\n");
    
      //配列の文字をずらす処理
      for(j=0;j<5;j++){
        for(i=n-1;i>-1;i--){
        if(puzzle[i][j]==-1){
          head=i;
          while(puzzle[i][j]==-1&&i>0){
            i--;
          }
          if(puzzle[i][j]!=-1){
          puzzle[head][j]=puzzle[i][j];
          puzzle[i][j]=-1;
          i+=2;
          }
        }
      }
    }
    for(l=0;l<n;l++){
        for(j=0;j<5;j++){
       printf("%d ",puzzle[l][j]);
        }
        printf("\n");
      }
      printf("%d\n",test);
      printf("\n");
if(test!=0){
  count+=test;
  } else {
    break;
  }
}
  printf("%d\n",count);
}
  return 0;
}