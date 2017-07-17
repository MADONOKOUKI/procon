#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
using namespace std;

const int d[4]={-1, 1, -4, 4};

map<string,int> Count;

void bfs(void)  {
  queue<string> que;

  que.push("01234567");
  while ( !que.empty() )  {
    string wk1=que.front(); que.pop();
    int pos=wk1.find('0');
    for (int i=0; i<4; ++i)
      if ( 0<=pos+d[i] && pos+d[i]<8 && !(pos==3 && i==1) &&  !(pos==4 && i==0) ) {
        string wk2=wk1;
        swap(wk2[pos],wk2[ pos+d[i] ]);
        if ( !Count[wk2] )  {
          que.push(wk2);
          Count[wk2]=Count[wk1]+1;
        }
      }
  }
}

void Slove(int n) {
  string str="";

  str+=(n+'0');
  for (int i=0; i<7; ++i) {
    cin >> n;
    str+=(n+'0');
  }
  cout << Count[str]-1 << endl;
}

int main(void)  {
  int n;

  Count["01234567"]=1;
  bfs();
  while (cin >> n)
    Slove(n);
  return 0;
}
