#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <ctype.h>
#include <cstdlib>
#include <set>
#include <map>
#include <queue> 
#include <deque>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>
//#include <stdlib.h>
//#include <string.h>
using namespace std;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef long long i64;
#define debug(x) cout << #x << " = " << x << endl
#define sz size()
#define mod(A, B) ((((A) % (B)) + (B)) % (B))
#define b2e(A) (A).begin(), (A).end()
#define e2b(A) (A).rbegin(), (A).rend()
#define rev(A) reverse(b2e(A))
#define s(A) sort(b2e(A))
#define ss(A) stable_sort(b2e(A))
#define un(A) unique(b2e(A))
#define er(A) (A).erase(un(A), (A).end())
#define Fill(A,B) fill(b2e(A), B)
#define minelt(A) *min_element(b2e(A))
#define maxelt(A) *max_element(b2e(A))
#define contains(A,B) (find(b2e(A),B)!=(A).end()) 
 
int gcd(int a, int b) { return (b==0) ? a : gcd(b,a%b); }
vi tok(string a){
  vi r; 
  char b[100],*s; 
  strcpy(b,a.c_str());
  b[0]=',';
  b[strlen(b)-1]=','; 
  for(s=strtok(b,",");s;s=strtok(0,",")){
    cout<<s<<endl;
  r.push_back(atoi(s)); 
  }
  return r;}
vs tokS(string a, string d){
  vs r; 
  char b[100],*s; 
  strcpy(b,a.c_str()); 
  for(s=strtok(b,d.c_str());
    s;
    s=strtok(0,d.c_str())) 
    r.push_back(s); 
  return r;
}

 class BettingMoney{
  public:
  int moneyMade(vector <int> amounts, vector <int> centsPerDollar, int finalResult) {
    int intake=0;
    for(int i=0;i<amounts.sz;i++)
    {
      if(i==finalResult)
      {
        intake-=amounts[i]*centsPerDollar[i];  
      }
      else intake+=100*amounts[i];
    }
    return intake;  
  }
};

int main(){
  string a,b;
  int n;
  BettingMoney money;
  cin>>a>>b>>n;
  int ans=money.moneyMade(tok(a),tok(b),n);
  cout<<ans<<endl;
  return 0;
}