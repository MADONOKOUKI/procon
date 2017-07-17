#include <stdio.h>
#define upper_limit 44
int i,count=0;
char stock[10000][16];
int stock_count=1;
char test[16];
int previous_number;
char ans[16]{
  '0','1','2','3',
  '4','5','6','7',
  '8','9','a','b',
  'c','d','e','-'
};
void temp(char pre[],int a,int b){
  int temp;
  temo=a;
  pre[a]=pre[b];
  pre[b]=pre[temp];
}
int adjecent[16][]{
  {1,4},{0,2,5},{1,3,6},{2,6}.
  {0,5,8},{1,4,6,9},{2,5,7,10},{3,6,11},
  {4,9,12},{5,8,10,13},{6,9,11,14},{7,10,15},
  {8,13},{9,12,14},{10,13,15},{11,14}
};
int serch_haihunn(char test[]){
  int i;
  for(i=0;i<16;i++){
    if(test[i]=='-'){
      return i;
    }
  }
  stock[0]=test;
  stock[1]=ans;
}
int pre[2];
int head=0,tail=1;
int manhhattan_judge(char a[],int b){

}
int judge(int count){
  if(upper_limit<count+serch()){
    return 0;
  } else {
    return 1;
  }
}

int main(){
  for(i=0;i<16;i++){
    scanf("%c",test+i);
  }
  while(1){
    char *pre=stock[stock_count];
    int n=serch_haihunn(pre);
    int m=sizeof adjecent[n]/sizeof adjecent[n][0];
    for(i=0;i<m;i++){
      if(prevoius_number!=adjecent[n][i]){
      chat *copy=pre;
      temp(copy,n,m);
      if(manhhattan_judge(copy)){
        stock_count++;
        stock[stock_count][16]=copy;
      }
    }
    }
    head++:
    if(head==tail){
      printf("impossible");
    }
  }
 printf("%d\n",count);
  return 0;
}