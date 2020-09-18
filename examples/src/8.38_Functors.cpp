#include <iostream>

using namespace std;

struct Test
{
    virtual bool operator()(string &Test)=0;
    virtual ~Test(){};
};

struct MatchTest : public Test
{
    bool operator()(string & text) 
    {
        return text == "lion";
    }
};

void check(string text, Test &test)
{
    if (test(text)){
        cout << "Passed!\n";
    } else {
        cout << "Failed\n";
    }
}

int main()
{

    MatchTest pred;

    string value = "lion";
    check(value,pred);

    return 0;
}