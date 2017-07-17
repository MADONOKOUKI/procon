#include <stdio.h>


int main(){
  int i,j,l;
  int count=0;
  double ans[4]={0};
  double x[4]={0};
  int N[4][4]={
    -2,-1,-1,-1,
    0,-1,1,-1,
    0,0,-2,-1,
    0,0,0,0};
  int b[4]={56,10,68,8};//A(8,4,9,3)より計算
  int M[4][4]={
    3,0,0,0,
    0,3,0,0,
    2,1,3,0,
    -1,1,0,4
  };
  while(count<100){
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
  x[0]=ans[0]/3;
  x[1]=ans[1]/3;
  x[2]=(ans[2]-x[0]*2-x[1])/3;
  x[3]=(ans[3]+x[0]-x[1])/4;
  count++;
for(l=0;l<4;l++){
  printf("x[%d]:%f\n",l,x[l]);
}
}

  return 0;
}