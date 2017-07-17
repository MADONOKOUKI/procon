#include <stdio.h>
#include <math.h>

int main(void){
    int l,i,j,a[30]={0},count;
    long n,tmp,max,min,b[30]={0},f=0;
    
    scanf("%ld %d",&n,&l);
    while(1){
        if(n==0&&l==0){
            break;
        }//nもlも0だったらおわり
        max=0;min=0;tmp=0;count=0;f=0;
    
        while(f!=1){
            max=0;min=0;
            if(count==0){//一周目だったらbの一番最初に代入した数を代入
                b[count]=n;
            } else {
                for(i=0;i<count;i++){
                if(n==b[i]||i>=29){
                    printf("%d %ld %d\n",i,b[i],count-i);
                    f=1;
                    break;
                }
            }
        }
        for(i=0;i<l;i++){
            a[i]=n%10;
            n/=10;
        }
        for(i=0;i<l-1;i++){
            for(j=i+1;j<l;j++){
                if(a[i]<a[j]){
                    tmp=a[i];
                    a[i]=a[j];
                    a[j]=tmp;
                }
            }
        }
        for(i=0;i<l;i++){
            max+=a[i]*pow(10,(l-i-1));
            min+=a[i]*pow(10,1);
        }
        
        count++;
        
        n=max-min;
        
        b[count]=n;
    }
    scanf("%ld %d",&n,&l);
    }
    return 0;
}