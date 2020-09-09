#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using namespace std;

namespace coveofprogramming {

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

}

using namespace coveofprogramming;

int main(){

    Complex c1(1.3,6.8);
    Complex c2 = c1;
    Complex c3(5.5,2.2);

    Obj obj;

    cout << c1 << ": " << c2 << ": " << c3 << endl;

    cout << c1[obj] << " | " << c3[obj] << endl;

    Complex c4 = c1 + c3;
    Complex c5 = c4 + 2;

    cout << c4 << ": " << c5 << endl;

    if ( c4 == c5 ){
        cout << "C1 and C2 Equals!" << endl;
    } else {
        cout << "Diferentes!\n";
    }

    cout << *c1 << endl;

    return 0;

}

#endif /* COMPLEX_H_ */