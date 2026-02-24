/*
-----------------------------------------------------------------------
-------------------      Stone - Paper - Scissor       -------------------
-----------------------------------------------------------------------
-|	Welcome to my first simple program :)
-|	PROBLEM : WRITE A SMALL GAME PROGRAM FOR Stone - Paper - Scissor
-----------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//-----------------------------------------------------------
// Enums & Structs
//-----------------------------------------------------------

enum enGameChoice
{
    Stone = 1, Paper = 2, Scissor = 3
};

enum enWinner
{
    Player = 1, Computer = 2, Draw = 3
};

struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice PlayerChoice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName = "";
};

struct stGameResults 
{
    short GameRounds = 0;
    short PlayerWinnerTimes = 0;
    short ComputerWinnerTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";
};

//-----------------------------------------------------------
// Helper Functions
//-----------------------------------------------------------

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

string ChoiceName(enGameChoice Choice)
{
    string arrChoiceName[3] = { "Stone", "Paper", "Scissor" };
    return arrChoiceName[Choice - 1];
}

string WinnerName(enWinner Winner)
{
    string arrWinnerName[3] = { "Player", "Computer", "No Winner" };
    return arrWinnerName[Winner - 1];
}

string Tabs(short NumberOfTabs)
{
    string Tab = "";
    for (short i = 0; i < NumberOfTabs; i++) {
        Tab += "\t";
    }
    return Tab;
}

void setWinnerScreenColor(enWinner Winner)
{
    switch (Winner) {
    case enWinner::Player:
        system("color 2F"); // Green
        break;
    case enWinner::Computer:
        system("color 4F"); // Red
        cout << "\a";       // Bell sound
        break;
    case enWinner::Draw:
        system("color 6F"); // Yellow
        break;
    }
}

void ResetScreen() 
{
    system("cls");
    system("color 0F");
}

//-----------------------------------------------------------
// Input Functions
//-----------------------------------------------------------

short ReadHowManyRound()
{
    short Number = 1;
    do {
        cout << "How Many Rounds You Want To Play (1 -> 10): ";
        cin >> Number;
    } while (Number <= 0 || Number > 10);
    return Number;
}

enGameChoice ReadPlayerChoise()
{
    short Choice = 1;
    do {
        cout << "\nWhat Do You Choose? [1] Stone, [2] Paper, [3] Scissor: ";
        cin >> Choice;
    } while (Choice <= 0 || Choice > 3);
    return (enGameChoice)Choice;
}

enGameChoice getComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}

//-----------------------------------------------------------
// Game Logic Functions
//-----------------------------------------------------------

enWinner WhoWinnerinRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
        return enWinner::Draw;

    switch (RoundInfo.PlayerChoice)
    {
    case enGameChoice::Stone:
        if (RoundInfo.ComputerChoice == enGameChoice::Paper) return enWinner::Computer;
        break;
    case enGameChoice::Paper:
        if (RoundInfo.ComputerChoice == enGameChoice::Scissor) return enWinner::Computer;
        break;
    case enGameChoice::Scissor:
        if (RoundInfo.ComputerChoice == enGameChoice::Stone) return enWinner::Computer;
        break;
    }
    return enWinner::Player;
}

enWinner WhoWinnerInGame(short PlayerTimes, short ComputerTimes)
{
    if (PlayerTimes == ComputerTimes)
        return enWinner::Draw;
    else if (PlayerTimes > ComputerTimes)
        return enWinner::Player;
    else
        return enWinner::Computer;
}

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

//-----------------------------------------------------------
// Screen Rendering Functions
//-----------------------------------------------------------

void PrintResultRound(stRoundInfo RoundInfo)
{
    cout << "\n-------------- Round [" << RoundInfo.RoundNumber << "] --------------\n";
    cout << "Player Choice   : " << ChoiceName(RoundInfo.PlayerChoice) << endl;
    cout << "Computer Choice : " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Winner In Round : [" << RoundInfo.WinnerName << "]" << endl;
    cout << "--------------------------------------------\n";
    setWinnerScreenColor(RoundInfo.Winner);
}

void ShowGameOverScreen()
{
    cout << "\n" << Tabs(2) << "--------------------------------------------------\n";
    cout << Tabs(2) << "                +++ Game Over +++\n";
    cout << Tabs(2) << "--------------------------------------------------\n";
}

void ShowFinalGameResults(stGameResults GameResults)
{
    cout << Tabs(2) << "-----------------[ Game Results ]----------------\n";
    cout << Tabs(2) << "Rounds Played        : " << GameResults.GameRounds << endl;
    cout << Tabs(2) << "Player Won Times     : " << GameResults.PlayerWinnerTimes << endl;
    cout << Tabs(2) << "Computer Won Times   : " << GameResults.ComputerWinnerTimes << endl;
    cout << Tabs(2) << "Draw Times           : " << GameResults.DrawTimes << endl;
    cout << Tabs(2) << "Final Game Winner    : " << GameResults.WinnerName << endl;
    cout << Tabs(2) << "--------------------------------------------------\n";
    setWinnerScreenColor(GameResults.GameWinner);
}

//-----------------------------------------------------------
// Main Game Flow
//-----------------------------------------------------------

stGameResults PlayGame(short HowManyRound)
{
    stRoundInfo RoundInfo;
    short PlayerWinnerTimes = 0, ComputerWinnerTimes = 0, DrawTimes = 0;

    for (short GameRound = 1; GameRound <= HowManyRound; GameRound++) {
        cout << "\nRound [" << GameRound << "] Begins:\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.PlayerChoice = ReadPlayerChoise();
        RoundInfo.ComputerChoice = getComputerChoice();
        RoundInfo.Winner = WhoWinnerinRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Player) PlayerWinnerTimes++;
        else if (RoundInfo.Winner == enWinner::Computer) ComputerWinnerTimes++;
        else DrawTimes++;

        PrintResultRound(RoundInfo);
    }
    return FillGameResults(HowManyRound, PlayerWinnerTimes, ComputerWinnerTimes, DrawTimes);
}

void StartGame()
{
    char Again = 'Y';
    do {
        ResetScreen();
        stGameResults GameResults = PlayGame(ReadHowManyRound());
        ShowGameOverScreen();
        ShowFinalGameResults(GameResults);

        cout << endl << Tabs(2) << "Do You Want To Play Again? Y/N: ";
        cin >> Again;
    } while (Again == 'Y' || Again == 'y');
}

int main() 
{
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}