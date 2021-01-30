#ifndef SAVE_USER_H_INCLUDED
#define SAVE_USER_H_INCLUDED
#include "var.h"
#include "encrypt_decrypt.h"

void save(){
    strcpy(ed_name, driveLetter);
    en_de_crypt(0);
    FILE *fp;
    int i;
    fp = fopen (driveLetter, "w");
    for (i=0; i<usercount; i++){
        fprintf(fp,"ID:%d\nFirst Name:%s\nLast Name:%s\nMobile Number:%s\nHouse no.:%s\nStreet Name:%s\nBarangay:%s\nCity:%s\nEmail: %s\nPassword: %s\n\n", users[i].userID, users[i].fname, users[i].lname, users[i].mobile_number, users[i].house_no, users[i].street, users[i].brgy, users[i].city,users[i].email, users[i].password);
    }
    fclose(fp);
    en_de_crypt(1);
    memset(ed_name, 0, sizeof(ed_name));
}

#endif // SAVE_USER_H_INCLUDED
