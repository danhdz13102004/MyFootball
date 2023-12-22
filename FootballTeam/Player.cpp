#include "Player.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <Windows.h>
#include <cstring>
#include "../CTDL/String.h"
#include "../CTDL/Vector.h"
#include "../PrintCenter.h"
using namespace std;

Player::Player(String id, String name, String date, String address, String nameTeam, int numberClothes, int goal, int yellowCard, int redCard)
    : Human(id, name, date, address)
{

    this->goal = goal;
    this->numberClothes = numberClothes;
    this->nameFootballTeam = this->standardizeName(nameTeam);
    this->redCard = redCard;
    this->yellowCard = yellowCard;
}
Player::Player()
{
}

Player::~Player()
{
}

bool Player::cmp(Player p1, Player p2)
{
    int g1 = p1.getGoal(), g2 = p2.getGoal();
    if (g1 != g2)
    {
        return g1 > g2;
    }
    else
    {
        int r1 = p1.getRedCard(), r2 = p2.getRedCard();
        if (r1 != r2)
            return r1 < r2;
        return p1.getYellowCard() < p2.getYellowCard();
    }
}

void Player::show1()
{
    char arrAge[10], numberClo[10], ylCard[10], rCard[10], goal[10], nameFbTeam[10];
    sprintf(arrAge, "%d", this->age);
    sprintf(numberClo, "%d", this->numberClothes);
    sprintf(ylCard, "%d", this->yellowCard);
    sprintf(rCard, "%d", this->redCard);
    sprintf(goal, "%d", this->goal);
    // sprintf(nameFbTeam, "%d", this->nameFootballTeam);
    String myage(arrAge);
    String myNumberClo(numberClo);
    String myYlCard(ylCard);
    String myRCard(rCard);
    String myGoal(goal);
    String id = "ID", tenct = "The name Player", date = "Date", add = "Address", age = "Age", numberclo = "NumberClother", yl = "YellowCard", r = "RedCard", go = "Goal", namefb = "The name football";
    int console = 120;
    int colum = (console - id.size() - tenct.size() - date.size() - add.size() - age.size() - numberclo.size() - yl.size() - r.size() - go.size() - namefb.size()) / 2;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << setw(colum - 4) << id << setw(colum) << tenct << setw(colum) << date << setw(colum) << add << setw(colum) << age << setw(colum) << numberclo << setw(colum) << yl << setw(colum) << r << setw(colum) << go << setw(colum) << namefb << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << setw(colum - 4) << this->id << setw(colum) << this->name << setw(colum) << this->dateOfBirth << setw(colum) << this->address << setw(colum) << myage << setw(colum) << myNumberClo << setw(colum) << myYlCard << setw(colum) << myRCard << setw(colum) << myGoal << setw(colum) << this->nameFootballTeam << endl;
}

void Player::show2()
{
    char arrAge[10], numberClo[10], ylCard[10], rCard[10], goal[10];
    sprintf(arrAge, "%d", this->age);
    sprintf(numberClo, "%d", this->numberClothes);
    sprintf(ylCard, "%d", this->yellowCard);
    sprintf(rCard, "%d", this->redCard);
    sprintf(goal, "%d", this->goal);
    String myage(arrAge);
    String myNumberClo(numberClo);
    String myYlCard(ylCard);
    String myRCard(rCard);
    String myGoal(goal);
    String id = "ID", tenct = "The name Player", date = "Date", add = "Address", age = "Age", numberclo = "NumberClother", yl = "YellowCard", r = "RedCard", go = "Goal", namefb = "The name football";
    int console = 120;
    int colum = (console - id.size() - tenct.size() - date.size() - add.size() - age.size() - numberclo.size() - yl.size() - r.size() - go.size() - namefb.size()) / 2;
    cout << setw(colum - 4) << this->id << setw(colum) << this->name << setw(colum) << this->dateOfBirth << setw(colum) << this->address << setw(colum) << myage << setw(colum) << myNumberClo << setw(colum) << myYlCard << setw(colum) << myRCard << setw(colum) << myGoal << setw(colum) << this->nameFootballTeam << endl;
    // cout << left << setw(10) << this->id + "," << setw(25) << this->name + "," << setw(17) << this->dateOfBirth + "," << setw(15) << this->address + "," << setw(15) << myage + "," << setw(15) << myNumberClo + "," << setw(15) << myYlCard + "," << setw(15) << myRCard + "," << setw(15) << myGoal + "," << setw(15) << this->nameFootballTeam << endl;
}

int Player::getGoal()
{
    return this->goal;
}

void Player::setGoal(int goal)
{
    this->goal = goal;
}

void Player::setNumberClothes(int number)
{
    this->numberClothes = number;
}

int Player::getNumberClothes()
{
    return this->numberClothes;
}

void Player::updateGoal(int newGoal)
{
    this->setGoal(newGoal);
}

