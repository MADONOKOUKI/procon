#include <stdio.h>
#include <string.h>

char box[9][5]={
  {'.',',','!','?',' '},{'a','b','c'},
  {'d','e','f'},{'g','h','i'},
  {'j','k','l'},{'m','n','o'},
  {'p','q','r','s'},{'t','u','v'},
  {'w','x','y','z'}
};
int main(){
  int i,n=0,j;
  scanf("%d",&n);
  char check[100];
    char out[100];
    int k=-1,m=0;
  for(i=0;i<n+1;i++){
    fgets(check,100,stdin);
    for(j=0;j<strlen(check);j++){
      while(check[j]!='0'&&j+1<strlen(check)){
        k++;
        j++;
      }
      if(k==-1)continue;
      if(check[j-1]-'1'==0){
        printf("%c",box[(check[j-1]-'1')][k%5]);
      }else if(check[j-1]-'1'==6||check[j-1]-'1'==8){
      printf("%c",box[(check[j-1]-'1')][k%4]);
       }else {
    printf("%c",box[(check[j-1]-'1')][k%3]);
      }
       k=-1;
  }
  printf("\n");
}
  return 0;
}