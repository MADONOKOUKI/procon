#include<stdio.h>
#include<string.h>

int max_(int x,int y){
    if(x<y){return y;}
    else{
        return x;
        }   
    }

int min_(int x,int y){
    if(x<y){
        return x;
    } else {
        return y;
    }
}

int main(){
    char h[1000000],str[1000000];
    int i,a=-1,b=-1,c=-1,max,min,ans=1000000;
    //h=getchar();
    while(fgets(h, 1000000, stdin) != NULL){
        strcpy(str+i, h);
        i += strlen(h)-1;
    }
    for(i=0;i<strlen(str);i++){
    if(tolower(str[i])=='t'){
        a=i;
    } else if(tolower(str[i])=='a'){
        b=i;
    } else if(tolower(str[i])=='g'){
        c=i;
    }
    if(a+b+c!=-3){
        max=max_(max_(a,b),c);
        min=min_(min_(a,b),c);
        if(ans>max-min){
            ans=max-min;
            if(min==a)a=-1;
            if(min==b)b=-1;
            if(min==c)c=-1;
            }
        }
        
    }
   if(ans==1000000){
        printf("none\n");
    } else {
        printf("%d\n",ans+1);
    }
    
    return 0;
}