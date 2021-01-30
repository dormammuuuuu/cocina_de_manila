#ifndef USER_CART_H_INCLUDED
#define USER_CART_H_INCLUDED
#include "var.h"
#include "other_activities.h"
#include "User_cart_checkout.h"
#include "User_cart_remove_order.h"
#include "User_cart_payment.h"
#include "get_eta.h"
#include <string.h>

void displayOrders(){
    int i, str_length, spaces;
    total = 0;
    for(i=0; i<num_orders; i++){
        printf("\n%5d%7d\t %s", i+1, orders[i].orderQuantity, orders[i].orderName);
        str_length = strlen(orders[i].orderName);
        spaces = 37 - str_length;
        while(spaces!=0){
            printf(" ");
            spaces--;
        }
        printf("%2.2f", orders[i].orderPrice);
        total+=orders[i].orderPrice;
    }
}

void viewCart(){
    system("cls");
    char ch; reset = 0;
    do{
        system("cls");
        if(num_orders==0){ nl
            system("Color 9F");
            printf("\n\n\n%45s\n%48s", "Your cart is empty.", "Press ANY KEY to continue.");
            getch();
            resetcolor();
            break;
        }else{
            total = 0;
            printf("\n\n%43s\n%s\n\n%5s%8s%22s%24s","YOUR PENDING ORDERS","=======================================================================", "#","QTY.","ORDER", "PRICE");
            displayOrders();
            if (strcmp(users[logged_in_user].city, "San Juan City")==0 || strcmp(users[logged_in_user].city, "Mandaluyong City")==0 || strcmp(users[logged_in_user].city, "Makati City")==0 || strcmp(users[logged_in_user].city, "Pasay City")==0 || strcmp(users[logged_in_user].city, "Manila City")==0){
                delivery_fee = 30;
                addMins = 30;
            }else if (strcmp(users[logged_in_user].city, "Taguig City")==0 || strcmp(users[logged_in_user].city, "Pasig City")==0 || strcmp(users[logged_in_user].city, "Paranaque City")==0 || strcmp(users[logged_in_user].city, "Quezon City")==0 || strcmp(users[logged_in_user].city, "Las Pinas City")==0){
                delivery_fee = 40;
                addMins = 45;
            }else if (strcmp(users[logged_in_user].city, "Marikina City")==0 || strcmp(users[logged_in_user].city, "Malabon City")==0 || strcmp(users[logged_in_user].city, "Muntinlupa City")==0){
                delivery_fee = 50;
                addHour = 1;
            }else{
                delivery_fee = 60;
                addMins = 15; addHour = 1;
            }
            printf("\n\n%s", "=======================================================================");
            printf("\n\n%33s%13.2f", "DELIVERY FEE", delivery_fee);
            printf("\n%31s%15.2f", "SUBTOTAL", total);
            printf("\n%30s%16.2f\n\n%58s", "TOTAL", total + delivery_fee, "===============================================");
            printf("\n\n%50s\n%51s\n%60s\n%47s", "Press [1] to remove an order.", "Press [2] to proceed to payment.", "Press [3] to view the summary of delivery charges.", "Press ANY KEY to go back.");
            ch = getch();
            if (ch == '1'){
                remove_order();
            }else if (ch == '2'){
                pay_order();
                if (reset != 0){
                    break;
                }
            }else if(ch == '3'){
                system("cls");
                deliveryFees();
                printf("\n%48s","Press ANY KEY to continue.");
                getch();
            }else total = 0;
        }
    }while(ch == '1' || ch == '2' || ch == '3');
}

#endif // USER_CART_H_INCLUDED
