#include <stdio.h>
#include <stdlib.h>
#define V 8
typedef struct node *link;//link型がstruct node *型であること
struct node{ 
    int v; 
    link next;//struct node *nextと同じであること
     };//vとnextの一組を接点あるいはnodeという
link NEW(int v, link next){ 
    link x = malloc(sizeof(*x));
    x->v = v; 
    x->next = next;   //nextがnextを参照しているということ,ここにはポインタ型の変数が入るので、アドレスを入れることが出来る。  
  return x;                         
}
int main(void){
 int i=0, j; 
 link adj[V];
  for (i = 0; i < V; i++) adj[i] = NULL;
  while (scanf("%d %d", &i, &j) == 2)
    {
      adj[j] = NEW(i, adj[j]);
      adj[i] = NEW(j, adj[i]);
    }
    while( adj[i]!= NULL){
        printf("%d->",adj[4]->v);
        adj[4]=adj[4]->next;
    }
    printf(".\n");
  return 0;
}
