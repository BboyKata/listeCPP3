#include <iostream>
#include <stdlib.h>

using namespace std;

bool listInitialised = false;

struct nodo
{
    int x; //valore del nodo della lista
    nodo *next; //indirizzo dell'elemento successivo
};

void initLista(nodo **T, nodo **coda){
    *T = NULL;
    *coda = NULL;
    listInitialised = true;
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
    nodo *p = new nodo;
    p = *T;
    while(p != NULL){
        cont++;
        p = p->next;
    }
    return cont;
}

void popList(nodo** T,nodo** coda,int e, int x){
    nodo *p = new nodo;
    nodo *j = new nodo;
    p = *T;
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
            j = p->next;
            if(isEmpty(&j->next)){
                p->next = NULL;
                *coda = p;
            }else{
                j = j->next;
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

void midAddList(int x, int v, int e, nodo **T, nodo **coda){
    nodo *nuovoP = new nodo;
    nodo *p = new nodo;
    nodo *j = new nodo;
    nuovoP->x = v;
    nuovoP->next = NULL;
    if(e == 0){
        headAdd(0,v,T,coda);
    } else if(e > elemLista(T)){
        cout<<"Errore, non esiste un nodo all'indice "<<e<<" !!!"<<endl<<endl;
    }else if(isEmpty(T)){
        cout<<"Errore, lista non ancora inizializzata "<<" !!!"<<endl<<endl;
    }else if(e == elemLista(T)-1){
        tailAdd(0,v,T,coda);
    }else{
        p = *T;
        for(int i = 0; i<e;i++){
            p = p->next;
        }
        j = p->next;
        p->next = nuovoP;
        nuovoP->next = j;
    }
}

void stampaLista(nodo **T, nodo **coda){
    nodo *p = new nodo;
    p = *T;
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
    if(!listInitialised){
        initLista(T,coda);
    }
    for(int i=0; i < 10; i++){
        tailAdd(0,i,T,coda);
        headAdd(0,i,T,coda);
    }
}

void sortList(nodo **T){
    nodo *p = new nodo;
    nodo *i = new nodo;
    nodo *j = new nodo;
    int *temp = new int;
    if(isEmpty(T)){
        cout<<"Errore, non posso ordinare una lista vuota!!!"<<endl;
    } else{
        p = *T;
        i = *T;
        j = (*T)->next;
        while(p != NULL){
            while(j != NULL){
                if(i->x>j->x){
                    *temp = i->x;
                    i->x = j->x;
                    j->x = *temp;
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
    int i = 0;
    nodo *p = *T;
    nodo *j = new nodo;
    if(isEmpty(T)){
        cout<<"Errore, lista non ancora inizializzata "<<" !!!"<<endl<<endl;
    } else {
        while(!isEmpty(&p->next)){
            j = p->next;
            temp = j->x;
            popList(T,coda,i+1,0);
            headAdd(0,temp,T,coda);
            i++;
        }
    }
}

int findIndexList(nodo **T, int s){
    nodo *p =*T;
    int ind = -1;
    bool found = false;
    while(p != NULL && !found){
        ind++;
        if(p->x == s){
            found = true;
        }
        p = p->next;
    }
}


int main()
{
    int c,s,v;
    nodo *T, *coda;
    do{
        cout<<"Operazioni sulla lista:"<<endl;
        cout<<"0) Esci;\n1) Crea lista;\n2) Aggiungi elemento in testa;\n3) Aggiungi elemento in coda;\n4) Visualizza lista;\n";
        cout<<"5) TestLista;\n6) Ricerca valore nella lista;\n7) Ordina lista;\n8) Rimuovi nodo dalla lista;\n9) Inverti lista;\n";
        cout<<"10) Rimozione in testa;\n11) Rimozione in coda;\n12) Rimozione con ricerca;\n13) Inserimento in mezzo;\n14) Inserimento ordinato;\nInserisci scelta: ";
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
                if(!listInitialised){
                    cout<<"Errore, lista non ancora inizializzata "<<" !!!"<<endl<<endl;
                } else {
                   headAdd(1,0,&T,&coda);
                   stampaLista(&T,&coda);
                }
                break;
            case 3:
                if(!listInitialised){
                    cout<<"Errore, lista non ancora inizializzata "<<" !!!"<<endl<<endl;
                } else {
                    tailAdd(1,0,&T,&coda);
                    stampaLista(&T,&coda);
                }
                break;
            case 4:
                if(!listInitialised){
                    cout<<"Errore, lista non ancora inizializzata "<<" !!!"<<endl<<endl;
                } else {
                    stampaLista(&T,&coda);
                }
                break;
            case 5:
                faiUnPoTu(&T,&coda);
                break;
            case 6:
                if(!listInitialised){
                    cout<<"Errore, lista non ancora inizializzata "<<" !!!"<<endl<<endl;
                } else {
                    cout<<"Inserisci il valore da ricercare nella lista: ";
                    cin>>s;
                    if(findList(&T,s)){
                        cout<<"Elemento trovato!"<<endl;
                    } else {
                        cout<<"Elemento non trovato!"<<endl;
                    }
                }
                break;
            case 7:
                if(!listInitialised){
                    cout<<"Errore, lista non ancora inizializzata "<<" !!!"<<endl<<endl;
                } else {
                    sortList(&T);
                    stampaLista(&T,&coda);
                }
                break;
            case 8:
                if(!listInitialised){
                    cout<<"Errore, lista non ancora inizializzata "<<" !!!"<<endl<<endl;
                } else {
                    cout<<"Inserisci l'indice dell'elemento da rimuovere[0-"<<elemLista(&T)-1<<"]: ";
                    cin>>s;
                    popList(&T,&coda,s,1);
                    stampaLista(&T,&coda);
                }
                break;
            case 9:
                if(!listInitialised){
                    cout<<"Errore, lista non ancora inizializzata "<<" !!!"<<endl<<endl;
                } else {
                    reverseList(&T,&coda);
                    stampaLista(&T,&coda);
                }
                break;
            case 10:
                if(!listInitialised){
                    cout<<"Errore, lista non ancora inizializzata "<<" !!!"<<endl<<endl;
                } else {
                    popList(&T,&coda,0,1);
                    stampaLista(&T,&coda);
                }
                break;
            case 11:
                if(!listInitialised){
                    cout<<"Errore, lista non ancora inizializzata "<<" !!!"<<endl<<endl;
                } else {
                    popList(&T,&coda,elemLista(&T)-1,1);
                    stampaLista(&T,&coda);
                }
                break;
            case 12:
                if(!listInitialised){
                    cout<<"Errore, lista non ancora inizializzata "<<" !!!"<<endl<<endl;
                } else {
                    cout<<"Inserisci il valore da eliminare dalla lista: ";
                    cin>>s;
                    if(findList(&T,s)){
                        int ind = findIndexList(&T,s);
                        popList(&T,&coda,ind,1);
                        stampaLista(&T,&coda);
                    } else {
                        cout<<"L'elemento non e' stato trovato, non puo essere eliminato!!!"<<endl;
                    }
                }
                break;
            case 13:
                if(!listInitialised){
                    cout<<"Errore, lista non ancora inizializzata "<<" !!!"<<endl<<endl;
                } else {
                    cout<<"Inserisci il valore da mettere nel nodo da aggiungere: ";
                    cin>>v;
                    cout<<"Inserisci l'indice nel quale inserire a fianco il nodo [0-"<<elemLista(&T)-1<<"]: ";
                    cin>>s;
                    midAddList(1,v,s,&T,&coda);
                    stampaLista(&T,&coda);
                }
                break;
            case 14:
                if(!listInitialised){
                    cout<<"Errore, lista non ancora inizializzata "<<" !!!"<<endl<<endl;
                } else {
                    headAdd(1,0,&T,&coda);
                    sortList(&T);
                    stampaLista(&T,&coda);
                }
                break;
            default:
                cout<<"Errore, reinserire la scelta."<<endl;
                break;
        }
    }while(c != 0);
    return 0;
}
