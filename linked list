#include <iostream>
using namespace std;

struct no{
    int valor;
    struct *prox;
};
typedef struct no no;

no *criar(int x){
    no *a;
    a = (no*) malloc(sizeof(no));
    a->prox=NULL;
    a->valor=x;
    return a;
}

no *inserir(no *a,int x){
    if(a==NULL){
        return criar(x);
    }
    else{
        a->prox = inserir(a->prox,x);
    }    
    return a;
}
