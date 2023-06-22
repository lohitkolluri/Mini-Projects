#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ch[10][130] = {"Bhubaneswar Express", "Jodhpur Liner", "Manali Express", "Northern Bus Lines", "Chennai Express"};
char name[32][100] = {'\0'};
char number[32][2] = {'\0'};
int num1[32] = {0};
int trno;

void bus();
void name_number(int booking, char numstr[100]);
void booking();
int read_number(int trno);
void read_name(int trno);
void status();
void status_1(int trno);
void cancel();

int main()
{
    int num, i;
    do
    {
        system("cls");
        printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
        printf("\t     PPS MINI PROJECT");
        printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
        printf("\t    BUS RESERVATION");
        printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
        printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd  MAIN MENU  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
        printf("   [1] View Bus List\n\n");
        printf("   [2] Book Tickets\n\n");
        printf("   [3] Cancel Booking\n\n");
        printf("   [4] Bus Status Board\n\n");
        printf("   [5] Exit\n\n");
        printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
        printf("   ENTER YOUR CHOICE: ");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            bus(); //for list of bus
            break;
        case 2:
            booking(); //for booking the tickets
            break;
        case 3:
            cancel(); //for cancelling the tickets
            break;
        case 4:
            status(); //to exit the app
            break;
        }
        getch();
    } while (num != 5);
    system("CLS");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\tTHANK YOU");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    return 0;
}

void bus()
{
    int i;
    printf("\n\n\n\n\n");
    printf("\t    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t       BUS LIST");
    printf("\n\t    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    printf("\t    BUS NAME\t\t\t BUS NO.\n");
    printf("\t    ________\t\t\t ______\n\n");
    for (i = 0; i <= 4; i++)
    {
        printf("\t    %-30s %s\n", ch[i], number[i]);
    }
    printf("\n\t    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
}

void name_number(int booking, char numstr[100])
{
    int i;
    FILE *fileptr;
    fileptr = fopen("bus.dat", "r");
    for (i = 1; i <= booking; i++)
    {
        fscanf(fileptr, "%s\t\t%s\n", name[i], numstr);
    }
    fclose(fileptr);
}

void booking()
{
    int booking, i, j;
    char numstr[100] = "\0";
    FILE *fileptr1, *fileptr2;
    fileptr1 = fopen("bus.dat", "r");
    fscanf(fileptr1, "%d", &trno);
    fclose(fileptr1);
    fileptr1 = fopen("bus.dat", "w");
    printf("\n\n\t ENTER THE BUS NO.: ");
    scanf("%d", &booking);
    fprintf(fileptr1, "%d\n", booking);
    fclose(fileptr1);
    if (booking > 4 || booking < 0)
    {
        printf("\n\n\t INVALID BUS NUMBER\n\n");
        getch();
        return;
    }
    fileptr1 = fopen("bus.dat", "a");
    printf("\n\n\t ENTER THE NUMBER OF TICKETS TO BE BOOKED: ");
    scanf("%d", &booking);
    if (booking < 1 || booking > 32)
    {
        printf("\n\n\t INVALID NUMBER OF TICKETS\n\n");
        getch();
        return;
    }
    fprintf(fileptr1, "%d\n", booking);
    fclose(fileptr1);
    name_number(booking, numstr);
    fileptr2 = fopen("bus.dat", "a");
    for (i = 1; i <= booking; i++)
    {
        printf("\n\n\t ENTER THE NAME OF PASSENGER NO. %d: ", i);
        scanf("%s", name[i]);
        fprintf(fileptr2, "%s\t\t%s\n", name[i], numstr);
        for (j = 1; j <= trno; j++)
        {
            if (strcmp(numstr, number[j]) == 0)
            {
                num1[j] = num1[j] + 1;
            }
        }
    }
    fclose(fileptr2);
}

int read_number(int trno)
{
    FILE *fileptr1;
    int i, number1;
    fileptr1 = fopen("bus.dat", "r");
    fscanf(fileptr1, "%d", &number1);
    for (i = 1; i <= number1; i++)
    {
        fscanf(fileptr1, "%s", number[i]);
    }
    fclose(fileptr1);
    return number1;
}

void read_name(int trno)
{
    FILE *fileptr2;
    int i, booking;
    char namestr[100] = "\0";
    fileptr2 = fopen("bus.dat", "r");
    fscanf(fileptr2, "%d", &booking);
    for (i = 1; i <= booking; i++)
    {
        fscanf(fileptr2, "%s", namestr);
    }
    fclose(fileptr2);
}

void status()
{
    int i;
    printf("\n\n\n\n\n");
    printf("\t    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t     BUS STATUS BOARD");
    printf("\n\t    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    printf("\t    BUS NO.\t BUS NAME\t\tBOOKING STATUS\n");
    printf("\t    ______\t ________\t\t______________\n\n");
    read_number(trno);
    read_name(trno);
    for (i = 1; i <= trno; i++)
    {
        printf("\t    %s\t %-30s %d/32\n", number[i], ch[i - 1], num1[i]);
    }
    printf("\n\t    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
}

void cancel()
{
    int i, booking, flag = 0;
    char namestr[100] = "\0", ch1;
    FILE *fileptr1, *fileptr2;
    printf("\n\n\t ENTER THE BUS NO. : ");
    scanf("%d", &booking);
    if (booking > trno || booking < 0)
    {
        printf("\n\n\t INVALID BUS NUMBER\n\n");
        getch();
        return;
    }
    fileptr1 = fopen("bus.dat", "r");
    fscanf(fileptr1, "%s\t\t%s\n", namestr, number[1]);
    fclose(fileptr1);
    fileptr1 = fopen("bus.dat", "w");
    fprintf(fileptr1, "%d\n", trno);
    fclose(fileptr1);
    fileptr2 = fopen("bus.dat", "a");
    for (i = 1; i <= trno; i++)
    {
        if (i != booking)
        {
            fprintf(fileptr2, "%s\t\t%s\n", namestr, number[i]);
        }
        else if (i == booking)
        {
            printf("\n\n\t ENTER THE NAME OF PASSENGER TO BE CANCELLED: ");
            scanf("%s", namestr);
            if (strcmp(namestr, "X") == 0 || strcmp(namestr, "x") == 0)
            {
                fclose(fileptr2);
                return;
            }
            else if (strcmp(namestr, "ALL") == 0 || strcmp(namestr, "all") == 0)
            {
                printf("\n\n\t ARE YOU SURE TO CANCEL ALL PASSENGERS (Y/N): ");
                scanf("%s", &ch1);
                if (ch1 == 'y' || ch1 == 'Y')
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                    fprintf(fileptr2, "%s\t\t%s\n", namestr, number[i]);
                }
            }
            else
            {
                flag = 0;
                fprintf(fileptr2, "%s\t\t%s\n", namestr, number[i]);
            }
        }
        if (flag == 1)
        {
            num1[i] = 0;
        }
        if (flag == 0)
        {
            for (i = 1; i <= trno; i++)
            {
                if (strcmp(namestr, number[i]) == 0)
                {
                    num1[i] = num1[i] - 1;
                    flag = 1;
                    break;
                }
            }
        }
    }
    fclose(fileptr2);
}
