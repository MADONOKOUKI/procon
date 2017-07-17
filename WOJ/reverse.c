#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node{
  char *item;
  link next;
};
link NEW(char *item, link next){
  link p;
  p= (link)malloc(sizeof *p);
  p->item= item;  p->next= next;
  return p;
}
void show(char *name, link p){
  printf("%s:", name);
  while( p!=NULL ){
    printf("->%s", p->item);
    p= p->next;
  }
  printf("->.\n");
}

int main(int argc, char *argv[]){
  link h1, h2;
  int i;

  h1= NULL;
  for(i= 1; i!=argc; i++){
    h1= NEW(argv[i], h1);
  }
  show("h1", h1);
  h2= NULL;
  while( h1!=NULL ){
    link p;
    p= h1;  h1= p->next;
    p->next= h2; h2= p;
  }
  show("h1",h1);
  show("h2",h2);
  return 0;
}
 