#include "pch.h"
#include <iostream>

void swap(float *x_ptr, float *y_ptr)
{
	float temp = 0.0;
	temp = *x_ptr;
	*x_ptr = *y_ptr;
	*y_ptr = temp;
}

void swap2(unsigned long int x_addr, unsigned long int y_addr)
{
	float temp = 0.0;
	float *x_ptr = (float *) x_addr;
	float *y_ptr = (float *)y_addr;

	temp = *x_ptr;
	*x_ptr = *y_ptr;
	*y_ptr = temp;
}

void swap3(float &x, float &y)
{
	float temp = 0.0;
	temp = x;
	x = y;
	y = temp;
}

int main()
{
	float a = 5;
	float b = 7.1;
	float temp = 0.0;
	float * a_ptr = NULL;
	float *b_ptr = NULL;
	unsigned long int a_addr, b_addr;
	a_ptr = &a;
	b_ptr = & b;

	a_addr = (unsigned long int) a_ptr;
	b_addr = (unsigned long int) b_ptr;

	printf("Address of a = %08X  %08X \n", &a, a_ptr); //缺項補0, 強制8位數
	printf("Address of b = %0X  %0X \n", &b, b_ptr); // %x 的來源必須是unsigned其實我們應該做個轉型

	printf("Value of a = %f  %f \n", a, *a_ptr);
	printf("Value of b = %f  %f \n", b, *b_ptr);

	// temp = *a_ptr;   *a_ptr = *b_ptr; *b_ptr = temp;
	//swap(a_ptr, b_ptr);
	//swap2(a_addr, b_addr);
	swap3(a, b);

	printf("Value of a = %f  %f \n", a, *a_ptr);
	printf("Value of b = %f  %f \n", b, *b_ptr);
}