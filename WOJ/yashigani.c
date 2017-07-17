#include <stdio.h>
#include <math.h>
int main(){
  int n,m;
  int i,j;
  while(1){
    scanf("%d",&n);
    if(n==0){
      break;
    }
    m=1000000;
    for(i=0;i*i<=n;i++){
      for(j=0;j*j*j<=n;j++){
        if(i*i+j*j*j<=n&&m>n+i+j-i*i-j*j*j){
          m=n+i+j-i*i-j*j*j;
      }
    }
  }
  printf("%d\n",m);  
  }
  return 0;
}

/*
 if(n==0){
      break;
    }
    x=0;
    y=0;
    z=0;
    pre=0;
    while((z+1)*(z+1)*(z+1)<=n){
      z++;
      if(z*z*z==n){
        pre++;
      }
    }
    if(pre!=1){
      n=n-z*z*z;
      while((y+1)*(y+1)<=n){
        y++;
        if(n==y*y){
          pre++;
        }
      }
    }
    if(pre!=1){
       n=n-y*y;
      while((x+1)<=n){
        x++;
        if(x==n){
          break;
        }
      }
      }
    printf("%d\n",x+y+z);
*/