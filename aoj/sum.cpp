#include <iostream>
#include <algorithm>

const int MAX_N = 20;

int n,m;
int k[MAX_N+1];

bool dfs(int i,int sum){
  if(i==n) return sum==m;

  if(dfs(i+1,sum)) return true;
  if(dfs(i,sum+k[i])) return true;

  return false;
}

void solve(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&k[i]);
  }
  scanf("%d",&m);
  if(dfs(0,0)) puts("Yes");
  else puts("No");

}

int main(){
solve();
  return 0;
}