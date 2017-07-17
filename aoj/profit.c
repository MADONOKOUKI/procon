#include<stdio.h>
int main()
{

    int n, i, Rt[200000], max=-1000000000;
    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &Rt[i]);
    }
    int min =Rt[0];
    for(i=1; i<n; i++){
        if(max < Rt[i]-min){
            max = Rt[i]-min;
        }
        if(min > Rt[i]){
            min = Rt[i];
        }
    }
    printf("%d\n", max);
    return 0;

  }
