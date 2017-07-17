#include <stdio.h>
#include <math.h>

int main(){
  int n;
  int count=0,i,j;
  while(1){
    scanf("%d",&n);
    if(n==0){
      break;
    }
    for(i=n+1;i<=2*n;i++){
      if(i==2){
        count++;
        continue;
      }
      if(i%2==0){
        continue;
      }
      for(j=3;j<=sqrt(i);j+=2){
        if(i%j==0){
          count--;
          break;
        }
      }
      count++;
    }
    printf("%d\n",count);
    count=0;
  }
  return 0;
}