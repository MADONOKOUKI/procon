#include <stdio.h>
#include <string.h>

int main(){
  int i,n,q,m,d;
  int sum[101];
  int max,day;

  while(1){
    scanf("%d%d",&n,&q);
    if(!n&&!q) break;

    memset(sum,0,sizeof(sum));
    max=0;
    while(n--){
      scanf("%d",&m);
      while(m--){
      scanf("%d",&d);
      sum[d]++;
    }
  }
  for(i=1;i<=100;i++){
    if(sum[i]>max){
      max=sum[i];
      day=i;
    }
  }
  if(max>=q)
    printf("%d\n",day);
     else 
    printf("0\n");
  }
  return 0;
}