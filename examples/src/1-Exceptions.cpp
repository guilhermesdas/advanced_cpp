#include <iostream>
#include <string>

using namespace std;

class CanGoWrong {
public:
	CanGoWrong(){
		char *pMemory = new char[912379127391];
		delete[] pMemory;
	}
};

void mightGoWrong(){

	bool error1 = true;
	bool error2 = false;

	string str("1");

	if (error1)
		throw str;
	if (error2)
		throw 2;

}

void usesMightGoWrong(){
	mightGoWrong();
}

int main(){

	// Try 1
	try{
		usesMightGoWrong();
	}
	catch(string &e){
		cout << "String error code: " << e << endl;
	}

	cout << "Still running!\n";

	// Try 2
	try {
		CanGoWrong wrong;
	}
	catch(bad_alloc &e) {
		cout << "Caugh exception: " << e.what() << endl;
	}

	cout << "Still running... Try again!\n";

	return 0;

}