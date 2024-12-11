#include <iostream>
// #include <bits/stdc++.h>
using namespace std;


class A{
    public:
    virtual void f1()=0;
    // this is a pure virtual function, it is abstract class
    // by using a pure virtual function we can create abstract class, in this class we can not create object
    // we have to override the all pure virtual function in child class 

      void f2(){
        cout<<"f2 from class A"<<endl;
    }
};

class B : public A{
    public:
    void f1(){
        cout<<"f1 from class B"<<endl;
    }
    void f2(){
        cout<<"f2 from class B"<<endl;
    }

    
};

int main(){

   A* a;
   B o1;

   a=&o1;
   a->f1();
   a->f2();

 return 0;
}