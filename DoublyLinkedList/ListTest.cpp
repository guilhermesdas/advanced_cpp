

#include <iostream>
#include "List.cpp"

using namespace std;

int main(){

    List<double> list;
    // Test print, addFront and addEnd
    cout << "Test print, addFront and addEnd\n";
    list.print();    
    list.addEnd(1.3);
    list.addFront(0);
    list.addEnd(1.2);
    list.addFront(1);
    list.addEnd(1); 
    list.addFront(-0.5);
    list.addEnd(-10);
    list.addFront(1);
    list.addFront(3);
    list.addEnd(5);
    list.print();    

    // Teste remove
    cout << "Test remove: 5, 90, 0, -0.5\n";
    list.remove(list.begin());
    list.remove(3);
    list.remove(90);
    list.remove((double)0);
    list.remove(-0.5);
    cout << list.size() << endl;
    list.print();   

    // Test get
    cout << "Test get 1.2\n";
    List<double>::node * n = list.get(1.2);
    if ( n != NULL ){
        cout << n->data << " " << endl; 
    }

    // Teste add after and add before
    list.addAfter(n, 90);
    list.addBefore(list.get(5), -5);
    list.addAfter(list.get(5), 20);
    list.addBefore(list.begin(), -5);
    list.addBefore(list.begin(), 9);
    list.addAfter(list.begin(), 0);
    list.print();

}