void Player::savePlayerToFile(ofstream &o, int check)
{
    char arrAge[10], numberClo[10], ylCard[10], rCard[10], goal[10];
    sprintf(arrAge, "%d", this->age);
    sprintf(numberClo, "%d", this->numberClothes);
    sprintf(ylCard, "%d", this->yellowCard);
    sprintf(rCard, "%d", this->redCard);
    sprintf(goal, "%d", this->goal);
    String myage(arrAge);
    String myNumberClo(numberClo);
    String myYlCard(ylCard);
    String myRCard(rCard);
    String myGoal(goal);
    ifstream f("Player.txt");
    if (check == 0)
    {
        f.seekg(0, ios::end);
        if (f.tellg() == 0)
        {
            o << left << setw(10) << "ID" << setw(25) << "Ten cau thu" << setw(17) << "Ngay sinh" << setw(15) << "Dia chi" << setw(15) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(15) << "The do" << setw(15) << "Ban thang" << setw(15) << "Ten doi bong";
        }
        f.close();
    }
    if (check == 1)
    {
        o << left << setw(10) << "ID" << setw(25) << "Ten cau thu" << setw(17) << "Ngay sinh" << setw(15) << "Dia chi" << setw(15) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(15) << "The do" << setw(15) << "Ban thang" << setw(15) << "Ten doi bong";
    }

    if (o.is_open())
    {
        o << endl
          << left << setw(10) << this->id + "," << setw(25) << this->name + "," << setw(17) << this->dateOfBirth + "," << setw(15) << this->address + "," << setw(15) << myage + "," << setw(15) << myNumberClo + "," << setw(15) << myYlCard + "," << setw(15) << myRCard + "," << setw(15) << myGoal + "," << setw(15) << this->nameFootballTeam;
    }
}

void Player::getAllPlayerFromFile()
{
    ifstream i("Player.txt");
    if (i.is_open())
    {
        String tmp;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i] != ' ')
                    status = true;
                if (tmp[i] == ',')
                {
                    status = false;
                    check++;
                    continue;
                }
                if (check == 1 && status)
                    id = id + tmp[i];
                else if (check == 2 && status)
                    name = name + tmp[i];
                else if (check == 3 && status)
                    date = date + tmp[i];
                else if (check == 4 && status)
                    address = address + tmp[i];
                else if (check == 5 && status)
                    age = age + tmp[i];
                else if (check == 6 && status)
                    numberClo = numberClo + tmp[i];
                else if (check == 7 && status)
                    yellowCard = yellowCard + tmp[i];
                else if (check == 8 && status)
                    redCard = redCard + tmp[i];
                else if (check == 9 && status)
                    goal = goal + tmp[i];
                else if (check == 10 && status && tmp[i] != '\n')
                    nameTeam = nameTeam + tmp[i];
            }
            Player p(id, name, date, address, nameTeam, String::toint(numberClo), String::toint(goal), String::toint(yellowCard), String::toint(redCard));
            p.show();
            // cout << id << " " << name << " " << date << " " << address << " " <<  age << " " << numberClo << " " << yellowCard << " " << redCard << " " << goal <<  " " << nameTeam << endl;
        }
    }
}
void Player::setYellowCard(int ylcard)
{
    this->yellowCard = ylcard;
}

void Player::setRedCard(int rcard)
{
    this->redCard = rcard;
}

int Player::getYellowCard()
{
    return this->yellowCard;
}
int Player::getRedCard()
{
    return this->redCard;
}

void Player::enterInforPlayer()
{
    system("cls");
    String id, name, date, address, nameTeam;
    int numberClothes, goal, yellowCard, redCard;
    cout << "CREATE A NEW LEAGUE/Add a new team/Input data from the keyboard/Add player" << endl
         << endl;
    cout << "Enter citizen identification card: ";
    String::getline(cin, id);
    cout << "Enter the name: ";
    String::getline(cin, name);
    cout << "Enter the date (dd/mm/yyyy): ";
    String::getline(cin, date);
    if (date[1] == '/')
    {
        String tmp("0");
        date = tmp + date;
    }
    if (date[4] == '/')
        date.String::insert(3, "0");
    cout << "Enter the address: ";
    String::getline(cin, address);
    cout << "Enter the number clother: ";
    cin >> numberClothes;
    cin.ignore();
    // Cap nhat thong tin cau thu
    this->setId(id);
    this->setName(String::standadizeString(name));
    this->setDateOfBirth(date);
    this->setAddress(address);
    this->setAgeByDateOfBirth(date);
    this->setNumberClothes(numberClothes);
    this->setGoal(0);
    this->setYellowCard(0);
    this->setRedCard(0);
}

void Player::setNameFootballTeam(String nameFB)
{
    this->nameFootballTeam = nameFB;
}

String Player::getNameFootballTeam()
{
    return this->nameFootballTeam;
}

