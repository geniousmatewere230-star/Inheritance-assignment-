// access_control_specifiers.cpp
#include <iostream>
using namespace std;

class Base {
private:
    int Base_private;
protected:
    int Base_protected;
public:
    int Base_public;

    void setBasenum(int n1, int n2, int n3) {
        Base_private = n1;   // OK: inside Base class
        Base_protected = n2; // OK
        Base_public = n3;    // OK
        cout << "Base::setBasenum called. All members assigned." << endl;
    }
};

class Derived : public Base {
public:
    void setBasenum(int n1, int n2, int n3) {
        // Base_private = n1;   // ❌ COMPILE ERROR: cannot access private member of base
        Base_protected = n2; // ✅ OK: protected is accessible in derived
        Base_public = n3;    // ✅ OK: public is accessible
        cout << "Derived::setBasenum called. Protected and public assigned." << endl;
    }
};

int main() {
    Base base;
    base.setBasenum(10, 20, 30); // Works fine

    Derived derived;
    derived.setBasenum(100, 200, 300); // Only assigns protected/public

    // These will NOT compile if uncommented:
    // base.Base_private = 1;     // ❌ private not accessible outside class
    // base.Base_protected = 2;   // ❌ protected not accessible via object
    base.Base_public = 3;        // ✅ public is accessible

    cout << "base.Base_public = " << base.Base_public << endl;

    return 0;
}
