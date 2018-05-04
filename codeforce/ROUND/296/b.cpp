#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1000000;

bool myoperator(const pair<int, int> left, const pair<int, int> right){
  if(left.first != right.first){
    return (left.first < right.first);
  // }else{
  //   return (left.second >= right.second);
  // }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N; cin >> N;
  vector<pair<int, int> > pr;
  for(int i=0;i<N;i++){
    int x, w; cin >> x >> w;
    pr.push_back(make_pair(x, w));
  }
  sort(pr.begin(), pr.end(), myoperator);
  for(int i=0;i<N;i++){
    cout<<pr[i].first<<" "<<pr[i].second<<endl;
  }
  int dp[N];
  fill(dp, dp+N, INF);
  for(int i=0;i<N;i++){
    *lower_bound(dp, dp+N, pr[i].first + pr[i].second) = pr[i].first + pr[i].second;
  }
  cout << lower_bound(dp, dp+N, INF) - dp << endl;
}
