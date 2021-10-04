#include <iostream>
#include <stdlib.h>

using namespace std;
struct nodo
{
    int x; //valore del nodo della lista
    nodo *next; //indirizzo dell'elemento successivo
};

void initLista(nodo **T, nodo **coda){
    *T = NULL;
    *coda = NULL;
    cout<<endl<<"|||| LISTA CREATA ||||"<<endl;
}

void headAdd(int x = 0, int v = 0, nodo **T = NULL, nodo **coda = NULL){
    nodo *nuovoP = new nodo;
    if(x != 0){
        cout<<"Inserisci il valore del nodo da aggiungere in testa: ";
        cin>>nuovoP->x;
    } else {
        nuovoP->x=v;
    }

    nuovoP->next = NULL;
    if(T == NULL){
        *T = nuovoP;
        *coda = nuovoP;
    } else {
        nuovoP->next = *T;
        *T = nuovoP;
    }
    if( x != 0){
        cout<<endl<<"|||| NODO AGGIUNTO IN TESTA ||||"<<endl;
    }
}

void tailAdd(int x = 0, int v = 0, nodo **T = NULL, nodo **coda = NULL){
    nodo *nuovoP = new nodo;
    if(x != 0){
        cout<<"Inserisci il valore del nodo da aggiungere in coda: ";
        cin>>nuovoP->x;
    } else {
        nuovoP->x = v;
    }
    nuovoP->next = NULL;
    if(*T == NULL){
        *T = nuovoP;
        *coda = nuovoP;
    } else {
        nuovoP->next = NULL;
        (*coda)->next = nuovoP;
        *coda = nuovoP;
    }
    if(x != 0){
        cout<<endl<<"|||| NODO AGGIUNTO IN CODA ||||"<<endl;
    }
}

void stampaLista(nodo **T, nodo **coda){
    nodo *p = *T;
    int counter = 0;
    cout<<endl<<"Elementi della lista: "<<endl;
    while(p != NULL){
        cout<<counter<<") "<<p->x<<endl;
        p = p->next;
        counter++;
    }
    cout<<endl;
}

void faiUnPoTu(nodo **T, nodo **coda){
    initLista(T,coda);
    for(int i=0; i < 10; i++){
        tailAdd(0,i,T,coda);
        headAdd(0,i,T,coda);
    }
    stampaLista(T,coda);
}

int main()
{
    int c;
    nodo *T, *coda;
    do{
        cout<<"Operazioni sulla lista:"<<endl;
        cout<<"0) Esci;\n1) Crea lista;\n2) Aggiungi elemento in testa;\n3) Aggiungi elemento in coda;\n4) Visualizza lista;\nInserisci scelta: ";
        cin>>c;
        system("cls");
        switch(c){
            case 0:
                cout<<"Arrivederci"<<endl;
                break;
            case 1:
                initLista(&T,&coda);
                break;
            case 2:
                headAdd(1,0,&T,&coda);
                break;
            case 3:
                tailAdd(1,0,&T,&coda);
                break;
            case 4:
                stampaLista(&T,&coda);
                break;
            case 5:
                faiUnPoTu(&T,&coda);
                break;
            default:
                cout<<"Errore, reinserire la scelta."<<endl;
                break;
        }
    }while(c != 0);
    return 0;
}
