#include <stdio.h>
int main(){
  int n, i, j, All=196471 , Y, M, D, sum;
  scanf("%d",&n);
  for(j = 0 ,sum = 0 ; j < n ; j++ , sum = 0){
  scanf("%d %d %d",&Y, &M, &D);
 
  for(i = 1 ; i < Y ; i++){
    if(i % 3 == 0){
      sum+=200;
    }else{
      sum+=195;
    }
  }
 
    for(i = 1 ; i < M ; i++){
      if(Y % 3 == 0|| i % 2 == 1){
    sum+=20;
      }else{
    sum+=19;
      }
    }
   
    sum+=D;
    printf("%d\n",All-sum);
  }
   
  return 0;
}