#include <stdio.h>
 
 
char str[102];
 
int solve(){
    int stack[101]={};
    int i,p=0;
    for(i=0;str[i]!='.';i++){
        switch(str[i]){
            case '(':
                p++;
                stack[p]=1;
                break;
            case ')':
                if(stack[p]==1){
                    p--;
                }else{
                    return 1;
                }
                break;
            case '[':
                p++;
                stack[p]=2;
                break;
            case ']':
                if(stack[p]==2){
                    p--;
                }else{
                    return 1;
                }
                break;
        }
    }
    if(p==0){
        return 0;
    }else{
        return 1;
    }
}
 
int main(void){
    while(fgets(str,102,stdin),str[0]!='.'){
        if(!solve()){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
    return 0;
}