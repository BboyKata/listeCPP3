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

bool findList(nodo **T, int s){
    nodo *p = *T;
    bool found = false;
    while(p != NULL && !found){
        if(p->x == s){
            found = true;
        }
        p = p->next;
    }
    return found;
}

bool isEmpty(nodo **T){
    bool isempty;
    if(*T == NULL){
        isempty = true;
    } else {
        isempty = false;
    }
    return isempty;
}

int elemLista(nodo** T){
    int cont=0;
    nodo *p = *T;
    while(p != NULL){
        cont++;
        p = p->next;
    }
    return cont;
}

void popList(nodo** T,nodo** coda,int e, int x){
    nodo *p = *T;
    nodo *i = new nodo;
    nodo *j = new nodo;
    if(e >= elemLista(T)){
        cout<<"Errore, non esiste un nodo all'indice "<<e<<" !!!"<<endl<<endl;
    }else if(isEmpty(T)){
        cout<<"Errore, lista non ancora inizializzata "<<" !!!"<<endl<<endl;
    } else {
        if(e==0){
            p = (*T)->next;
            (*T)->next = NULL;
            (*T)->x = NULL;
            *T = p;
        } else {
            for(int i = 0;i<e-1;i++){
                p = p->next;
            }
            i = p->next;
            j = i->next;
            (i)->next = NULL;
            (i)->x = NULL;

            if(isEmpty(&j)){
                p->next = NULL;
                *coda = p;
            }else{
                p->next = j;
            }
        }
        if(x != 0){
            cout<<endl<<"|||| ELEMENTO RIMOSSO ALL'INDICE "<<e<<" ||||"<<endl;
        }
    }
}

void headAdd(int x, int v, nodo **T, nodo **coda){
    nodo *nuovoP = new nodo;
    if(x != 0){
        cout<<"Inserisci il valore del nodo da aggiungere in testa: ";
        cin>>nuovoP->x;
    } else {
        nuovoP->x=v;
    }

    nuovoP->next = NULL;
    if(isEmpty(T)){
        *T = nuovoP;
        *coda = nuovoP;
    } else {
        nuovoP->next = *T;
        *T = nuovoP;
    }
    if( x != 0){
        cout<<endl<<"|||| NODO AGGIUNTO IN TESTA ||||"<<endl;
        cout<<"|||| NUMERO NODI ATTUALI: "<<elemLista(T)<<" ||||"<<endl;
    }
}

void tailAdd(int x, int v, nodo **T, nodo **coda){
    nodo *nuovoP = new nodo;
    if(x != 0){
        cout<<"Inserisci il valore del nodo da aggiungere in coda: ";
        cin>>nuovoP->x;
    } else {
        nuovoP->x = v;
    }
    nuovoP->next = NULL;
    if(isEmpty(T)){
        *T = nuovoP;
        *coda = nuovoP;
    } else {
        nuovoP->next = NULL;
        (*coda)->next = nuovoP;
        *coda = nuovoP;
    }
    if(x != 0){
        cout<<endl<<"|||| NODO AGGIUNTO IN CODA ||||"<<endl;
        cout<<"|||| NUMERO NODI ATTUALI: "<<elemLista(T)<<" ||||"<<endl;
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

void sortList(nodo **T){
    if(isEmpty(T)){
        cout<<"Errore, non posso ordinare una lista vuota!!!"<<endl;
    } else{

        nodo *p = *T;
        nodo *i = *T;
        nodo *j = (*T)->next;
        int temp;
        while(p != NULL){
            while(j != NULL){
                if(i->x>j->x){
                    temp = i->x;
                    i->x = j->x;
                    j->x = temp;
                    }
                j = j->next;
                i = i->next;
                }
            p = p->next;
            i= *T;
            j = (*T)->next;
        }
        cout<<endl<<"|||| LISTA ORDINATA ||||"<<endl;
    }

}

void reverseList(nodo **T, nodo**coda){
    int temp;
    nodo *p = *T;
    nodo *j = new nodo;
    if(isEmpty(T)){
        cout<<"Errore, lista non ancora inizializzata "<<" !!!"<<endl<<endl;
    } else {
        for(int i=0;i<elemLista(T)-1;i++){
            j = p->next;
            temp = j->x;
            popList(T,coda,i+1,0);
            headAdd(0,temp,T,coda);
        }
    }
}

int main()
{
    int c,s;
    nodo *T, *coda;
    do{
        cout<<"Operazioni sulla lista:"<<endl;
        cout<<"0) Esci;\n1) Crea lista;\n2) Aggiungi elemento in testa;\n3) Aggiungi elemento in coda;\n4) Visualizza lista;\n";
        cout<<"5) TestLista;\n6) Ricerca valore nella lista;\n7) Ordina lista;\n8) Rimuovi nodo dalla lista;\n9) Inverti lista;\nInserisci scelta: ";
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
            case 6:
                cout<<"Inserisci il valore da ricercare nella lista: ";
                cin>>s;
                if(findList(&T,s)){
                    cout<<"Elemento trovato!"<<endl;
                } else {
                    cout<<"Elemento non trovato!"<<endl;
                }
                break;
            case 7:
                sortList(&T);
                break;
            case 8:
                cout<<"Inserisci l'indice dell'elemento da rimuovere[0-"<<elemLista(&T)-1<<"]: ";
                cin>>s;
                popList(&T,&coda,s,1);
                break;
            case 9:
                reverseList(&T,&coda);
                break;
            default:
                cout<<"Errore, reinserire la scelta."<<endl;
                break;
        }
    }while(c != 0);
    return 0;
}
