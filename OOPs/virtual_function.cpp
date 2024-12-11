#include <iostream>
// #include <bits/stdc++.h>
using namespace std;


class A{
    public:
    void f1(){
        cout<<"f1 from class A"<<endl;
    }
     virtual void f2(){
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

    // a pointer is formed which points to A class. 
    A * a;

    A o1;
    B o2;
    // pointer points to object of b 
    a=&o2;

    a->f1();
    a->f2();

    // here a->f1() is early binding and in complile time complier dont know which address does it has, hence it add the type of pointer that is class A
    // for this we use virtual function for late binding, it make a * _vptr (pointer to virtual table) which stores the address of f2() for class A and f2() for class B
    


    // (base) rohitgoyal@ROHITs-Air-3 OOPs % g++ virtual_function.cpp
    // (base) rohitgoyal@ROHITs-Air-3 OOPs % ./a.out                 
    // f1 from class A
    // f2 from class B
    // (base) rohitgoyal@ROHITs-Air-3 OOPs % 


 return 0;
}