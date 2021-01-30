#ifndef USER_INFO_H_INCLUDED
#define USER_INFO_H_INCLUDED
#include "var.h"
#include "other_activities.h"
#include "User_edit.h"

void userProfile(){
    int select;
    do{
        system("cls");
        printf("\n\n\n%41s\n%62s\n\n","USER PROFILE", "====================================================");
        printf("%20s%s %s\n%25s%s\n%21s%s","Name: ", users[logged_in_user].fname, users[logged_in_user].lname, "Number: +63", users[logged_in_user].mobile_number, "Email: ",users[logged_in_user].email);
        printf("\n%22s %s %s %s, %s\n\n%62s", "Address:",users[logged_in_user].house_no, users[logged_in_user].street, users[logged_in_user].brgy, users[logged_in_user].city, "====================================================");
        printf("\n\n%35s\n%29s\n%32s\n%32s\n%35s\n%24s\n\n%24s", "Select an operation:", "[1] Edit name", "[2] Change Email", "[3] Edit Address", "[4] Change password", "[5] Back", "Choice: ");
        scanf("%d", &select);
        switch(select){
            case 1:
                edit_name();
                break;
            case 2:
                edit_email();
                break;
            case 3:
                edit_address();
                break;
            case 4:
                edit_pw();
                break;
            case 5:
                select = -1;
                break;
            default:
                error_input();
        }
    }while(select>-1);
}

#endif // EDIT_USER_INFO_H_INCLUDED
