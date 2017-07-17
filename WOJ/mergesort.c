#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
typedef int Item;
#define maxN 10000000
Item aux[maxN];
#define min(A,B) (A<B) ? A : B
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) {Item t = A; A=B;B=t;}
#define compexch(A,B) if (less(B,A)) exch(A,B)

void fixDown(Item a[] , int k, int N){
    int j;
    while(2*k<=N){
        j=2*k;
        //大きい方の子をjとする
        if(j<N&&less(a[j],a[j+1])){
            j++;
        }
        //大きい方の子のキーが親のキーより小さくなければよいから
        //もしa[k]>a[j]だったら終わりにする
        if(!less(a[k],a[j])){
            break;
        }
        exch(a[k],a[j]);
        k=j;
    }
}
//要するに一番子ノードのものからヒープソートしてけばいい
void heapsort(Item a[] , int l.int r){
    clock_t t1,t2;
    int k;
    int n=r-1+l;
    Item* pq = a+l-1;
    t1=clock();
    for(k=n/2;k>=1;k--){
        fixDown(pq,k,n);
    }
    t2=clock()
    
    //ボトムアップのヒープ化
    //下降整列で最大要素と最後尾とを交換する
    while(N>1){
        exch(pq[1],pq[n]);
        fixDown(pq,1,--n);
    }
    printf("ヒープソートソート,ランダム,%d要素,%10.6fsec\n",N,(double)(t2-t1)/CLOCKS_PER_SEC);
    
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
  int N=atoi(argv[1]);
  int sw=atoi(argv[2]);
  int *a=malloc(N*sizeof(int));
  int i;
  
  srand(1);
  if(sw){
    for(i=0;i<N;i++){
      a[i]=100*(1.0*rand()/RAND_MAX);
   }
   // for(i=0;i<N;i++){
     // a[i]=i;
    //}
  } else {
    for(N=0;scanf("%d",&a[N]) == 1;N++);
  }
  t1=clock();
  heapsort(a,0,N);
  t2=clock();

  for(i=0;i<N;i++){
    printf("%3d",a[i]);
  }
  printf("\n");
  printf("ボトムアップマージソート,ランダム,%d要素,%10.6fsec\n",N,(double)(t2-t1)/CLOCKS_PER_SEC);
}

 

