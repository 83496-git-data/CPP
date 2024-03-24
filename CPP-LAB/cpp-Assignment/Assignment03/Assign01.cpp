#include<iostream>
using namespace std;

class Volume{
 private:
  double r;
  double h;
  static double pi;
  double v;
  public:
Volume(){
     r = 0;
     h = 0;
     v = 0;
  }

 double getVolume(){
   double vol = pi*r*r*h;
    v = vol;
    return v;
 }
 void printVolume(){
  cout<<"cylinder volume "<<v<<endl;
 }
 void setHeight(int height){
      
     h = height;
 }
 void setRadius(int radius){
    r = radius;
 }
 double intgetHeight(){
    return h;
 }
  double getRadius(){
    return r;
 }
 

};
double Volume::pi = 3.14;




int main(){
   Volume v;
   cout<<"enter height -";
   double h;
   cin>>h;
   cout<<"enter radius -";
   double r;
   cin>>r;

   v.setRadius(r);
   v.setHeight(h);
   v.getVolume();
   v.printVolume();

}