#include <stdio.h>
int p[100];
int ransuu(int a,int b,int c,int x){
  int dx;
  dx=(a*x+b)%c;
  return dx;
}

int main(){
  int i,n,a,b,c,x,j;
   int count=0,play=0;
  while(1){
  scanf("%d",&n);
  scanf("%d",&a);
  scanf("%d",&b);
  scanf("%d",&c);
  scanf("%d",&x);
  if(n==0&&a==0&&b==0&&c==0&&x==0){
    break;
  }
  for(i=0;i<n;i++){
    scanf("%d",&j);
    p[i]=j;
  }
  i=0;
  while(play<=10000){
    if(p[i]==x){
      count++;
      if(count==n){
        printf("%d\n",play);
        break;
      }

      i++;
      x=ransuu(a,b,c,x);
      play++;
    } else {
      x=ransuu(a,b,c,x);
      play++;
    }
    if(play==10001){
      printf("-1\n");
      break;
    }
  }
  count=0;
  play=0;
}
  return 0;
}