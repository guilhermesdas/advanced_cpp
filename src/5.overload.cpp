#include <iostream>

using namespace std;

class Test {
    int id;
    string name;

public:
    Test() : id(0), name("") {

    }

    Test(int id, string name) : id(id), name(name){}

    void print(){
        cout << id << ": " << name << endl;
    } 

    // Assignment operator
    const Test &operator=(const Test &other){

        cout << "Assignment running" << endl;
        id = other.id+1;
        name = other.name;

        return *this;
    }

    // Copy constructor
    Test(const Test &other){
        *this = other;
    }

    friend ostream &operator<<(ostream &out, const Test &test){
        out << test.id << ": " << test.name;
        return out;
    }

};

int main(){

    // Assignment operator

    Test test1(10,"mike");
    test1.print();

    Test test2(20,"23");
    test2.print();
    
    test2 = test1;

    test2.print();

    Test test3 = test2;

    test3.print();

    cout << test1 << endl;

    return 0;
}