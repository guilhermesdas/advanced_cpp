#include <iostream>

using namespace std;

class Parent {

public:
    void print(){
        cout << "parent" << endl;
    }
    Parent()
    {

    }
    Parent(const Parent &other)
    {
        cout << "copy constructor" << endl;
    }

};

class Parent2 {

public:
    virtual void print(){
        cout << "parent" << endl;
    }
};

class Child: public Parent, public Parent2{
public:
    void print(){
        cout << "child" << endl;
    }
};

int main()
{

    Parent p;
    p.print();
    Child c;
    c.print();
    Parent &p1 = c;
    p1.print();
    Parent2 &p2 = c;
    p2.print();
    Parent p4(p2);
    p4.print();

    return 0;

}