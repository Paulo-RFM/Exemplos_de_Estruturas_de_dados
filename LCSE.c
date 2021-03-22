#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sBBT_LCSE{
    char letra;
    struct BBT_LCSE* prox;
}No_LCSE;

void inicializa_lista(No_LCSE** lista){
    *lista = NULL;
}

bool lista_vazia(No_LCSE** lista){
    if(*lista == NULL){
        return true;        
    }else{
        return false;
    }
}

No_LCSE* aloca_No_LCSE(){
    return (No_LCSE*) malloc (sizeof(No_LCSE));
}

void inserir_inicio(No_LCSE** lista, char elemento){
    No_LCSE* aux = *lista;
    No_LCSE* no_LCSEvo = aloca_No_LCSE();

    if(no_LCSEvo != NULL){
        no_LCSEvo->letra = elemento;
        if(lista_vazia(&aux)){
            no_LCSEvo->prox = no_LCSEvo;
            *lista = no_LCSEvo;
            return;   
        }

        no_LCSEvo->prox = (*lista)->prox;
        (*lista)->prox = no_LCSEvo;

    }else{
        putchar("\n\tErro na alocacao...\n");
        return;
    }
}

void inserir_final(No_LCSE** lista, char elemento){
    No_LCSE* aux = *lista;
    No_LCSE* no_LCSEvo = aloca_No_LCSE();

    if(no_LCSEvo != NULL){
        no_LCSEvo->letra = elemento;
    
        if(lista_vazia(&aux)){
            no_LCSEvo->prox = no_LCSEvo;
        }else{
            no_LCSEvo->prox = (*lista)->prox;
            (*lista)->prox = no_LCSEvo;
        }
        *lista = no_LCSEvo;
    }else{
        printf("\n\tErro na alocacao\n");
        return;
    }
}

void remover_inicio(No_LCSE** lista){
    No_LCSE* aux = *lista;

    if(lista_vazia(&aux)){
        printf("\n\tlista vazia...");
        return;
    }


    if(*lista == (*lista)->prox){
        free(aux);
        *lista = NULL;
        return;
    }

    aux = (*lista)->prox;
    (*lista)->prox = aux->prox;
    free(aux);

}

void remover_final(No_LCSE** lista){
    No_LCSE* aux = *lista;

    if(lista_vazia(&aux)){
        printf("\n\tLista Vazia...");
        return;
    }

    if(*lista == (*lista)->prox){
        free(aux);
        *lista = NULL;
        return;
    }

    do{
        aux = aux->prox;
        
    }while(aux->prox != *lista);

    aux->prox = (*lista)->prox;
    No_LCSE* q = *lista;
    *lista = aux;
    free(q);
}

void mostrar_lista(No_LCSE** lista){
    No_LCSE* aux = *lista;

    if(lista_vazia(&aux)){
        printf("->Null\n");
        return;
    }

   do{
       aux = aux->prox;
       putchar(aux->letra);
       printf("->");
   }while(aux != *lista);
printf("<-ptrList\n");
}

void mostra_vogais(No_LCSE** lista){
    No_LCSE* aux = *lista;
    char vogais[] = {'a', 'e', 'i', 'o', 'u'};

    if(lista_vazia(&aux)){
        printf("\n\tLista vazia");
        return;
    }

     if(*lista == (*lista)->prox){
        for(int i = 0 ; i < 5 ; i++){
            if(strcmp(aux->letra, vogais[i]) == 0){
                putchar(aux->letra);
            }
        }
        return;
    }

    for(int i = 0 ; aux->prox != *lista ; i++){
        if(strcmp(aux->letra, vogais[i]) == 0){
            putchar(aux->letra);
        }
        aux = aux->prox;
    }

}

void lista_libera(No_LCSE** lista){
    No_LCSE *p;
    No_LCSE *t;

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

char pedir_letra(){
    char elemento;
    printf("\nEntre com uma letra: ");
    fflush(stdin);
    scanf(" %s", &elemento);
    return elemento;
}

int pedir_int(){
    int op;
    printf("\nEntre com um numero inteiro: ");
    fflush(stdin);
    scanf("%d", &op);
    return op;
}

void menu_LCSE(){
    printf("\n\n\tMENU LCSE");
    printf("\n(1) Inserir elemento no_LCSE início da lista");
    printf("\n(2) Inserir elemento no_LCSE final da lista");
    printf("\n(3) Remover elemento no_LCSE início da lista");
    printf("\n(4) Remover elemento do final da lista");
    printf("\n(5) Exibir todos os elementos da lista");
    printf("\n(6) Exibir os elementos que forem vogais");
    printf("\nEntre com uma opcao: ");
}

void controller_LCSE(){
    int op;
    char letra;
    No_LCSE* lista;
    inicializa_lista(&lista);
    do{
        menu_LCSE();
        scanf("%d", &op);
    
        switch (op){
        case 1:
            inserir_inicio(&lista, pedir_letra());
            break;
        case 2:
            inserir_final(&lista, pedir_letra());
            break;
        case 3:
            remover_inicio(&lista);
            break;
        case 4:
            remover_final(&lista);
            break;
        case 5:
            mostrar_lista(&lista);
            break;
        case 6:
            mostra_vogais(&lista);
            break;
        default:
            printf("\nOpcao invalida...\n");
            break;
        }
    }while(op != 0);

    lista_libera(&lista);

}