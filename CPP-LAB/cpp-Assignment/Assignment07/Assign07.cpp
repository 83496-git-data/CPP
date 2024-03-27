#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    double salary;

public:
    Employee()
    {
        cout << "Inside Employee()" << endl;
    }
    Employee(int id, double salary)
    {
        cout << "Inside Employee(int,double)" << endl;
    }
    virtual void accept()
    {
        cout << "Enter the empid - ";
        cin >> id;
        cout << "Enter the salary - ";
        cin >> salary;
    }
    virtual void display()
    {
        cout << "Id - " << id << endl;
        cout << "Salary - " << salary << endl;
    }
    virtual ~Employee()
    {
        cout << "~Employee()" << endl;
    }
};

class Manager : virtual public Employee
{
private:
    double bonus;

protected:
    void acceptManager()
    {
        cout << "Enter the bonus - ";
        cin >> bonus;
    }
    void displayManager()
    {
        cout << "Bonus - " << bonus << endl;
    }

public:
    Manager()
    {
        cout << "Inside Manager()" << endl;
    }
    Manager(int id, double salary, double bonus)
    {
        cout << "Inside Manager(int,double,double)" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
    }

    void display()
    {
        Employee::display();
        displayManager();
    }
    ~Manager()
    {
        cout << "~Manager()" << endl;
    }
};

class Salesman : virtual public Employee
{
private:
    double commission;

protected:
    void acceptSalesman()
    {
        cout << "Enter the Commission - ";
        cin >> commission;
    }
    void displaySalesman()
    {
        cout << "Commission - " << commission << endl;
    }

public:
    Salesman()
    {
        cout << "Inside Salesman()" << endl;
    }
    Salesman(int id, double salary, double commission)
    {
        cout << "Inside Salesman(int,double,double)" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displaySalesman();
    }
    ~Salesman()
    {
        cout << "~Salesman()" << endl;
    }
};
class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {
        cout << "Inside Salesmanager()" << endl;
    }
    SalesManager(int id, double salary, double bonus, double commission)
    {
        cout << "Inside SalesManager(int,double,double,double)" << endl;
    }
    ~SalesManager()
    {
        cout << "~Salesmanager()" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displayManager();
        displaySalesman();
    }
};

int main()
{
  Employee *M[5];
  int m=0;
  int s=0;
  int sm=0;
  int choice;
  int choice1;
  int index = 0;
 
do
{
  cout << "0. EXIT" << endl;
    cout << "1. Accept Employee" << endl;
    cout << "2. Display the count of all employees with respect to designation"<< endl;
    cout << "3. Display All Managers" << endl;
    cout << "4. Display All Salesman" << endl;
    cout << "5. Display All SalesManager" << endl;
    cout << "Enter Your Choice -" << endl;
    cin >> choice;


switch (choice)
{
case 0:
  cout << "THANK YOU SO MUCH" << endl;
break;

case 1:

do
{

    cout << "0. Exit" << endl;
    cout << "1. Accept Manager" << endl;
    cout << "2. Accept Salesman" << endl;
    cout << "3. Accept SalesManager" << endl;
    cout << "Enter Your choice" << endl;
    cin >> choice1;  


switch (choice1)
{
case 0:
   cout << "MAIN" << endl;
break;

case 1:
   if (index < 5)
            {
                M[index] = new Manager();
                M[index]->accept();
                index++;
            }
            else
            {
              cout << "Array is Full..." << endl;
            }
break;

case 2:
   if (index < 5)
            {
                M[index] = new Salesman();
                M[index]->accept();
                index++;
            }
            else
            {
              cout << "Array is Full..." << endl;
            }
break;

case 3:
   if (index < 5)
            {
                M[index] = new SalesManager();
                M[index]->accept();
                index++;
            }
            else
            {
              cout << "Array is Full..." << endl;
            }
break;

default:
   cout << "INVALID CHOICE...." << endl;
    break;
}

} while (choice1 );

break;

case 2:
            for (int i = 0; i < index; i++)
           {
                  if(typeid(*M[i]).name()==typeid(Manager).name())
                  {
                    m++;
                  }
                 else if(typeid(*M[i]).name()==typeid(Salesman).name())
                  {
                    s++;
                  }
                 else if(typeid(*M[i]).name()==typeid(SalesManager).name())
                  {
                    sm++;
                  }
            }
         cout<<"number of managers :  "<<m<<endl;
         cout<<"number of salesman :  "<<s<<endl;
         cout<<"number of salesmanager : "<<sm<<endl;

         cout<<"total number of employees : "<<m+s+sm<<endl;
break;

case 3:
   {


            cout<<"------MANAGERS-----"<<endl;
            
             int count=0;

             for (int i = 0; i < index; i++)
                {
                  if(typeid(*M[i])==typeid(Manager))
                  {
                     M[i]->display();
                     count++;
                     cout<<"-------------------------------------------"<<endl;
                  }
                 }

                if (count==0)
                {
                    cout<<"THERE ARE NO MANAGERS IN THE COMPANY"<<endl;
                }
                
            }
break;

case 4:
 {

            cout<<"-----SALESMAN-----"<<endl;

            int count=0;

             for (int i = 0; i < index; i++)
                 {
                  if(typeid(*M[i])==typeid(Salesman))
                  {
                     M[i]->display();
                     count++;
                     cout<<"---------------------------------------------"<<endl;
                  }
                 }

                if (count==0)
                {
                    cout<<"THERE ARE NO SALESMAN IN THE COMPANY"<<endl;
                }
            }
break;

case 5:

{

            cout<<"------SALESMANAGER------"<<endl;

            int count=0;
             for (int i = 0; i < index; i++)
                 {
                  if(typeid(*M[i])==typeid(SalesManager))
                  {
                     M[i]->display();
                     count++;
                     cout<<"-------------------------------------------------"<<endl;
                  }
                 }
                
                if (count==0)
                {
                    cout<<"THERE ARE NO SALESMANAGERS IN THE COMPANY"<<endl;
                }
         }
break;

default:
   cout << "INVALID CHOICE" << endl;
    break;
}

} while (choice !=0);

for (int i = 0; i < index; i++)

delete M[i];

return 0;

}

 
