#ifndef SIGNIN_H_INCLUDED
#define SIGNIN_H_INCLUDED
#include "var.h"
#include "other_activities.h"
#include "MainUI.h"

void sign_in(){
    char li_email[30], li_pass[30];
    int i, proceed = 0;
    system("cls");nl
    printf("%37s\n%50s\n\n","LOG IN","===============================");
    printf("%27s","Email: ");
    scanf("%s", li_email);
    printf("%30s","Password: ");
    password_mask();
    strcpy(li_pass, mask_pass);
    reset_char();
    for(i=0; i<usercount; i++){
        if((strcmp(li_email, users[i].email)==0)&&(strcmp(li_pass, users[i].password)==0)){
            proceed++;
            logged_in_user=i;
            break;
        }
    }
    if (proceed == 1)
        ui_main();
    else{
        red();
        printf("\n\n%43s\n","User not found.");
        clrScrn();
        system("Color F0");
    }
}
#endif // SIGNIN_H_INCLUDED
