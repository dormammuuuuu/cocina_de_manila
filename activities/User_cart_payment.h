#ifndef USER_CART_PAYMENT_H_INCLUDED
#define USER_CART_PAYMENT_H_INCLUDED
#include "var.h"
#include "other_activities.h"

void pay_order(){
    char ch;
    printf("\n\n%28s\n%33s\n%22s\n%23s", "Mode of payment:", "[1] Cash on Delivery", "[2] GCash", "[3] Cancel");
    ch = getch();
    time_t currentTime = time(0);
    struct tm TimeOrder = *localtime(&currentTime);
    strftime (gettime, 10, "%H:%M:%S", &TimeOrder);
    sscanf(gettime, "%d:%d:%d", &hours, &mins, &secs);
    if(ch=='1'){
        printf("\n\n%52s %.2f.", "COD: Please prepare the total amount of", total+delivery_fee);
        mofp = 0;
        delay(1500);
        check_out();
    }else if(ch=='2'){
        printf("\n\n%33s %.2f to COCINA DE MANILA\n%41s %s %s","GCash: Your payment of", total+delivery_fee,"has been successfully processed on", __DATE__, gettime);
        mofp = 1;
        delay(1500);
        check_out();
    }else{
        system("cls");nl system("Color CF");
        printf("\n%43s\n%48s","PAYMENT CANCELLED", "Press ANY KEY to continue.");
        getch(); system("Color F0");
    }
}

#endif // USER_CART_PAYMENT_H_INCLUDED
