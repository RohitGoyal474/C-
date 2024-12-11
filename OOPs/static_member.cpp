#include <iostream>
using namespace std;

class Counter {
    static int count;
public:
     // Declaration of static member variable

    Counter() {
        count++; // Increment count for each object
    }
    static int getcount(){
        return count;
    }
};

// Definition and initialization
// declare static member variable is must other vise it will give linker error
int Counter::count = 0;

int main() {
    Counter c1, c2, c3; // Three objects created
    cout << "Total objects created: " << Counter::getcount() << endl; // Access via class name
    return 0;
}


// Key Characteristics of Static Member Functions
// No this Pointer:

// Static functions don’t operate on a specific instance of the class and hence don’t have access to the this pointer.
// Access Restrictions:

// They can only access other static members (both variables and functions) of the class.
// They cannot access non-static data members or call non-static member functions directly.
// Shared Across the Class:

// A static member function is shared among all objects of the class, just like static variables.
// How to Call:

// Can be called using the class name: ClassName::staticFunction().
// Can also be called using an object, though this is not recommended.
