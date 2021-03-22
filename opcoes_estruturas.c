#include "menu.c"
#include <stdlib.h>
#include <string.h>
#include "LCSE.c"
#include "LLE.c"

int main(){
    int op;

    do{
        menu_home();
        scanf("%d", &op);

        switch (op){
            case 1:
                controller_LLE();
                break;
            case 2: 
                //inserir_final(&ptrLista, pedir_letra());
                break;
            case 3:
                //remover_inicio(&ptrLista);
                break;
            case 4:
                controller_LCSE();
                break; 
            case 5:
                //mostrar_lista();
                break;
            case 6:
                //mostra_vogais();
                break;
            default:
                break;
            }
        }while(op != 0);

return 0;
}