#include <stdio.h>

int main(){
  int n,i,j;
  int count=100000;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        if((j+i)*j<n){
          if(n-(j+i)*j+i<count){
            count=n-(j+i)*j+i;
          }
        }
    }
  }
  printf("%d\n",count);
  return 0;
}