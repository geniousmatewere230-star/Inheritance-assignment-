// person_student_raii.cpp
#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char* name;
    int age;

public:
    Person(int age, const char* name) {
        this->age = age;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        cout << "Person constructor: allocated name='" << name << "'" << endl;
    }

    ~Person() {
        cout << "Person destructor: freeing name='" << name << "'" << endl;
        delete[] name;
    }

    void PrintPerson() const {
        cout << "My age is " << age << endl;
        cout << "My name is " << name << endl;
    }
};

class Student : public Person {
private:
    char* major;

public:
    Student(int age, const char* name, const char* major)
        : Person(age, name)  // Call base constructor first
    {
        this->major = new char[strlen(major) + 1];
        strcpy(this->major, major);
        cout << "Student constructor: allocated major='" << major << "'" << endl;
    }

    ~Student() {
        cout << "Student destructor: freeing major='" << major << "'" << endl;
        delete[] major;
    }

    void PrintStudent() const {
        PrintPerson();  // Reuse base class printing
        cout << "My major is " << major << endl;
    }
};

int main() {
    cout << "=== Creating Student Object ===" << endl;
    Student* s = new Student(20, "Alice", "Computer Science");

    cout << "\n=== Printing Student Info ===" << endl;
    s->PrintStudent();

    cout << "\n=== Deleting Student Object ===" << endl;
    delete s;  // Calls ~Student() then ~Person()

    return 0;
}
