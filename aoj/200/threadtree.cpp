#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
char str[1100][110];
vector<int>g[1100];
void dfs(int a,int b){
    for(int i=0;i<b;i++)printf(".");
    printf("%s\n",str[a]);
    for(int i=0;i<g[a].size();i++)dfs(g[a][i],b+1);
}
int main(){
    int a;scanf("%d",&a);
    for(int i=0;i<a;i++){
        int t;scanf("%d%s",&t,str[i]);
        if(t){
            t--;
            g[t].push_back(i);
        }
    }
    dfs(0,0);
}
