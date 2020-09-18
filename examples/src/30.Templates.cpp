#include <iostream>
#include <vector>
using namespace std;

/**
 * Class to identify exception errors in VectorString class
 * */
class InvalidIDException : public exception {
public:
    virtual const char* message() const throw() {
        return "Invalid ID!";
    } 
    
    /**
     * Overload << operator to show all objects side-by-side
     * */
    friend ostream &operator<<(ostream &out, const InvalidIDException &invalidIDException ){
        out << invalidIDException.message();
        return out;
    }
};

/**
 * Templace for a data access object
 * */
template<class T>
class Vector {
public:
    virtual T get(int) = 0;
    virtual vector<T> getAll() = 0;
    virtual void erase(int) = 0;
    virtual void update(T,int) = 0;
    virtual void add(T j) = 0;
    virtual int getId(string) = 0;
};

/**
 * Implementation of a data access objec (DAO templace virtual class)
 * */
class VectorString : Vector<string> {

private:
    vector<string> str;
public:

    /**
     * Construct vector names
     * */
    VectorString(){
        str = vector<string>();
    }

    /**
     * Get an element from vector
     * */
    string get(int id) override {
        if ( id >= str.size() ){
            throw InvalidIDException();
        } else {
            return str[id];
        }
    }

    /**
     * Get the first element id from a string
     * */
    int getId(string obj) override {
        
        // Iterate vector
        for ( int i = 0; i < str.size(); i++ ){
            // Search string
            if ( obj.compare(str[i]) == 0 ){
                return i;
            }
        }

        // String not found, return -1
        return -1;

    }

    /**
     * Add an element in vector
     * */
    void add(string obj) override {
        str.push_back(obj);
    }

    /**
     * Get all elements from the vector
     * */
    vector<string> getAll() override {
        return str;
    }

    /**
     * Update an element from the vector with id i
     * */
    void update(string obj, int id) override {
        if ( id >= str.size() ) {
            throw InvalidIDException();
        } else {
            str[id] = obj;
        }
    }

    /**
     * Erase an element from the vector with id i
     * */
    void erase(int id) override {
        if ( id >= str.size() ) {
            throw InvalidIDException();
        } else {
            str[id] = "\0";
        }
    }

    /**
     * Overload << operator to show all objects side-by-side
     * */
    friend ostream &operator<<(ostream &out, VectorString &vectorString ){
        vector<string> str = vectorString.getAll();
        for ( string i : str ){
            out << i << " ";
        }
        return out;
    }

};

int main(){

    VectorString names;

    // Add a string
    names.add("Rice");
    names.add("Bean");
    names.add("Wholesome");
    names.add("Bolero");

    // Print all objects
    cout << names << endl;

    // Update one object
    int riceId = names.getId("Rice");
    if ( riceId != -1 ){
        names.update("Ricee", riceId);
        cout << names << endl;
    }

    // Erase one object
    int beanId = names.getId("Bean");
    if ( beanId != -1 ){
        names.erase(beanId);
        cout << names << endl;
    }

    // Update a invalid object
    try {
        names.update("Bean", 10);
    } catch ( InvalidIDException e ){
        cout << e << endl;
    }
    cout << names << endl;

    // Erase a invalid object
    try {
        names.erase(7);
    } catch (InvalidIDException e) {
        cout << e << endl;
    }
    cout << names << endl;

    return 0;

}