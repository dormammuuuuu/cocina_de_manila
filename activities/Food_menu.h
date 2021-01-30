#ifndef FOOD_MENU_H_INCLUDED
#define FOOD_MENU_H_INCLUDED
#include "var.h"
#include "other_activities.h"
#include "Browse_foods.h"
#include "User_Info.h"
#include "drinks_menu.h"
#include <string.h>
#include "encrypt_decrypt.h"

void foodsMenu(int select){
    char ob, selectedMenu[][25] = {"menu/mealsList.txt", "menu/dessertsList.txt", "menu/pastaList.txt", "menu/juiceList.txt", "menu/bundleList.txt", "menu/snacksList.txt"};
    int i=0, s_len, spaces=0, quantity = 0;
    if (select == 3){
        load_drinks();
    }else{
        strcpy(ed_name, selectedMenu[select]);
        en_de_crypt(0);
        FILE *listFoods;
        listFoods = fopen (selectedMenu[select], "r");
        while (!feof(listFoods)){
            fscanf(listFoods,"%[^\n]\n%f\n", foods[i].foodName, &foods[i].foodPrice);
            j++;
            i++;
        }
        pass++;
        fclose(listFoods);
        en_de_crypt(1);
    }
    if (pass != 0){
        do{
            int notlisted = 0;
            char selectedMenuName[][15] = {"MEALS", "DESSERTS", "PASTA", "DRINKS", "BUNDLE", "SNACKS"};
            system("cls");
            if (select == 4){
                FILE *bundleDisplay; char c;
                strcpy(ed_name, "menu/bundleDisplayList.txt");
                en_de_crypt(0);
                bundleDisplay = fopen(ed_name, "r");
                c = fgetc(bundleDisplay);
                printf("\n\n\n\n\n\n");
                while (c != EOF){
                    printf("%c", c);
                    c = fgetc(bundleDisplay);
                }
                fclose(bundleDisplay);
                en_de_crypt(1);
            }else{
                printf("\n\n\n\n%14s%23s%21s\n%60s\n", "#", selectedMenuName[select], "PRICE","===================================================");
                for(i=0; i<j; i++){
                    printf("\n%14d\t  %s",i+1, foods[i].foodName);
                    s_len = strlen(foods[i].foodName);
                    spaces = 35-s_len;
                    while(spaces!=0){
                        printf(" ");
                        spaces--;
                    }
                printf("%.2f", foods[i].foodPrice);
            }
        }
        printf("\n\n%60s\n", "===================================================");
        printf("\n%50s\n%49s\n","Press [1] to enter your order.", "Press [2] to go back to menu.");
        ob = getch();
        switch(ob){
            case '1':
                printf("\n\n%32s","Enter your order: ");
                scanf("%d", &order);
                if(order>j||order==0){
                    error_input();
                    ob = '0';
                }else{
                    printf("%24s","Quantity: ");
                    scanf("%d", &quantity);
                    order--;
                    for(i=0; i < num_orders; i++){
                        if (strcmp(orders[i].orderName,foods[order].foodName)==0){
                            orders[i].orderQuantity += quantity;
                            orders[i].orderPrice += foods[order].foodPrice * quantity;
                            notlisted++;
                        }
                    }
                    if (notlisted == 0){
                        strcpy(orders[num_orders].orderName, foods[order].foodName);
                        orders[num_orders].orderPrice = foods[order].foodPrice * quantity;
                        orders[num_orders].orderQuantity = quantity;
                        num_orders++;
                    }
                    system("cls");
                    system("Color 9f");
                    strlength = (strlen(foods[order].foodName) + 31) /2;
                    space = 35 - strlength;
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
                    while (space!=0){
                        printf(" ");
                        space--;
                    }
                    printf("%s[%d]%s", foods[order].foodName, quantity," has been added to your cart.");
                    printf("\n\n\n\n%48s\n%51s","Press [0] to order again.", "Press ANY KEY to go back to menu");
                    ob = getch();
                    resetcolor();
                    system("cls");
                }
                break;
            case '2':
                break;
            default:
                error_input();
            }
        }while(ob == '0');
    }
    memset(foods, 0, sizeof(foods));
    memset(ed_name, 0, sizeof(ed_name));
    i = j = pass = 0;
}


#endif // FOOD_MENU_H_INCLUDED
