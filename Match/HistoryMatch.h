#include "Match.h"

class HistoryMatch : public Match
{
private:
    int numGoalTeam1, numGoalTeam2;

public:
    HistoryMatch();
    HistoryMatch(Match, int, int);
    ~HistoryMatch();
    void showHistoryMatch();
    void saveHistoryMatchToFile(ofstream &);
    void updateHistoryMatch();
    void updateHistoryMatch1();
    void updateGoalandLostGoalandDiffofTeam(String, String, String, String);
    void showHMbydate(String);
    void showHMbyidoneteam(String);
    void showHMbyidtwoteam(String, String);
    void showHMbyidround(String);
    String getGoal(String);
    String getLostGoal(String);
    void updatePoint(String, String);
    String getPoint(String);
    Vector<int> entergoal(String, String, String, int, int);
    String getgoalSavePlayer(String, String);
    String getbanthangbyPlayertxt(String);
    void editSavePlayer(String, String, String);
    void editGoalPlayertxt(String, String);
    void showdateHM();
    void showidHM();
    void showidvongHM();
    Vector<int> duyetsaveplayer();
    void chuyenhoa(String, String);
    void deleterPlayerafterchuyenhoa(String);
    static bool checkHistoryMatchExist(String,String,String);
    static void resetPointOfTeamAndDelelteHistoryMatch(String,String,String);
    static void resetGoalOfPlayerAndDeleteSavePlayer(String,String,String);
};
