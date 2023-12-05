#include <iostream>
#include "Player.h"
#include "Human.h"
#include "Coach.h"
#include "../CTDL/Vector.h"
#include "../CTDL/DBLL.h"
#include <String.h>
using namespace std;

#ifndef Team_H
#define Team_H

class Team
{
private:
    String idTeamFootball;
    String nameFootballTeam;
    DBLL<Player> listMember;
    Coach coach;
    int rank;
    int numberGoal;
    int numberLoseGoal;
    int point;
    int difference;

public:
    Team();
    Team(String, Coach, int, int, int, int);
    ~Team();
    DBLL<Player> getlistMember();
    void createNewFootballTeam();
    String getIdTeam();
    void setIdTeam(String);
    void showAllMemberOfTeam();
    void showALLInforOfTeam();
    void addPlayer(Player &);
    void addCoach(Coach &);
    void findPlayerByName();
    void findPlayerByNameFootballTeam();
    DBLL<Player> getListPlayerByNameFootballTeam(String);
    void findPlayerById();
    void dkcDeleteTeamwithPlayer(String);
    void dkcDeleteTeamwithCoach(String);
//    void deletePlayerById(ifstream &, ofstream &);
//    void deleteCoachById(ifstream &, ofstream &);
    void deleteTeamById();
    void saveTeamToFile(ofstream &, int = 0);
    String getSizeTeamFromFile();
    Coach getCoachByNameFootballTeam(String);
    void findCoachByNameFootballTeam();
    void findCoachByID();
    void findCoachByName();
    void updateTeam();

    // Chuan hoa ten -> ngUyen van a -> Nguyen Van A
    String standardizeName(String);
    void showRankOfTeam();
    void showInforOfCoach();
    void testFile();
    int String_to_int(String);
    String getNameFootballTeam();
    Team findTeamByName();
    Team getTeamById(String);
    Team getTeamByName(String);
    String getIdByNameTeam(String);
    void setListMember(DBLL<Player>);
    void setNameFootballTeam(String);
    static bool cmp(Team, Team);
    int getPoint();
    void setPoint(int);
    int getDifference();
    void setDifference(int);
    void sortRankAllTeam();
    void setRank(int);
    void setGoal(int);
    void setLoseGoal(int);
    int getGoal();
    int getLoseGoal();
    void updateTeamAfterMatch(String, int, int, int);
    void addTeamFromFile();
    void increaseNumberOfTeam(String,int = 1);
    void addPlayerToTeam();
    String nameTeambyId(String);
    void showTeam();
    void showchampion();
    void showNameTeam();
    // void setcolor(int);
    int getMaxIdFromFile();
    void showIDTeam();
    void resetInforOfTeam(String,int,int);
};

#endif