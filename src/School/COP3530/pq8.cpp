#include <iostream>
#include <string>
#include <set>
using namespace std;

string findTheDigits(string x, string y) {
	set<char> xDigits, yDigits;
	string output = "";
	for(int i = 0; i < x.length(); i++) {
		xDigits.insert(x[i]);
	}
	for(int i = 0; i < y.length(); i++) {
		if(xDigits.find(y[i]) == xDigits.end()) {
			yDigits.insert(y[i]);
		}
	}
	for(auto it = yDigits.begin(); it != yDigits.end(); it++) {
		output += *it;
	}
	return output;
}