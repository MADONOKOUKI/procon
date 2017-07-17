#include <cstdio>
#include <set>
using namespace std;

int main(){
    //宣言
    set<int> s;

    //要素の追加
    s.insert(1);
    s.insert(3);
    s.insert(5);

    //要素の検索
    set<int>::iterator ite;

    ite=s.find(1);
    if(ite == s.end()){
        puts("not found");
    } else {
        puts("found");
    }

    ite=s.find(2);
    if(ite==s.end()){
        puts("not found");
    } else {
        puts("found");
    }
    //要素の削除
    s.erase(3);

    //要素の検索の別の方法
    if(s.count(3)!=0){
        puts("found");
    } else {
        puts("not found"); //not found が出力される
    }

    //要素をすべてループする
    for(ite = s.begin();ite != s.end();++ite){
        printf("%d\n",*ite);
    }
    return 0;
}