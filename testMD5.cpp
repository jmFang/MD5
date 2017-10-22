#include <iostream>
#include "md5.cpp"
using namespace std;


void printMD5(const string& message) {
  cout << "md5(\"" << message << "\") = "
       << MD5(message).toString() << endl;
}

int main() {
	string in = "";
	while(in != "quit") {
		cout << "enter message to transform" << endl << endl << "message: ";
		cin >> in;
		cout <<endl <<  "md5:" << MD5(in).toString() << endl << endl;
	}

	return 0;
}
