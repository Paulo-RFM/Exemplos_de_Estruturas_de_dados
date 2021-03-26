#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Pilha Linear Dinamica de pratos

typedef struct sPrato{
    char cor[15];
    int tamanaho;
    char tipo_prato[15];
}Prato;


typedef struct sPLD{
    Prato prato;
    struct sPLD* prox;
}No_PLD;

void menu_PLD(){
    printf("\n\n\tMENU PLD");
    printf("\n(1) Inserir prato na pilha(PUSH)");
    printf("\n(2) Remover prato do topo da pilha(POP)");
    /*printf("\n(3) Retornar ultimo prato da lista");
    printf("\n(4) Exibir todos os pratos pilha");
    printf("\n(0) Voltar para menu inicial");*/
    printf("\nEntre com uma opcao: ");
}


void inicializa_pilhaDinan(No_PLD** pilha){
    *pilha = NULL;
}

No_PLD* aloca_NoPLD(){
    return (No_PLD*) malloc (sizeof(No_PLD));
}

bool pilha_vaziaPLD(No_PLD** pilha){
    if(*pilha == NULL){
        return true;
    }else{
        return false;
    }
}

void lista_liberaPLD(No_PLD** lista){
    No_PLD *p;
    No_PLD *t;

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

void preenche_NoPLD(No_PLD** novo){
    fflush(stdin);
    No_PLD* aux = *novo;
    
    if(novo != NULL){printf("\nCor do prato: ");
        scanf("%s", aux->prato.cor);
        printf("\nTamanho do prato: ");
        scanf("%d", &aux->prato.tamanaho);
        printf("Material do prato: ");
        scanf("%s", aux->prato.tipo_prato);
    }else{
        printf("Erro na alocacao do novo no");
    }
    *novo = aux; 
}

void push_PLD(No_PLD** pilha){
    No_PLD* aux = *pilha;
    No_PLD* novo = aloca_NoPLD(novo);
    preenche_NoPLD(&novo);

    if(pilha_vaziaPLD(pilha)){
        *pilha = novo;
        novo->prox = NULL;
    }else{
       novo->prox = aux;
       *pilha = novo;
    }
}

void pop_PLD(No_PLD** pilha){
    No_PLD* aux = *pilha;

    if(pilha_vaziaPLD(&aux)){
        printf("\n\tLista vazia");
    }else{
        *pilha = aux->prox;
        free(aux);
    }
}



void controller_PLD(){
    No_PLD* pilha;
    inicializa_pilhaDinan(&pilha);
    int op = 0;

    do{
        menu_PLD();
        scanf("%d", &op);

        switch (op){
            case 1:
                push_PLD(&pilha);
                break;
            case 2:
                pop_PLD(&pilha);
                break;
            default:
                printf("\nOpcao invalida...");
                break;
        }
    }while(op != 0);

lista_liberaPLD(&pilha);
}
