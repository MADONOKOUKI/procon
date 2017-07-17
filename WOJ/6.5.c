#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
typedef int Item;
#define maxN 100000
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) {Item t = A; A=B;B=t;}
#define compexch(A,B) if (less(B,A)) exch(A,B)
void distcount(int a[], int l, int r,int M){ 
  int i, j, cnt[M+10]; 
  int b[maxN+10];
  for (j = 0; j <  M; j++) cnt[j] = 0;
  for (i = l; i <= r; i++) cnt[a[i]+1]++;
  for (j = 1; j <  M; j++) cnt[j] += cnt[j-1];
  for (i = l; i <= r; i++) b[cnt[a[i]]++] = a[i];
  for (i = l; i <= r; i++) a[i] = b[i];
} 

int main(int argc , char *argv[]){
  clock_t t1,t2;
  int i;
  int N=atoi(argv[1]);
  int sw=atoi(argv[2]);
  int *a=malloc(N*sizeof(int));
  srand(1);
  if(sw){
   // for(i=0;i<N;i++){
     // a[i]=100*(1.0*rand()/RAND_MAX);
    //}
    for(i=0;i<N;i++){
      a[i]=i;
    }
  } else {
    for(N=0;scanf("%d",&a[N]) == 1;N++);
  }
  t1=clock();
  distcount(a,0,N-1,N-1);
  t2=clock();

  for(i=0;i<N;i++){
    printf("%3d",a[i]);
  }
  printf("\n");
 printf("キー添字計数法,整列済み,%d要素,%10.6fsec\n",N,(double)(t2-t1)/CLOCKS_PER_SEC);
}

 
 