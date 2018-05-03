#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define INF (1LL<<30)
#define LLINF (1LL<<60)
#define PI 3.14159265359
#define EPS 1e-12
#define int ll

int h, w, n, dp[1010][1010], dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0}, gx[15], gy[15], cnt;
string b[1010];
int bfs(int sx, int sy) {
  queue<PII> que;
  REP(j, h) REP(k, w) dp[j][k] = INF;
  dp[sy][sx] = 0;
  que.push(PII(sx, sy));
  dp[sy][sx] = 0;

  while(que.size()) {
    PII p = que.front(); que.pop();
    if(p.first == gx[cnt] && p.second == gy[cnt]) break;
    REP(i, 4) {
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if(nx >= 0 && nx < w && ny >= 0 && ny < h && b[ny][nx] != 'X' && dp[ny][nx] == INF) {
        que.push(PII(nx, ny));
        dp[ny][nx] = dp[p.second][p.first] + 1;
      }
    }
  }

  return dp[gy[cnt]][gx[cnt]];
}

signed main(void)
{
  cin >> h >> w >> n;
  REP(i, h) cin >> b[i];

  REP(i, h) REP(j, w) {
    if(b[i][j] == 'S') {
      gx[0] = j;
      gy[0] = i;
    } else if(b[i][j] >= '0' && b[i][j] <= '9') {
      gx[b[i][j]-'0'] = j;
      gy[b[i][j]-'0'] = i;
    }
  }
  //REP(i, n+1) cout << gx[i] << " " << gy[i] << endl;

  ll ret = 0;
  cnt = 1;
  REP(i, n) {
    ret += bfs(gx[i], gy[i]);
    cnt++;
    /*
    REP(j, h) {
      REP(k, w) {
        if(dp[j][k] == INF) cout << "-1 ";
        else cout << dp[j][k] << " ";
      }
      cout << endl;
    }
    cout << i << " ret:" << ret << endl;
    */
  }
  cout << ret << endl;
  return 0;
}
