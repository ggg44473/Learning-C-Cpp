#include "pch.h"
#include <iostream>

int main() {

	int convert_type;
	float c; //int運算比較快，且預期輸入是有限的，利用float value接輸出入
	float f;

	std::cout << "Which format you want ot convert?" << std::endl;
	std::cout << "1 for c to f" << std::endl;
	std::cout << "2 for f to c" << std::endl;
	std::cin >> convert_type;

	if (convert_type == 1) {
		std::cout << "Input a c degree." << std::endl << "c = ";
		std::cin >> c;
		f = 1.8 * c + 32;
		std::cout << "f = " << f;
	}
	else if (convert_type == 2) {
		std::cout << "Input a f degree." << std::endl << "f = ";
		std::cin >> f;
		c = (f - 32) * 5 / 9;
		std::cout << "c = " << c;
	}
	else {
		std::cout << "You entered a wrong type!";
	}

	return 0;
}


int Add(int a, int b);

int main2()
{
	int x = 3;
	int y = 5;
	int z = 0;

	// std::cout << sizeof(x);

	std::cout << "x = " << x << " x = ?" << std::endl;
	std::cin >> x;
	std::cout << "y = " << y << " y = ?" << std::endl;
	std::cin >> y;

	z = Add(x, y);

	std::cout << "x + y = " << z << std::endl;

	// leap year or not.
	int n;
	std::cout << "Input a year to see if it is a leap year." << std::endl;
	while (std::cin >> n) {

		if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0))
		{
			std::cout << "Yes" << std::endl;
		}
		else
		{
			std::cout << "No" << std::endl;
		}
	}

	return 0;
}

int Add(int a, int b) {

	int result = 0;
	result = a + b;

	return result;
}