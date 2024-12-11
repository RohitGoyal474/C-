#include <iostream>
#include <memory>
using namespace std;

class A {
public:
    int data;
    A() {
        cout << "Constructor " << endl;
    }
    A(int data){
        data=data;
        cout<<"parameterized constructor"<<endl;
    }
    ~A(){
        cout<<"destructor"<<endl;
    }
   
    
};


int main() {
    unique_ptr<A> p1{new A};
    unique_ptr<A>P2=make_unique<A>();
    unique_ptr<A> p3=make_unique<A>(5);

    unique_ptr<int> p1{new int{10}};
    // this cant be done as unique_ptr can not copy , it only mode
    // *p1=20;
    // cout<<*p1<<endl;
}


