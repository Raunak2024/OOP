//OOP(OBJECT ORIENTED PROGRAMMING)
#include<iostream>
using namespace std;
//Creating a Class called Student
class Student{//CLASS SYNTAX
int roll;
int age;
int marks; 
};
int main()
{//Creating Object of that class Statically
Student s1;
Student S2;
Student s3;
//cout<<"size:"<<sizeof(s1);//Size of an object is equal to the total size of its properties initially defined in the class
//For empty class,The object size is one
//Creating Object Dynamically
Student *s6=new Student;//POINTER DATATYPE AND NEW DATATYPE
}