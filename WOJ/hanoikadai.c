#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int m;
void change(char a[],char b[],char c[]);
void shift(char a[],char b[],char c[],int n,int d);
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
    m=n;
    char a[n],b[n],c[n];
    for(i=0;i<n;i++){
        a[i]='0'+i;
        b[i]='.';
        c[i]='.';
    }
    change(a,b,c);
    hanoi(a,b,c,n-1,1);
    return 0;
}


//関数
void change(char a[],char b[],char c[]){
 int i;
        for(i=0;i<m;i++){
            printf("%c",a[i]);
        }
        printf(" ");
        for(i=0;i<m;i++){
            printf("%c",b[i]);
        }
        printf(" ");
        for(i=0;i<m;i++){
            printf("%c",c[i]);
        }
         printf("\n");
}

void shift(char a[],char b[],char c[],int n,int d){
    int i=0,j=0;
    int len=strlen(a);
    char tem;
    while(1){
        if(a[j]=='0'+n){
            n=1;
            break;
        }
        if(b[j]=='0'+n){
            n=2;
            break;
        }
        if(c[j]=='0'+n){
            n=3;
            break;
        }
        j++;
    }
    if(d==1){
        if(n==1){
            while(a[i]=='.'){
                i++;
            }
            tem=a[i];
            a[i]='.';
            i=strlen(a);
            while(c[i]!='.'){
                i--;
            }
            c[i]=tem;
        } else if(n==2){
            while(b[i]=='.'){
                i++;
            }
            tem=b[i];
            b[i]='.';
            i=strlen(a);
            while(a[i]!='.'){
                i--;
            }
            a[i]=tem;
        } else if(n==3){
            while(c[i]=='.'){
                i++;
            }
            tem=c[i];
            c[i]='.';
            i=len;
            while(b[i]!='.'){
                i--;
            }
            b[i]=tem;
        }
       change(a,b,c);
    } else if(d==-1){
        
        if(n==1){
            while(a[i]=='.'){
                i++;
            }
            tem=a[i];
            a[i]='.';
            i=len;
            while(b[i]!='.'){
                i--;
            }
            b[i]=tem;
        } else if(n==2){
            while(b[i]=='.'){
                i++;
            }
            tem=b[i];
            b[i]='.';
            i=len;
            while(c[i]!='.'){
                i--;
            }
            c[i]=tem;
        } else if(n==3){
            while(c[i]=='.'){
                i++;
            }
            tem=c[i];
            c[i]='.';
            i=len;
            while(a[i]!='.'){
                i--;
            }
            a[i]=tem;
        }
            change(a,b,c);
    }
}