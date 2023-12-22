#include "Human.h"
#include "../CTDL/Vector.h"
#include <fstream>
#ifndef PLAYER_H
#define PLAYER_H

class Player : public Human
{
private:
    int goal, numberClothes, yellowCard, redCard;
    String nameFootballTeam;

public:
    Player();
    Player(String, String, String, String, String, int, int = 0, int = 0, int = 0);
    ~Player();
    void show1();
    void show2();
    void updateInfor(String, String, String, String, int, int, int, String);
    int getGoal();
    void setGoal(int);
    int getNumberClothes();
    void setNumberClothes(int);
    void updateGoal(int);
    int getYellowCard();
    void setYellowCard(int);
    int getRedCard();
    void setRedCard(int);
    void setNameFootballTeam(String);
    String getNameFootballTeam();
    void savePlayerToFile(ofstream &, int = 0);
    void getAllPlayerFromFile();
    void enterInforPlayer();
    void updatePlayer();
    static bool cmp(Player, Player);
    static void sortAllPlayer();
    static void updatePlayerAfterMatch(String, int, int, int);
    // void dkcDeleteTeam(String);
    void deletePlayerById();
    void dkcdeletePlayer(String);
    void addPlayerFromFile();
    friend ostream &operator<<(ostream &, const Player &);
    void showPlayer();
    void showKing();
    Vector<String> nameKing();
    void showNamePlayer();
    void showIDPlayer();
    void resetPlayer(String, int);
    String getnamebyid(String id);
};
#endif