#include <stdio.h>

int money(int i, int k){
  return (int)(i*(100+k)/100);
  }

int x,y,s,i,j;
int prise=0;
int main(){
  while(1){
  scanf("%d",&x);
  scanf("%d",&y);
  scanf("%d",&s);
  if(x==0&&y==0&&s==0){
    break;
  }
    for(i=1;i<=s/2;i++){
      for(j=i;j<=s-i;j++){
        if(s==money(i,x)+money(j,x)){
          int hypo=money(i,y)+money(j,y);
          if(prise<hypo){
              prise=hypo;
      }
    }
  }
}
  printf("%d\n",prise);
  prise=0;
}
  return 0;
}