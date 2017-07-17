#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
typedef int Item;
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) {Item t = A; A=B;B=t;}
#define compexch(A,B) if (less(B,A)) exch(A,B)
int partition(Item a[], int l, int r){ 
  int i = l-1, j = r; Item v = a[r];
  for (;;){ 
    while (less(a[++i], v)) ;
    while (less(v, a[--j])) if (j == l) break;
    if (i >= j) break;
    exch(a[i], a[j]);}
  exch(a[i], a[r]);
  return i;}

void quicksort(Item a[],int l,int r){
  int i;
  if(r<=l){
    return;
  }
  i=partition(a,l,r);
  quicksort(a,l,i-1);
  quicksort(a,i+1,r);
}

/*void sort(Item a[], int l, int r)
  { int i, j;
    for (i = l; i < r; i++)
      { int min = i;
        for (j = i+1; j <= r; j++) 
            if (less(a[j], a[min])) min = j;
        exch(a[i], a[min]);
      } 
  }
*/

int main(int argc , char *argv[]){
  clock_t t1,t2;
  int i;
  int N=atoi(argv[1]);
  int sw=atoi(argv[2]);
  int *a=malloc(N*sizeof(int));
  srand(1);
  if(sw){
    //for(i=0;i<N;i++){
    //  a[i]=100*(1.0*rand()/RAND_MAX);
   // }
    for(i=0;i<N;i++){
      a[i]=i;
    }
  } else {
    for(N=0;scanf("%d",&a[N]) == 1;N++);
  }
  t1=clock();
  quicksort(a,0,N);
  t2=clock();

  for(i=0;i<N;i++){
    printf("%3d",a[i]);
  }
  printf("\n");
  printf("クイックソート,整列済み,%d要素,%10.6fsec\n",N,(double)(t2-t1)/CLOCKS_PER_SEC);
}

 

