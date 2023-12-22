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
    Coach c;
    String t = c.changeCoach();
    c.dkcDeleteCoach(t, c.returnnameCoach(t));
}