void Player::updatePlayer()
{
    bool kt = true;
    system("cls");
    String ma;
    cout << "LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Update coach information" << endl
         << endl;
    // cout << "The tournament consists of players with the following citizen identification card:" << endl;
    // showIDPlayer();
    showPlayer();
    cout << endl;
    cout << "Enter the citizen identification card: ";
    String::getline(cin, ma);
    fstream file("Player.txt", ios::in);
    fstream tempFile("tempPlayer.txt", ios::out | ios::app);
    tempFile << left << setw(10) << "ID" << setw(25) << "Ten cau thu" << setw(17) << "Ngay sinh" << setw(15) << "Dia chi" << setw(15) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(15) << "The do" << setw(15) << "Ban thang" << setw(15) << "Ten doi bong" << endl;
    if (file.is_open() && tempFile.is_open())
    {
        String tmp;
        String::getline(file, tmp);
        while (!file.eof())
        {
            String::getline(file, tmp);
            if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
            {
                break;
            }
            int check = 1;
            bool status = false;
            String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i] != ' ')
                    status = true;
                if (tmp[i] == ',')
                {
                    status = false;
                    check++;
                    continue;
                }
                if (check == 1 && status)
                    id = id + tmp[i];
                else if (check == 2 && status)
                    name = name + tmp[i];
                else if (check == 3 && status)
                    date = date + tmp[i];
                else if (check == 4 && status)
                    address = address + tmp[i];
                else if (check == 5 && status)
                    age = age + tmp[i];
                else if (check == 6 && status)
                    numberClo = numberClo + tmp[i];
                else if (check == 7 && status)
                    yellowCard = yellowCard + tmp[i];
                else if (check == 8 && status)
                    redCard = redCard + tmp[i];
                else if (check == 9 && status)
                    goal = goal + tmp[i];
                else if (check == 10 && status && tmp[i] != '\n')
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (ma == id)
            {
                kt = false;
                int u;
                do
                {
                    system("cls");
                    String newname1, newname, newdate, tmpnewdate, newadd, newnamefb;
                    int newage, newnum, newyl, newr, newg, d, m, y, year, month, day;
                    time_t ti = time(0);
                    tm *now = localtime(&ti);
                    printCentered("LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Update coach information");
                    cout << endl;
                    printCentered(drawBorder(50));
                    printCentered(drawOption("1. The player name.", 50));
                    printCentered(drawOption("2. The date.", 50));
                    printCentered(drawOption("3. The address.", 50));
                    printCentered(drawOption("4. The number clother.", 50));
                    printCentered(drawOption("5. The yellow card.", 50));
                    printCentered(drawOption("6. The red card.", 50));
                    // printCentered(drawOption("7. Chinh sua so ban thang cua cau thu.", 50));
                    printCentered(drawOption("0. Back.", 50));
                    printCentered(drawBorder(50));
                    printCentered("Please enter your choice: ", 0);
                    int t;
                    cin >> t;
                    cin.ignore();
                    switch (t)
                    {
                    case 1:
                        system("cls");
                        cout << "LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Update coach information/The player name" << endl
                             << endl;
                        cout << "Enter player name: ";
                        String::getline(cin, newname1);
                        newname = standardizeName(newname1);
                        name = newname;
                        break;
                    case 2:
                        system("cls");
                        cout << "LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Update coach information/The date" << endl
                             << endl;
                        cout << "Enter the date: ";
                        String::getline(cin, newdate);
                        if (newdate[1] == '/')
                        {
                            String tmp("0");
                            newdate = tmp + newdate;
                        }
                        if (newdate[4] == '/')
                            newdate.insert(3, "0");
                        date = newdate;
                        tmpnewdate = date;
                        d = 0;
                        m = 0;
                        y = 0;
                        for (int i = 0; i < tmpnewdate.size(); i++)
                        {
                            if (tmpnewdate[i] == '/')
                                continue;
                            if (i <= 2)
                                d = d * 10 + String::toint(tmpnewdate[i]);
                            else if (i <= 4)
                                m = m * 10 + String::toint(tmpnewdate[i]);
                            else if (i <= 9)
                                y = y * 10 + String::toint(tmpnewdate[i]);
                        }
                        year = now->tm_year + 1900;
                        month = now->tm_mon + 1;
                        day = now->tm_mday;
                        if (month > m)
                        {
                            newage = year - y;
                        }
                        else if (month < m)
                        {
                            newage = year - y - 1;
                        }
                        else
                        {
                            if (day >= d)
                            {
                                newage = year - y;
                            }
                            else
                            {
                                newage = year - y - 1;
                            }
                        }
                        age = String::tostring(newage);
                        break;
                    case 3:
                        system("cls");
                        cout << "LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Update coach information/The address" << endl
                             << endl;
                        cout << "Enter the address: ";
                        String::getline(cin, newadd);
                        address = newadd;
                        break;
                    case 4:
                        system("cls");
                        cout << "LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Update coach information/The number clother" << endl
                             << endl;
                        cout << "Enter the number clother: ";
                        cin >> newnum;
                        numberClo = String::tostring(newnum);
                        break;
                    case 5:
                        system("cls");
                        cout << "LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Update coach information/The yellow card" << endl
                             << endl;
                        cout << "Enter the yellow card: ";
                        cin >> newyl;
                        yellowCard = String::tostring(newyl);
                        break;
                    case 6:
                        system("cls");
                        cout << "LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Update coach information/The red card" << endl
                             << endl;
                        cout << "Enter the red card: ";
                        cin >> newr;
                        redCard = String::tostring(newr);
                        break;
                    case 0:
                        return;
                    default:
                        break;
                    }
                    // cout << "Press key 1 if you want to continue editing, press key 0 if you want to exit: ";
                    // cin >> u;
                } while (false);
                tempFile << left << setw(10) << id + "," << setw(25) << name + "," << setw(17) << date + "," << setw(15) << address + "," << setw(15) << age + "," << setw(15) << numberClo + "," << setw(15) << yellowCard + "," << setw(15) << redCard + "," << setw(15) << goal + "," << setw(15) << nameTeam << endl;
            }
            else
            {
                // kt = false;
                tempFile << tmp << endl;
            }
        }

        file.close();
        tempFile.close();
        remove("Player.txt");
        rename("tempPlayer.txt", "Player.txt");
    }
    else
        cout << "Failed";
    if (kt)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "Players have citizen identification card of " << ma << " not found!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }

    // cout << "Successfully updated" << endl;
    cout << "Press the Enter key to continue . .";
    getchar();
}

