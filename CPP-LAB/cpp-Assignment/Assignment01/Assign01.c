#include<stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};


    void initDate(struct Date *ptrDate)
{
    printf("Enter day: ");
    scanf("%d", &ptrDate->day);
    printf("Enter month: ");
    scanf("%d", &ptrDate->month);
    printf("Enter year: ");
    scanf("%d", &ptrDate->year);
}


void printDateOnConsole(struct Date *ptrDate) 
{
    printf("Date: %d/%d/%d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}

void acceptDateFromConsole(struct Date *ptrDate) 
{
    printf("Enter day: ");
    scanf("%d", &ptrDate->day);
    printf("Enter month: ");
    scanf("%d", &ptrDate->month);
    printf("Enter year: ");
    scanf("%d", &ptrDate->year);
};

int main()

{
struct Date date;
int choice;
   
   do {
        printf("\nMenu:\n1. Initialize Date\n2. Print Date\n3. Accept Date\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 0:
                printf("Exiting...\n");
                break;
            case 1:
                initDate(&date);
                break;
            case 2:
                printDateOnConsole(&date);
                break;
            case 3:
                acceptDateFromConsole(&date);
                break;
            default:
                printf("Wrong Choice.\n");
        }
    } while (choice != 4);
   
    return 0;
}