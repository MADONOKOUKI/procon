#include <stdio.h>
#include <math.h>

int main(){
  int i,N,count=0;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    int n,j,l=0;
    scanf("%d",&n);
    if(n==1||n==2){
      count++;
      continue;
    }
    if(n%2==0){
      continue;
    }
    for(j=3;j<=sqrt(n);j+=2){
      if(n%j==0){
        l+=1;
        break;
      }
    }
    if(l!=1){
      count++;
    }
    l=0;
  }
  printf("%d\n",count);
  return 0;
}