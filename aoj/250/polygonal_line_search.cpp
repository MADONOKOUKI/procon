#include<stdio.h>
#include<algorithm>
using namespace std;
int dx[10];
int dy[10];
int ex[10];
int ey[10];
int main(){
    int a;
    while(scanf("%d",&a),a){
        int b;
        scanf("%d",&b);
        int p,q;
        scanf("%d%d",&p,&q);
        for(int i=0;i<b-1;i++){
            int c,d;
            scanf("%d%d",&c,&d);
            dx[i]=c-p;
            dy[i]=d-q;
            p=c;
            q=d;
        }
        for(int i=0;i<a;i++){
            bool ok=false;
            int n;
            scanf("%d",&n);
            int s,t;
            scanf("%d%d",&s,&t);
            for(int j=0;j<n-1;j++){
                int u,v;
                scanf("%d%d",&u,&v);
                ex[j]=u-s;
                ey[j]=v-t;
                s=u;
                t=v;
            }
            if(n!=b)continue;
            for(int j=0;j<4;j++){
                bool OK=true;
                for(int k=0;k<n-1;k++)if(dx[k]!=ex[k]||dy[k]!=ey[k])OK=false;
                if(OK)ok=true;
                OK=true;
                for(int k=0;k<n-1;k++)if(dx[k]!=ex[n-2-k]||dy[k]!=ey[n-2-k])OK=false;
                if(OK)ok=true;
                // 4方向行うためこれを記述する
                for(int k=0;k<n-1;k++){
                    int f=ey[k];
                    int g=-ex[k];
                    ex[k]=f;
                    ey[k]=g;
                }
            }
            if(ok)printf("%d\n",i+1);
        }
        printf("+++++\n");
    }
}
