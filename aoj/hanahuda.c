#include <stdio.h>

int main (){
    int n,r,i,j;
    while(1){
        scanf("%d %d",&n,&r);
        if(n==0&&r==0){
            break;
        } else {
        int x[n];
            j=1;
            for(i=n-1;i>=0;i--){
                x[i]=j;
                j++;
            }
            for(i=0;i<r;i++){
                int m,l,k;
                scanf("%d %d",&m,&l);
                int y[m-1+l];
                for(k=0;k<m-1+l;k++){
                    y[k]=x[k];
                }
                for(k=0;k<l;k++){
                    x[k]=y[m-2+l-k];
                }
            }
        printf("%d\n",x[0]);
        }
    }
    return 0;
}