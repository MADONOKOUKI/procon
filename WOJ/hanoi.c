#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shift(char a[],char b[],char c[],int n,int d){
  
}
void hanoi(char a[],char b[],char c[],int n,int d){
    if(n==-1){
        return;
    }
    hanoi(a,b,c,n-1,-d);
    shift(a,b,c,n,d);
    hanoi(a,b,c,n-1,-d);
}
int main(){
    int n,i;
    scanf("%d",&n);
    return 0;
}