void Player::sortAllPlayer()
{
    Vector<Player> v;
    ifstream i("Player.txt");
    if (i.is_open())
    {
        String tmp;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i] != ' ')
                    status = true;
                if (tmp[i] == ',')
                {
                    status = false;
                    check++;
                    continue;
                }
                if (check == 1 && status)
                    id = id + tmp[i];
                else if (check == 2 && status)
                    name = name + tmp[i];
                else if (check == 3 && status)
                    date = date + tmp[i];
                else if (check == 4 && status)
                    address = address + tmp[i];
                else if (check == 5 && status)
                    age = age + tmp[i];
                else if (check == 6 && status)
                    numberClo = numberClo + tmp[i];
                else if (check == 7 && status)
                    yellowCard = yellowCard + tmp[i];
                else if (check == 8 && status)
                    redCard = redCard + tmp[i];
                else if (check == 9 && status)
                    goal = goal + tmp[i];
                else if (check == 10 && status && tmp[i] != '\n')
                    nameTeam = nameTeam + tmp[i];
            }
            Player p(id, name, date, address, nameTeam, String::toint(numberClo), String::toint(goal), String::toint(yellowCard), String::toint(redCard));
            v.push_back(p);
            // p.show();
        }
    }
    ofstream o("Tmp.txt");
    o << left << setw(10) << "ID" << setw(25) << "Ten cau thu" << setw(17) << "Ngay sinh" << setw(15) << "Dia chi" << setw(15) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(15) << "The do" << setw(15) << "Ban thang" << setw(15) << "Ten doi bong";
    Vector<Player>::sort(v, cmp);
    for (int i = 0; i < v.size(); i++)
        v[i].savePlayerToFile(o);
    o.close();
    i.close();
    const char *i1("Player.txt");
    const char *tmp1("Tmp.txt");
    remove(i1);
    rename(tmp1, "Player.txt");
}

void Player::updatePlayerAfterMatch(String idCheck, int ylCard, int rCard, int newGoal)
{
    ofstream o("Tmp.txt");
    o << left << setw(10) << "ID" << setw(25) << "Ten cau thu" << setw(17) << "Ngay sinh" << setw(15) << "Dia chi" << setw(15) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(15) << "The do" << setw(15) << "Ban thang" << setw(15) << "Ten doi bong";
    ifstream i("Player.txt");
    if (i.is_open())
    {
        String tmp;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
            if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
            {
                break;
            }
            int check = 1;
            bool status = false;
            String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i] != ' ')
                    status = true;
                if (tmp[i] == ',')
                {
                    status = false;
                    check++;
                    continue;
                }
                if (check == 1 && status)
                    id = id + tmp[i];
                else if (check == 2 && status)
                    name = name + tmp[i];
                else if (check == 3 && status)
                    date = date + tmp[i];
                else if (check == 4 && status)
                    address = address + tmp[i];
                else if (check == 5 && status)
                    age = age + tmp[i];
                else if (check == 6 && status)
                    numberClo = numberClo + tmp[i];
                else if (check == 7 && status)
                    yellowCard = yellowCard + tmp[i];
                else if (check == 8 && status)
                    redCard = redCard + tmp[i];
                else if (check == 9 && status)
                    goal = goal + tmp[i];
                else if (check == 10 && status && tmp[i] != '\n')
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            Player p(id, name, date, address, nameTeam, String::toint(numberClo), String::toint(goal), String::toint(yellowCard), String::toint(redCard));
            if (id == idCheck)
            {
                p.setYellowCard(String::toint(yellowCard) + ylCard);
                p.setRedCard(String::toint(redCard) + rCard);
                p.setGoal(String::toint(goal) + newGoal);
            }
            p.savePlayerToFile(o);
        }
    }
    o.close();
    i.close();
    const char *i1("Player.txt");
    const char *tmp1("Tmp.txt");
    remove(i1);
    rename(tmp1, "Player.txt");
}
void Player::resetPlayer(String idCheck, int g)
{
    ofstream o("Tmp.txt");
    o << left << setw(10) << "ID" << setw(25) << "Ten cau thu" << setw(17) << "Ngay sinh" << setw(15) << "Dia chi" << setw(15) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(15) << "The do" << setw(15) << "Ban thang" << setw(15) << "Ten doi bong";
    ifstream i("Player.txt");
    if (i.is_open())
    {
        String tmp;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i] != ' ')
                    status = true;
                if (tmp[i] == ',')
                {
                    status = false;
                    check++;
                    continue;
                }
                if (check == 1 && status)
                    id = id + tmp[i];
                else if (check == 2 && status)
                    name = name + tmp[i];
                else if (check == 3 && status)
                    date = date + tmp[i];
                else if (check == 4 && status)
                    address = address + tmp[i];
                else if (check == 5 && status)
                    age = age + tmp[i];
                else if (check == 6 && status)
                    numberClo = numberClo + tmp[i];
                else if (check == 7 && status)
                    yellowCard = yellowCard + tmp[i];
                else if (check == 8 && status)
                    redCard = redCard + tmp[i];
                else if (check == 9 && status)
                    goal = goal + tmp[i];
                else if (check == 10 && status && tmp[i] != '\n')
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            Player p(id, name, date, address, nameTeam, String::toint(numberClo), String::toint(goal), String::toint(yellowCard), String::toint(redCard));
            if (id == idCheck)
            {
                p.setGoal(String::toint(goal) - g);
            }
            p.savePlayerToFile(o);
        }
    }
    o.close();
    i.close();
    const char *i1("Player.txt");
    const char *tmp1("Tmp.txt");
    remove(i1);
    rename(tmp1, "Player.txt");
}
void Player::dkcdeletePlayer(String tt)
{
    int num;
    fstream file("Team.txt", ios::in);
    fstream tempFile("tempTeam.txt", ios::out | ios::app);
    tempFile << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Cau Thu," << setw(25) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Thu hang" << endl;
    if (file.is_open() && tempFile.is_open())
    {
        String tmp;
        String::getline(file, tmp);
        while (!file.eof())
        {
            String::getline(file, tmp);
            int check = 1;
            bool status = false;
            String id, nameTeam, numMember, nameCoach, numberGoal, numberLoseGoal, difference, point, rank;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i] != ' ')
                    status = true;
                if (tmp[i] == ',')
                {
                    status = false;
                    check++;
                    continue;
                }
                if (check == 1 && status)
                    id = id + tmp[i];
                else if (check == 2 && status)
                    nameTeam = nameTeam + tmp[i];
                else if (check == 3 && status)
                    numMember = numMember + tmp[i];
                else if (check == 4 && status)
                    nameCoach = nameCoach + tmp[i];
                else if (check == 5 && status)
                    numberGoal = numberGoal + tmp[i];
                else if (check == 6 && status)
                    numberLoseGoal = numberLoseGoal + tmp[i];
                else if (check == 7 && status)
                    difference = difference + tmp[i];
                else if (check == 8 && status)
                    point = point + tmp[i];
                else if (check == 9 && status && tmp[i] != '\n')
                {
                    rank = rank + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (tt == nameTeam)
            {
                num = String::toint(numMember) - 1;
                numMember = String::tostring(num);
                tempFile << left << setw(10) << id + "," << setw(20) << nameTeam + "," << setw(20) << numMember + "," << setw(25) << nameCoach + "," << setw(15) << numberGoal + "," << setw(15) << numberLoseGoal + "," << setw(15) << difference + "," << setw(15) << point + "," << setw(15) << rank << endl;
            }
            else
                tempFile << tmp << endl;
        }
        file.close();
        tempFile.close();
        remove("Team.txt");
        rename("tempTeam.txt", "Team.txt");
    }
    else
        cout << "Failed";
}

