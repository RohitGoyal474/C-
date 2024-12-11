#include <iostream>
// #include <bits/stdc++.h>
using namespace std;


class A{

   
    public:
     int* a;
    A(){
        a=new int(10);

    }
    A(const A& obj );
    A( A&& obj );
 
};


A::A(const A& obj)
{
    a=new int(*obj.a);
}

A::A( A&& obj ) noexcept {
    a=obj.a;
    obj.a=nullptr;
    
}


int main(){


}