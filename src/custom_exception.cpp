#include <iostream>
#include <string>

using namespace std;

class Die : public exception {
public:
	virtual const char* what() const throw() {
			return "Take care! Something bad happened!";
	}
};

void everybodyIsGonnaDie(){

	throw Die();

}

int main(){

	try {
		everybodyIsGonnaDie();
	} catch ( Die &die ){
		cout << die.what() << endl;
	} 

	return 0;

}