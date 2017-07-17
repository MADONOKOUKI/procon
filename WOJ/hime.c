#include <stdio.h>

long long int n,m;
long long int p;
long long int i=1,total=0;
long long int j,member;
int main(){
  while(1){
  scanf("%lld",&n);
  scanf("%lld",&m);
  scanf("%lld",&p);
  if(n==0&& m==0 && p==0){break;}
  while(i<=n){
    scanf("%lld",&j);
    if(i==m)member=j;
    total+=j;
    i++;
  }
  if(member==0){
    printf("0\n");
    total=0;
  i=1;
    continue;
  }
  printf("%lld\n",total*(100-p)/member);
  total=0;
  i=1;
}
  return 0;
}