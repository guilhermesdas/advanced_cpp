#include <iostream>
using namespace std;

template<class T, class K>
class Test {
    private:
    T obj;
    public:
    Test(T obj){
        this->obj = obj;
    }
    void print(){
        std::cout << obj << endl;
    }

};

int main(){

    Test<string, int> test("Hello");
    test.print();

    return 0;

}