#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
  int i,j=0,n;
  int count=0;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",a+i);
  }
  while(j<n-1){
    if(j+3==n-1){
      if(abs(a[j+1]-a[j])+abs(a[j+3]-a[j+1])>abs(a[j+2]-a[j])+abs(a[j+3]-a[j+2])){
      count+=abs(a[j+2]-a[j]);
      j+=2;
      continue;
    } else {
      count+=abs(a[j+1]-a[j]);
      j+=1;
      continue;
    }
    }
    if(j+1==n-1){
      count+=abs(a[j+1]-a[j]);
      break;
    }
    if(abs(a[j+1]-a[j])>abs(a[j+2]-a[j])){
      count+=abs(a[j+2]-a[j]);
      j+=2;
      continue;
    } else {
      count+=abs(a[j+1]-a[j]);
      j+=1;
      continue;
    }
  }
  printf("%d\n",count);
  return 0;
}