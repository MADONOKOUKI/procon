#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <bitset>
using namespace std;
 
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
 
#define INF 1000000000
 
int main(){
  int n;
  cin>>n;
  rep(repeat, n){
    char rule[10];
    scanf("%s", rule);
    string s;
    cin>>s;
 
    int sz=s.size();
    for(int i=strlen(rule)-1; i>=0; i--){
      switch(rule[i]){
      case 'J':
    s = s.substr(sz-1,1) + s.substr(0, sz-1);
    break;
      case 'C':
    s = s.substr(1, sz-1) + s.substr(0,1);
    break;
      case 'E':
    s = s.substr((sz+1)/2, sz/2) + s.substr(sz/2, sz%2)
      + s.substr(0, sz/2);
    break;
      case 'A':
    reverse(all(s));
    break;
      case 'P':
    rep(j,sz){
      if(s[j]>='1' && s[j]<='9') s[j]--;
      else if(s[j]=='0') s[j]='9';
    }
    break;
      case 'M':
    rep(j,sz){
      if(s[j]>='0' && s[j]<='8') s[j]++;
      else if(s[j]=='9') s[j]='0';
    }
    break;
      default:
    cout<<"BUG"<<endl;
      }
    }
    cout<<s<<endl;
  }
  return 0;
}