// g++ temp.cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <climits>
#define MAXN 2222
#define INF 1<<28
using namespace std;
int cost[26];
int n,m;
int a,b;
string s,l;
//map <string ,int > ADD;
//map <string ,int > REMOVE;
int dp[MAXN+1][MAXN+1];
//int a,b;
//string l;
int  dfs(int k,int j){
  if(k>=j){
    return 0;
  }
  if(dp[k][j]!=INF){
    return dp[k][j];
  }
  int res=INF;
  res=min(res,dfs(k+1,j)+cost[s[k]-'a']);
  res=min(res,dfs(k,j-1)+cost[s[j]-'a']);
  if(s[k]==s[j]){
  res=min(dfs(k+1,j-1),res);
 }
 return dp[k][j]=res;
}

int main(){
  cin>>n>>m>>s;
  for(int i=0;i<n;i++){
    cin>>l>>a>>b;
    cost[l[0]-'a']=min(a,b);
  }
  for(int i=0;i<MAXN;i++){
    for(int j=0;j<MAXN;j++){
      dp[i][j]=INF;
    }
  }
  
  cout<<dfs(0,m-1)<<endl;
  return 0;
}