//============================================================================
// Name        : Cpp_Training_WeakPointers.cpp
// Author      : Nico
// Version     :
// Copyright   : Your copyright notice
// Description : Testing SmartPointers in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>

using namespace std;

weak_ptr<int> weakPtr_global;

void f (){
	if (auto sharedPtr_local = weakPtr_global.lock()) {
		cout << "weak_ptr to shared_ptr converted" << endl;
		cout << "its value is " << *sharedPtr_local << endl;
		cout << "number of owners of shared object: " << sharedPtr_local.use_count() << endl;
	}
	else {
		cout << "can't convert weak_ptr to shared_ptr anymore, because there is no shared obj anymore" << endl;
	}
}

int main() {
	{
		auto sharedPtr_local = make_shared<int>(22);
		weakPtr_global = sharedPtr_local;
		f();
		cout << "leaving programming block..." << endl;
	}
	f();

	return 0;
}
