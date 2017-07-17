#include <stdio.h>
int x[200];
int y[200];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int xleft=0,xright=0;
int yleft=0,yright=0;
int main(){
  while(1){
    int i,n,l,ni;
    scanf("%d",&n);
    if(n==0)break;
    x[0]=0;
    y[0]=0;
    xleft=0;
    xright=0;
    yleft=0;
    yright=0;
    for(i=1;i<=n-1;i++){
        scanf("%d %d",&ni,&l);
        x[i] = x[ni] + dx[l];
        y[i] = y[ni] + dy[l];
            //更新処理・上下左右
            if(x[i] < xleft) xleft = x[i];
            if(x[i] > xright) xright = x[i];
            if(y[i] < yleft) yleft = y[i];
            if(y[i] > yright) yright = y[i];
    }
    printf("%d",xright+1-xleft);
    printf(" %d\n",yright+1-yleft);
  }
  return 0;
}