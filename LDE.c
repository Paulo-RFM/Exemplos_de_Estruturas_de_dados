#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Lista ordenada duplamente Encadeada
typedef struct sLDE{
    int info;
    struct sLDE* prox;
    struct sLDE* ant;
}No_LDE;

void lista_liberaLDE(No_LDE** lista){
    No_LDE *p;
    No_LDE *t;

    p = *lista;
    while(p!= NULL){
            //Guardando a referencia para o proximo elemento
            t = p->prox;
            // libera a memoria apontada por p
            free(p);
            // faz apontar para prox
            p=t;

    }
}

void menu_LDE(){
    printf("\n\n\tMENU LDE");
    printf("\n(1) Inserir elemento início da lista");
    /* printf("\n(2) Inserir elemento final da lista");
    printf("\n(3) Remover elemento no inicio da lista");
    printf("\n(4) Remover elemento por valor");
   printf("\n(5) ");
    printf("\n(6) ");
    printf("\n(7) ");*/
    printf("\n(8) Exibir todos os elementos da lista");
    printf("\n(0) Voltar para menu inicial");
    printf("Entre com uma opcao: ");
}

No_LDE* aloca_NoLDE(No_LDE* novo){
    novo = (No_LDE*) malloc (sizeof(No_LDE));
}

void inicializar_listaLDE(No_LDE** lista){
    *lista  = NULL;
}

bool lista_vaziaLDE(No_LDE** lista){
    if(*lista == NULL){
        return true;
    }else{
        return false;
    }
}

void inserir_incicioLDE(No_LDE** lista){
    No_LDE* aux = *lista;
    No_LDE* novo = aloca_NoLDE(novo);
    int elem;

    if(novo != NULL){
        printf("Entre com um valor inteiro:");
        scanf("%d", &elem);
        novo->info = elem;

        if(lista_vaziaLDE(&aux)){
            *lista = novo;
            novo->ant = NULL;
            novo->prox = NULL;
        }else{
            (*lista)->ant = novo;
            novo->prox = *lista;
            novo->ant = NULL;
            *lista = novo;
        }
    }else{
        printf("Erro na alocacao do novo no...");
    }

return;
}

void mostrar_listaLDE(No_LDE** lista){
    No_LDE* aux = *lista;
    
    if(lista_vaziaLDE(&aux)){
        printf("\n\tLista vazia");
        return;
    }

    printf("\nLista¬\nNULL");
    do{
        printf("<-%d->", aux->info);
        aux = aux->prox;
    }while(aux != NULL);
    printf("NULL");

}

void controller_LDE(){
    No_LDE* lista;
    inicializar_listaLDE(&lista);
    int op;

    do{
        menu_LDE();
        scanf("%d", &op);

        switch (op){
        case 1:
            inserir_incicioLDE(&lista);
            break;
       /*case 2:
           lista = inserir_fimLDE(lista);
            break; 
         case 3:
           lista = remover_inicioLDE(lista);
            break;
         case 4:
            modificar_listaLDE(lista);
            break;
        case 5:
            remover_inicioLDE(lista);
            break;
        case 6:
            remover_finalLDE(lista);
            break;
        case 7:
            remover_elementoLDE(lista);
            break;*/
        case 8:
            mostrar_listaLDE(&lista);
            break;
        case 0:
            break;
        default:
            printf("\n\tOpcao invalida...\n");
            break;
        }

    }while(op != 0);

lista_liberaLDE(&lista);
return;
}
