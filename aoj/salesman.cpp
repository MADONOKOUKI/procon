#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
 
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
 
using namespace std;
 
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;
 
const int INF=1<<29;
int dp[1<<16][20];
int d[20][20];
int main(){
  int V,E;
    cin>>V>>E;
    for(int i =0;i <(1<<16);i++){
        for(int j =0;j < V;j++){
            dp[i][j]=INF;
        }
    }
    for(int i =0;i < V;i++){
        for(int j =0;j < V;j++){
            d[i][j]=INF;
        }
    }
     
    for(int i =0;i < E;i++){
        int x,y,c;
        cin>>x>>y>>c;
        d[x][y] =c;
    }
    dp[1][0]=0;
    for(int i =0;i <(1<<V);i++){
        for(int j =0;j <V;j++){
            if((i>>j&1)==0)continue;
            for(int k =0;k < V;k++){
                if((i>>k&1)==1)continue;
                dp[i|(1<<k)][k] =min(dp[i|(1<<k)][k],dp[i][j]+d[j][k]);
                //cout <<"dp = "<<dp[i|(1<<k)][k]<<endl;
            }
        }
    }
    int ans =INF;
    for(int i =0;i <V;i++){
        ans =min(ans,dp[(1<<V)-1][i]+d[i][0]);
    }
    if(ans>=INF){
        cout <<-1<<endl;
    }else{
        cout <<ans<<endl;
    }
    return 0;
}