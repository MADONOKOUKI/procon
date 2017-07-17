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
using namespace std;

#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,n) FOR(i,0,n)
#define EACH(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
const unsigned long long MOD = 100000000000000000;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;

#define INF INT_MAX/3
#define MAX_N 1000
struct Block{
    int h, a, c;
    Block(int h, int a, int c) : h(h),a(a),c(c) {}
    Block() {}
};
bool operator<(const Block &a, const Block &b){
    return a.a < b.a;
}
int K;
int dp[40010];
Block b[400];

int main(){
    scanf("%d", &K);
    for(int i = 0; i < K; ++i){
        int h, a, c;
        scanf("%d%d%d", &h, &a, &c);
        b[i] = Block(h, a, c);
    }
    sort(b, b + K);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i = 0; i < K; ++i){
      for(int j = 0; j <= b[i].a; ++j){
            if(dp[j] >= 0) dp[j] = b[i].c;
            if(j >= b[i].h) dp[j] = max(dp[j], dp[j-b[i].h] - 1);
        }
    }
    int r;
    for(r = 40000; ; --r) if(dp[r] >= 0) break;
    printf("%d\n", r);
    return 0;
}