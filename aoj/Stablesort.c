#include<stdio.h>
typedef struct
{
    char m;
    int n;
}Card;
int main()
{
    int a,b,d=0,i,j;
    scanf("%d",&a);
    Card x[a],y[a],c={0};
    for(i=0;i<a;i++){
        scanf(" %c%d",&x[i].m,&x[i].n);
        y[i]=x[i];
    }
    for(i=0;i<a-1;i++){
        for(j=a-1;j>i;j--){
            if(x[j].n<x[j-1].n){
                c=x[j-1];
                x[j-1]=x[j];
                x[j]=c;
            }
        }
    }
    for(i=0;i<a;i++){
        if(i==a-1)printf("%c%d\n",x[i].m,x[i].n);
        else printf("%c%d ",x[i].m,x[i].n);
    }
    puts("Stable");
    for(i=0;i<a;i++){
        b=i;
        for(j=i;j<a;j++){
            if(y[j].n<y[b].n){
                b=j;
            }
        }
        if(i!=b){
            c=y[i];
            y[i]=y[b];
            y[b]=c;
        }
    }
    for(i=0;i<a;i++){
        if(i==a-1)printf("%c%d\n",y[i].m,y[i].n);
        else printf("%c%d ",y[i].m,y[i].n);
    }
    for(i=0;i<a;i++){
        if(x[i].m==y[i].m)d++;
    }
    if(a==d)puts("Stable");
    else puts("Not stable");
    return 0;
}
