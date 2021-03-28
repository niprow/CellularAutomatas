#include <iostream>

#include "Main.h"

const unsigned int bools_length_x = 50;
const unsigned int bools_length_y = 50;

bool bools[bools_length_x][bools_length_y]{ false };

int main() {
	return 0;
}

void draw() {
	system("cls"); //clear the console
	for (int i = 0; i < bools_length_x; i++) {
		for (int j = 0; j < bools_length_y; j++) {
			std::cout << (bools[i][j] ? "0" : " ");
		}
		std::cout << std::endl;
	}
}

/*update booleans in the array bools*/
void change_bools() {
	bool new_bools[bools_length_x][bools_length_y]{ false };

	for (int i = 0; i < bools_length_x; i++) {
		for (int j = 0; j < bools_length_y; j++) {
			new_bools[i][j] = get_next_bool(i, j);
		}
	}
	for (int i = 0; i < bools_length_x; i++) {
		for (int j = 0; j < bools_length_y; j++) {
			bools[i][j] = new_bools[i][j];
		}
	}
}

/*get next boolean of position*/
bool get_next_bool(unsigned int x, unsigned int y) {
	/*check position*/
	if (x > bools_length_x || y > bools_length_y) {
		std::cout << "you fucked up you little piece of...";
		return false;
	}

	/*get surounding positions*/
	bool mid = get_bool(x, y);
	bool nw = false;
	if (!(x == 0 || y == bools_length_y)) nw = get_bool(x - 1, y + 1);
	bool n = false;
	if (y != bools_length_y) n = get_bool(x, y + 1);
	bool no = false;
	if (!(x == bools_length_x || y == bools_length_y)) no = get_bool(x + 1, y + 1);
	bool o = false;
	if (x != bools_length_x) o = get_bool(x + 1, y);
	bool so = false;
	if (!(x == bools_length_x || y == bools_length_y)) so = get_bool(x + 1, y - 1);
	bool s = false;
	if (y != 0) s = get_bool(x, y - 1);
	bool sw = false;
	if (!(x == 0 || y == 0)) sw = get_bool(x - 1, y - 1);
	bool w = false;
	if (x != 0) w = get_bool(x - 1, y);

	/*return right bool*/ //TODO

	return false;
}

bool get_bool(int x, int y) {
	return bools[x][y];
}