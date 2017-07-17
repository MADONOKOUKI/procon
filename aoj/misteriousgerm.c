#include <stdio.h>
 
int main(){
  char a;
  int b,c,i,j,k,m,n,gx[20],gy[20],rx,ry;
 
  while(scanf("%d\n",&n)){
    if(n==0) break;
    rx=10;ry=10;c=0;
    for(i=0;i<n;i++) scanf("%d %d\n",&gx[i],&gy[i]);
    scanf("%d\n",&m);
    for(i=0;i<m;i++){
      scanf("%c %d\n",&a,&b);
      for(j=0;j<b;j++){
        switch(a){
          case 'N': ry++; break;
          case 'E': rx++; break;
          case 'W': rx--; break;
          case 'S': ry--; break;
        }
        for(k=0;k<n;k++){
          if(gx[k]==rx && gy[k]==ry){ 
            c++;
            gx[k]=-1;gy[k]=-1;
            break;
          }
        }
      }
    }
    if(c==n) printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}