#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    void initDate()
    {
        day = 0;
        month = 0;
        year = 0;
    }
    void printDateOnConsole()
    {
        cout << "Date -" << day << " / " << month << " / " << year << endl;
    }
    void acceptDateFromConsol()
    {
        cout << "Enter day -";
        cin >> day;
        cout << " Enter month -";
        cin >> month;
        cout << " Enter year -";
        cin >> year;
    }

    bool isLeapYear() 
    {
        if(year%400==0)
        return true;
     else
       return false;
    }
};

int main()
{
    int choice;
    Date d;

    do
    {
        
        
        cout << "Welcome..." << endl;
        cout << "0. EXIT" << endl;
        cout << "1. Initilazation Succesfull" << endl;
        cout << "2. Accept Date" << endl;
        cout << "3. Print Date" << endl;
        cout << "4. Check Leap Year" << endl;
        cout << "Enter your choice -" << endl;

        cin >> choice;

        switch (choice)
        {
            case 0:
            cout << "Thank you so much..." << endl;
            break;
            case 1:
            cout << "Enter day, month, and year : ";
            break;
            case 2:
            d.acceptDateFromConsol();
            break;
            case 3:
            d.printDateOnConsole();
            break;
            case 4:
             if (d.isLeapYear()) 
             {
                    std::cout << "The year " << " is a leap year." << endl;
                } 
                else 
                {
                    std::cout << "The year " << " is not a leap year." << endl;
                }
                break;
            default:
            cout << "Wrong Choice..." << endl;
             break;
        }

    }while (choice != 0);

}