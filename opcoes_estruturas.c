#include "menu.c"
#include <stdlib.h>
#include <string.h>
#include "LCSE.c"
#include "LLE.c"
#include "LSE.c"

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
            case 4:
                controller_LCSE();
                break; 
            default:
                break;
            }
        }while(op != 0);

return 0;
}