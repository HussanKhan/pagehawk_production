// Create an object with certain datatypes
#include <stdio.h>


int main () {
	// Basically allows you to create your own datatype
	struct date
	{
		int month;
		int day;
		int year;
	};

	//////// You replace char or int with your struct, so 

	// today is the variable and it will hold 3 values
	// struct date today;
	// // Assign values
	// today.month = 5;
	// today.day = 15;
	// today.year = 2018;
	/////OR//////////
	struct date today = {5, 16, 2018};
	OR
	// struct date today = {.day = 16, .year = 2018};
	//use same method to access values
	printf(" Today is: %d/%d/%d\n", today.month, today.day, today.year);
} 