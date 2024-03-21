#include<iostream>
using namespace std;

class studnet
{
 private:
    int rollno;
    string name;
    int marks;
 public:
    void initStudent()
    {
      rollno = 0;
      name = " "; 
      marks = 0;
    }

    void perintStudentOnConsole()
    {
       cout << "rollno" << "name" << "marks" << endl;
    }
    void acceptStudentFromConsole()
    { 

        cout << "Enter RollNo -";
        cin >> rollno;
        cout << "Enter Name -";
        cin >> name;
        cout << "Enter Marks -";
        cin >> marks;  
    }
};
 
     int main()
 {
     int choice;
     studnet s;

     do
    {
      cout << "0. EXIT" << endl;
      cout << "1. initialization Succesfull" << endl;
      cout << "2. Print Studnet" << endl;
      cout << "3. Accept Student" << endl;
      cout << "Enter your choice -" << endl;
      cin >> choice;

      switch (choice)
      {
      case 0:
           cout << "Thank you so much..." << endl;
           break;
        case 1:
            s.initStudent();
            break;
        case 2:
             s.perintStudentOnConsole();
             break;
        case 3:
             s.acceptStudentFromConsole();
             break;
        default:
            cout << "Wrong Choice..." << endl;
            break;
      }

    } while (choice !=0);

 return 0;

}