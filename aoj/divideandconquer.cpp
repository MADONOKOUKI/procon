#include <isostream>
#include <algotrithm>
using namespace std;
#define MAX_N 2000
int n,m;
int a[MAX_N+1];
int q[MAX_N+1];
bool dp[MAX_N+1][MAX_N+1];
dp[0][0]=true;

void calc(){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<i+1;k++){
      if(dp[i][j]){
        dp[i+1][j] = true;
        dp[i+1][j+a[k]] =true; 
        }
      }
    }
  }
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<m;i++){
    cin>>q[i];
  }
  calc();
  for(int i=0;i<m;i++){
    if(dp[n][q[i]]){
      cout<<"yes"<<endl;
    } else {
      cout<<"no"<<endl;
    }
  }
  return 0;
}