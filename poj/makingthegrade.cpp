#include <cstdio>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
using namespace std ;

typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const double inf = 0x3f3f3f3f3f3f3f;
const double eps = 1e-8;
const int maxn = 3e4 + 5;
const int dr[] = {0, 0, -1, 1};
const int dc[] = {-1, 1, 0, 0};
int m, n;
inline bool is_in(int r, int c){
    return r >= 0 && r < n && c >= 0 && c < m;
}
int a[maxn], b[maxn];
LL d[maxn];

int main(){
    while(scanf("%d", &n) == 1){
        for(int i = 0; i < n; ++i)  scanf("%d", &a[i]), b[i] = a[i];
        sort(b, b+n);
        for(int i = 0; i < n; ++i) { d[i] = abs(b[i]-a[0]); //printf("%lld\n",d[i]);
      }
        for(int i = 1; i < n; ++i){
            LL mmin = d[0];
            for(int j = 0; j < n; ++j){
             // printf("%lld %lld\n",d[j],mmin);
                mmin = min(mmin, d[j]);
                d[j] = (LL)mmin + (LL)abs(b[j]-a[i]);
                printf("%lld ",d[j]);
            }
            printf("\n");
        }
        LL ans = INF;
        for(int i = 0; i < n; ++i) { ans = min(ans, d[i]); printf("%lld ",ans);}
        cout << ans << endl;
    }
    return 0;
}