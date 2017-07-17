#include <stdio.h>
char l[30][30];
int x,y;
int i,j;
int cnt=0;
void dp(int i,int j);
int main(){
  while(1){
  scanf("%d %d",&x,&y);
  if(x==0&&y==0){
    break;
  }
  for(i=0;i<y;i++){
      scanf("%s",l[i]);
  }
  for(i=0;i<y;i++){
    for(j=0;j<x;j++){
      if(l[i][j]=='@'){
        dp(j,i);
        break;
      }
    }
  }
  printf("%d\n",cnt);
  cnt=0;
}
  return 0;
}

void dp(int i,int j){
  if(i>=x||j>=y||i<0||j<0){
    return;
  }
  if(l[j][i]=='&'||l[j][i]=='#'){
    return;
  }
  l[j][i]='&';
  cnt++;
  dp(i+1,j);
  dp(i-1,j);
  dp(i,j+1);
  dp(i,j-1);
  return ;
}