#include <iostream>
#include <algorithm>

const int MAX_N = 100;

using namespace std;

int N,M;
char k[MAX_N+1][MAX_N+1];

void dfs(int x,int y){
  int dx,dy;
  k[x][y]='.';
  for(dx=-1;dx<2;dx++){
    for(dy=-1;dy<2;dy++){
      if(dx==0&&dy==0){
        continue;
      }
      if((x+dx>-1&&x+dx<N)&&(y+dy>-1&&y+dy<M)){
      if(k[x+dx][y+dy]=='W'){
        dfs(x+dx,y+dy);
      }
    }
    }
  }
  return ;
}

void solve(){
  int res=0;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
      scanf("%s",k[i]);
  }
  /*for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      printf("%c",k[i][j]);
    }
    printf("\n");
  }
  */
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(k[i][j]=='W'){
        dfs(i,j);
       // printf("%d %d %d\n",res,i,j);      
      res++;
    }
    }
  }
  printf("%d\n",res);
}

int main(){
  solve();
  return 0;
}