#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Lista Simplesmente Encadeada
typedef struct sLSE{
    int info;
    struct sLSE* prox;
}No_LSE;

void menu_LSE(){
    printf("\n\n\tMENU LSE");
    printf("\n(1) Inserir elemento início da lista");
    printf("\n(2) Inserir elemento final da lista");
    printf("\n(3) Remover elemento no inicio da lista");
    printf("\n(4) Remover elemento por valor");
    /*printf("\n(5) ");
    printf("\n(6) ");
    printf("\n(7) ");*/
    printf("\n(8) Exibir todos os elementos da lista");
    printf("\n(0) Voltar para menu inicial");
    printf("\nEntre com uma opcao: ");
}

No_LSE* inicializar_listaLSE(No_LSE* lista){
    lista = NULL;
    return lista;
}

No_LSE* aloca_No_LSE(){
    return (No_LSE*) malloc (sizeof(No_LSE));
}

bool lista_vaziaLSE(No_LSE* lista){
    if(lista == NULL){
        return true;
    }else{
        return false;
    }
}

void lista_liberaLSE(No_LSE* lista){
    No_LSE *p;
    No_LSE *t;

    p = lista;
    while(p!= NULL){
            //Guardando a referencia para o proximo elemento
            t = p->prox;
            // libera a memoria apontada por p
            free(p);
            // faz apontar para prox
            p=t;

    }
}

No_LSE* inserir_inicioLSE(No_LSE* lista){
    int elem;
    No_LSE* novo = aloca_No_LSE(novo);

    if(novo != NULL){
        printf("Entre com o valor:");
        scanf("%d", &elem);
        novo->info = elem;
        
        if(lista_vaziaLSE(lista)){
            novo->prox = NULL;
            lista = novo;
            return lista;
        }

        novo->prox = lista;
        lista = novo;
    }else{
        printf("\n\tErro na alocacao..\n");
        return NULL;
    }

    return lista;
}

No_LSE* inserir_fimLSE(No_LSE* lista){
    No_LSE* novo = aloca_No_LSE(lista);
    No_LSE* aux = lista;
    int elem;

    if(novo != NULL){
        novo->prox = NULL;
        printf("Entre com o elemento: ");
        scanf("%d", &elem);
        novo->info = elem;
        
        if(lista_vaziaLSE(lista)){
            lista = novo;
            return;
        }

        while(aux->prox != NULL){ //Encontra ultimo elemento da lista;
            aux = aux->prox;
        }
    }else{
        printf("\n\tErro na alocacao");
        return ;
    }

    aux->prox = novo;
    return lista;
}

No_LSE* remover_inicioLSE(No_LSE* lista){
    No_LSE* aux = lista;

    if(lista_vaziaLSE(aux)){
        printf("\n\tLista vazia");
        return;
    }

    lista = aux->prox;
    free(aux);

return lista;
}
/*
No_LSE* remove_elementoLSE(No_LSE* lista){
    No_LSE* aux = lista;
    No_LSE* ant = lista;
    int elem = 0, k = 0;
    if(lista_vaziaLSE(lista)){
        printf("\n\tlLista vazia");
        return;
    }

    printf("\n-Entre com o valor a ser removido: ");
    scanf("%d", &elem);

    //if(lista->prox == NULL && aux == lista){
        if(aux->info == elem){
            ant = aux->prox;
            lista = ant;
            
        }
    

    
    free(aux);
    free(ant);
}
*/
void mostrar_listaLSE(No_LSE* lista){
    No_LSE* aux = lista;
    
    if(lista_vaziaLSE(lista)){
        printf("\n\tLista Vazia");
        return;
    }

    printf("\nLISTA:\n ptrLista->");
    do{
        printf("%d->", aux->info);
        aux = aux->prox;
    }while(aux != NULL);

    printf("NULL");
}


void controller_LSE(){
    No_LSE* lista;
    lista = inicializar_listaLSE(lista);
    int op;

    do{
        menu_LSE();
        scanf("%d", &op);

        switch (op){
        case 1:
           lista = inserir_inicioLSE(lista);
            break;
       case 2:
           lista = inserir_fimLSE(lista);
            break; 
         case 3:
           lista = remover_inicioLSE(lista);
            break;
        /*case 4:
            modificar_listaLSE(lista);
            break;
        case 5:
            remover_inicioLSE(lista);
            break;
        case 6:
            remover_finalLSE(lista);
            break;
        case 7:
            remover_elementoLSE(lista);
            break;*/
        case 8:
            mostrar_listaLSE(lista);
            break;
        case 0:
            break;
        default:
            printf("\n\tOpcao invalida...\n");
            break;
        }

    }while(op != 0);

lista_liberaLSE(lista);
return;
}