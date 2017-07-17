#include <iostream>
#include <algorithm>
using namespace std;
int n;
int w[11];
bool judge;
void dfs(int c,int i,int j){
  if(c>=10){
    judge=true;
    return;
  }
  if(w[c]<i&&w[c]<j){
    return;
  }
  if(w[c]>i){
    dfs(c+1,w[c],j);
  } 
  if(w[c]>j){
    dfs(c+1,i,w[c]);
  } 
}


int main(){
    cin>>n;
    for(int j=0;j<n;j++){
      judge=false;
    for(int i=0;i<10;i++){
      cin>>w[i];
      }
    dfs(0,0,0); 
    if(judge){
      cout<<"YES"<<endl;
    } else {
      cout<<"NO"<<endl;
    }
}
  return 0;
}