/**
	Main.cpp
	Starter
	@author Michael Henderson
	@version 1.0
*/

//#include <stdio.h>
//#include <stdlib.h>
#include <string>
#include <iostream>

#include "Core.h"
using namespace std;

int main(int argc, char* argv[]) {
	string fileNamePath;

	if (argc == 2) {
		fileNamePath = argv[1];
		//cout << argv[1] << endl;
	} else {
		fileNamePath = "names.txt";
		cout << "No command line arguments.\nUsing: " << fileNamePath << endl;
		
	} 

	Core core;
	core.generateOrderedGradeList(fileNamePath);

	//core.myCompareTest();

	//core.createListHCTest();

	//system("PAUSE");
	return 0;
}