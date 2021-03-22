#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAML 10


//Lista Linear Estatica
typedef struct sLLE{
    int lista[TAML];
    int n;
}No_LLE;

void menu_LLE(){
    printf("\n\n\tMENU LLE");
    printf("\n(1) Inserir elemento início da lista");
    printf("\n(2) Inserir elemento final da lista");
    printf("\n(3) Inserir elemento na posicao K");
    printf("\n(4) Modificar elemento na posicao K");
    printf("\n(5) Remover elemento no inicio da lista");
    printf("\n(6) Remover elemento no final da lista");
    printf("\n(7) Remover elemento(pelo valor)");
    printf("\n(8) Exibir todos os elementos da lista");
    printf("\nEntre com uma opcao: ");
}



No_LLE* inicializa_listaLLE(No_LLE* lista){
    lista = (No_LLE*) malloc (sizeof (No_LLE));
    lista->n = -1;
    
    return lista;
}

bool lista_vaziaLLE(No_LLE* lista){
    if(lista->n == -1){
        return true;
    }else{
        return false;
    }
}

bool lista_cheiaLLE(No_LLE* lista){
    if(lista->n+1 == TAML){
        return true;
    }else{
        return false;
    }
}

void inserir_inicioLLE(No_LLE* lista){
    int elemento;
    if(lista_cheiaLLE(lista)){
        printf("\n\tError:Lista cheia...");
        return;
    }

    for(int i = lista->n ; i >= 0 ; i--){
        lista->lista[i+1] = lista->lista[i];
    }

    printf("Entre com o valor: ");
    scanf("%d", &elemento);
    
    lista->lista[0] = elemento;
    lista->n++;
}

void inserir_fimLLE(No_LLE* lista){
    int elemento;

    if(lista_cheiaLLE(lista)){
        printf("\n\tError:Lista cheia...");
        return;
    }

    printf("Entre com valor: ");
    scanf("%d", &elemento);

    lista->n++;
    lista->lista[lista->n] = elemento;
}

void inserir_posK_LLE(No_LLE* lista){
    int elemen, k;
    if(lista_cheiaLLE(lista)){
        printf("\n\tError:Lista cheia...");
        return;
    }

    printf("\nInserir na posicao..: ");
    scanf("%d", &k);
    
    if(k< 0 || k>lista->n+1){
        printf("\nError: Posicao invalida..\n");
        return;
    }
    
    lista->n++;
    int i = lista->n;
    for(i = lista->n ; i > k ; i--){
        lista->lista[i] = lista->lista[i-1];
    }
    
    printf("\nEntre com o valor: ");
    scanf("%d", &elemen);
    lista->lista[k] = elemen;
}

void modificar_listaLLE(No_LLE* lista){
    int elemen, k;

    if(lista_vaziaLLE(lista)){
        printf("\n\tLista vazia...");
        return;
    }

    printf("\nInserir na posicao..: ");
    scanf("%d", &k);
    
    if(k< 0 || k>lista->n+1){
        printf("\nError: Posicao invalida..\n");
        return;
    }

    lista->lista[k] = elemen;
}

int remover_finalLLE(No_LLE* lista){
    int removed = 0;
    if(lista_vaziaLLE(lista)){
        printf("\n\tLista Vazia");
        return removed;
    }
    removed = lista->lista[lista->n];
    lista->lista[lista->n] = 0;
    lista->n--;
    
return removed;
}

int remover_inicioLLE(No_LLE* lista){
    int removed;
    if(lista_vaziaLLE(lista)){
        printf("\n\tLista Vazia");
        return;
    }

    for(int i = 0 ; i < lista->n ; i++){
        lista->lista[i] = lista->lista[i+1];
    }

    removed = lista->lista[lista->n];
    lista->lista[lista->n] = 0;
    lista->n--;
    return removed;
}

int remover_elementoLLE(No_LLE* lista){
    int element =0 , k;

    if(lista_vaziaLLE(lista)){
        printf("\n\tLista Vazia");
        return element;
    }

    printf("\nEntre com o elemento: ");
    scanf("%d", &element);

    //Localiza elemento na lista
    for(int i = 0 ; i <= lista->n ; i++){
        if(element == lista->lista[i]){
            k = i;
            element = lista->lista[i];
            break;
        }
        printf("\n\tElemento nao encontrado");
        return element;
    }

    for(int i = k ; i < lista->n ; i++){
        lista->lista[i] = lista->lista[i+1];
    }

    lista->lista[lista->n] = 0;
    lista->n--;
    return element;
}

void mostrar_listaLLE(No_LLE* lista){
    printf("\nLista\n");

    if(lista_vaziaLLE(lista)){
        printf("Lista Vazia..\n");
        return;
    }

    for(int i = 0 ; i <= lista->n ; i++){
        printf("[%d]:%d ", i, lista->lista[i]);
    }
}
 
void controller_LLE(){
    No_LLE* lista;
    lista = inicializa_listaLLE(lista);
    int op;

    do{
        menu_LLE();
        scanf("%d", &op);

        switch (op){
        case 1:
            inserir_inicioLLE(lista);
            break;
        case 2:
            inserir_fimLLE(lista);
            break; 
        case 3:
            inserir_posK_LLE(lista);
            break;
        case 4:
            modificar_listaLLE(lista);
            break;
        case 5:
            remover_inicioLLE(lista);
            break;
        case 6:
            remover_finalLLE(lista);
            break;
        case 7:
            remover_elementoLLE(lista);
            break;
        case 8:
            mostrar_listaLLE(lista);
            break;
        default:
            printf("\n\tOpcao invalida...\n");
            break;
        }

    }while(op != 0);

free(lista);
}