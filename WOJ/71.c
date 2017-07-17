#include <stdio.h>
#include <string.h>

int main(){
    int a=0,b=0,c=0,i;
    char h[1024];
    fgets(h,1024,stdin);
    for(i=0;i<strlen(h);i++){
        if(h[i]=='('){
            a++;
        }
        if(h[i]=='{'){
            b++;
        }
        if(h[i]=='['){
            c++;
        }
        if(h[i]==')'){
            a--;
        }
        if(h[i]=='}'){
            b--;
        }
        if(h[i]==']'){
            c--;
        }
    }
    if(a==0&&b==0&&c==0){
    printf("correct");
        } else {
    printf("wrong");
    }
    return 0;
}