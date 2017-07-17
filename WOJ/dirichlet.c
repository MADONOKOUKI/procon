#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MAX 1000000
int main(){
  int a,d,n,i;;
  int m=0;
  int pre=0;
  while(1){
  scanf("%d%d%d",&a,&d,&n);
  if(a==0&&d==0&&n==0){
    break;
  }
    for(a=a;a<MAX;a+=d){
      if(a==1){
        continue;
      }
      if(a==2){
        m++;
      }
      if(a%2!=0){
        for(i=3;i<=sqrt(a);i++){
          if(a%i==0){
            pre++;
            break;
          }
        }
        if(pre==0){
          m++;
        }
      }
      pre=0;
      if(m>=n){
        break;
      }
    }
  printf("%d\n",a);
  m=0;
}
  return 0;
}