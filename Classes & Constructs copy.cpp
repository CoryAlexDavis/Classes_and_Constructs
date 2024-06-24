
/*
 assignment details:
 Create an encapsulated class with 4 fields and the respective methods to access and edit those fields. Then go ahead and create a test class to verify.
 */
#include <format>
#include <iostream>
#include <string>

using std::format;
using std::cout;
using std::string;

const int base_val =0;
const string base_str = "default";

class Student {
    int studentID {};
    string studentName {};
    string collegeName {};
    string studentAddress {};
public:
    // default constructor
    Student();
    //constructor with arguments
    Student(const int& studentID, const string& studentName, const string& collegeName, const string& studentAddress);
    // constructor that creates a clone
    Student(const Student&);
    // destructor
    ~Student();
    // copy / assignment operator
    Student& operator = (const Student&);
    // print function
    void print() const;
};
// -- implementation --
Student::Student() : studentID(base_val), studentName(base_str), collegeName(base_str), studentAddress(base_str) {
   cout << "default constructor \n";
}
Student::Student(const int& student_ID, const string& student_name, const string& college_name, const string& student_address) : studentID(student_ID), studentName(student_name), collegeName(college_name), studentAddress(student_address) {
    cout << "constructor with arguments \n";
}
Student::Student(const Student& girl) {
   cout << "copy constructor \n";
   studentID = girl.studentID;
   studentName = girl.studentName;
   collegeName = girl.collegeName;
   studentAddress = girl.studentAddress;
}

Student::~Student() {
   cout << "destructor \n";
}
Student& Student::operator = (const Student& o) {
   if(this != &o) {
       studentID = o.studentID;
       studentName = o.studentName;
       collegeName = o.collegeName;
       studentAddress = o.studentAddress;
   }
   return *this;
}

void Student::print() const {
   cout << format("student ID: {}\n", studentID);
   cout << format("student name: {}\n", studentName);
   cout << format("college name: {}\n", collegeName);
   cout << format("student address: {}\n", studentAddress);
}

int main() {
    const Student girl(4444, "Wiktoria", "Columbia University", "4449 Elsie Stoneman Lane");
    girl.print();
    const Student girl_2(777, "Freya", "Brown University", "2083 Heinrich Hemler Drive");
    girl_2.print();
}

