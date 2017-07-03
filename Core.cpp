/**
	Core.cpp
	Contains functions that are called for main program and tests.
	@author Michael Henderson
	@version 1.0
*/

#include "Core.h"
#include "OrderedGradeList.h"

//#include <stdio.h>
//#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

Core::Core() {}
Core::~Core() {}

void Core::generateOrderedGradeList(string fileName) {
	cout << "Generating Ordered Grade List." << endl;
	OrderedGradeList newList;
	int r = newList.readFile(fileName);
	if (r == 1) {
		newList.printListConsole();
		newList.printListFile(fileName);
	}
}

void Core::myCompareTest()
{
	int r = 0;
	int t = 0;
	string one, two;

	OrderedGradeList compareTest;

	cout << "Running myCompare Tests" << endl;
	//START BLOCK TEST 1
	t = 1;
	one = "a";
	two = "b";
	r = compareTest.myCompare(one, two);
	
	cout << "Test " << t << ": Is " << one << " > " << two << " == " << r;
	if (r == 0) {
		cout << " : PASS" << endl;
	} else {
		cout << " : FAIL" << endl;
	}
	//END BLOCK TEST 1

	//START BLOCK TEST 2
	t = 2;
	one = "b";
	two = "a";
	r = compareTest.myCompare(one, two);

	cout << "Test "<< t << ": Is " << one << " > " << two << " == " << r;
	if (r == 1) {
		cout << " : PASS" << endl;
	} else {
		cout << " : FAIL" << endl;
	}
	//END BLOCK TEST 2

	//START BLOCK TEST 3
	t = 3;
	one = "ab";
	two = "aa";
	r = compareTest.myCompare(one, two);

	cout << "Test " << t << ": Is " << one << " > " << two << " == " << r;
	if (r == 1) {
		cout << " : PASS" << endl;
	} else {
		cout << " : FAIL" << endl;
	}
	//END BLOCK TEST 3

	//START BLOCK TEST 4
	t = 4;
	one = "aa";
	two = "ab";
	r = compareTest.myCompare(one, two);

	cout << "Test " << t << ": Is " << one << " > " << two << " == " << r;
	if (r == 0) {
		cout << " : PASS" << endl;
	} else {
		cout << " : FAIL" << endl;
	}
	//END BLOCK TEST 4

	//START BLOCK TEST 5
	t = 5;
	one = "aa";
	two = "aa";
	r = compareTest.myCompare(one, two);

	cout << "Test " << t << ": Is " << one << " > " << two << " == " << r;
	if (r == 0) {
		cout << " : PASS" << endl;
	} else {
		cout << " : FAIL" << endl;
	}
	//END BLOCK TEST 5

	//START BLOCK TEST 6
	t = 6;
	one = "aac";
	two = "aab";
	r = compareTest.myCompare(one, two);

	cout << "Test " << t << ": Is " << one << " > " << two << " == " << r;
	if (r == 1) {
		cout << " : PASS" << endl;
	} else {
		cout << " : FAIL" << endl;
	}
	//END BLOCK TEST 6

	//START BLOCK TEST 7
	t = 7;
	one = "ALICE";
	two = "ANDY";
	r = compareTest.myCompare(one, two);

	cout << "Test " << t << ": Is " << one << " > " << two << " == " << r;
	if (r == 0) {
		cout << " : PASS" << endl;
	} else {
		cout << " : FAIL" << endl;
	}
	//END BLOCK TEST 7

	//START BLOCK TEST 8
	t = 8;
	one = "ALI";
	two = "ALICE";
	r = compareTest.myCompare(one, two);

	cout << "Test " << t << ": Is " << one << " > " << two << " == " << r;
	if (r == 0) {
		cout << " : PASS" << endl;
	} else {
		cout << " : FAIL" << endl;
	}
	//END BLOCK TEST 8

	//START BLOCK TEST 9
	t = 9;
	one = "ALICE";
	two = "ALI";
	r = compareTest.myCompare(one, two);

	cout << "Test " << t << ": Is " << one << " > " << two << " == " << r;
	if (r == 1) {
		cout << " : PASS" << endl;
	} else {
		cout << " : FAIL" << endl;
	}
	//END BLOCK TEST 9

	//START BLOCK TEST 10
	t = 10;
	one = "1";
	two = "2";
	r = compareTest.myCompare(one, two);

	cout << "Test " << t << ": Is " << one << " > " << two << " == " << r;
	if (r == 0) {
		cout << " : PASS" << endl;
	} else {
		cout << " : FAIL" << endl;
	}
	//END BLOCK TEST 10
}

void Core::createListHCTest()
{
	cout << "Testing linked list creation." << endl;
	OrderedGradeList hc;

	cout << "List is empty(TRUE): " << hc.isEmpty() << endl;
	cout << "List length(0): " << hc.length() << endl;
	cout << endl;

	hc.insertNode("a", "b", 1);
	hc.insertNode("aa", "b", 2);
	hc.insertNode("aa", "ba", 5);
	hc.insertNode("aa", "bab", 5);
	hc.insertNode("aa", "aba", 5);
	hc.insertNode("aa", "ba", 5);
	hc.insertNode("bee", "sally", 5);

	cout << "List is empty(FALSE): " << hc.isEmpty() << endl;
	cout << "List length(7): " << hc.length() << endl;
	hc.printListConsole();

	cout << endl;
	cout << "List is empty(FALSE): " << hc.isEmpty() << endl;
	cout << "List length(7): " << hc.length() << endl;
}