void Player::deletePlayerById()
{
    bool kt = true;
    system("cls");
    String ma, thaythe;
    cout << "LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Delete player information" << endl
         << endl;
    // cout << "The league includes players with the following citizen identification card:" << endl;
    // showIDPlayer();
    showPlayer();
    cout << endl;
    cout << "Enter the citizen identification card: ";
    String::getline(cin, ma);
    fstream file("Player.txt", ios::in);
    fstream tempFile("tempPlayer.txt", ios::out | ios::app);
    tempFile << left << setw(10) << "ID" << setw(25) << "Ten cau thu" << setw(17) << "Ngay sinh" << setw(15) << "Dia chi" << setw(15) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(15) << "The do" << setw(15) << "Ban thang" << setw(15) << "Ten doi bong" << endl;
    if (file.is_open() && tempFile.is_open())
    {
        String tmp;
        String::getline(file, tmp);
        while (!file.eof())
        {
            String::getline(file, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i] != ' ')
                    status = true;
                if (tmp[i] == ',')
                {
                    status = false;
                    check++;
                    continue;
                }
                if (check == 1 && status)
                    id = id + tmp[i];
                else if (check == 2 && status)
                    name = name + tmp[i];
                else if (check == 3 && status)
                    date = date + tmp[i];
                else if (check == 4 && status)
                    address = address + tmp[i];
                else if (check == 5 && status)
                    age = age + tmp[i];
                else if (check == 6 && status)
                    numberClo = numberClo + tmp[i];
                else if (check == 7 && status)
                    yellowCard = yellowCard + tmp[i];
                else if (check == 8 && status)
                    redCard = redCard + tmp[i];
                else if (check == 9 && status)
                    goal = goal + tmp[i];
                else if (check == 10 && status && tmp[i] != '\n')
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (ma == id)
            {
                kt = false;
                thaythe = nameTeam;
            }

            else
            {
                tempFile << tmp << endl;
                // kt = true;
            }
        }

        file.close();
        tempFile.close();
        remove("Player.txt");
        rename("tempPlayer.txt", "Player.txt");
    }
    else
        cout << "Failed";
    if (kt)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "The player has a citizen identification card " << ma << " not found" << endl
             << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }

    dkcdeletePlayer(thaythe);
    cout << "Deleted successfully" << endl;
    cout << "Press the Enter key to continue . .";
    getchar();
}
void Player::addPlayerFromFile()
{
    while (true)
    {
        char filename[256];
        cout << "Enter the file name containing the players: ";
        cin.getline(filename, 256);
        ifstream i(filename);
        if (i.is_open())
        {
            String tmp;
            String::getline(i, tmp);
            while (!i.eof())
            {
                String::getline(i, tmp);
                int check = 1;
                bool status = false;
                String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
                for (int i = 0; i < tmp.size(); i++)
                {
                    if (tmp[i] != ' ')
                        status = true;
                    if (tmp[i] == ',')
                    {
                        status = false;
                        check++;
                        continue;
                    }
                    if (check == 1 && status)
                        id = id + tmp[i];
                    else if (check == 2 && status)
                        name = name + tmp[i];
                    else if (check == 3 && status)
                        date = date + tmp[i];
                    else if (check == 4 && status)
                        address = address + tmp[i];
                    else if (check == 5 && status)
                        age = age + tmp[i];
                    else if (check == 6 && status)
                        numberClo = numberClo + tmp[i];
                    else if (check == 7 && status)
                        yellowCard = yellowCard + tmp[i];
                    else if (check == 8 && status)
                        redCard = redCard + tmp[i];
                    else if (check == 9 && status)
                        goal = goal + tmp[i];
                    else if (check == 10 && status && tmp[i] != '\n')
                        nameTeam = nameTeam + tmp[i];
                }
                Player p(id, name, date, address, nameTeam, String::toint(numberClo), String::toint(goal), String::toint(yellowCard), String::toint(redCard));
                ofstream o("Player.txt", ios::app);
                p.savePlayerToFile(o);
            }
            cout << "Data added successfully." << endl;
            return;
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "The file does not exist. Please enter again." << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }
    }
}

