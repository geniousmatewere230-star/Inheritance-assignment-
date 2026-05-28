// inheritance_types_demo.cpp
#include <iostream>
using namespace std;

class Base {
private:
    int priv = 1;
protected:
    int prot = 2;
public:
    int pub = 3;

    void showBase() {
        cout << "Base: priv=" << priv << ", prot=" << prot << ", pub=" << pub << endl;
    }
};

// PUBLIC INHERITANCE
class PubDeriv : public Base {
public:
    void showPubDeriv() {
        // cout << priv;      // ❌ Error: private not accessible
        cout << "PubDeriv: prot=" << prot << ", pub=" << pub << endl; // ✅ OK
    }
};

// PROTECTED INHERITANCE
class ProtDeriv : protected Base {
public:
    void showProtDeriv() {
        // cout << priv;      // ❌ Error
        cout << "ProtDeriv: prot=" << prot << ", pub=" << pub << endl; // ✅ Now both are protected in ProtDeriv
    }
};

// PRIVATE INHERITANCE
class PrivDeriv : private Base {
public:
    void showPrivDeriv() {
        // cout << priv;      // ❌ Error
        cout << "PrivDeriv: prot=" << prot << ", pub=" << pub << endl; // ✅ Now both are private in PrivDeriv
    }
};

int main() {
    cout << "=== Public Inheritance ===" << endl;
    PubDeriv pd;
    pd.showPubDeriv();
    // pd.pub;       // ✅ Still public
    // pd.prot;      // ❌ Not accessible — it's protected in PubDeriv? Wait — NO!

    // Actually, under public inheritance:
    // - Base::pub remains public in PubDeriv → so pd.pub is OK
    // - Base::prot remains protected → so pd.prot is NOT accessible from main

    cout << "pd.pub = " << pd.pub << endl; // ✅ OK

    cout << "\n=== Protected Inheritance ===" << endl;
    ProtDeriv prd;
    prd.showProtDeriv();
    // prd.pub;      // ❌ Now pub is protected in ProtDeriv → not accessible in main
    // prd.prot;     // ❌ Also protected

    cout << "\n=== Private Inheritance ===" << endl;
    PrivDeriv prv;
    prv.showPrivDeriv();
    // prv.pub;      // ❌ Now private → not accessible
    // prv.prot;     // ❌ Also private

    return 0;
}
