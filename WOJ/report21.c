#include <stdio.h>


int main(){
  int i,j,l;
  int count=0;
  float ans[4]={0};
  float x[4]={0};
  int N[4][4]={
    -1,-1,-1,-1,
    0,0,1,-1,
    0,0,-1,-1,
    0,0,0,0};
  int b[4]={56,10,68,8};//A(8,4,9,3)より計算
  int M[4][4]={
    4,0,0,0,
    0,4,0,0,
    2,1,4,0,
    -1,1,0,4,
  };
  while(count<21){
    //右側の答えを初期化する関数
    for(i=0;i<4;i++){
      ans[i]=0;
    }
    //右側のNi*xk+bを計算する関数
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      ans[i]+=N[i][j]*x[j];
    }
    ans[i]+=b[i];
  }
  //xを導出する関数
  x[0]=ans[0]/4;
  x[1]=ans[1]/4;
  x[2]=(ans[2]-x[0]*2-x[1])/4;
  x[3]=(ans[3]+x[0]-x[1])/4;
  count++;
  printf("%d回目\n",count);
for(l=0;l<4;l++){
  printf("x[%d]:%f\n",l,x[l]);
}
}
  return 0;
}