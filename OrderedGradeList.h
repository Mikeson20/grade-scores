/**
	OrderedGradeList.h
	A bare bones custom ordered linked list class which is sorted by grade hightest to lowest,
	if grades are same sorted by lastame and then firstname alphabetically.
	@author Michael Henderson
	@version 1.0
*/
#ifndef ORDEREDGRADELIST_H
#define ORDEREDGRADELIST_H

#include <string>
using namespace std;

typedef struct Node {
	string lastName;
	string firstName;
	int grade;
	Node * next;
	//Node * previous;

}Node;

class OrderedGradeList {

private:
	Node * head;
	Node * tail;
	int count;

public:
	/**
	Constructor
	@author Michael Henderson
	@version 1.0
	*/
	OrderedGradeList();

	/**
	Deconstructor
	@author Michael Henderson
	@version 1.0
	*/
	~OrderedGradeList();

	/**
	Will delete list nodes if it has them.
	@author Michael Henderson
	@version 1.0
	*/
	void initializeList();

	/**
	Will read file and a data to list line by line.
	@param: string - file path and name (C:\readme.txt)
	@return: int - 1 file opened, 0 file error
	@author Michael Henderson
	@version 1.0
	*/
	int readFile( string );

	/**
	Will do as function named.
	@param: string - lastname
	@param: string - firstname
	@param: int - grade
	@author Michael Henderson
	@version 1.0
	*/
	void insertNode( string, string, int );

	/**
	Will test whether string one is greater than string two by each character if so it exits immediately true, 
	if charaters are equal moves onto next character till the length of string one.
	If a character of string one is less the string two's, it exits immediately false
	@param: string - one
	@param: string - two
	@return: int - 1 string one higher otherwise 0
	@author Michael Henderson
	@version 1.0
	*/
	int myCompare( string, string );

	/**
	Will print list to file with "-graded" amend to original input filename.
	I.e C:\names.txt becomes C:\names-graded.txt 
	@param: string - source file path and name (C:\readme.txt)
	@author Michael Henderson
	@version 1.0
	*/
	void printListFile( string );

	/**
	Is empty
	@return: 1 - true, 0 - false
	@author Michael Henderson
	@version 1.0
	*/
	int isEmpty();

	/**
	Will generate a ordered linked list of grades as per assignment details.
	@return: int - count
	@author Michael Henderson
	@version 1.0
	*/
	int length();
	
	/**
	Will destory list.
	@author Michael Henderson
	@version 1.0
	*/
	void destoryList();

	/**
	Will print list console
	@author Michael Henderson
	@version 1.0
	*/
	void printListConsole();
};
#endif // ORDEREDGRADELIST_H

