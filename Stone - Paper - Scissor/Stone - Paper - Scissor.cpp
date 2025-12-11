/*
-----------------------------------------------------------------------
-------------------     Stone - Paper - Scissor  	-------------------
-----------------------------------------------------------------------
-|	Welcome to my first simple program :)
-|	This is my first time developing software, and the application was based
-|	on the following idea from Dr. Mohammed Abu HadhoÚd Roadmap course .

-|	PROBLEM : WRITE A SMALL GAME PROGRAM FOR Stone - Paper - Scissor

-|	Requirements:
-|		1) Ask For How Many Rounds Thw Game Will be ( 1 -> 10 ) ?
-|		2) Start Each Round Player Vs Computer
-|		3) Show The Results With Each Round
-|			If Player Choice == Computer Choice Return [ NO Winner & Yellow Screen ]
-|			If Player Choice Win Return [ Winner & Green Screen ]
-|			If Player Choice Loss Return [ Computer Winner & Red Screen ]
-|		4) After All Round Show Game Over The Print Game Result Them Ask The User
			if S/He Want To Play Again Y/N ?
-----------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;

// This Enum Key is defined as containing game options.
enum enGameChoice
{

	Stone = 1,
	Paper = 2,
	Scissor = 3

};

// This Enum key is defined as containing the winner options in the game.
enum enWinner
{

	Player = 1,
	Computer = 2,
	Draw = 3

};

// This structure was defined to contain information for each round played.
struct stRoundInfo
{

	short RoundNumber = 0;
	enGameChoice PlayerChoice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName = "";

};

// This structure was defined to contain all game information.
struct stGameResults {

	short GameRounds = 0;
	short PlayerWinnerTimes = 0;
	short ComputerWinnerTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string WinnerName = "";

};

// This function of type enWinner was defined to tell us who the ultimate winner of the game is.
enWinner WhoWinnerInGame(short PlayerTimes, short ComputerTimes)
{

	if (PlayerTimes == ComputerTimes)
		return enWinner::Draw;
	else if (PlayerTimes > ComputerTimes)
		return enWinner::Player;
	else
		return enWinner::Computer;

}

// This function of type String was defined to tell us the name of the winner.
string WinnerName(enWinner Winner)
{

	string arrWinnerName[3] = { "Player" , "Computer" , "No Winner" };
	return arrWinnerName[Winner - 1];

}

// This function of type stGameResults was defined to fill in the entire game results.
stGameResults FillGameResults(int GameRounds, short PlayerTimes, short ComputerTimes, short DrawTimes)
{

	stGameResults GameResults;

	GameResults.GameRounds = GameRounds;
	GameResults.PlayerWinnerTimes = PlayerTimes;
	GameResults.ComputerWinnerTimes = ComputerTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = WhoWinnerInGame(PlayerTimes, ComputerTimes);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);

	return GameResults;
}

// This function of type enWinner was defined to tell us who won the current round.
enWinner WhoWinnerinRound(stRoundInfo RoundInfo)
{

	if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
	{
		return enWinner::Draw;
	}

	switch (RoundInfo.PlayerChoice)
	{

	case enGameChoice::Stone:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper)
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Scissor)
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoice::Scissor:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone)
		{
			return enWinner::Computer;
		}
		break;

	}

	return enWinner::Player;

}

// This function returns the name of the option selected by the user or computer.
string ChoiceName(enGameChoice Choice)
{

	string arrChoiceName[3] = { "Stone" , "Paper" , "Scissor" };
	return arrChoiceName[Choice - 1];

}

// This feature displays a color on the screen according to whether it's won Player, Lost Player, or Draw.
void setWinnerScreenColor(enWinner Winner)
{

	//What Is Color :
	// Green => Player Winner
	// Red => Computer Winner
	// Yellow => It`s Draw 

	switch (Winner) {

	case enWinner::Player:
		system("color 2F"); // turn Green Screen
		break;

	case enWinner::Computer:
		system("color 4F"); // turn Red Screen
		cout << "\a";
		break;

	case enWinner::Draw:
		system("color 6F"); // turn Yellow Screen
		break;

	}

}

// This function prints the results of each round that is played.
void PrintResultRound(stRoundInfo RoundInfo)
{

	cout << "\n--------------Round[" << RoundInfo.RoundNumber << "]--------------\n\n";
	cout << "Player Choice : " << ChoiceName(RoundInfo.PlayerChoice) << endl;
	cout << "Computer Choice : " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Winner In Round : " << RoundInfo.WinnerName << endl;
	cout << "\n------------------------------------\n\n";

	setWinnerScreenColor(RoundInfo.Winner);
}

// This function ask the user which option they want.
enGameChoice ReadPlayerChoise()
{

	short Choise = 1;

	do {

		cout << "Waht You Need Choise [1] Stone | [2] Paper | [3] Scissor : ";
		cin >> Choise;

	} while (Choise <= 0 || Choise > 3);

	return enGameChoice(Choise);

}

// This function ask the user how many rounds they want to play against the computer.
short ReadHowManyRound()
{

	short Number = 1;

	do {
		cout << "How Many Round You Want Play (1 -> 10) : ";
		cin >> Number;
		cout << endl;
	} while (Number <= 0 || Number > 10);

	return Number;

}

// This function returns a random number each time from among the numbers specified within it.
int RandomNumber(int From, int To)
{

	// Function to generate a random number 

	int randNum = rand() % (To - From + 1) + From;
	return randNum;

}

// This function reselects the computer based on the function RandomNumber.
enGameChoice getComputerChoice()
{

	return (enGameChoice)RandomNumber(1, 3);

}

// This is the basic function that populates the information for each round,
// then gathers the information needed by the FillGameResult function,
// and then prints the round results using the PrintResultRound function.
stGameResults PlayGame(short HowManyRound)
{

	stRoundInfo RoundInfo;
	short PlayerWinnerTimes = 0, ComputerWinnerTimes = 0, DrawTimes = 0;

	for (short GameRound = 0; GameRound < HowManyRound; GameRound++) {

		cout << "Round [" << GameRound + 1 << "] Begins : " << endl;
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.PlayerChoice = ReadPlayerChoise();
		RoundInfo.ComputerChoice = getComputerChoice();
		RoundInfo.Winner = WhoWinnerinRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		//Count Times Win :
		if (RoundInfo.Winner == enWinner::Player)
			PlayerWinnerTimes++;
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWinnerTimes++;
		else
			DrawTimes++;

		PrintResultRound(RoundInfo);
	}

	return FillGameResults(HowManyRound, PlayerWinnerTimes, ComputerWinnerTimes, DrawTimes);

}


// This function prints a tab space according to the entered number.
string Tabs(short NumberOfTabs)
{

	string Tab = "";
	for (short i = 0; i < NumberOfTabs; i++) {
		Tab += "\t";
		cout << Tab;
	}
	return Tab;

}

// This function displays the game over screen.
void ShowGameOverScreen()
{

	cout << Tabs(2) << "--------------------------------------------------\n";
	cout << Tabs(2) << "		+++ Game Over +++\n";
	cout << Tabs(2) << "--------------------------------------------------\n\n";

}

// This function prints the complete final results of the game and identifies the ultimate winner.
void ShowFinalGameResults(stGameResults GameResults)
{

	cout << Tabs(2) << "-----------------[ Game Results ]----------------\n\n";
	cout << Tabs(2) << "Rounds Game : " << GameResults.GameRounds << endl;
	cout << Tabs(2) << "Number Player Won In Game : " << GameResults.PlayerWinnerTimes << endl;
	cout << Tabs(2) << "Number Computer Won In Game : " << GameResults.ComputerWinnerTimes << endl;
	cout << Tabs(2) << "Number Draw In Game : " << GameResults.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner : " << GameResults.WinnerName << "\n\n";
	cout << Tabs(2) << "--------------------------------------------------\n\n";

	setWinnerScreenColor(GameResults.GameWinner);

}

// This function erases all information on the screen and turns it black if the game is about to restart.
void ResetScreen() {

	system("cls");
	system("color 0F");

}

// This is where everything begins, all the processes and beautiful structures for producing the game.
void StartGame()
{

	char Again = 'Y';

	do {
		ResetScreen();
		stGameResults GameResults = PlayGame(ReadHowManyRound());
		ShowGameOverScreen();
		ShowFinalGameResults(GameResults);

		cout << endl << Tabs(5) << "Do You Want To Play Again ? Y/N : ";
		cin >> Again;
	} while (Again == 'Y' || Again == 'y');

}

// Run the program
int main() {

	// Fanction rand Need This Line to generator Random Number In C++ 
	srand((unsigned)time(NULL));

	StartGame();
	return 0;

}


/*

Proposed improvements :
	1)	Game level settings: easy, medium, hard
	2)	Improved response and performance speeds
	3)	Improved accuracy
	4)	Converting code into a game application using C# and Windows Forms

Thank you for making it this far.
This program was developed by Ali Talal Ibrahim on December 2nd.

 */