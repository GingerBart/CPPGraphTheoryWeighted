#ifndef GUARD_Engine_h
#define GUARD_Engine_h

#include "Surface.h"

class Engine {
public:
	Engine();
	int p1size;
	int p2size;
	   
private:
	void printIntro();
	void printStartMenu();
	void printWeightMenu();
	void createPetersenGraph(int, int);
	void parseMasterData();
	void dataAnalysis(int);
};

#endif