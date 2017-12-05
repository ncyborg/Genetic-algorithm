#include "Puzzle.h"

ostream& operator<<(ostream& os, const Puzzle& obj) {

	obj.print(os);

	return os;
}

istream& operator>>(istream& is, Puzzle& obj) {

	obj.in(is);
	return is; 

}
