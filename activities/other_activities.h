#ifndef OTHER_ACTIVITIES_H_INCLUDED
#define OTHER_ACTIVITIES_H_INCLUDED
#define nl printf("\n\n\n\n\n\n\n\n\n\n\n");
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include "var.h"
#include "encrypt_decrypt.h"

void consoleStyle(){
    SetConsoleTitle("Cocina De Manila");
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    SMALL_RECT windowSize = {0 , 0 , 70, 30};
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    COORD bufferSize = {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1};
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);
}

void delay(int number_of_seconds)
{
    int milli_seconds = number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds) ;
}

void splashScreen(){
    delay(500);
    int i;
    char splash[][30] = {"display/splash/1.txt","display/splash/2.txt","display/splash/3.txt"};
    for (i=0; i < 3; i++){
        strcpy(ed_name, splash[i]);
        en_de_crypt(0);
        system("cls");
        FILE *Ss; char c;
        Ss = fopen(ed_name, "r");
        c = fgetc(Ss);
        printf("\n\n\n\n\n\n");
        while (c != EOF)
        {
            printf("%c", c);
            c = fgetc(Ss);
        }
        printf("\n\n\n\n\n\n");
        fclose(Ss);
        delay(750);
        en_de_crypt(1);
        memset(ed_name, 0, sizeof(ed_name));
    }
    system("cls");
}

void red(){
    printf("\033[90;91m");
}

void resetcolor(){
    system("Color F0");
}

void clrScrn(){
    printf("\n\n%50s\n\n","Press any key to continue...");
    getch();
    system("cls");
}

void error_input(){
    red();
    printf("\n%50s\n", "Invalid Input! Please try again");
    getch();
    system("cls");
    system("Color F0");
}

void displayCities(){
    for(int i=0; i<14; i++){
        printf("\n%26s%d]     %s", "[",i+1, cities[i]);
    }
}

void password_mask(){
    int i=0;
    char letter;
    while(i<30){
        letter = getch();
        if (letter == 13 || letter == 9){
            mask_pass[i] = '\0';
            break;
        }
        else if(letter == 8){
            if(i>0){
                i--;
                printf("\b \b");
            }
        }
        else{
            mask_pass[i++] = letter;
            printf("* \b");
        }
    }
}

void reset_char(){
    memset(mask_pass, 0, sizeof(mask_pass));
}

void welcome_art(){
    FILE *wart; char c;
    strcpy(ed_name, "display/welcome_art.txt");
    en_de_crypt(0);
    wart = fopen(ed_name, "r");
    c = fgetc(wart);
    while(c != EOF){
        printf("%c", c);
        c = fgetc(wart);
    }
    fclose(wart);
    en_de_crypt(1);
    memset(ed_name, 0, sizeof(ed_name));
}

void bye(){
    FILE *bye; char c;
    strcpy (ed_name, "display/bye.txt");
    en_de_crypt(0);
    bye = fopen(ed_name, "r");
    c = fgetc(bye);
    printf("\n\n\n\n\n\n");
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(bye);
    }
    printf("\n\n\n\n\n\n");
    fclose(bye);
    en_de_crypt(1);
    memset(ed_name, 0, sizeof(ed_name));
}

#endif // OTHER_ACTIVITIES_H_INCLUDED
