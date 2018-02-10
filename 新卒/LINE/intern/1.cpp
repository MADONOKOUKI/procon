#include <iostream>
using namespace std;

typedef long long ll;
inline ll fix(ll num){
  // cout<<num<<endl;
  return num / 10 * 9 + num % 10;
}

inline ll decode(ll num){
  // cout<<num<<endl;
  return num/9 * 10 + num % 9 ;
}
int main(int argc, char *argv[])
{
  // start from 1 to ignore script name; argv[0] will be a name of processing file.
  for (int i = 1; i < argc; i++) {
    printf ("argv[%i]: %s\n", i, argv[i]);

  }
  // if(strcmp(argv[2],"+") == 0){
  //   cout<<decode(fix(atoi(argv[1])) + fix(atoi(argv[3])))<<endl;
  // } else {
  //   cout<<decode(fix(atoi(argv[1])) * fix(atoi(argv[3])))<<endl;
  // }
  return 0;
}
