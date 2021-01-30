#ifndef DRINKS_MENU_H_INCLUDED
#define DRINKS_MENU_H_INCLUDED
#include "var.h"
#include "other_activities.h"
#include "encrypt_decrypt.h"
#include <string.h>

int load_drinks(){
    int select;
    system("cls"); nl
    printf("%42s\n\n%37s\n%42s\n%36s\n%36s\n\n%36s","Type of Drink:", "[1] Juice", "[2] Softdrinks", "[3] Beer", "[4] Back", "Choice: ");
    scanf("%d", &select);
    if (select > 4 || select == 0){
        error_input();
    }else if(select > 0 && select < 4){
        select--;
        char selectedMenu[][25] = {"menu/juiceList.txt", "menu/softdrinksList.txt", "menu/beerList.txt"};
        strcpy(ed_name, selectedMenu[select]);
        en_de_crypt(0);
        FILE *listFoods;
        int i=0;
        listFoods = fopen (selectedMenu[select], "r");
        while (!feof(listFoods)){
            fscanf(listFoods,"%[^\n]\n%f\n", foods[i].foodName, &foods[i].foodPrice);
            j++;
            i++;
        }
        fclose(listFoods);
        system("cls");
        pass++;
        en_de_crypt(1);
    }
}

#endif // DRINKS_MENU_H_INCLUDED
