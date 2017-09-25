#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;
typedef pair<ll, ll> PL;
typedef pair<P, ll> PPL;
 
#define INF INT_MAX/3
 
#define MAX_N 1000
 
int n,m,p;
int board[11][11][11];
int x[555],y[555];
int h[11][11];
 
/// black 1 white 2
 
bool check(int p){
    rep(i,n)rep(j,n)rep(k,h[i][j]){
        repl(dx,-1,2)repl(dy,-1,2)repl(dz,-1,2){
            if(dx==0&&dy==0&&dz==0)continue;
            int nx=i,ny=j,nz=k;
            int cnt=0;
            while(nx>=0&&nx<n&&ny>=0&&ny<n&&nz>=0&&ny<n&&board[nx][ny][nz]==p){
                nx+=dx,ny+=dy,nz+=dz;
                cnt++;
            }
            if(cnt==m)return true;
        }
    }
    return false;
}
 
int main(){
    cin.sync_with_stdio(false);
    while(1){
        cin>>n>>m>>p;
        if(n==0)break;
        rep(i,p){
            cin>>x[i]>>y[i];
            x[i]--; y[i]--;
        }
        bool draw=true;
        memset(board,0,sizeof(board));
        memset(h,0,sizeof(h));
        rep(i,p){
            board[x[i]][y[i]][h[x[i]][y[i]]++]=i%2+1;
            if(check(i%2+1)){
                if(i%2+1==1)cout<<"Black "<<i+1<<endl;
                else cout<<"White "<<i+1<<endl;
                draw=false;
                break;
            }
        }
        if(draw)cout<<"Draw"<<endl;
    }
    return 0;
}