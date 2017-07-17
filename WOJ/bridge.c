#include <stdio.h>
#define N 100000
int NODE[N][N];
int island[800];
//int dob[N]={0};
int n,count,max_long;
int count_;
int dps(int a,int distance,int pre,int pre_long){
  //printf("a==%d distance==%d\n",a,distance);
  int test=0;
  int i,index=0,dis=0;
  for(i=2;i<=n;i++){
    if((island[i]==a&&pre!=i)||(i==a&&pre!=i)){
      test++;
    }
  }
  if(test>0){
  for(i=2;i<=n;i++){
    if(island[i]==a&&dis<NODE[i][island[i]]&&pre!=i&&pre!=island[i]){
        dis=NODE[i][island[i]];
        index=i;
      //  printf("入れました！");
    } if(i==a&&dis<NODE[i][island[i]]&&pre!=island[i]){
        dis=NODE[i][island[i]];
        index=island[i];
    //     printf("入れました！!!!!!!!!!!!!!!!");
    } 
  }
  if(index!=0){
  distance+=dis;
  dps(index,distance,a,dis);
  } 
}
  //  printf("何も入らなかった");
    if(max_long<distance-NODE[pre][a]){
    max_long=distance-NODE[pre][a];
  }
  return distance-NODE[pre][a];
  
}
int is(int m[],int n){
  int i,j;
  for(i=2;i<n;i++){
    for(j=i+1;j<=n;j++){
    if(m[i]==m[j]){
      return 1;
    }
  }
  }
  return 0;
}
int main(){
  int i,j,freq;
  int box=0;
  int connect=0;
  while(1){
    connect=0;
    box=0;
    max_long=0;
    count=0;
    count_=0;
  scanf("%d",&n);
  if(n==0){
    break;
  }
  for(i=2;i<=n;i++){
    scanf("%d",&island[i]);
  //printf("%d\n",island[i]);
  }
  for(i=2;i<=n;i++){
    freq=0;
    scanf("%d",&NODE[i][island[i]]);
    NODE[island[i]][i]=NODE[i][island[i]];
    count+=NODE[i][island[i]];
    //printf("%d\n",count);
    for(j=2;j<=10;j++){
      if(island[j]==i){
        if(connect==0){
          connect=island[j];
        } else if(connect!=0&&connect!=-1&&connect!=island[j]){
          connect=-1;
        }
        freq++;
      }
    }
    if(freq>1){
      count_+=NODE[i][island[i]];
    }
    //printf("%d\n",NODE[i][island[i]]);
  }
  for(i=1;i<=n;i++){
      for(j=2;j<=10;j++){
        if(island[j]==i){
            box=dps(i,0,0,0);
      //printf("max_long==%d\n",max_long);
      break;
    }
  }
}
  //printf("%d\n",count);
  //printf("count_==%d\n",count_);
if(connect!=-1){
  //printf("%d\n",count);
  //printf("%d\n",count);
  printf("%d\n",count);
} else if(is(island,n)==0){
//printf("%d\n",count);
printf("%d\n",count);
} else {
printf("%d\n",count+count_*2-max_long);
}
  }
  return 0;
}