#include <iostream>
using namespace std;

class Obj {
    public:
        double square(double x){
            return x * x;
        }
};

class Complex {
    double real;
    double imaginary;

public:

    Complex(){}

    // Constructor
    Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

    // Copy constructor
    Complex( const Complex &complex ){
        *this = complex;
    }

    double getReal() const {
        return real;
    }

    double getImaginary() const {
        return imaginary;
    }

    // Assignment operator overload 
    const Complex &operator=(const Complex &other){
        real = other.real;
        imaginary = other.imaginary;
        return *this;
    } 

    double operator [](Obj obj) const
    {
        return obj.square(real);
    }

    bool operator==(const Complex &other) const {
        return this->real == other.getReal() && imaginary == other.getImaginary();
    }

    bool operator!=(const Complex &other) const {
        return this->real != other.getReal() || imaginary != other.getImaginary();
    }

    Complex operator*() const{
        return *this;
    }

};

// Out operator
ostream &operator<<(ostream &out, const Complex &c){
    out << c.getReal() << " + " << c.getImaginary() << "i";
    return out;
}

// Plus operator 1
Complex operator+(const Complex &c1, const Complex &c2){
    return Complex(c1.getReal()+c2.getReal(),c1.getImaginary()+c2.getImaginary());
}

// Plus operator 2
Complex operator+(const Complex &c1, double d){
    return Complex(c1.getReal()+d,c1.getImaginary());
}

// Plus operator 3
Complex operator+( double d, const Complex &c1 ){
    return Complex(c1.getReal()+d,c1.getImaginary());
}

template<class T>
class Test {

private:
    T obj;

public:

    Test(){}

    Test(T obj) {
        this->obj = obj;
    }

    void print() {
        cout << obj << endl;
    }

    friend ostream &operator<<(ostream &out, const Test &test){
        out << test.obj;
        return out;
    }

};

// Template functions
template<class T> void print(T n){
    cout << "template1 " << n << endl;
}

// Template functions
template<class K>
void print(){
    cout <<  K() << endl;
}

int main() {

    Complex c(2.5,2.1);
    Complex c2(3,5);
    Test<Complex> test1(c+c2);
    cout << test1 << endl;
    print(1);
    print("as");
    print<Complex>();

    return 0;

}