/**
	Core.h
	Contains functions that are called for main program and tests.
	@author Michael Henderson
	@version 1.0
*/
#ifndef CORE_H
#define CORE_H

#include <string>
using namespace std;

class Core{
public:
	/**
	Constructor
	@author Michael Henderson
	@version 1.0
	*/
	Core();

	/**
	Deconstructor
	@author Michael Henderson
	@version 1.0
	*/
	~Core();

	/**
	 Will generate a ordered linked list of grades as per assignment details.
	 @param: string - file path and name (C:\readme.txt)
	 @return: NIL
	 @author Michael Henderson
	 @version 1.0
	*/
	void generateOrderedGradeList( string );

	/**
	Tests to see if the function works correctly.
	@author Michael Henderson
	@version 1.0
	*/
	void myCompareTest();

	/**
	Tests hard coded list creation and prints results to console.
	@author Michael Henderson
	@version 1.0
	*/
	void createListHCTest();
};
#endif // CORE_H
