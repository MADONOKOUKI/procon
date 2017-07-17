#include <stdio.h>

int main(){
  int n,i,j,k;
    scanf("%d",&n);
  int x[n];
  for(i=0;i<n;i++){
    scanf("%d",&x[i]);
  }
  for(k=0;k<n;k++){
    k==n-1?printf("%d\n",x[k]):printf("%d ",x[k]);
    }
  for(i=1;i<n;i++){
    int key=x[i];
    j=i-1;
    while(j>=0&&x[j]>key){
    x[j+1]=x[j];
    j--;
    }
    x[j+1]=key;
    for(k=0;k<n;k++){
      k==n-1?printf("%d\n",x[k]):printf("%d ",x[k]);
      }
  }
  return 0;
}
