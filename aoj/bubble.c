#include <stdio.h>

void temp(int x[],int y[]){
  int temp=*y;
  *y=*x;
  *x=temp;
}

int main(){
  int i,j,n,count=0;
  scanf("%d",&n);
  int x[100]={0};
  for(i=0;i<n;i++){
    scanf("%d",&x[i]);
  }
  
  for(i=0;i<n-1;i++){
    int min=i;
  for(j=i;i<n;i++){
  if(x[j]<x[min]){
      min=j;
      }
    }
    if(min!=j){
      count++;
    }
    temp(&x[min],&x[i]);
  }
  for(i=0;i<n;i++){
    if(i==n-1){
        printf("%d",x[i]);
    } else {
      printf("%d ",x[i]);
    }
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
