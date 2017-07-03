/**
	OrderedGradeList.cpp
	A bare bones custom ordered linked list class which is sorted by grade hightest to lowest,
	if grades are same sorted by lastame and then firstname alphabetically.
	@author Michael Henderson
	@version 1.0
*/
#include "OrderedGradeList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "string.h"
#include <iostream>

#include "Core.h"
using namespace std;

OrderedGradeList::OrderedGradeList()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

OrderedGradeList::~OrderedGradeList()
{
	destoryList();
}

void OrderedGradeList::initializeList()
{
	destoryList();
}

int OrderedGradeList::readFile(string fileName)
{
	int ret = 1;
	char buffer[256], lastName[256], firstName[256], grade[3];
	//char lastName[256];
	//char firstName[256];
	//char grade[3];
	int section = 0, lineNumber = 1, index = 0;
	char cc = '0';
	//char filePath[] = fileName;
	const char *filePath = fileName.c_str();

	//cout << "Opening File: " << filePath << "\n";

	FILE * file;

	file = fopen(filePath, "r");

	if (file == NULL) {
		ret = 0;
		cout << "Error opening file: " << filePath << endl;
		perror("Error opening file");
	} else {

		do {
			cc = getc(file);
			if (cc == '\n' || cc == ',' || cc == EOF) {

				buffer[index] = '\0';
				if (section == 0) {
					strcpy(lastName, buffer);
					//cout << lastName << " ";
				} else if (section == 1) {
					strcpy(firstName, buffer);
					//cout << firstName << " ";
				} else if (section == 2) {
					strcpy(grade, buffer);
					//cout << grade << "\n";
				} else {
					perror("To many sections Last name, First name, grade only");
				}

				index = 0;
				if (section == 2) {
					section = 0;
					//cout << lineNumber << " ";
					//A new record is about to be obtained, current data is added in correct position to list
					insertNode(lastName, firstName, atoi(grade));
					//if (rv == 0) {
						//printf("Error: Data was not added to list ()");
					//}
					//lineNumber++;
				} else {
					section++;
				}
			} else {
				if (cc != ' ') {
					buffer[index] = cc;
					index++;
				}
			}
		} while (cc != EOF);
		fclose(file);
	}
	return ret;
}

void OrderedGradeList::insertNode(string ln, string fn, int gd)
{
	bool found;
	Node *p, *current, *newNode;
	newNode = new Node;
	newNode->lastName = ln;
	newNode->firstName = fn;
	newNode->grade = gd;
	newNode->next = NULL;

	//if list is empty, newNode is the only node
	if (head == NULL) {
		head = newNode;
		tail = newNode;
		count++;
	} else {
		found = false;
		current = head;

		//Find its position
		while (current != NULL && !found) {

			//search the list
			if (gd > current->grade) {
				found = true;
			} else {
				// sort by lastname
				if (current->grade == gd) {
					if (myCompare(current->lastName, ln) == 1) {
						found = true;
					} else {
						// If they are equal sort by firstname
						if (ln.compare(current->lastName) == 0) {
							if (myCompare(current->firstName, fn) == 1)	{
								found = true;
							}
						}
					}
				}
				if (found != true) {
					p = current;
					current = current->next;
				}
			}
		}

		//Insert at its position
		if (current == head) {	//insert newNode before first
			newNode->next = head;
			head = newNode;
			count++;
		} else {
			p->next = newNode;
			newNode->next = current;

			if (current == NULL) {
				tail = newNode;
			}
			count++;
		}//end else
	}//end else
}

int OrderedGradeList::myCompare(string one, string two)
{
	int a = one.size();
	//int b = two.size();
	int w = 0, c = 0, r = 0;

	//cout << "one: " << one << " two: " << two << endl;
	while (w == 0) {
		if (c < a) {
			if (one[c] > two[c]) {
				//printf("one[%d]: %c > two[%d]: %c\n", c, one[c], c, two[c]);
				//cout << "Two: " << two << endl;
				//cout << "One: " << one << endl;
				r = 1;						//Return True.
				w = 1;						//close while.
			} else if (one[c] < two[c]) {
				r = 0;						//Return False.
				w = 1;						//close while.
			} else {
				c++;						// They are the same.
			}
		} else {
			w = 1; //exit while
		}
	}
	//cout << r << endl;
	return r;
}

void OrderedGradeList::printListFile(string fileName)
{
	
	//Start amend string to new file name.
	string nn = "-graded.txt";
	int i, c = 0;
	int cfns = fileName.size();
	int nns = nn.size();
	char newFileName[256];
	strncpy(newFileName, fileName.c_str(), sizeof(newFileName));
	int limit = cfns + nns - 4;				//Max number of charaters to join two file names minus .txt characters.
	for (i = cfns - 4; i < limit; i++) {	//i starts of where the '.'txt is / starts in original filename.
		newFileName[i] = nn[c];
		if (i == limit) {					
			newFileName[i] = '\0';
		}
		c++;
	}
	//End amend string to new file name.

	const char *ln, *fn;
	//cout << "Opening Write File: " << newFileName << "\n";

	FILE * file;

	file = fopen(newFileName, "w");

	if (file == NULL) {
		cout << "Error opening write file: " << newFileName << endl;
		perror("Error opening write file");
	} else {

		Node * current;
		current = head;

		while (current != NULL)	{
			ln = current->lastName.c_str();
			fn = current->firstName.c_str();
			fprintf(file, "%s, %s, %d\n", ln, fn, current->grade);
			current = current->next;
		}	
		fclose(file);
		cout << "Finished: created " << newFileName << endl;
	}
	
}

int OrderedGradeList::isEmpty()
{
	return (head == NULL);
}

int OrderedGradeList::length()
{
	return count;
}

void OrderedGradeList::destoryList()
{
	Node * temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	tail = NULL;
	count = 0;
}

void OrderedGradeList::printListConsole()
{
	Node * current;
	current = head;

	while ( current != NULL )
	{
		cout << current -> lastName << " " << current -> firstName << " " << current -> grade << endl;
		current = current -> next;
	}
}
