#ifndef SIGNUP_H_INCLUDED
#define SIGNUP_H_INCLUDED
#include "var.h"
#include "other_activities.h"
#include "save_user.h"

void sign_up(){
    char rpass[30];
    int selectCity, i, passmismatch=0;
    system("cls");
    users[usercount].userID = usercount+1;
    printf("\n\n%38s\n%55s\n\n%31s","SIGN UP","=========================================","BASIC INFORMATION");
    printf("\n\n%32s","Enter First Name: ");
    scanf(" %[^\n]s", users[usercount].fname);
    printf("%31s","Enter Last Name: ");
    scanf(" %[^\n]s", users[usercount].lname);
    printf("%38s","Enter mobile number: +63");
    scanf("%s", &users[usercount].mobile_number);
    printf("\n%21s\n\n", "ADDRESS");
    printf("%34s", "Enter house number: ");
    scanf(" %[^\n]s", users[usercount].house_no);
    printf("%33s","Enter street Name: ");
    scanf(" %[^\n]s", users[usercount].street);
    printf("%30s","Enter Barangay: ");
    scanf(" %[^\n]s", users[usercount].brgy);
    displayCities();
    printf("\n\n%27s", "Choose City: ");
    scanf("%d", &selectCity);
    selectCity--;
    if (selectCity == 13){
        printf("%26s","Enter City: ");
        scanf(" %[^\n]s", users[usercount].city);
    }else
        strcpy(users[usercount].city, cities[selectCity]);
    printf("%18s = %s\n", "City",users[usercount].city);
    printf("\n%32s\n","EMAIL AND PASSWORD");
    printf("\n%27s","Enter Email: ");
    scanf("%s", users[usercount].email);
    for(i=0; i<usercount; i++){
        while(strcmp(users[i].email,users[usercount].email)==0){
            printf("\n%51s\n%27s","Email already taken. Please try again","Enter Email: ");
            scanf("%s", users[usercount].email);
        }
    }
    printf("%30s","Enter Password: ");
    password_mask();
    strcpy(users[usercount].password,mask_pass);
    reset_char();
    printf("\n%32s","Confirm password: ");
    password_mask();
    strcpy(rpass,mask_pass);
    passmismatch = strcmp(users[usercount].password, rpass);
    reset_char();
    while(passmismatch!=0){
        printf("\n\n%32s\n%32s","Password mismatch.","Confirm password: ");
        password_mask();
        strcpy(rpass,mask_pass);
        passmismatch = strcmp(users[usercount].password, rpass);
        reset_char();
    }
    usercount++;
    printf("\n\n%31s\n\n","Sign up complete!");
    clrScrn();
    save();
}
#endif // SIGNUP_H_INCLUDED
