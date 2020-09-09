#include <iostream>
#include <map>

using namespace std;

int main(){

    /* Maps */

    // One of this operator can be a custom class
    map<string,int> ages;
    ages["Mike"] = 40;
    ages["Guilherme"] = 20;
    ages["Mike"] = 10;

    cout << ages["Mike"] << endl;

    for(map<string,int>::iterator it = ages.begin(); it != ages.end(); it++ ) {
        cout << it->first << ":" << it->second << endl;
    }

    for ( pair<string,int> age : ages ){
        cout << age.first << ":" << age.second << endl;
    }

    if ( ages.find("Guilherme") != ages.end() )
        cout << "founded: " << ages["Guilherme"] << endl;
    else
    {
        cout << "not found" << endl;
    }
    
    /* Multimaps */
    multimap<int,string> lookup;

    cout << "\nMULTIMAPS\n\n";

    lookup.insert(make_pair(30,"sad"));
    lookup.insert(make_pair(10,"raj"));
    lookup.insert(make_pair(30,"gui"));

    for ( pair<int, string> look : lookup ){
        cout << look.first << ":" << look.second << endl;
    }
    cout << endl;

    return 0;

}