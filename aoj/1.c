#include <stdio.h>

int main(){
  int i,j;
  scanf("%d %d",&i,&j);
  if(i-j<j-1){
    printf("%d\n",i-j);
  } else {
    printf("%d\n",j-1);
  }
  return 0;
}