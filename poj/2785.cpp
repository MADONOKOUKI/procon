#include <iostream>
#include <algorithm>
#define MAX_N 1000
using namespace std;

//入力
int n;
int A[MAX_N],B[MAX_N],C[MAX_N],D[MAX_N];

int CD[MAX_N*MAX_N];

void solve(){
  //CとDの取り出し方の組を全列挙
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      CD[i*n+j]=C[i]+D[j];
    }
  }
sort(CD,CD+n*n);

long long res = 0;
for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
    int cd = -(A[i]+B[j]);
    //CとDから和がcdとなるように取り出す
    res += upper_bound(CD,CD+n*n,cd) - lower_bound(CD,CD+n*n,cd);
  }
}
printf("%lld\n",res);
}

int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  for(int i=0;i<n;i++){
    cin>>B[i];
  }
  for(int i=0;i<n;i++){
    cin>>C[i];
  }
  for(int i=0;i<n;i++){
    cin>>D[i];
  }
  solve();
  return 0;
}