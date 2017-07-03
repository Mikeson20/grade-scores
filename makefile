#Make file for grade-scores

all:	grade-scores.exe

grade-scores.exe:	Main.o OrderedGradeList.o Core.o
	g++ Main.o OrderedGradeList.o Core.o -o grade-scores
	
Main.o:	OrderedGradeList.h Core.h Main.cpp
	g++ -c Main.cpp 
	
Core.o:	Core.h Core.cpp
	g++ -c Core.cpp
	
OrderedGradeList.o:	OrderedGradeList.h OrderedGradeList.cpp 
	g++ -c OrderedGradeList.cpp
	
clean:
	-rm Main.o OrderedGradeList.o Core.o grade-scores.exe
	

	
	