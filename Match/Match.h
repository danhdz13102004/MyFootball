#include "../FootballTeam/Team.h"
#include "../CTDL/Vector.h"
#include "../CTDL/String.h"
#include "../CTDL/DBLL.h"
#include "../PrintCenter.h"
#include <thread>
#include <chrono>
#ifndef MA_H
#define MA_H
class Match
{
private:
    DBLL<Team> v;
    String idRound;
    String address;
    String time;
    String date;

public:
    Match();
    Match(const Team &, const Team &, String, String, String);
    ~Match();
    void addTeam(const Team &);
    void showMatch();
    void changeAddress(String);
    void changeTime(String);
    DBLL<Team> getTwoTeam();
    String getAddress();
    void setAddress(String);
    String getTime();
    void setTime(String);
    void setDate(String);
    String getDate();
    void setIdRound(String);
    String getIdRound();
    DBLL<Match> getAllMatchFromFile();
    void findMatchByIdTeam();
    DBLL<Match> getListMatchByIdTeam();
    static Match getMatchByIdRoundAndIdTwoTeam(String, String, String);
    void deleteMatchByIdRoundAndTwoTeam(Match &);
    void findMatchByNameTeam();
    void findMatchByTwoNameTeam();
    void findMatchByDay();
    void updateInforOfMatch();
    void updateMatch(String, Match, int, String = "");
    String getIdTeam1();
    String getIdTeam2();
    void enterResultMatch();
    void saveToHistoryMatch(String, String, int, int);
    bool checkMatch(String, String, String);
    bool checkPlayer(String);
    void showPlayerofTeam(String);
    String returnNameTeamByID(String);
    bool checkidPlayerofTeam(String, String);
    void showdate();
    void showschedule();
    Match getMatchFromHistoryMatch(String,String,String);
};
#endif