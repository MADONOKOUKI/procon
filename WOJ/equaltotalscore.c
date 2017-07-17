#include <stdio.h>

int main(){
  while(1){
    int a_total=0,b_total=0;
    int x=100,y=100;
    int n,m;
    int i,j;
    int a[100],b[100];
    scanf("%d",&n);
    scanf("%d",&m);
  if(n==0&&m==0){
    break;
  }
  for(i=0;i<n;i++){
  scanf("%d",a+i);
  a_total+=a[i];
  }
  for(i=0;i<m;i++){
  scanf("%d",b+i);
  b_total+=b[i];
  }
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      if(a_total-a[i]+b[j]==b_total+a[i]-b[j]&&(a[i]+b[i]<x+y)){
        x=a[i];
        y=b[j];
      }
    }
  }
  if(x==100 && y==100){
  printf("-1\n");
  } else {
fprintf(stdout,"%d %d\n",x,y);
}
}
return 0;
} 