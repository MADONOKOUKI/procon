#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node { char item; link l, r;};

#define LINE_LENGTH 100
char line[LINE_LENGTH+2];

link genTree();
void show(link h);

int main(int argc, char *argv[]){
  link head;
  fgets(line,LINE_LENGTH,stdin);
  head= genTree();
  show(head);
  return 0;
}

int cp; char ch;
void get_ch(){
  ch= line[cp++];
}
link genR(){
  link p;
  if( ch=='.' ){ get_ch(); return NULL; }
  if( ch=='\n' || ch=='\0' ) return NULL;
  p= (link)malloc(sizeof *p);
  p->item= ch; get_ch();
  p->l= genR();
  p->r= genR();
  return p;
}
link genTree(){
  cp= 0; get_ch();
  return genR();
}
void spaces(int n){
 while( n-- !=0 ) printf("  ");
}
void showR(link h, int depth){
  if( h==NULL ){ 
    spaces(depth); printf(".\n"); return; 
  }
  showR(h->r, depth+1);
  spaces(depth); printf("%c\n", h->item);
  showR(h->l, depth+1);
}
void show(link h){
  showR(h, 0);
}