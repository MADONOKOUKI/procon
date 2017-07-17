#include <stdio.h>
#include <string.h>

int main(){
    int a=0,b=0,i=0,x=0,y=0,ans=0;
    char h[10000];
    int low=0,len=0;
    while(fgets(h+i,1000,stdin)!=NULL){
    while(i<strlen(h)){
        if(h[i]=='('){
            a++;
            low=i;
        }
        if(h[i]=='['){
            b++;
            len=i;
        }
        if(h[i]==')'){
            a--;
            if(low<len){
                a-=100;
            }
            low=0;
        }
        if(h[i]==']'){
            b--;
            if(low>len){
                b-=100;
            }
            len=0;
        }
        if(a<0||b<0){
            while(h[i]!='.'){
                i++;
            }
        }
        if(h[i]='.'){
            break;
        }
        i++;
        printf("%d\n",a);
         printf("%d\n",b);
        
    }
        if(a==0&&b==0){
            printf("yes\n");
            } else {
            printf("no\n");
            }
            a=0;b=0;low=0;len=0;
            i++;
        }
    return 0;
}












/*
#include <stdio.h>
#include <string.h>

int main(){
    int a=0,b=0,i=0,x=0,y=0,ans=0,j;
    char l[10000];
    while(fgets(l+i,1000,stdin)!=NULL){
        char h[10000];
        int u=0;
        for(j=0;j<strlen(l);j++){
         if(l[j]!=' '){
             h[u]=l[j];
             u++;
         }   
        }
    while(i<strlen(h)){
        if(h[i]=='('){
            a++;
            x-=i;
        }
        if(h[i]=='['){
            b++;
            y-=i;
        }
        if(h[i]==')'){
            a--;
            x+=i;
        }
        if(h[i]==']'){
            b--;
            y+=i;
        }
        if(a<0||b<0){
            while(h[i]!='.'){
                i++;
            }
        }
        if(h[i]='.'){
            break;
        }
        i++;
    }
        if(a==0&&b==0&&x==y){
            printf("yes\n");
            } else {
            printf("no\n");
            }
            a=0;b=0;x=0;y=0;ans=0;
            i++;
        }
    return 0;
}
*/