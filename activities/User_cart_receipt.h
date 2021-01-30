#ifndef USER_CART_RECEIPT_H_INCLUDED
#define USER_CART_RECEIPT_H_INCLUDED
#include "var.h"
#include "other_activities.h"

void receipt_order(){
    char mop [][15] = {"COD", "GCash"};
    char stat [][8] = {"UNPAID","PAID"};
    system("cls"); system ("Color F0");
    printf("\n%38s\n%s\n\n%5s%8s%22s%24s","RECEIPT","=======================================================================", "#", "QTY.","ORDER", "PRICE");
    displayOrders();
    printf("\n\n%s", "=======================================================================");
    printf("\n\n%11s%s %s\n%16s%s\n%12s%s","Name: ", users[logged_in_user].fname, users[logged_in_user].lname, "Number: +63", users[logged_in_user].mobile_number, "Email: ",users[logged_in_user].email);
    printf("\n%22s %s %s\n%39s, %s\n", "Delivery Address:",users[logged_in_user].house_no, users[logged_in_user].street, users[logged_in_user].brgy, users[logged_in_user].city);
    printf("\n%19s %11s", "Payment Method", mop[mofp]);
    printf("%21s %13s", "Order Time", gettime);
    printf("\n%19s %11s", "Payment Status", stat[mofp]);
    printf("%18s %16s\n", "ETA", eta);
    printf("\n%33s%13.2f", "Delivery Fee", delivery_fee);
    printf("\n%31s%15.2f", "Subtotal", total);
    printf("\n%30s%16.2f\n\n%58s", "TOTAL", total + delivery_fee, "===============================================");
    printf("\n\n%48s", "Press ANY KEY to continue.");
    getch();
}

#endif // USER_CART_RECEIPT_H_INCLUDED
