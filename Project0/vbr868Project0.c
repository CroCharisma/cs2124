#include <stdio.h>  //For input/output functions.
#include <stdlib.h> //For malloc, free, etc.
#include "Project0.h"  //Include our own header file for the Employee struct.


int main()
{
	int n = 0;
	char buffer[50] = "";
	//1.  Open the file Project0.txt and read in the first line of the file to determine how many Employees we need for our array, and use malloc() to dynamically allocate an array of this size.
	FILE *infile = fopen( "./Project0Input.txt", "r" );
	if( infile == NULL ){
		printf("%s", "ERROR FILE NO OPEN\n");
		return -1;
	}

	fscanf(infile,"%d\n", &n );

	Employee* list = (Employee*)malloc( n * sizeof( Employee ) );
	
	//2.  Use a loop to read the Employee information from Project0.txt and write the information to the entries of your array.  Suggestion:  read a single line of the file using fgets() then use sscanf() to parse out the variables from the line.  
	int i = 0;
	for( i = 0; i < n; i++ ){
		fgets( buffer, 50, infile );
		sscanf( buffer, "%s %d %lf", list[i].name, &(list[i].ID), &(list[i].rate));
	}
	//3.  Loop through your array and print out the employee information.  Each employee (name, ID, hourly rate) should be on a single line.  The name should be left justified in a column of width 10. 
	// The IDs are each 6 digits long so they can be printed with a single space after it.  The hourly rate should be printed to 2 decimal places.
	for( i = 0; i < n; i++ ){
		printf( "%-10s %d %.2lf\n", list[i].name, list[i].ID, list[i].rate);
	}

	free( list );
	return 0;
}