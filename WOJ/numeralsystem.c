#include <stdio.h>
#include <string.h>
int l=0,pre=0;
int total=0;
char a[10010];

void total_pre(int n){
  int j=0;
  if(n/1000==1000){
    a[j++]='m';
    a[j++]='m';
    n-=1000*(n/1000);
  } else if(n/1000==100){
    a[j++]='c';
    a[j++]='m';
     n-=1000*(n/1000);
  } else if(n/1000==10){
    a[j++]='x';
    a[j++]='m';
    n-=1000*(n/1000);
  } else if(n/1000<10&&n/1000>1){
    a[j++]='0'+n/1000;
    a[j++]='m';
    n-=1000*(n/1000);
  } else if(n/1000==1){
    a[j++]='m';
    n-=1000*(n/1000);
}
if(n/100==100){
    a[j++]='c';
    a[j++]='c';
     n-=100*(n/100);
  } else if(n/100==10){
    a[j++]='x';
    a[j++]='c';
    n-=100*(n/100);
  } else if(n/100<10&&n/100>1){
    a[j++]='0'+n/100;
    a[j++]='c';
    n-=100*(n/100);
  } else if(n/100==1){
    a[j++]='c';
    n-=100*(n/100);
}
 if(n/10==10){
    a[j++]='x';
    a[j++]='x';
    n-=10*(n/10);
  } else if(n/10<10&&n/10>1){
    a[j++]='0'+n/10;
    a[j++]='x';
    n-=10*(n/10);
  } else if(n/10==1){
    a[j++]='x';
    n-=10*(n/10);
  }
  if(n/1<10&&n/1>1){
    a[j++]='0'+n/1;
    a[j++]='i';
    n-=n/1;
  }
  if(n==1){
    a[j++]='i';
  }
  a[j]=0;
}
int main(){
  int i,j,l;
  char c;
  scanf("%d",&l);
  scanf("%c",&c);
  for(i=0;i<l;i++){
    total=0;
    fgets(a,10010,stdin);
    for(j=0;j<strlen(a);j++){
      if('0'<=a[j]&&'9'>=a[j]){
        pre=a[j]-'0';
      } else if(a[j]=='m'){
        if(pre!=0){
          total+=pre*1000;
          pre=0;
        } else {
          total+=1000;
        }
      } else if(a[j]=='c'){
        if(pre!=0){
          total+=pre*100;
          pre=0;
        } else {
          total+=100;
        }
      } else if(a[j]=='x'){
        if(pre!=0){
          total+=pre*10;
          pre=0;
        } else {
          total+=10;
        }
      } else if(a[j]=='i'){
        if(pre!=0){
          total+=pre*1;
          pre=0;
        } else {
          total+=1;
        }
      }
    }
    //printf("%d\n",total);
    total_pre(total);
    printf("%s\n",a);
  }
  return 0;
}