#include <stdio.h>
#include <string.h>

char s[256][256];
char c[256];
int count=0;
int judge(char c[],int n){
  int i;
  for(i=0;i<n;i++){
    if(strcmp(c,s[i])==0){
    return 1;
  }
  }
  return 0;
}
int main(){
  int n,i,m;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",s[i]);
  }
  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%s",c);
    c[strlen(c)]=0;
    if(judge(c,n)==1){
      if(count==0){
        printf("Opened by %s\n",c);
        count=1;
      } else if (count==1) {
        printf("Closed by %s\n",c);
        count=0;
      }
    } else {
      printf("Unknown %s\n",c);
    }
  }
  return 0;
}