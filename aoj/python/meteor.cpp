#include <iostream>
#include <queue>
const int MAX_N=300;
const int INF=-1;
using namespace std;
int M,x,y;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int place[MAX_N+1][MAX_N+1];
int meteor[MAX_N+1][MAX_N+1];

void dfs(){
  if(meteor[0][0]==0){
    cout<<-1<<endl;
    return;
  }
  int ans=50001;
  queue < pair<int,int> > que;
  que.push(make_pair(0,0));
  place[0][0]=0;
  //int l=0;
  while(!que.empty()){
    //cout<<l++<<endl;
    int nx=que.front().first;
    int ny=que.front().second;
    que.pop();
    if(place[nx][ny]!=INF){
    for(int i=0;i<4;i++){
        int ux=nx+dx[i];
        int uy=ny+dy[i];
       // printf("%d\n",meteor[ux][uy]);
      if(-1<ux&&-1<uy&&ux<MAX_N&&uy<MAX_N&&place[ux][uy]==INF){
        place[ux][uy]=place[nx][ny]+1;
        if(place[ux][uy]<meteor[ux][uy]){
          que.push(make_pair(ux,uy));
        }
        if(meteor[ux][uy]==0){
          //printf("%d %d\n",ux,uy);
          cout<<place[ux][uy]<<endl;
          return ;
        } 
      }
    }
  }
}
    cout<<-1<<endl;
  return;
}
int main(){
  cin>>M;
  for(int i=0;i<M;i++){
    cin>>x;
    cin>>y;
    cin>>meteor[x][y];
    for(int j=0;j<4;j++){
      meteor[x+dx[j]][y+dy[j]]=meteor[x][y];
    }
  }
  for(int i=0;i<MAX_N+1;i++){
    for(int j=0;j<MAX_N+1;j++){
      place[i][j]=INF;
  }
}
  dfs();
  return 0;
}