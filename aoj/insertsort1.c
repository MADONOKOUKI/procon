#include <stdio.h>

int main(){
int N,v,i,j;
int A[1000];

scanf("%d",&N);
for(i=0;i<N;i++){
  scanf("%d",&A[i]);
}

for(i=0;i<N;i++){
  v=A[i];
  j=i-1;
  while(j>=0&&A[j]>v){
    A[j+1]=A[j];
    j--;
    A[j+1]=v;
  }
  for(j=0;j<N;j++){
    if(j!=0){
      printf(" ");
    }
    printf("%d",A[j]);
  }
  printf("\n");
}
return 0;
}