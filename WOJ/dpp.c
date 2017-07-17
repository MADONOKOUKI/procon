#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 4096

int i,j,n[N][N];
int m;
char str1[N],str2[N];

int min(int k,int p){
    if(k>p){
        return p;
    } else {
        return k;
    }
}

int main(void){
    scanf("%s",str1);
    scanf("%s",str2);
    int y=strlen(str1);
    int z=strlen(str2);
    n[0][0]=0;
    for(i=0;i<=y;i++){
        n[i][0]=i;
    }
    for(j=0;j<=z;j++){
        n[0][j]=j;
    }
    for(i=1;i<=y;i++){
      for(j=1;j<=z;j++){
        if(str1[i]==str2[i]){
          m=0;
        } else {
            m=1;
        }
        n[i][j]=min(min(n[i-1][j]+1,n[i-1][j-1]+m),n[i][j-1]+1);
      }
    }
    printf("%d\n",n[y][z]);
    return 0;
}
