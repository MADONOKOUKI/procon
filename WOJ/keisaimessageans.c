#include <stdio.h>
#include <stdlib.h>
 
int main(){
    int max;
    int count=0;
    char c[1025];
    int i,j;
    char key[10][5]={
        {0},
        {'.',',','!','?',' '},
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r','s'},
        {'t','u','v'},
        {'w','x','y','z'},
    };
    int counter=0;
    char d[77];
    char kiroku=0;
     
    scanf("%d\n",&max);
     while(counter<max){
        gets(c);
        i=0;
        j=0;
        count=0;
        while(c[i]){
            if(c[i]!='0'){
                if(kiroku==c[i]){
                    count++;
                }else{
                    kiroku=c[i];
                    count=0;
                }
            }else if(kiroku!=0){
                int test=3;
                switch(kiroku-'0'){
                    case 1:test++;
                    case 7:
                    case 9:test++;break;
                }
                count=count%test;
                d[j]=key[kiroku-'0'][count];
                j++;
                kiroku=0;
            }
            i++;
        }
        d[j]=0;
        printf("%s\n",d);
        counter++;
    }
    return 0;
}