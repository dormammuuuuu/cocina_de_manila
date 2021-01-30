#ifndef USER_EDIT_H_INCLUDED
#define USER_EDIT_H_INCLUDED
#include "var.h"
#include "other_activities.h"
#include "save_user.h"

void edit_name(){
    system("cls"); nl
    printf("%40s\n%57s\n\n", "UPDATE NAME","============================================");
    printf("%31s","Enter first name:");
    scanf(" %[^\n]s", users[logged_in_user].fname);
    printf("%31s","Enter last Name: ");
    scanf(" %[^\n]s", users[logged_in_user].lname);
    printf("\n%57s", "============================================");
    profile_update();
}

void edit_email(){
    char email[30], confirm_Email[30]; int cmp, i;
    do{
        cmp = 0;
        system("cls");nl
        printf("%40s\n%57s\n\n", "UPDATE EMAIL","============================================");
        printf("%30s","Enter new email:");
        scanf(" %[^\n]s", email);
        printf("%32s","Confirm new email:");
        scanf(" %[^\n]s", confirm_Email);
        printf("\n%57s", "============================================");
        if (strcmp(email, confirm_Email)!=0){
                printf("\n\n%43s\n%47s","Email doesn't match.", "Press ANY KEY to try again.");
                getch();
        }else{
                for(i=0; i<usercount; i++){
                    if(strcmp(users[i].email,confirm_Email)==0){
                        printf("\n\n%43s\n%47s","Email already taken.","Press ANY KEY to try again.");
                        cmp++;
                        break;
                    }
                }
                if (cmp == 1)
                    getch();
                else{
                    cmp=0;
                    strcpy(users[logged_in_user].email, email);
                    profile_update();
                }
        }
    }while(strcmp(users[logged_in_user].email, confirm_Email)!=0 || cmp == 1);
}

void edit_address(){
    int selectCity;
    system("cls");
    printf("\n\n%21s\n%59s\n\n", "ADDRESS", "=============================================");
    printf("%34s", "Enter house number: ");
    scanf(" %[^\n]s", users[logged_in_user].house_no);
    printf("%33s","Enter street Name: ");
    scanf(" %[^\n]s", users[logged_in_user].street);
    printf("%30s","Enter Barangay: ");
    scanf(" %[^\n]s", users[logged_in_user].brgy);
    displayCities();
    printf("\n\n%27s", "Choose City: ");
    scanf("%d", &selectCity);
    selectCity--;
    if(selectCity == 13){
        printf("%26s","Enter City: ");
        scanf(" %[^\n]s", users[logged_in_user].city);
    }else{
        strcpy(users[logged_in_user].city, cities[selectCity]);
    }
    printf("%18s = %s\n", "City",users[logged_in_user].city);
    profile_update();
}

void edit_pw(){
    char temp_pass[20];nl
    int passmismatch;
    system("cls"); nl
    printf("%43s\n%57s\n\n", "UPDATE PASSWORD","============================================");
    printf("%34s","Enter new password: ");
    password_mask();
    strcpy(temp_pass, mask_pass);
    reset_char();
    printf("\n%36s","Confirm new password: ");
    password_mask();
    passmismatch = strcmp(temp_pass, mask_pass);
    printf("\n\n%57s", "============================================");
    while(passmismatch!=0){
        printf("\n\n%32s\n%36s","Password mismatch.","Confirm new password: ");
        password_mask();
        passmismatch = strcmp(temp_pass, mask_pass);
        reset_char();
    }
    strcpy(users[logged_in_user].password, temp_pass);
    profile_update();
}

void profile_update(){
    printf("\n\n%47s","Press ANY KEY to continue");
    getch();
    save();
    system("cls"); system("Color 9F");nl
    printf("\n\n%43s\n%47s", "Profile updated!","Press ANY KEY to continue");
    getch();
    system("Color F0");
}

#endif // USER_EDIT_NAME_H_INCLUDED
