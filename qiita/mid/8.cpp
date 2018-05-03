#include <bits/stdc++.h>
#define int long long
#define INF 1e+18
using namespace std;

int n,m,x[100010];

bool C(int t){
  int l = 0;
  for(int i = 0;i < m;i++){
    if(t < x[i] - l - 1) return false;
    l = min(x[i + 1] - 1,x[i] + max(t - (x[i] - l - 1) * 2,(t - (x[i] - l - 1)) / 2));
  }
  return l >= n;
}

signed main(){
  cin >> n >> m;
  for(int i = 0;i < m;i++) cin >> x[i];
  x[m] = n + 1;
  int low = -1,up = INF;
  while(up - low > 1){
    int mid = (low + up) / 2;
    if(C(mid)) up = mid;
    else low = mid;
  }
  cout << up << endl;
  return 0;
}
