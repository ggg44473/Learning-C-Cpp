#include <iostream>

using namespace std;

// 0 for greater month, 1 for common, the rest is Feb.
void print_day(int month_type, int leap) {

	for (int i = 0; i < 28; i++)
	{
		cout << i + 1 << ", ";
	}

	if (month_type == 0)
	{
		cout << "29, 30, 31";
	}
	else if (month_type == 1)
	{
		cout << "29, 30";
	}
	else
	{
		if (leap)
		{
			cout << "29";
		}
	}
}

void print_month_day(int month, int leap) {
	switch (month)
	{
		case 1:
			cout << "January ";
			print_day(0, leap);
			break;
		case 2:
			cout << "Febuary ";
			print_day(2, leap);
			break;
		case 3:
			cout << "March ";
			print_day(0, leap);
			break;
		case 4:
			cout << "April ";
			print_day(1, leap);
			break;
		case 5:
			cout << "May ";
			print_day(0, leap);
			break;
		case 6:
			cout << "June ";
			print_day(1, leap);
			break;
		case 7:
			cout << "July ";
			print_day(0, leap);
			break;
		case 8:
			cout << "August ";
			print_day(0, leap);
			break;
		case 9:
			cout << "September ";
			print_day(1, leap);
			break;
		case 10:
			cout << "October ";
			print_day(0, leap);
			break;
		case 11:
			cout << "November ";
			print_day(1, leap);
			break;
		case 12:
			cout << "December ";
			print_day(0, leap);
			break;
		default:
			break;
	}
}

int main()
{
	int year = 0;
	int leap = 0;

	cout << "Please enter a year." << endl;
	cin >> year;

	if (year > 0)
	{
		cout << "Analyzing..." << endl;
		if ((year%400 == 0) || (year%4 == 0 && year%100 != 0))
		{
			leap = 1;
			cout << "It's a leap year." << endl;
			for (int i = 1; i < 13; i++)
			{
				print_month_day(i, leap);
				cout << endl;
			}
		}
		else
		{
			cout << "It's a common year." << endl;
			for (int i = 1; i < 13; i++)
			{
				print_month_day(i, leap);
				cout << endl;
			}

		}
	}
	else
	{
		cout << "Error: year must be more than 0." << endl;
	}

	return 0;
}