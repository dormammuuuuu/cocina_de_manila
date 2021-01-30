#ifndef USER_CART_CHECKOUT_H_INCLUDED
#define USER_CART_CHECKOUT_H_INCLUDED
#include "var.h"
#include "other_activities.h"
#include "Load_delivery_fees.h"
#include "User_cart_receipt.h"

void check_out(){
    system("Color 9F");
    estimated_time_arrival();
    system("cls");nl
    printf("\n\n%47s", "Your order has been placed.");
    printf("\n%51s", "Press ANY KEY to view your receipt.");
    getch();
    receipt_order();
    memset(orders, 0, sizeof(orders));
    strcpy(gettime,"");
    strcpy(tempHour,"0");
    strcpy(tempMin,"0");
    strcpy(tempSec,"0");
    total = num_orders = hours = secs = mins = 0;
    reset++;
}


#endif // USER_CART_CHECKOUT_H_INCLUDED
