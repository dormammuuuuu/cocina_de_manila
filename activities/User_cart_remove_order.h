#ifndef USER_CART_REMOVE_ORDER_H_INCLUDED
#define USER_CART_REMOVE_ORDER_H_INCLUDED
#include "var.h"
#include "other_activities.h"


void remove_order(){
    int orderRemove, i, j, delcounter = 0;
    printf("\n\n%60s", "Enter the number of the order you want to remove: ");
    scanf("%d", &orderRemove);
    orderRemove--;
    for (i=0; i<num_orders; i++)
        if (i == orderRemove){
            orders[i].orderPrice=0;
            strcpy(orders[i].orderName,"");
            delcounter++;
        }
    for(i=1; i<num_orders; i++) {
        for(j=0; j<num_orders-i; j++) {
            if(orders[j].orderPrice == 0 && strcmp(orders[j].orderName, "")==0) {
                order_temp = orders[j];
                orders[j] = orders[j+1];
                orders[j+1] = order_temp;
            }
        }
    }
    if (delcounter == 0){
        error_input();
    }
    else{
        for (i=0; i<delcounter; i++)
            num_orders--;
        printf("\033[1;32m");
        printf("\n%28s %d has been removed\n%48s", "Order", orderRemove+1, "Press ANY KEY to continue.");
        getch();
        resetcolor();
        total = 0;
    }
}

#endif // USER_CART_REMOVE_ORDER_H_INCLUDED
