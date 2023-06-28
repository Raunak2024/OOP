#include<iostream>
#include<string>
using namespace std;
    // CLASS IS A USER-DEFINED DATATYPE(RELA-WORLD BLUERPRINT)
    // OOP=> 4 PILLARS-> ENCAPSULATION, POLYMORPHISM, ABSTARCTION, INHERITANCE
    // CONTAINS SOME USER-DEFINED PROPERTIES AND METHODS/FUNCTIONS
    // OBJECTS-VARIABLES OF TYPE CLASS(INSTANCES OF A CLASS)
    // ALWAYS DEFINED OUTSIDE BEFORE MAIN()
    class Fruit // Creating class of Type Fruit where we can create many objects of type fruit like mango,apple etc
    {
        //ACCESS SPECIFIER-> PRIVATE,PUBLIC,PROTECTED
        //->public-they can be accessed from anywhere in the code
        //->private-they can be accessed inside the class where it was defined
        //->protected-they can be accessed only from the own class,parent class and derived class
        public: // DEFAULT-PRIVATE
        string name;
        string color;
    };
    // Empty Class occupies 1 byte in memory default.
    class Rectangle{
    public:
        int l;
        int b;
        //CONTRUCTORS ARE USED TO INITLIAZE AN OBJECT
        //CONTRUCTOR IS A SPECIAL TYPE OF FUNCTION WHICH IS CALLED WHEN AN OBJECT IS CREATED
        //HAS SAME NAME AS CLASS NAME
        //3 TYPES
        Rectangle(){//-> DEFAULT CONSTRUCTOR(WITH NO PARAMS)
        l=0;
        b=0;
        }
        Rectangle(int x, int y){// paramterized constructor-takes in params
        l=x;
        b=y;
        }
        Rectangle(Rectangle& r){//copy contructor-initializes an object with values from an existing another object
        l=r.l;
        b=r.b;
        }
        ~Rectangle(){
            cout<<"destructor called"<<endl;
        }
    };
        // destructor-it is called when an object is deleted from a class
        // it cannot take any parameters
        // same name as class name
    class ABC {
            int x;
            // Getters and Setters are very important as they are used to read and modify the private data functions of a class.
            public:
            //Setter Function-Used to modify the private data of a class
            void set(int n)
            {
                x=n;
            }
            //Getter Function-used to access the private data of a class
            int get(){
                return x;
            }

    };
    class Parent {

        public:
        int x;
        private:
        int y;
        protected:
        int z;          

    };
    
    class Child1:public Parent{ //here we are inheriting the parent class properties to the child class publicly
    //this means that originality will sustain
        //x will be public
        //y will be private
        //z will be protected
    };
    class Child2:private Parent{//here we are inheriting the parent class properties to the child class privately
        //x will be private
        //y will be private
        //z will be private
    };
    class Child3:protected Parent{
        //x will be protected
        //y will be private
        //z will be protected
    };
    //Single Inheritance
    class Parents1{
    public:
    Parents1(){
        cout<<"Parents1 Class"<<endl;
    }        
    };
    class Parents2{
    public:
    Parents2(){
        cout<<"Parents2 Class"<<endl;
    }        
    };
    //multiple inheritance(class a->class b<-class c)
    class Child:public Parents1, Parents2{
    public:
    Child(){
        cout<<"Child Class"<<endl;
    }
    };
    //Single Inheritance-(CLASS A -> CLASS B)
    
    class Parentify{
        public:
        Parentify(){
            cout<<"Parent Class"<<endl;
        }

    };

    class Childify: public Parentify{
         public:
         Childify(){
            cout<<"Child Class"<<endl;
         }
    };
    //MULTI-LEVEL INHERITANCE
    //child class is derived from parent class which is derived from another class (Class A->Class B->Class C)
    class GrandChild: public Child{
        public:
        GrandChild(){
            cout<<"grandchild class"<<endl;
    }
    };
    //hierarchial inheritance(class a->class b && class a->class c)
     class Childs1: public Parents1{
        public:
        Childs1(){
            cout<<"Childs1 Class"<<endl;
        }
     };
     class Childs2: public Parents2{
        public:
        Childs2(){
            cout<<"Childs2 Class"<<endl;
        }
     };
     //Hybrid Inheritance-Combination of more than one inheritance types
        // DESTRUCTOR-SPECIAL FUNCTION IS CALLED WHEN AN OBJECT IS DELETED
        //-> DOESNOT TAKE ANY PARAMETERS
        //-> SAME NAME AS CLASS NAME
        class Sum{
            public:
            void add(int x, int y){
                int sum=x+y;
                cout<<sum<<endl;
            }
            void add(int x, int y, int z ){
                int sum=x+y+z;
                cout<<sum<<endl;
            }
            void add(float x, float y, float z){
                float sum=x+y+z;
                cout<<sum<<endl;
            }
        };
        //Run-time polymorphism
        class Grand{
            public:
            virtual void print(){
                cout<<"Grand class"<<endl;
            }
            void show(){
                cout<<"Grand class"<<endl;
            }
        };

        class Rand: public Grand{
            public:
            void print(){
                cout<<"child class"<<endl;
            }
            void show(){
                cout<<"child class"<<endl;
            }
        };
        
        class C{
            int a;
        public:
            C(int b){
                a=b;
            }

            friend void print(C &obj);
        
        };

        void print(C &obj){
            cout<<obj.a<<endl;
        }

        int main(){
        // WE CAN CREATE ANY NO OF OBJECTS OF ANY CLASS BOTH STATICALLY AND DYNAMICALLY
        Fruit apple; // statically creating object of type Fruit
        apple.name="Apple";
        apple.color="Red";
        Fruit* mango=new Fruit();// dynamically creating object
        mango->name="Apple";
        mango->color="Red";
        cout<<apple.name<<"-"<<apple.color<<endl;
        cout<<mango->name<<"->"<<mango->color<<endl;
        //default constructor values printing
        Rectangle r1;
        cout<<r1.l<<" "<<r1.b<<endl;
        r1.l=10;
        r1.b=15;
        cout<<r1.l<<" "<<r1.b<<endl;
        //parameterized constructor values printing
        Rectangle r2(3,4);
        cout<<r2.l<<" "<<r2.b<<endl;
        //copy contructor values printing
        Rectangle r3=r2;
        cout<<r3.l<<" "<<r2.b<<endl;
        delete mango;
        ABC obj1;
        //obj1.x->cannot directly use it since it is private
        obj1.set(3);
        cout<<obj1.get()<<endl;
        // this will work since x is public
        //p.y->this will not work since y is private
        //p.z->this will also not work since z is protected
        Childify c1;//Single Inheritance
        GrandChild g;//multi-level inheritance
        Childify c2;//multiple inheritance
    //-> Function Overloading-define a no of functions with same function name but they perform differently according to arguments(how many/type) passed
    Sum s;
    s.add(2,3);
    s.add(2,3,4);
    s.add(float(2.5),float(3.5),float(4.5));
    Grand *r;
    Rand c;
    r=&c;
    r->print();
    r->show();
    C obj(5);
    print(obj);
    //operator overloading
    cout<<1+2<<endl;// + is used to add two ints
    string str1="cat";
    string str2="woman";
    cout<<str1+str2<<endl; // + is used to concatenate two strings
    //4)inheritance-enables a class to inhetit the properties of another class
    //in inheritance two classes are involved-> parent class/base class/superclass and derived class/subclass/child class
    //inheritance enables code reusability
    // examples of three access modifiers- public, private, protected
    //public-data and functions can be accessed anywhere inside the code
    //private-accessible in own class
    //protected-accessible in own class,parent class and child class 
    //-> Multilevel-inheritance
    //-> Hierarchial Inheritance
    //-> Multiple Inheritance
    //-> Single Inheritance
    //-> Hybrid Inheritance
    //-> class does not occupy any memory generally except 1 byte.only objects defined for a class occupy memory
    //EXTRA
    //Diamond Problem(v.imp)->base class has multiple parent classes having a common ancestor class
    //Friend Function-non-member function which can access private members of the class 
    //Sorting And Binary Search Implementation without STL (V.IMP)
    //encapuslation can be achieved by two methods
//-> declaring the varibales of a class as private
// providing public setter and getter methods to modify and view the variables values
// Data abstraction is the ability to hide unwanted information.
// Data encapsulation refers to the ability to hide the data as well as the method together.
// Errors and exceptions are different, and an error means a problem that the program should not catch while the exception implies a condition that should be caught by the program.
// limitations of the process of inheritance, for example, it requires more processing time for the programs as it has to navigate various classes during execution. Also, due to inheritance, the parent and child class are tightly coupled. When any changes are needed in the logic, it may require changes in both parent and child classes.
// Single inheritance - A class inherits the properties of a single parent class.
// Multiple inheritances - An object or class can inherit features from more than one parent object or parent class. Not supported in all programming languages.
// Multi-level inheritance - One class has more than one parent class but at different levels of inheritance
// Hierarchical inheritance - One parent can have one or more child/sub/derived classes
// Hybrid inheritance - Combination of more than one type of inheritance in a single program
// Keywords-
//Static Keyword
//The static keyword is used to create variables and methods that belong to the class itself, rather than to any particular instance of the class. This means that static variables and methods are shared by all instances of the class.
//Virtual Keyword
//The virtual keyword is used to declare a method that can be overridden by a subclass. This means that the subclass can provide its own implementation of the method, which will override the implementation in the superclass.
//This Keyword
//The this keyword refers to the current object in a method or constructor. This can be used to access the object's fields and methods.
//New Keyword
//The new keyword is used to create a new object. This is done by calling the constructor of the class.
//Const Keyword
//The const keyword is used to declare a constant variable. A constant variable is a variable whose value cannot be changed after it is initialized.
//Final Keyword
//The final keyword is used to declare a final variable or method. A final variable cannot be changed after it is initialized, and a final method cannot be overridden by a subclass.
//Super Keyword
//The super keyword is used to refer to the superclass of the current object. This can be used to access the superclass's fields and methods.
//Abstract Keyword
//The abstract keyword is used to declare an abstract class. An abstract class is a class that cannot be instantiated. It must be subclassed, and the subclass must provide implementations for the abstract methods in the superclass.
//Explicit Keyword
//The explicit keyword is used to specify that a cast is required. This is done when the compiler cannot automatically determine the type of an expression.
//Runtime Polymorphism
//#4 PILLARS OF OOP
    //1)encapsulation
    //-> process of binding variables and functions together in a single unit=> "Class"
    //-> Data is only accesible only from the class methods
    //-> also leads to data abstraction
    //-> so we can also call class a abstract data type(ADT)
    //3)abstraction(implementation hiding)-enable us to display only eesential information to us while hiding the implementation details from us
    //2)polymorphism-ability of objects/methods to take many forms
    //-> Runtime Polymorphism
    //-> Resolved at runtime and implements function overriding through virtual function
    //-> child class defines a function of parent class
    //-> Compile Time Polymorphism-defined at compile time
}
