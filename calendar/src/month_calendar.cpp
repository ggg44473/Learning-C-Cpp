#include <iostream>

using namespace std;


int isLeapYear(int year)
{
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}


// 1900-01-01 is Monday, one space(week starts with Sunday).
int getSpace(int year, int month, int leap)
{
	int space = 1;
	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month == 2 && leap == 1)
	{
		days[1] = 29;
	}

	// spaces in January of the year.
	for (int i = 0; i < year-1900; i++)
	{
		if (isLeapYear(1900+i))
		{
			space = (space + 366) % 7;
		}
		else
		{
			space = (space + 365) % 7;
		}
	}

	// the input month's space
	for (int i = 0; i < month-1; i++)
	{
		space = space + days[i];
	}
	space = space % 7;

	return space;
}


void printTitle(int year, int month)
{
	char months[12][10] = 
		{"January", "February", "March", "April",
		 "May", "June", "July", "August", "September",
		 "October", "November", "December"};
	cout << months[month - 1] << "\t" << year << endl;
}


void printMonthlyCalendar(int month, int space, int leap)
{
	// TODO make a function to do this. How to return an array?
	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month == 2 && leap == 1)
	{
		days[1] = 29;
	}

	cout << "Sun\tMon\tTue\tWed\tThu\tFri\tSat" << endl;

	for (int i = 0; i < space; i++)
	{
		cout << "\t";
	}
	for (int i = 0; i < days[month-1]; i++)
	{
		cout << i+1 << "\t";
		if ((i + 1) % 7 == (7 - space))
		{
			cout << endl;
		}
	}
}


// 1.the spaces before the first day 2. LF at %7=(7-space) 3. total days
// Every year +1 day(365%7=1)
int main()
{
	int year, month, leap, space;

	cout << "Welcome to month calendar." << endl << "Input a year.(number only): ";
	cin >> year;
	// TODO we should check input is int. If input is char, while loop won't stop.
	while (year < 1900) // We should check until correct input.
	{
		cout << "Sorry, we only have records after 1900." << endl << "Try again: ";
		cin >> year;
	}

	cout << "Input a month.(number only): ";
	cin >> month;
	// TODO we should check input is int.
	while (month < 1 || month >12)
	{
		cout << "Sorry, there are only 12 months a year." << endl << "Try again: ";
		cin >> month;
	}
	cout << endl;

	leap = isLeapYear(year);

	space = getSpace(year, month, leap);

	printTitle(year, month); cout << endl;
	printMonthlyCalendar(month, space, leap);

	return 0;
}