ostream &operator<<(ostream &o, const Player &p)
{
    // cout << left << setw(10) << "ID" << setw(25) << "Ten cau thu" << setw(17) << "Ngay sinh" << setw(15) << "Dia chi" << setw(15) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(15) << "The do" << setw(15) << "Ban thang" << setw(15) << "Ten doi bong";
    String id = "ID", tenct = "The name Player", date = "Date", add = "Address", age = "Age", numberclo = "NumberClother", yl = "YellowCard", r = "RedCard", goal = "Goal", namefb = "The name football";
    int console = 120;
    int colum = (console - id.size() - tenct.size() - date.size() - add.size() - age.size() - numberclo.size() - yl.size() - r.size() - goal.size() - namefb.size()) / 2;
    o << setw(colum - 4) << p.id << setw(colum) << p.name << setw(colum) << p.dateOfBirth << setw(colum) << p.address << setw(colum) << p.age << setw(colum) << p.numberClothes << setw(colum) << p.yellowCard << setw(colum) << p.redCard << setw(colum) << p.goal << setw(colum) << p.nameFootballTeam << endl;
    return o;
}

void Player::showIDPlayer()
{
    ifstream f("Player.txt");
    int lineCount = 0;
    String line;
    String::getline(f, line);
    while (!f.eof())
    {
        String::getline(f, line);
        lineCount++;
    }
    f.close();
    int dem = 0;
    ifstream file("Player.txt");
    String tmp;
    String::getline(file, tmp);
    // cout << left << setw(10) << "ID" << setw(15) << "Ten cau thu" << setw(15) << "Ngay sinh" << setw(20) << "Dia chi" << setw(10) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(10) << "The do" << setw(10) << "Ban thang" << setw(20) << "Ten doi bong" << endl;
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] != ' ')
                status = true;
            if (tmp[i] == ',')
            {
                status = false;
                check++;
                continue;
            }
            if (check == 1 && status)
                id = id + tmp[i];
            else if (check == 2 && status)
                name = name + tmp[i];
            else if (check == 3 && status)
                date = date + tmp[i];
            else if (check == 4 && status)
                address = address + tmp[i];
            else if (check == 5 && status)
                age = age + tmp[i];
            else if (check == 6 && status)
                numberClo = numberClo + tmp[i];
            else if (check == 7 && status)
                yellowCard = yellowCard + tmp[i];
            else if (check == 8 && status)
                redCard = redCard + tmp[i];
            else if (check == 9 && status)
                goal = goal + tmp[i];
            else if (check == 10 && status && tmp[i] != '\n')
            {
                nameTeam = nameTeam + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        dem++;
        if (lineCount == dem)
            cout << id;
        else
            cout << id << ", ";
    }
    file.close();
}

String Player::getnamebyid(String idb)
{
    ifstream file("Player.txt");
    String tmp;
    String::getline(file, tmp);
    String notf = "Not found";
    // cout << left << setw(10) << "ID" << setw(15) << "Ten cau thu" << setw(15) << "Ngay sinh" << setw(20) << "Dia chi" << setw(10) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(10) << "The do" << setw(10) << "Ban thang" << setw(20) << "Ten doi bong" << endl;
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] != ' ')
                status = true;
            if (tmp[i] == ',')
            {
                status = false;
                check++;
                continue;
            }
            if (check == 1 && status)
                id = id + tmp[i];
            else if (check == 2 && status)
                name = name + tmp[i];
            else if (check == 3 && status)
                date = date + tmp[i];
            else if (check == 4 && status)
                address = address + tmp[i];
            else if (check == 5 && status)
                age = age + tmp[i];
            else if (check == 6 && status)
                numberClo = numberClo + tmp[i];
            else if (check == 7 && status)
                yellowCard = yellowCard + tmp[i];
            else if (check == 8 && status)
                redCard = redCard + tmp[i];
            else if (check == 9 && status)
                goal = goal + tmp[i];
            else if (check == 10 && status && tmp[i] != '\n')
            {
                nameTeam = nameTeam + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        if (id == idb)
        {
            file.close();
            return name;
        }
    }
    file.close();
    return notf;
}

