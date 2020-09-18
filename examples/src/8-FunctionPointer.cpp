#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Random function
double test(int a, double b)
{
    return ((double) a) * b;
}

// Match function
bool match(double s)
{
    return s > 0;
}

// Example pointer function use
void examplePfunc()
{
    int a = 5;
    double b = 10.4f;

    // Calling some function
    cout << "Calling some function: " << test(a,b) << endl;

    // Pointer function variable
    double (*pTest)(int,double);

    // Attributing pointer function variable to function
    pTest = test;

    // Calling function test through pTest
    cout << "Calling function test through pTest: " << pTest(a,b) << endl;
}

// Test match function
void testMath(bool (*m)(double test))
{
    vector<double> strs;
    strs.push_back(1.2);
    strs.push_back(-3);
    strs.push_back(0);
    strs.push_back(7);

    cout << count_if(strs.begin(), strs.end(), m) << endl;

}

int main()
{

    testMath(match);

    return 0;


}