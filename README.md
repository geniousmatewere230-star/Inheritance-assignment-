# Inheritance-assignment- Expected outcomes

1. --- Creating ptr1 with Derived(2) ---
Constructor of base class
Constructor of derived class
Destructor of derived class
Destructor of base class

--- Creating ptr2 with Derived(1,2) ---
Constructor of base class
Constructor of derived class
Destructor of derived class
Destructor of base class

2. Base::setBasenum called. All members assigned.
Derived::setBasenum called. Protected and public assigned.
base.Base_public = 3

 3. === Public Inheritance ===
PubDeriv: prot=2, pub=3
pd.pub = 3

=== Protected Inheritance ===
ProtDeriv: prot=2, pub=3

=== Private Inheritance ===
PrivDeriv: prot=2, pub=3

4. === Creating Student Object ===
Person constructor: allocated name='Alice'
Student constructor: allocated major='Computer Science'

=== Printing Student Info ===
My age is 20
My name is Alice
My major is Computer Science

=== Deleting Student Object ===
Student destructor: freeing major='Computer Science'
Person destructor: freeing name='Alice'
