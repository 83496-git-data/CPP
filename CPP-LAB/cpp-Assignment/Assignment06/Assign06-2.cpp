#include<iostream>
using namespace std;

class Product
{
    int id;
    string title;
    double price;

public:

        virtual void accept()      
        {
            cout<<"Enter id"<<endl;
             cin>>id;

            cout<<"Enter title"<<endl;
            cin>>title;

            cout<<"Enter price"<<endl;
             cin>>price;
        }

        virtual void display()
        {
          cout<<"id : "<<id<<" title : "<<title<<"  price : "<<price<<endl;
        }
        double getPrice()
        {
            return price;
        }
        void setPrice(double price)
        {
            this->price=price;
        }

};

class Book : public Product
{
    string author;

public:

        void accept()
        {
        
             double p;

            cout<<"enter author"<<endl;
            cin>>author;

            Product::accept();
           
            p=getPrice();
            p=(p-0.1*p);
            setPrice(p);
        }
        void display()
        {


            cout<<"author : "<<author<<endl;
            Product::display();
        }
};



class Tape : public Product
{
    string artist;

public:

        void accept()
        {
             double p;

            cout<<"enter artist"<<endl;
            cin>>artist;

            Product::accept();
           
            p=getPrice();
            p=(p-0.05*p);
            setPrice(p);
        }
         void display()
        {
            cout<<"artist : "<<artist<<endl;
            Product::display();
        }
};
int main()
{
Product *arr[3];
int choice;
int index=0;
do
{  
    cout<<endl;
    cout<<endl;
    cout<<"0. EXIT" << endl;  
    cout << "1. TO BUY BOOK" << endl;  
    cout << "2. TO BUY TAPE" << endl;   
    cout << "3. TO CALCULATE TOTAL" << endl;   
    cout << "4. TO SEE ALL LIST DETAILS"<<endl;
    cout<<"enter choice : ";
    cin>>choice;

            switch(choice)
            {
            case 0:
                cout<<"THANKS FOR USING...."<<endl;
                break;

            case 1:
                if(index<3)
                {
                  arr[index]=new Book();        
                  arr[index]->accept();         
                  index++;
                }
                else
                {
                    cout<<"list is full"<<endl;
                }
                break;


            case 2:
                 if(index<3)
                {
                  arr[index]=new Tape();
                  arr[index]->accept();  
                  index++;
                }
                else
                {
                    cout<<"list is full"<<endl;
                }
                break;


            case 3:
                { 
                    double total=0;
                   for (int i = 0; i < index; i++)
                   {
                    total=total+arr[i]->getPrice();
                   }

                   cout<<"total is : "<<total;
                   

                }
                break;

            case 4:
                for(int i=0;i<index;i++)
                {
                    arr[i]->display();
                    cout<<endl;
                    cout<<endl;
                }
               break;


            default:
    
                  cout<<"enter right choice"<<endl;
    
              break;

            }
} while (choice!=0);

for (int i = 0; i < index; i++)
{
    delete arr[i];
    arr[i]=NULL;
}


return 0;
}