#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_W = 1000;
const int dy[] = {1,-1,0,0}, dx[] = {0,0,1,-1};

int H, W, N, SY, SX;
char board[MAX_W][MAX_W + 1];
int dist[MAX_W][MAX_W + 1];


void init() {
  scanf("%d%d%d ", &H, &W, &N);
  for (int i = 0; i < H; ++i) {
    scanf(" %s ", board[i]);
  }
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (board[i][j] == 'S') {
        SY = i;
        SX = j;
      }
    }
  }
}

int solve() {
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    char tar = '1' + i;
    memset(dist, -1, sizeof(dist));
    queue<pair<int,int> > que;
    que.push(make_pair(SY, SX));
    dist[SY][SX] = 0;
    for (;!que.empty();) {
      int y = que.front().first, x = que.front().second;
      if (board[y][x] == tar) {
        ans += dist[y][x];
        SY = y; SX = x;
        break;
      }
      que.pop();
      int nd = dist[y][x] + 1;
      for (int k = 0; k < 4; ++k) {
        const int ny = y + dy[k], nx = x + dx[k];
        if ( 0 <= ny && ny < H && 0 <= nx && nx < W && board[ny][nx] != 'X' && dist[ny][nx] == -1) {
          dist[ny][nx] = nd;
          que.push( make_pair(ny, nx) );
        }
      }
    }
  }
  return ans;
}

int main() {
  init();
  printf("%d\n", solve());

  return 0;
}