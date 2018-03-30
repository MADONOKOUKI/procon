#include<stdio.h>
int main(){
    double ax,ay,bx,by,cx,cy,dx,dy;
    while(~scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy)){
        if(
        ((ax-cx)*(by-ay)+(ay-cy)*(ax-bx))*
        ((ax-cx)*(dy-ay)+(ay-cy)*(ax-dx))<=0&&
        ((bx-dx)*(ay-by)+(by-dy)*(bx-ax))*
        ((bx-dx)*(cy-by)+(by-dy)*(bx-cx))<=0)printf("YES\n");
        else printf("NO\n");
    }
}
