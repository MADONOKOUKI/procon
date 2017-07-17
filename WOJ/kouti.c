#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct kazunode* dlink;
typedef struct mojinode* link;
typedef char Moji;
typedef int Kazu;
dlink head=NULL;
link tail=NULL;

struct kazunode{
    Kazu kazu;
    dlink next;
};
struct mojinode{
    Moji moji;
    link Next;
};
dlink New(Kazu kazu,dlink next){
    dlink x = malloc(sizeof(*x));
    x->kazu = kazu;
    x->next = next;
    return x;
}
void temp(){
  Kazu t = head->kazu;
  head->kazu=head->next->kazu;
  head->next->kazu=t;
}
void Kazupush(Kazu kazu){
    head = New(kazu,head);
}

Kazu Kazupop(void){
  //printf("%d\n",head->kazu);
    Kazu kazu = head->kazu;
    dlink t = head-> next;
    free(head);
    head = t;
    return kazu;
}
link NEW(Moji moji,link next){
    link x = malloc(sizeof(*x));
    x->moji = moji;
    x->Next = next;
    return x;
}
void Mojipush(Moji moji){
    tail = NEW(moji,tail);
}

Moji Mojipop(void){
    Moji moji = tail->moji;
    link t = tail-> Next;
    free(tail);
    tail = t;
    return moji;
}

int main(){
    int i;
    char h[1000];
    fgets(h,1000,stdin);
    //link suuji,enzan;
    for(i=0;i<strlen(h);i++){
        if(h[i]>='0'&&h[i]<='9'){
            Kazupush(0);
            while(isdigit(h[i])){
            Kazupush(10*Kazupop()+(h[i++]-'0'));
            }
        }
        if(h[i]=='+'||h[i]=='-'||h[i]=='*'||h[i]=='/'){
            Mojipush(h[i]);
        }
        if(h[i]==')'){
            switch(Mojipop()){
                case '+':
                Kazupush(Kazupop()+Kazupop());
                break;
                case '-':
                Kazupush(0-Kazupop()+Kazupop());
                break;
                case '*':
                Kazupush(Kazupop()*Kazupop());
                break;
                case '/':
               temp();
                Kazupush(Kazupop()/Kazupop());
                //  printf("%d\n",Kazupop());
                break;
            }
        }
    }
    printf("%d\n",Kazupop());
    return 0;
}