void Player::showNamePlayer()
{
    ifstream f("Player.txt");
    int lineCount = 0;
    String line;
    String::getline(f, line);
    while (!f.eof())
    {
        String::getline(f, line);
        lineCount++;
    }
    f.close();
    int dem = 0;
    ifstream file("Player.txt");
    String tmp;
    String::getline(file, tmp);
    // cout << left << setw(10) << "ID" << setw(15) << "Ten cau thu" << setw(15) << "Ngay sinh" << setw(20) << "Dia chi" << setw(10) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(10) << "The do" << setw(10) << "Ban thang" << setw(20) << "Ten doi bong" << endl;
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] != ' ')
                status = true;
            if (tmp[i] == ',')
            {
                status = false;
                check++;
                continue;
            }
            if (check == 1 && status)
                id = id + tmp[i];
            else if (check == 2 && status)
                name = name + tmp[i];
            else if (check == 3 && status)
                date = date + tmp[i];
            else if (check == 4 && status)
                address = address + tmp[i];
            else if (check == 5 && status)
                age = age + tmp[i];
            else if (check == 6 && status)
                numberClo = numberClo + tmp[i];
            else if (check == 7 && status)
                yellowCard = yellowCard + tmp[i];
            else if (check == 8 && status)
                redCard = redCard + tmp[i];
            else if (check == 9 && status)
                goal = goal + tmp[i];
            else if (check == 10 && status && tmp[i] != '\n')
            {
                nameTeam = nameTeam + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        dem++;
        if (lineCount == dem)
            cout << name;
        else
            cout << name << ", ";
    }
    file.close();
}

void Player::showPlayer()
{
    ifstream file("Player.txt");
    ofstream save("Savedata.txt", ios::out | ios::app);
    String tmp;
    String::getline(file, tmp);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    String id = "ID", tenct = "The name Player", date = "Date", add = "Address", age = "Age", numberclo = "NumberClother", yl = "YellowCard", r = "RedCard", go = "Goal", namefb = "The name football";
    int console = 120;
    int colum = (console - id.size() - tenct.size() - date.size() - add.size() - age.size() - numberclo.size() - yl.size() - r.size() - go.size() - namefb.size()) / 2;
    save << left << setw(colum - 4) << id << setw(colum) << tenct << setw(colum) << date << setw(colum) << add << setw(colum) << age << setw(colum) << numberclo << setw(colum) << yl << setw(colum) << r << setw(colum) << go << setw(colum) << namefb << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << setw(colum - 4) << id << setw(colum) << tenct << setw(colum) << date << setw(colum) << add << setw(colum) << age << setw(colum) << numberclo << setw(colum) << yl << setw(colum) << r << setw(colum) << go << setw(colum) << namefb << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    // cout << left << setw(10) << "ID" << setw(25) << "Ten cau thu" << setw(17) << "Ngay sinh" << setw(15) << "Dia chi" << setw(15) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(15) << "The do" << setw(15) << "Ban thang" << setw(15) << "Ten doi bong" << endl;
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] != ' ')
                status = true;
            if (tmp[i] == ',')
            {
                status = false;
                check++;
                continue;
            }
            if (check == 1 && status)
                id = id + tmp[i];
            else if (check == 2 && status)
                name = name + tmp[i];
            else if (check == 3 && status)
                date = date + tmp[i];
            else if (check == 4 && status)
                address = address + tmp[i];
            else if (check == 5 && status)
                age = age + tmp[i];
            else if (check == 6 && status)
                numberClo = numberClo + tmp[i];
            else if (check == 7 && status)
                yellowCard = yellowCard + tmp[i];
            else if (check == 8 && status)
                redCard = redCard + tmp[i];
            else if (check == 9 && status)
                goal = goal + tmp[i];
            else if (check == 10 && status && tmp[i] != '\n')
            {
                nameTeam = nameTeam + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        save << left << setw(colum - 4) << id << setw(colum) << name << setw(colum) << date << setw(colum) << address << setw(colum) << age << setw(colum) << numberClo << setw(colum) << yellowCard << setw(colum) << redCard << setw(colum) << goal << setw(colum) << nameTeam << endl;
        cout << setw(colum - 4) << id << setw(colum) << name << setw(colum) << date << setw(colum) << address << setw(colum) << age << setw(colum) << numberClo << setw(colum) << yellowCard << setw(colum) << redCard << setw(colum) << goal << setw(colum) << nameTeam << endl;
    }
    file.close();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

int maxgoal()
{
    int m = -1e9;
    ifstream i("Player.txt");
    if (i.is_open())
    {
        String tmp;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i] != ' ')
                    status = true;
                if (tmp[i] == ',')
                {
                    status = false;
                    check++;
                    continue;
                }
                if (check == 1 && status)
                    id = id + tmp[i];
                else if (check == 2 && status)
                    name = name + tmp[i];
                else if (check == 3 && status)
                    date = date + tmp[i];
                else if (check == 4 && status)
                    address = address + tmp[i];
                else if (check == 5 && status)
                    age = age + tmp[i];
                else if (check == 6 && status)
                    numberClo = numberClo + tmp[i];
                else if (check == 7 && status)
                    yellowCard = yellowCard + tmp[i];
                else if (check == 8 && status)
                    redCard = redCard + tmp[i];
                else if (check == 9 && status)
                    goal = goal + tmp[i];
                else if (check == 10 && status && tmp[i] != '\n')
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            m = max(m, String::toint(goal));
        }
    }
    i.close();
    return m;
}

