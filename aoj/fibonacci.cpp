#include <iostream>
#include <algorithm>
using namespace std;
 
int main(void){
    int i,v,d,ans;
    int fib[1012];
 
    while(cin>>v>>d){
        for(i=fib[0]=2,fib[1]=3;i<v;fib[i]=(fib[i-1]+fib[i-2])%1001,i++);
        sort(fib,fib+v);
        for(i=ans=1;i<v;i++) if(fib[i] - fib[i-1] >= d) ans++;
        cout<<ans<<endl;
    }
 
    return 0;
}