#include <stdio.h>
#include <stdlib.h>
#define V 8

typedef struct node *link;//link型がstruct node *link であるということ
/*struct node{
  int v;
  struct node *link//vとnextの一組をノードまたは接点という
}
*/
struct node{
 int v; 
 link next; //struct node *nextと同じ
};
link NEW(int v, link next){
  link x = malloc(sizeof(*x));//struct node *link と同じでxが指す構造体のv要素とnext要素に代入された数を代入する
  x->v = v;//確保されたメモリサイズのポインタを返す
  x->next = next;     
  return x;                         
}

int main(void){
 int i, j; 
 link adj[V];//struct node *linkを8個用意する
  for (i = 0; i < V; i++) adj[i] = NULL;
  while (scanf("%d %d", &i, &j) == 2)
    {
      adj[j] = NEW(i, adj[j]);
      adj[i] = NEW(j, adj[i]);
    }
      printf("%d\n", adj[4]->next->next->v);
      return 0;
}