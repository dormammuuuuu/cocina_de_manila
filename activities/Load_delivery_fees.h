#ifndef LOAD_DELIVERY_FEES_H_INCLUDED
#define LOAD_DELIVERY_FEES_H_INCLUDED
#include "encrypt_decrypt.h"
void deliveryFees(){
    FILE *deliver; char c;
    strcpy(ed_name, "menu/deliveryfee.txt");
    en_de_crypt(0);
    deliver = fopen(ed_name, "r");
    c = fgetc(deliver);
    printf("\n\n\n\n\n\n");
    while (c != EOF){
            printf("%c", c);
            c = fgetc(deliver);
    }
    printf("\n\n\n\n\n\n");
    fclose(deliver);
    en_de_crypt(1);
    memset(ed_name, 0, sizeof(ed_name));
}

#endif // LOAD_DELIVERY_FEES_H_INCLUDED
