#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "activities\var.h"
#include "activities\Load_users.h"
#include "activities\SignUp.h"
#include "activities\SignIn.h"
#include "activities\other_activities.h"

int main(){
    consoleStyle();
    system ("COLOR F0");
    splashScreen();
    int MenuChoice;
    loadFile();
    do{
        system("Color F0");
        welcome_art();
        printf("%50.0s\n\n%40s\n%39s\n%37s\n%37s", "Welcome to Food Delivery System", "[1] Sign up", "[2] Log in", "[3] Exit", "Choice: ");
        scanf("%d", &MenuChoice);
        switch(MenuChoice){
        case 1:
            sign_up();
            break;
        case 2:
            sign_in();
            break;
        case 3:
            system("cls");
            bye();
            return 0;
            break;
        default:
            error_input();
        }
    }while(MenuChoice>-1);
}

