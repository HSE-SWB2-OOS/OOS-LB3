#include "MyString.hpp"
//#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	const MyString cs("Ein konstanter String"); MyString s(cs);
	s.assign(cs);
	s.append(cs);
	cout << cs.c_str() << endl;
	cout << cs.size() << endl;
	cout << cs.capacity() << endl;
	cout << boolalpha << cs.empty() << endl;
	s = cs + cs;
	cout << (cs == cs) << endl;
	s = cs;
	cout << cs << endl;
	s.at(1) = 'X';
	s[2] = 'Y'; // Hallo
	cout << s << endl;
	cin.get();
return 0;
}