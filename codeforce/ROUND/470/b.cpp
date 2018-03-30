#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int mpf(int x) {
    static int i,ans;
    ans = 1;
    for(i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            ans = i;
            do {
                x /= i;
            } while (!(x % i));
        }
    }
    if (x != 1)
        ans = x;
    return ans;
}

int main() {
    int alice,range;
    scanf("%d", &alice);
    range = mpf(alice);
    cout<<range<<endl;
    int ans=alice,temp;
    for(int i = alice - range + 1;i <= alice;i++) {
        temp = mpf(i);
        cout<<temp<<endl;
        if (temp == i)
            continue;
        temp = i-temp+1;
        ans=min(temp,ans);
    }
    printf("%d\n",ans);
    return 0;
}
