#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Test {
    int id;
    string name;

public:

    Test(int id, string name) : id(id), name(name) {}

    void print() {
        cout << id << ": " << name << endl;
    }

/*     bool operator<(const Test& other) const {
        return name < other.name;
    } */

    // https://en.cppreference.com/w/cpp/language/friend
    // The friend declaration appears in a class body and
    // grants a function or another class access to private
    // and protected members of the class where the friend
    // declaration appears.
    friend bool comp(const Test &a, const Test &b);

};

bool comp(const Test &a, const Test &b){
    return a.name < b.name;
}

int main(){

    vector<Test> tests;

    tests.push_back(Test(5,"guilherme"));
    tests.push_back(Test(10,"alessandra"));
    tests.push_back(Test(1,"alessandro"));
    tests.push_back(Test(5,"adsa"));

    sort(tests.begin(), tests.end(),comp);

    for ( Test t : tests ){
        t.print();
    }

}