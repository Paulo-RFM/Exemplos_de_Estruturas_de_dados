#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define TAMP 10

//Pilha linear estatica
typedef struct sPLE{
    char letras[TAMP];
    int topo;
}No_PLE;

void inicializa_pilhaPLE(No_PLE* pilha){
    pilha->topo = -1;
}

bool pilha_vaziaPLE(No_PLE* pilha){
    if(pilha->topo == -1){
        return true;
    }else{
        return false;
    }
}

bool pilha_cheiaPLE(No_PLE* pilha){
    if(pilha->topo+1 == TAMP){
        return true;
    }else{
        return false;
    }
}

void push_PLE(No_PLE* pilha){
    char elemento;
    No_PLE* aux = pilha;
    if(pilha_cheiaPLE(pilha)){
        printf("\n\tError:pilha cheia...");
        return;
    }

    for(int i = pilha->topo ; i >= 0 ; i--){
        pilha->letras[i+1] = pilha->letras[i];   
    }

    printf("Entre com a Letras: ");
    scanf(" %s", &elemento);
    
    pilha->letras[0] = elemento;
    pilha->topo++;
}

char pop_PLE(No_PLE* pilha){
    char q;

    if(pilha_vaziaPLE(pilha)){
        printf("\nPilha vazia");
        return q;
    }else{
       q = pilha->letras[0];
       for(int i = 0 ; i <= pilha->topo ; i++){
           pilha->letras[i] = pilha->letras[i+1];
       }
       pilha->topo--;
       printf("\nletra removida: %c\n", q);
       return q;
    }
}

char retornar_topoPLE(No_PLE* pilha){
    if (pilha_vaziaPLE(pilha)){
        printf("\nPilha vazia");
    }else{
        /*char temp = pilha->letras[0];
        printf("\n%c\n", temp);*/
        return pilha->letras[0];
    }
}

void mostrar_pilhaPLE(No_PLE* pilha){

    if(pilha_vaziaPLE(pilha)){
        printf("Pilha vazia..\n");;
        return;
    }
    
    printf("\nSTACK\n");
    for(int i = 0 ; i <= pilha->topo ; i++){
        printf("[%d]:%c\n", i, pilha->letras[i]);
    }
}

void menu_PLE(){
    printf("\n\n\tMENU PLE");
    printf("\n(1) Inserir letra na pilha(PUSH)");
    printf("\n(2) Remover letra do topo da pilha(POP)");
    printf("\n(3) Retornar ultimo elemento da lista");
    printf("\n(4) Exibir todos os elementos pilha");
    printf("\n(0) Voltar para menu inicial");
    printf("\nEntre com uma opcao: ");
}

void controller_PLE(){
    No_PLE pilha;
    int op;
    
    inicializa_pilhaPLE(&pilha);

    do{
        menu_PLE();
        scanf("%d", &op);

        switch (op){
        case 1:
            push_PLE(&pilha);
            break;
        case 2:
            pop_PLE(&pilha);
            break;
        case 3:
            retornar_topoPLE(&pilha);
            break;
        case 4:
            mostrar_pilhaPLE(&pilha);
            break;
        default:
            printf("\nOpcao invalida..");
            break;
        }
       
    }while(op != 0);

}