#ifndef LOAD_USERS_H_INCLUDED
#define LOAD_USERS_H_INCLUDED
#include "var.h"
#include "encrypt_decrypt.h"

void loadFile(){
    FILE *fp;
    int i = 0;
    if (fp = fopen("D:\\users.txt", "r")){
        strcpy(ed_name, "D:\\users.txt");
        strcpy(driveLetter, "D:\\users.txt");
        en_de_crypt(0);
        while (!feof(fp)){
            fscanf(fp,"ID:%d\nFirst Name:%[^\n]\nLast Name:%[^\n]\nMobile Number:%[^\n]\nHouse no.:%[^\n]\nStreet Name:%[^\n]\nBarangay:%[^\n]\nCity:%[^\n]\nEmail:%s\nPassword:%s\n\n", &users[i].userID, users[i].fname, users[i].lname, users[i].mobile_number, users[i].house_no, users[i].street, users[i].brgy, users[i].city, users[i].email, users[i].password);
            i++;
        }
        usercount = ID = i;
        fclose(fp);
        en_de_crypt(1);
    }
    else if (fp = fopen("E:\\users.txt", "r")){
        strcpy(ed_name, "E:\\users.txt");
        strcpy(driveLetter, "E:\\users.txt");
        en_de_crypt(0);
        while (!feof(fp)){
            fscanf(fp,"ID:%d\nFirst Name:%[^\n]\nLast Name:%[^\n]\nMobile Number:%[^\n]\nHouse no.:%[^\n]\nStreet Name:%[^\n]\nBarangay:%[^\n]\nCity:%[^\n]\nEmail:%s\nPassword:%s\n\n", &users[i].userID, users[i].fname, users[i].lname, users[i].mobile_number, users[i].house_no, users[i].street, users[i].brgy, users[i].city, users[i].email, users[i].password);
            i++;
        }
        usercount = ID = i;
        fclose(fp);
        en_de_crypt(1);
    }
    else if (fp = fopen("F:\\users.txt", "r")){
        strcpy(ed_name, "F:\\users.txt");
        strcpy(driveLetter, "F:\\users.txt");
        en_de_crypt(0);
        while (!feof(fp)){
            fscanf(fp,"ID:%d\nFirst Name:%[^\n]\nLast Name:%[^\n]\nMobile Number:%[^\n]\nHouse no.:%[^\n]\nStreet Name:%[^\n]\nBarangay:%[^\n]\nCity:%[^\n]\nEmail:%s\nPassword:%s\n\n", &users[i].userID, users[i].fname, users[i].lname, users[i].mobile_number, users[i].house_no, users[i].street, users[i].brgy, users[i].city, users[i].email, users[i].password);
            i++;
        }
        usercount = ID = i;
        fclose(fp);
        en_de_crypt(1);
    }
    else if (fp = fopen("G:\\users.txt", "r")){
        strcpy(ed_name, "G:\\users.txt");
        strcpy(driveLetter, "G:\\users.txt");
        en_de_crypt(0);
        while (!feof(fp)){
            fscanf(fp,"ID:%d\nFirst Name:%[^\n]\nLast Name:%[^\n]\nMobile Number:%[^\n]\nHouse no.:%[^\n]\nStreet Name:%[^\n]\nBarangay:%[^\n]\nCity:%[^\n]\nEmail:%s\nPassword:%s\n\n", &users[i].userID, users[i].fname, users[i].lname, users[i].mobile_number, users[i].house_no, users[i].street, users[i].brgy, users[i].city, users[i].email, users[i].password);
            i++;
        }
        usercount = ID = i;
        fclose(fp);
        en_de_crypt(1);
    }
    else if (fp = fopen("H:\\users.txt", "r")){
        strcpy(ed_name, "H:\\users.txt");
        strcpy(driveLetter, "H:\\users.txt");
        en_de_crypt(0);
        while (!feof(fp)){
            fscanf(fp,"ID:%d\nFirst Name:%[^\n]\nLast Name:%[^\n]\nMobile Number:%[^\n]\nHouse no.:%[^\n]\nStreet Name:%[^\n]\nBarangay:%[^\n]\nCity:%[^\n]\nEmail:%s\nPassword:%s\n\n", &users[i].userID, users[i].fname, users[i].lname, users[i].mobile_number, users[i].house_no, users[i].street, users[i].brgy, users[i].city, users[i].email, users[i].password);
            i++;
        }
        usercount = ID = i;
        fclose(fp);
        en_de_crypt(1);
    }
    else if (fp = fopen("I:\\users.txt", "r")){
        strcpy(ed_name, "I:\\users.txt");
        strcpy(driveLetter, "I:\\users.txt");
        en_de_crypt(0);
        while (!feof(fp)){
            fscanf(fp,"ID:%d\nFirst Name:%[^\n]\nLast Name:%[^\n]\nMobile Number:%[^\n]\nHouse no.:%[^\n]\nStreet Name:%[^\n]\nBarangay:%[^\n]\nCity:%[^\n]\nEmail:%s\nPassword:%s\n\n", &users[i].userID, users[i].fname, users[i].lname, users[i].mobile_number, users[i].house_no, users[i].street, users[i].brgy, users[i].city, users[i].email, users[i].password);
            i++;
        }
        usercount = ID = i;
        fclose(fp);
        en_de_crypt(1);
    }
    else if (fp = fopen("J:\\users.txt", "r")){
        strcpy(ed_name, "J:\\users.txt");
        strcpy(driveLetter, "J:\\users.txt");
        en_de_crypt(0);
        while (!feof(fp)){
            fscanf(fp,"ID:%d\nFirst Name:%[^\n]\nLast Name:%[^\n]\nMobile Number:%[^\n]\nHouse no.:%[^\n]\nStreet Name:%[^\n]\nBarangay:%[^\n]\nCity:%[^\n]\nEmail:%s\nPassword:%s\n\n", &users[i].userID, users[i].fname, users[i].lname, users[i].mobile_number, users[i].house_no, users[i].street, users[i].brgy, users[i].city, users[i].email, users[i].password);
            i++;
        }
        usercount = ID = i;
        fclose(fp);
        en_de_crypt(1);
    }
    else{
        system("Color CF");
        welcome_art();
        printf("\n\n\n%48s\n\n\n\n\n\n\n\n","FLASH DRIVE NOT DETECTED!");
        exit(0);
    }
    memset(ed_name, 0, sizeof(ed_name));
}

#endif // LOAD_USERS_H_INCLUDED
