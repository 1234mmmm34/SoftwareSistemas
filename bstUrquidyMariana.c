#include<stdlib.h>
#include<stdio.h>

struct nodo{
    int key;
    struct nodo *izq;
	struct nodo *der;
};


struct nodo* nuevoNodo(int item){
    struct nodo* temp = (struct nodo*)malloc(sizeof(struct nodo));
        temp->key = item;
        temp->izq = temp->der = NULL;
        return temp;
}

struct nodo* insert(struct nodo* nodo, int key){
    if (nodo==NULL){
        return nuevoNodo(key);
    }
    if(key < nodo->key){
        nodo->izq = insert(nodo->izq, key);
    }
    else if(key > nodo->key){
        nodo->der = insert(nodo->der, key);
    }

    return nodo;
}


struct nodo *prev = NULL;

int validar(struct nodo* raiz){
	if(raiz){
		if(!validar(raiz->izq)){
			return 0;
		}
		if(prev != NULL && raiz->key <= prev->key){
			return 0;
		}
		prev = raiz;
		return validar(raiz->der);
	}
	return 1;
}

int main(){

    struct nodo *raiz = nuevoNodo(20);
    raiz->izq = nuevoNodo(19);
    raiz->der = nuevoNodo(21);
    raiz->izq->izq = nuevoNodo(22);
    raiz->izq->der = nuevoNodo(24);
    raiz->izq->der->der = nuevoNodo(25);
    raiz->izq->izq->der = nuevoNodo(23);

	if(validar(raiz)){
		printf("Aprobado");
	}
	else{
		printf("Reprobado");
	}

	
	return 0;
}
	
	
