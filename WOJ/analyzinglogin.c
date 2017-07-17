#include <stdio.h>
#include <string.h>

int time[10001][1300];
int login[10001];

int main(){
  int i,j,k;
  int N,M;
  int r,t,n,m,s;
  int q,ts,te;
  int ans,before;

  while(scanf("%d%d",&N,&M),N||M){
    scanf("%d",&r);
    memset(time,0,sizeof(time));
    before=0;
    for(i=0;i<r;i++){
      scanf("%d%d%d%d",&t,&n,&m,&s);
      for(j=1;j<=10000;j++){
        if(login[j]>0){
          for(k=t-1;k>=before;k--){
            time[j][k]=1;
          }
        }
      }
      before=t;

      if(s==0){
        login[m]--;
      } else {
        login[m]++;
      }
    }
      scanf("%d",&q);
      for(i=0;i<q;i++){
        scanf("%d%d%d",&ts,&te,&m);
        ans=0;
        for(j=ts;j<te;j++){
          ans+=time[m][j];
        }
        printf("%d\n",ans);
    }
  }
  return 0;
}