#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  //宣言(intがキー、const char*　が値)

  map<int ,const char*> m;

  //要素の追加
  m.insert(make_pair(1,"ONE"));
  m.insert(make_pair(10,"TEN"));
  m[100]="HUNDRED";

  //要素の検索
  map<int,const char*>::iterator ite;
  ite = m.find(1);
  puts(ite->second); // ONE

  ite=m.find(2);
  if(ite==m.end()){
    puts("not found"); //not found
  } else {
    puts(ite->second); // 別の書き方
  }

  puts(m[10]);

  //要素の削除
  m.erase(10);

  //要素すべてをループ
  for(ite=m.begin();ite!=m.end();++ite){
    cout << ite->first;
    cout << ite->second << endl;
  }
  return 0;
}