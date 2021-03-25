#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Lista Circular Simplesmente Encadeada
typedef struct sBBT_LCSE{
    char letra;
    struct BBT_LCSE* prox;
}No_LCSE;

void inicializa_lista(No_LCSE** lista){
    *lista = NULL;
}

bool lista_vaziaLCSE(No_LCSE** lista){
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
    No_LCSE* novo = aloca_No_LCSE();

    if(novo != NULL){
        novo->letra = elemento;
        if(lista_vaziaLCSE(&aux)){
            novo->prox = novo;
            *lista = novo;
            return;  
        }

        novo->prox = (*lista)->prox;
        (*lista)->prox = novo;

    }else{
        printf("\n\tErro na alocacao...\n");
        return;
    }
}

void inserir_final(No_LCSE** lista, char elemento){
    No_LCSE* aux = *lista;
    No_LCSE* novo = aloca_No_LCSE();

    if(novo != NULL){
        novo->letra = elemento;
    
        if(lista_vaziaLCSE(&aux)){
            novo->prox = novo;
        }else{
            novo->prox = (*lista)->prox;
            (*lista)->prox = novo;
        }
        *lista = novo;
    }else{
        printf("\n\tErro na alocacao\n");
        return;
    }
}

void remover_inicio(No_LCSE** lista){
    No_LCSE* aux = *lista;

    if(lista_vaziaLCSE(&aux)){
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

    if(lista_vaziaLCSE(&aux)){
        printf("\n\tLista Vazia...");
        return;
    }

    if(*lista == (*lista)->prox){
        free(aux);
        *lista = NULL;
        return;
    }

    do{
        //faz aux apontar para o penultimo elemento da lista*
        aux = aux->prox;
        
    }while(aux->prox != *lista);

    aux->prox = (*lista)->prox;
    No_LCSE* q = *lista;
    *lista = aux;
    free(q);
}

void mostrar_lista(No_LCSE** lista){
    No_LCSE* aux = *lista;

    if(lista_vaziaLCSE(&aux)){
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
 
    if(lista_vaziaLCSE(&aux)){
        printf("\n\tLista vazia");
        return;
    }
    
    printf("\nVogais: ");

    //Se existe apenas um elemento
     if(*lista == (*lista)->prox){
        if(aux->letra == 'a' || aux->letra == 'e' || aux->letra == 'i' || aux->letra == 'o' || aux->letra == 'u'){
            putchar(aux->letra);
        }
        return;
    }

    do{
        if(aux->letra == 'a' || aux->letra == 'e' || aux->letra == 'i' || aux->letra == 'o' || aux->letra == 'u'){
            putchar(aux->letra);
        }
        aux = aux->prox;
    }while(aux != *lista);

return;
}

void lista_liberaLCSE(No_LCSE** lista){
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
    printf("\n(1) Inserir letra no início da lista");
    printf("\n(2) Inserir letra no final da lista");
    printf("\n(3) Remover letra do início da lista");
    printf("\n(4) Remover letra do final da lista");
    printf("\n(5) Exibir todos as letras da lista");
    printf("\n(6) Exibir as letras que forem vogais");
    printf("\n(0) Voltar ao menu inicial");
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
        case 0:
            break;
        default:
            printf("\nOpcao invalida...\n");
            break;
        }
    }while(op != 0);

    lista_liberaLCSE(&lista);
return;
}