void Player::showKing()
{
    ifstream file("Player.txt");
    ofstream save("Savedata.txt", ios::out | ios::app);
    String tmp;
    String::getline(file, tmp);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    String id = "ID", tenct = "The name Player", date = "Date", add = "Address", age = "Age", numberclo = "NumberClother", yl = "YellowCard", r = "RedCard", go = "Goal", namefb = "The name football";
    int console = 120;
    int colum = (console - id.size() - tenct.size() - date.size() - add.size() - age.size() - numberclo.size() - yl.size() - r.size() - go.size() - namefb.size()) / 2;
    save << left << setw(colum - 4) << id << setw(colum) << tenct << setw(colum) << date << setw(colum) << add << setw(colum) << age << setw(colum) << numberclo << setw(colum) << yl << setw(colum) << r << setw(colum) << go << setw(colum) << namefb << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << setw(colum - 4) << id << setw(colum) << tenct << setw(colum) << date << setw(colum) << add << setw(colum) << age << setw(colum) << numberclo << setw(colum) << yl << setw(colum) << r << setw(colum) << go << setw(colum) << namefb << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    // cout << left << setw(10) << "ID" << setw(25) << "Ten cau thu" << setw(17) << "Ngay sinh" << setw(15) << "Dia chi" << setw(15) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(15) << "The do" << setw(15) << "Ban thang" << setw(15) << "Ten doi bong" << endl;
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] != ' ')
                status = true;
            if (tmp[i] == ',')
            {
                status = false;
                check++;
                continue;
            }
            if (check == 1 && status)
                id = id + tmp[i];
            else if (check == 2 && status)
                name = name + tmp[i];
            else if (check == 3 && status)
                date = date + tmp[i];
            else if (check == 4 && status)
                address = address + tmp[i];
            else if (check == 5 && status)
                age = age + tmp[i];
            else if (check == 6 && status)
                numberClo = numberClo + tmp[i];
            else if (check == 7 && status)
                yellowCard = yellowCard + tmp[i];
            else if (check == 8 && status)
                redCard = redCard + tmp[i];
            else if (check == 9 && status)
                goal = goal + tmp[i];
            else if (check == 10 && status && tmp[i] != '\n')
            {
                nameTeam = nameTeam + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        if (goal == String::tostring(maxgoal()))
        {
            save << left << setw(colum - 4) << id << setw(colum) << name << setw(colum) << date << setw(colum) << address << setw(colum) << age << setw(colum) << numberClo << setw(colum) << yellowCard << setw(colum) << redCard << setw(colum) << goal << setw(colum) << nameTeam << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << setw(colum - 4) << id << setw(colum) << name << setw(colum) << date << setw(colum) << address << setw(colum) << age << setw(colum) << numberClo << setw(colum) << yellowCard << setw(colum) << redCard << setw(colum) << goal << setw(colum) << nameTeam << endl;
            // cout << left << setw(10) << id + "," << setw(25) << name + "," << setw(17) << date + "," << setw(15) << address + "," << setw(15) << age + "," << setw(15) << numberClo + "," << setw(15) << yellowCard + "," << setw(15) << redCard + "," << setw(15) << goal + "," << setw(15) << nameTeam << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }
        else
        {
            save << left << setw(colum - 4) << id << setw(colum) << name << setw(colum) << date << setw(colum) << address << setw(colum) << age << setw(colum) << numberClo << setw(colum) << yellowCard << setw(colum) << redCard << setw(colum) << goal << setw(colum) << nameTeam << endl;
            cout << setw(colum - 4) << id << setw(colum) << name << setw(colum) << date << setw(colum) << address << setw(colum) << age << setw(colum) << numberClo << setw(colum) << yellowCard << setw(colum) << redCard << setw(colum) << goal << setw(colum) << nameTeam << endl;
        }
    }
    file.close();
    save.close();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

Vector<String> Player::nameKing()
{
    Vector<String> a;
    ifstream file("Player.txt");
    String tmp;
    String::getline(file, tmp);
    // cout << left << setw(10) << "ID" << setw(25) << "Ten cau thu" << setw(17) << "Ngay sinh" << setw(15) << "Dia chi" << setw(15) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(15) << "The do" << setw(15) << "Ban thang" << setw(15) << "Ten doi bong" << endl;
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] != ' ')
                status = true;
            if (tmp[i] == ',')
            {
                status = false;
                check++;
                continue;
            }
            if (check == 1 && status)
                id = id + tmp[i];
            else if (check == 2 && status)
                name = name + tmp[i];
            else if (check == 3 && status)
                date = date + tmp[i];
            else if (check == 4 && status)
                address = address + tmp[i];
            else if (check == 5 && status)
                age = age + tmp[i];
            else if (check == 6 && status)
                numberClo = numberClo + tmp[i];
            else if (check == 7 && status)
                yellowCard = yellowCard + tmp[i];
            else if (check == 8 && status)
                redCard = redCard + tmp[i];
            else if (check == 9 && status)
                goal = goal + tmp[i];
            else if (check == 10 && status && tmp[i] != '\n')
            {
                nameTeam = nameTeam + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        if (goal == String::tostring(maxgoal()))
        {
            a.push_back(name);
        }
    }
    file.close();
    return a;
}