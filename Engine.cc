#include <iostream>
#include "Surface.h"
#include "Engine.h"

#include <string>
#include <cstdio>
#include <ctime>
#include <fstream>	

#include <vector>

Engine::Engine()
{
	int numGamesToPlay = 0;
	int edgeWeight = 0;
	printIntro();
	printStartMenu();
	std::cin >> numGamesToPlay;
	printWeightMenu();
	std::cin >> edgeWeight;
	//startMenuList(choice);
	createPetersenGraph(numGamesToPlay, edgeWeight);
}

void Engine::printIntro()
{
	std::cout << std::endl;
	std::cout << "Welcome to the Text-Based Graph Theory Logging Program" << std::endl;
	std::cout << "C++ Final for COSC 226 SP 2014" << std::endl;
	std::cout << "Kyle Rodgers" << std::endl;
}

void Engine::printStartMenu()
{
	std::cout << std::endl;
	std::cout << "This version plays a game with equal edge weight of a Petersen Graph" << std::endl;
	std::cout << std::endl;
	std::cout << "How many games would you like to play?: ";
}

void Engine::printWeightMenu()
{
	std::cout << std::endl;
	std::cout << "What weight would you like the edges to be?: ";
}

void Engine::parseMasterData()
{
	p1size = 0;
	p2size = 0;
	std::ifstream master;
	std::ofstream p1;
	std::ofstream p2;
	std::string master_data_path = "output_data/master_data.txt";
	std::string player1_data_path = "output_data/player1_moves.txt";
	std::string player2_data_path = "output_data/player2_moves.txt";
	master.open(master_data_path);
	p1.open(player1_data_path, std::ios_base::app);
	p2.open(player2_data_path, std::ios_base::app);
	std::string parseLine;
	//std::string::iterator iter = parseLine.end();
	while (std::getline(master, parseLine))
	{
		std::string::iterator iter = (parseLine.end()-1);
//		std::getline(master, parseLine);
		//std::cout << parseLine << std::endl;
		//std::cout << *(parseLine.end()-1) << "*" << std::endl;
		if (*(iter) == '1')
		{
			p1size++;
			parseLine.pop_back();
			parseLine.pop_back();
			p1 << parseLine << std::endl;
		}
		else if(*(iter) == '2')
		{
			p2size++;
			parseLine.pop_back();
			parseLine.pop_back();
			p2 << parseLine << std::endl;
		}
		master.clear();
	}
	p1.close();
	p2.close();
	master.close();	
}	

void Engine::dataAnalysis(int choice)
{
	std::ifstream p1;
	std::ifstream p2;
	std::ofstream results;
	std::string player1_data_path = "output_data/player1_moves.txt";
	std::string player2_data_path = "output_data/player2_moves.txt";
	std::string results_data_path = "output_data/results.txt";
	p1.open(player1_data_path);
	p2.open(player2_data_path);
	results.open(results_data_path);
	std::string testLine;
	int numberOfGamesPlayed = choice;
	std::cout << "-----------------------------------------------" << std::endl;
	results << "-----------------------------------------------" << std::endl;
	std::cout << "Game Analysis" << std::endl;
	results << "Game Analysis" << std::endl;
	std::cout << std::endl;
	results << std::endl;
	std::cout << "Of the " << numberOfGamesPlayed << " games played:" << std::endl;
	results << "Of the " << numberOfGamesPlayed << " games played:" << std::endl;
	std::cout << std::endl;
	results << std::endl;
	std::cout << "Player 1 won " << p1size << "." << std::endl;
	results << "Player 1 won " << p1size << "." << std::endl;
	std::cout << "Player 2 won " << p2size << "." << std::endl;
	results << "Player 2 won " << p2size << "." << std::endl;
	std::vector<std::string> player1moves;
	std::vector<std::string> player2moves;
	while (std::getline(p1, testLine))
	{
		std::vector<std::string>::iterator it = find(player1moves.begin(), player1moves.end(), testLine);
		if (it == player1moves.end())
			player1moves.push_back(testLine);
		testLine.clear();
	}
	while (std::getline(p2, testLine))
	{
		std::vector<std::string>::iterator it = find(player2moves.begin(), player2moves.end(), testLine);
		if (it == player2moves.end())
			player2moves.push_back(testLine);
		testLine.clear();
	}
	p1.close();
	p2.close();
	std::sort(player1moves.begin(), player1moves.end());
	std::sort(player2moves.begin(), player2moves.end());
	std::cout << std::endl;
	results << std::endl;
	std::cout << "There are " << player1moves.size() << " unique moves for Player 1." << std::endl;
	results << "There are " << player1moves.size() << " unique moves for Player 1." << std::endl;
	std::cout << "There are " << player2moves.size() << " unique moves for Player 2." << std::endl;
	results << "There are " << player2moves.size() << " unique moves for Player 2." << std::endl;
	std::cout << std::endl;
	results << std::endl;
	std::cout << "The following moves led to Player 1's victory:" << std::endl;
	results << "The following moves led to Player 1's victory:" << std::endl;
	for (std::vector<std::string>::iterator i = player1moves.begin(); i != player1moves.end(); i++)
	{
		std::cout << *i << std::endl;
		results << *i << std::endl;
	}
	std::cout << std::endl;
	results << std::endl;
	std::cout << "The following moves led to Player 2's victory:" << std::endl;
	results << "The following moves led to Player 2's victory:" << std::endl;
	for (std::vector<std::string>::iterator i = player2moves.begin(); i != player2moves.end(); i++)
	{
		std::cout << *i << std::endl;
		results << *i << std::endl;
	}
	std::cout << std::endl;
	results << std::endl;
	results.close();
}

void Engine::createPetersenGraph(int numGamesToPlay, int edgeWeight)
{
	std::clock_t startTime = clock();
	for (int i = 1; i <= numGamesToPlay; i++)
	{
		Surface *a = new Surface(i, edgeWeight);
		delete a;
	}
	parseMasterData();
	dataAnalysis(numGamesToPlay);
	//Surface *a = new Surface(choice);
	std::clock_t endTime = clock();
	std::clock_t timeDelta = endTime - startTime;
	double timeInSeconds = timeDelta / (double)CLOCKS_PER_SEC;
	int timeInDays = timeInSeconds / (60*60*24);
	int timeInHours = (timeInSeconds / (60*60)) - (timeInDays * 24);
	int timeInMinutes = (timeInSeconds / 60) - (timeInHours * 60);
	int secondsRemaining = (int)(timeInSeconds - (timeInMinutes * 60));
	std::cout << "Benchmark:" << std::endl;
	if (secondsRemaining == 0 && timeInMinutes == 0)
	{
		std::cout << "This calculation was quite quick!" << std::endl;
		std::cout << std::endl;
	}
	else if (secondsRemaining >= 10)
	{
		std::cout << "Time to completion: " << timeInMinutes << ":" << secondsRemaining << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Time to completion: " << timeInMinutes << ":0" << secondsRemaining << std::endl;
		std::cout << std::endl;
	}
	std::cout << "This calculation took exactly " << timeInSeconds << " seconds." << std::endl;		
	std::cout << std::endl;
	//delete a;
}