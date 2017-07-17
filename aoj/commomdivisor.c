#include <stdio.h>
// for integer x and y, ifx>= y,then gcd(x,y)=gcd(y,x%y);
int main(){
  int a,b;
  scanf("%d",&a);
  scanf("%d",&b);
  while(b!=0){
    int c=a%b;
    a=b;
    b=c;
  }
  printf("%d\n",a);
  return 0;
}