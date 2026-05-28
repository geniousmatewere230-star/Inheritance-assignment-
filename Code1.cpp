// constructor_destructor_order.cpp
#include <iostream>
using namespace std;

class Base {
public:
    int Base_num;

    Base() {
        cout << "Constructor of base class" << endl;
        Base_num = 1;
    }

    Base(int n1) {
        cout << "Constructor of base class" << endl;
        Base_num = n1;
    }

    ~Base() {
        cout << "Destructor of base class" << endl;
    }
};

class Derived : public Base {
public:
    int Derived_num;

    Derived(int n1) {
        cout << "Constructor of derived class" << endl;
        Derived_num = n1;
    }

    Derived(int n1, int n2) : Base(n1) {
        cout << "Constructor of derived class" << endl;
        Derived_num = n2;
    }

    ~Derived() {
        cout << "Destructor of derived class" << endl;
    }
};

int main() {
    cout << "--- Creating ptr1 with Derived(2) ---" << endl;
    Derived *ptr1 = new Derived(2);
    delete ptr1;

    cout << "\n--- Creating ptr2 with Derived(1,2) ---" << endl;
    Derived *ptr2 = new Derived(1, 2);
    delete ptr2;

    return 0;
}
