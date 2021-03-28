#include <iostream>

#include "Main.h"

const unsigned int bools_length = 38;
bool bools[bools_length];

int main() {
	/*init bools*/
	bools[0] = true;
	bools[1] = true;
	bools[2] = false;
	bools[3] = true;
	bools[4] = true;
	bools[5] = false;
	bools[6] = true;
	bools[7] = true;

	for (int i = 0; i < 1000; i++) {
		draw();
		change_bools();
	}

	return 0;
}

/*draw the bools (in the console at the moment)*/
void draw() {
	for (bool b : bools) {
		std::cout << (b ? "0" : " ");
 	}
	std::cout << '\n';
}

void change_bools() {
	bool new_bools[bools_length];
	for (int i = 0; i < bools_length; i++) {
		new_bools[i] = get_next_bool(i);
	}
	for (int i = 0; i < bools_length; i++) {
		bools[i] = new_bools[i];
	}
}

/*get next bool of position position*/
bool get_next_bool(unsigned int position) {
	if (position > bools_length) {
		std::cout << "inserted position extends length of array \"bools\"";
		return false;
	}

	/*get the positions*/
	bool left;
	if (!position)
		left = bools[bools_length - 1];
	else
		left = bools[position - 1];
	bool mid = bools[position];
	bool right;
	if (position == bools_length)
		right = bools[0];
	else
		right = bools[position + 1];

	/*return the right bool*/
	if (left && mid && right) return false;
	if (left && mid && !right) return true;
	if (left && !mid && right) return false;
	if (left && !mid && !right) return true;
	if (!left && mid && right) return false;
	if (!left && !mid && right) return true;
	if (!left && mid && !right) return false;
	if (!left && !mid && !right) return true;

	return false;
}