#include "MathBuddy.h"

int main(int argc, char* argv[]) {

	mthbd::Int x = 100000;
	mthbd::Int y = 321;

	std::cout << mthbd::sum(x, y).getBitsString();

	return EXIT_SUCCESS;
}