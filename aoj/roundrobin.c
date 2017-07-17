#include <stdio.h>
#include <string.h>

typedef struct{
  char p[10];
  int m;
}Robin;

int judge(Robin x[],int n){
  int i;
  for(i=0;i<n;i++){
    if(x[i].m!= 0){
      return 1;
    }
  }
  return 0;
}

int main(){
  int i,j,n,l=0,subs;
  scanf("%d %d",&n,&subs);
  Robin x[n];
  for(i=0;i<n;i++){
  scanf("%s %d",x[n].p,&x[n].m);
  }
  while(n>0){
  for(i=0;i<n;i++){
    if(x[n].m-subs<0){
      l+=x[i].m;
    printf("%s %d",x[i].p,l);
    for(j=0;j<n;j++){
      *x[j].p=*x[j+1].p;
      x[j].m=x[j+1].m;
      n-=1;
      }
    }else {
    x[i].m-=subs;
    l+=subs;
    int pre1=x[i].m;
    char *prepre=x[i].p;
    for(j=0;j<n-1;j++){
      *x[j].p=*x[j+1].p;
      x[j].m=x[j+1].m;
      }
      *x[n-1].p=*prepre;
      x[n-1].m=pre1;
    }
    }
  }
  return 0;
}

/*
入力例 1
5 100
p1 150
p2 80
p3 200
p4 350
p5 20
出力例 1
p2 180
p5 400
p1 450
p3 550
p4 800

*/
