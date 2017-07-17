#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int Item;
#define maxN 1000
Item aux[maxN];

void show(Item a[], int ll, int l, int r, int rr){
  int i;
  for(i= ll; i!=l; i++) printf("  ");
  for(i= l; i<=r; i++) printf(" %c", a[i]);
  for(i=r; i!=rr; i++) printf("  ");
}

void showTwo(int ll, int rr, Item a[], int la,int ra, Item b[], int lb, int rb){
  show(a,ll,la,ra,rr);
  printf(" |");
  show(b,ll,lb,rb,rr);
  printf("\n");
}

void merge(Item a[], int l, int m, int r){ 
  int i, j, k;
  for (i = m+1; i > l; i--) {
    aux[i-1] = a[i-1];
  }
  for (j = m; j < r; j++){
    aux[r+m-j] = a[j+1];
  }
  showTwo(l,r, aux,l,r, a,r,r);
  for (k = l; k <= r; k++){
    if (aux[i]<aux[j]){
      a[k] = aux[i++]; 
    }else{                     
      a[k] = aux[j--];
    }
    showTwo(l,r, aux,i,j, a,l,k);
  }
}
int main(int argc, char *argv[]){
  int N= strlen(argv[1]);
  Item *a; 
  int i;
  a= (Item*)malloc(N*sizeof(Item));
  for(i= 0; i!=N; i++) {
    a[i]= argv[1][i];
  }
  showTwo(0,N-1, a,0,-1, a,0,N-1);
  merge(a,0,N/2-1,N-1);
}