#include <stdio.h>
int a[1000]={0};
int prime(int x){
  int p=6,i;
  for(i=0;p<x;i++){
    if(x%p==0){
      return 0;
    }
    if(p%7==6){
      p+=2;
    } else if (p%7==1) {
      p+=5;
    }
  }
  return 1;
}
int main(){
  int n,i,j=0,l;
  while(1){
    j=0;
  scanf("%d",&n);
  if(n==1)break;
  printf("%d: ",n);
  for(i=6;i<=n;i+=(i%7==1)?5:2){   
    if(n%i==0){
      if(prime(i)){
      a[j]=i;
      j++;
    }
  }
}
  for(i=0;i<j;i++){
    printf("%d",a[i]);
    if(i!=j-1){
      printf(" ");
    } else {
      printf("\n");
    }
  }
  for(i=0;i<j;i++){
    a[j]=0;
  }
}
  return 0;
}