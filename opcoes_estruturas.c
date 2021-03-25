#include "menu.c"
#include <stdlib.h>
#include <string.h>
#include "LCSE.c"
#include "LLE.c"
#include "LSE.c"
#include "LDE.c"
#include "PLE.c"

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
                controller_LSE();
                break;
            case 3:
                controller_LDE();
                break;
            case 4:
                controller_LCSE();
                break;
            case 5:
                controller_PLE();
                break;
            default:
                printf("\nOpção invalida...\n");
                break;
            }
        }while(op != 0);

return 0;
}