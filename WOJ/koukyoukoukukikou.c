#include <stdio.h>
 
int check(char c){
    switch(c){
        case 'y':
        case 'u':
        case 'i':
        case 'o':
        case 'p':
        case 'h':
        case 'j':
        case 'k':
        case 'l':
        case 'n':
        case 'm':
            return 1;
        default:
            return 0;
    }
}
 
int main(void){
    char line[34];
    int count,i;
    while(scanf("%s",line),line[0]!='#'){
        count=0;
        for(i=0;line[i+1];i++){
            if(check(line[i])!=check(line[i+1])) count++;
        }
        printf("%d\n",count);
    }
    return 0;
}