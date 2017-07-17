#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
#define MAXP 1000000
int p;
int a[MAXP+1];

int main(){
  cin>>p;
  for(int i=0;i<p;i++){
    cin>>a[i];
  }
  set<int> all;
  for(int i=0;i<p;i++){
    all.insert(a[i]);
  }
  int n = all.size();

  //しゃくとり法により解を求める
  int s=0,t=0,num=0;
  map<int,int> count;//事柄→出現率の対応
  int res=p;
  while(true){
    while(t<p&&num<n){
      //新しい事柄が出現
    if(count[a[t++]]++ == 0){
      num++;
    }
  }
  if(num<n){
    break;
  }
  res = min(res,t-s);
  if(--count[a[s++]] == 0){
    //ある事柄の出現率が0になった
    num--;
  }
}

printf("%d\n",res);
  return 0;
}