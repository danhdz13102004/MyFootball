#include "FootballTeam/Player.h"
#include "FootballTeam/Coach.h"
#include "FootballTeam/Team.h"
#include "FootballTeam/Human.h"
// #include "LapLich/Algorithm.cpp"
#include "Match/Match.h"
#include "Match/HistoryMatch.h"
#include "Algorithm.h"
#include "CTDL/String.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

main()
{
    for(int i = 0; i < 15; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
        cout << "hihi" << endl;
    }
}