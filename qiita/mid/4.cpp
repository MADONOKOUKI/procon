#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int SZ=10005;
int n,m;
int A[SZ],B[SZ*SZ];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m;
    rep1(i,n) cin>>A[i];
    int k=0;
    rep(i,n+1) for(int j=i;j<n+1;j++)
        B[k++]=A[i]+A[j];
    sort(B,B+k);

    int ans=0;
    rep(i,k){
        int j=upper_bound(B,B+k,m-B[i])-B;
        if(j>0) ans=max(ans,B[i]+B[j-1]);
    }
    cout<<ans<<endl;

}
