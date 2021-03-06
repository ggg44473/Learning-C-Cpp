#include "pch.h"
#include <iostream>

#define TOTAL 10

void build_index(int total,int course[], int ndx[])
{
	int temp = 0;
	int count = 0;

	do
	{
		count = 0;
		for (int i = 0; i < total-1; i++)
		{
			if (course[ndx[i]] < course[ndx[i + 1]])
			{
				temp = ndx[i]; ndx[i] = ndx[i + 1]; ndx[i + 1] = temp;//小心i+1不能超過TOTAL
				count++;
			}
		}
	} while (count);
}
/*
void build_index(int total, int course[], int ndx[])
{
	int temp = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = i; j < 10; j++) {
			if (course[ndx[j]] > course[ndx[i]]) {
				temp = ndx[j];
				ndx[j] = ndx[i];
				ndx[i] = temp;
			}
		}
	}
}
*/
int main()
{
	char name[TOTAL][20] = { "Allen", "Ben", "Cat", "Dog", "Elle", "Flora", "George", "Hugo", "Indian", "John" };
	int math[TOTAL] = { 80, 75, 70, 65, 60, 55, 50, 45, 40, 35 };
	int english[TOTAL] = { 69, 70, 88, 66, 88, 98, 20, 44, 57, 66 };
	int ndx_math[TOTAL] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int ndx_english[TOTAL] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	build_index(TOTAL, math, ndx_math);
	build_index(TOTAL,english, ndx_english);

	std::cout << "Score Table" << std::endl;
	for (int i = 0; i < TOTAL; i++)
	{
		std::cout << "[" << i + 1 << "] " << name[i] << " : " << math[i] << " : " << english[i] << std::endl;
	}
	std::cout << std::endl;
	
	for (int i = 0; i < TOTAL; i++) {
		std::cout << name[ndx_math[i]] << " : " << math[ndx_math[i]] << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < TOTAL; i++) {
		std::cout << name[ndx_english[i]] << " : " << english[ndx_english[i]] << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
