#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define maxn 10000
using namespace std;

int a[maxn],b[maxn];

int n;

int w1,w2;

void pri(int x){
  int p=n-x;
  p/=2;
  for(int i=1;i<=p;i++){
    printf("%d ",b[++w2]);
  }
  for(int i=1;i<=x;i++){
    printf("%d ",a[++w1]);
  }
  for(int i=1;i<=p;i++){
    printf("%d ",b[++w2]);
  }
}

int main(){
  cin>>n;
  for(int i=1;i<=n*n;i++){
    if(i%2==1){
      a[++a[0]]=i;
    } else {
      b[++b[0]]=i;
    }
  }

  for(int i=1,j=1;i<=n/2+1;i++,j+=2){
    pri(j);
    puts("");
  }
  for(int i=1,j=n-2;i<=n/2;i++,j-=2){
    pri(j);
    puts("");
  }
  return 0;
}