typedef int Item;
//今回は乱数を発生させてやるので
//typedef int Item を使用して良い
//typedef char Item;
#define eq(A,B) (A==B)
#define less(A,B) (A<B)
#define exch(A,B){
  Item t=A;
  A=B;
  B=t;
}


