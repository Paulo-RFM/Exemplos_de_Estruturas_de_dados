#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
    printf("\n(7) Remover elemento por valor");
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
        printf("Entre com um valor inteiro:");
        scanf("%d", &elem);
        novo->info = elem;
        
        if(lista_vaziaLSE(lista)){
            novo->prox = NULL;
            lista = novo;
        }else{
            novo->prox = lista;
            lista = novo;
        }
    }else{
        printf("\n\tErro na alocacaodo novo no..\n");
    }

return lista;
}

No_LSE* inserir_fimLSE(No_LSE* lista){
    No_LSE* novo = aloca_No_LSE(lista);
    No_LSE* aux = lista;
    No_LSE* ant = aux;
    int elem;

    if(novo != NULL){
        novo->prox = NULL;
        printf("Entre com um valor inteiro: ");
        scanf("%d", &elem);
        novo->info = elem;
        
        if(lista_vaziaLSE(lista)){
            lista = novo;
            return lista;
        }

        while(aux->prox != NULL){ //Encontra ultimo elemento da lista;
            aux = aux->prox;
        }
    }else{
        printf("\n\tErro na alocacao");
        return lista;
    }
    aux->prox = novo;
    return lista;
}

No_LSE* remover_inicioLSE(No_LSE* lista){
    No_LSE* aux = lista;

    if(lista_vaziaLSE(aux)){
        printf("\n\tLista vazia");
        return lista;
    }

    lista = aux->prox;
    free(aux);

return lista;
}

No_LSE* remover_elementoLSE(No_LSE* lista){
    No_LSE* aux = lista;
    No_LSE* ant = lista;
    No_LSE* q = NULL;
    int elem = 0, k = 0;
    
    if(lista_vaziaLSE(lista)){
        printf("\n\tlLista vazia");
        return lista;
    }

    printf("\n-Entre com o valor a ser removido: ");
    scanf("%d", &elem);

    //Elemento na primeira posição
    if(aux->info == elem){
        if(aux->prox != NULL){
           aux = aux->prox;
           lista = aux;
           free(ant);
           return lista;
        }else{
            aux = aux->prox;
            lista = aux;
            free(ant);
            return lista;
        }
    }

    do{
        if(aux->info == elem){
            aux = aux->prox;
            q = ant->prox;
            ant->prox = aux;
            ant = q;
            free(ant);
            return lista;
        }
        ant = aux;
        aux = aux->prox;

    }while(aux != NULL);

return lista;
}

//função implementada usando caracter como info da estrutura
void exercicio_3_LSE(No_LSE** lista){
    No_LSE* aux = *lista;
    No_LSE* ptrO = *lista;
    No_LSE* ptrB = *lista;
    No_LSE* ptrS = aux;
    No_LSE* ptrA = aux;

    while(aux != NULL){
        
        if(aux->info == 'o' || aux->info == 'O'){
            ptrO = aux;
            ptrS->prox = NULL;
            aux = *lista;
            while(aux != NULL){
                if(aux->info == 'b' || aux->info == 'B'){
                    ptrB = aux;
                    ptrA->prox = ptrS; 
                    aux = aux->prox;
                }else{
                    ptrA = aux;
                    aux = aux->prox;
                }
            }
        }else{
            ptrS = aux;
            aux = aux->prox;
        }

    }

    ptrO->prox = *lista;
    ptrB->prox = ptrO;
    *lista = ptrB;
    aux = *lista;
    while(aux != NULL){
        putchar(aux->info);
        aux = aux->prox;
    }
return;
}

void mostrar_listaLSE(No_LSE* lista){
    No_LSE* aux = lista;
    
    if(lista_vaziaLSE(lista)){
        printf("\n\tLista Vazia");
        return;
    }

    printf("\nLISTA:\n ptrLista->");
    do{
        printf("%d", aux->info);
        printf("->");
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
            break;*/
        case 7:
           lista = remover_elementoLSE(lista);
            break;
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