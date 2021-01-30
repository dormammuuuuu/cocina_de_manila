#ifndef MAINUI_H_INCLUDED
#define MAINUI_H_INCLUDED
#include "var.h"
#include "other_activities.h"
#include "Browse_foods.h"
#include "User_cart.h"
#include "User_info.h"
#include "User_cart_checkout.h"


void ui_main(){
    int muiChoice, slen;
    do{
        system("cls");
        strlength = (strlen(users[logged_in_user].fname) + strlen(users[logged_in_user].lname) + 8) /2;
        space = 35 - strlength;
        printf("\n\n\n\n\n\n");
        while (space!=0){
            printf(" ");
            space--;
        }
        printf("%s %s %s!", "Hello,", users[logged_in_user].fname, users[logged_in_user].lname);
        printf("\n%50s\n%49s\n\n\n%39s\n%58s\n\n%31s\n%23s\n%31s\n%27s\n\n%58s\n\n%23s","You have successfully logged in", "to our food delivery system!","MAIN MENU", "=============================================", "[1] Browse Foods", "[2] Cart","[3] User profile", "[4] Sign out", "=============================================", "Choice: ");
        scanf("%d", &muiChoice);
        switch(muiChoice){
            case 1:
                browseFoods();
                break;
            case 2:
                viewCart();
                break;
            case 3:
                userProfile();
                break;
            case 4:
                system("cls");
                muiChoice=-1;
                break;
            default:
                error_input();
        }
    }while(muiChoice>-1);
}

#endif // MAINUI_H_INCLUDED
