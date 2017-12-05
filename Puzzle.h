#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;
class Puzzle {

	friend ostream& operator<<(ostream& os, const Puzzle& obj);
	friend istream& operator>>(istream& is, Puzzle& obj);

	public:
		virtual void print(ostream& where) const {}
		virtual void in(istream& in) = 0;

};
