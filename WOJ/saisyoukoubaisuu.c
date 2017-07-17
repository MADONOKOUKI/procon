#include <stdio.h>
unsigned long long int a,b;
unsigned long long int yuku(unsigned long long int a,unsigned long long int b){
    unsigned long long int temp;
    int gage=0;
    while(b!=0){
        if(gage>3){
            return 1;
        }
        temp=a%b;
        a=b;
        b=temp;
        gage++;
    }
    return a;
}
int main(){
    scanf("%lld %lld",&a,&b);
    printf("%lld\n",a*b/yuku(a,b));
    return 0;
}