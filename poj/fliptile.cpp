#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAX_M 15
const int dx[5]={-1,0,0,0,1};
const int dy[5]={0,-1,0,1,0};

//入力
int m,n;
int tile[MAX_M+1][MAX_M+1];

int opt[MAX_M+1][MAX_M+1]; //最適解保存用
int flip[MAX_M+1][MAX_M+1]; //作業用

//(x,y)の色を調べる
int get(int x,int y){
  int c = tile[x][y];
  for(int d=0;d<5;d++){
    int x2 = x+dx[d];
    int y2 = y+dy[d];
    if(0<=x2 && x2 <m && 0<=y2 && y2 <n){
      c += flip[x2][y2];
    }
  }
  return c%2;
}

//1行目を決めた場合の最小操作回数を求める
//絵画存在しないならば-1を出力
int calc(){
  //2行目からのひっくり返し方を求める
  for(int i=1;i<m;i++){
    for(int j=0;j<n;j++){
      if(get(i-1,j) != 0){
        //(i-1,j) が黒色なら、このマスをひっくり返すしかない
        flip[i][j] = 1;
      } 
    }
  }

//最後の行が全部白かどうかチェックする
for(int j=0;j<n;j++){
  if(get(m-1,j) != 0){
    //解なし
    return -1;
  }
}

//反転回数をカウント
int res = 0;
for(int i=0;i<m;i++){
  for(int j=0;j<m;j++){
    res += flip[i][j];
    }
  }
  return res;
}

void solve(){
  int res = -1;

  //1行目を辞書順で全通り試す
  for(int i=0;i<1<<n;i++){
    memset(flip,0,sizeof(flip));
    for(int j=0;j<n;j++){
      flip[0][n-j-1]=i>>j&1;
    }
    int num = calc();
    if(num>=0 &&(res <0 || res > num)){
      res=num;
      memcpy(opt,flip,sizeof(flip));
    }
  }

  if(res<0){
    //解なし
    printf("IMPOSSIBLE\n");
  } else{
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        printf("%d%c",opt[i][j],j+1==n ? '\n' : ' ' );
      }
    }
  }
}
int main(){
  cin>>m>>n;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      cin>>tile[i][j];
    }
  }
  solve();
  return 0;
}