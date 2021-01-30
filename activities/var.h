#ifndef VAR_H_INCLUDED
#define VAR_H_INCLUDED

typedef struct{
    int userID;
    char fname[30];
    char lname[30];
    char mobile_number[15];
    char house_no[11];
    char street[15];
    char brgy[20];
    char city[20];
    char email[35];
    char password[30];
} User;

typedef struct{
    char foodName[50];
    float foodPrice;
} food;

typedef struct{
    char orderName[50];
    float orderPrice;
    int orderQuantity;
}cart;

User users[50]; cart orders[50]; food foods[15]; cart order_temp;
int pass = 0, usercount = 0, logged_in_user=0, order, num_orders=0, j=0,num_checkOut=0, ID=0, quantity = 0, mins, hours, secs, addMins = 0, addHour = 0, ec_dc = 0, mofp = 0, choice, strlength, space, reset;
float total = 0, delivery_fee = 0;
char mask_pass[30], driveLetter[20];
char ed_name [50], eta[9], gettime[10], min[3], sec[3], hour[2], tempHour[2] = "0", tempMin[] = "0", tempSec[] = "0";
char cities[][20] = {"Las Pinas City", "Makati City", "Malabon City", "Mandaluyong City", "Manila City", "Marikina City", "Muntinlupa City", "Paranaque City", "Pasay City", "Pasig City", "Quezon City", "San Juan City", "Taguig City", "Others"};

#endif // VAR_H_INCLUDED
