#ifndef BROWSE_FOODS_H_INCLUDED
#define BROWSE_FOODS_H_INCLUDED
#include "var.h"
#include "Food_menu.h"

void browseFoods(){
    do{
        system("cls");
        printf("\n\n\n\n\n%35s\n%46s\n\n%30s\n%33s\n%30s\n%31s\n%32s\n%31s\n\n%46s\n\n%34s\n%29s\n\n%46s\n\n%29s", "MENU", "=========================", "[1] Meals", "[2] Desserts", "[3] Pasta", "[4] Drinks", "[5] Bundles", "[6] Snacks", "=========================", "[7] View Cart", "[8] Back","=========================", "Choice: ");
        scanf("%d", &choice);
        choice--;
        switch(choice){
            case 0:
                foodsMenu(choice);
                break;
            case 1:
                foodsMenu(choice);
                break;
            case 2:
                foodsMenu(choice);
                break;
            case 3:
                foodsMenu(choice);
                break;
            case 4:
                foodsMenu(choice);
                break;
            case 5:
                foodsMenu(choice);
                break;
            case 6:
                system("cls");
                viewCart();
                break;
            case 7:
                choice=-2;
                break;
            default:
                error_input();
        }
    }while(choice>-2);
}

#endif // BROWSER_FOODS_H_INCLUDED
