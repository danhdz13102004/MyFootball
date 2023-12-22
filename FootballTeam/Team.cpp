
#include "Team.h"
#include <iomanip>
#include <limits>
// #include "../Library.h"
#include <Windows.h>
#include <fstream>
// #include <Windows.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"
#include "../PrintCenter.h"
Team::Team()
{
    // cout << "Tao t";
    // this->idTeamFootball = this->getSizeTeamFromFile();
    this->numberGoal = 0;
    this->numberLoseGoal = 0;
    this->rank = 1;
    this->point = 0;
    this->difference = 0;
}
Team::~Team()
{
}
bool Team::cmp(Team t1, Team t2)
{
    int p1 = t1.getPoint(), p2 = t2.getPoint();
    if (p1 != p2)
    {
        return p1 > p2;
    }
    return t1.getDifference() > t2.getDifference();
}
void Team::setGoal(int goal)
{
    this->numberGoal = goal;
}
void Team::setLoseGoal(int loseGoal)
{
    this->numberLoseGoal = loseGoal;
}

int Team::getPoint()
{
    return this->point;
}

void Team::setPoint(int point)
{
    this->point = point;
}

int Team::getDifference()
{
    return this->difference;
}

void Team::setDifference(int difference)
{
    this->difference = difference;
}
void Team::setRank(int rank)
{
    this->rank = rank;
}
int Team::getGoal()
{
    return this->numberGoal;
}
int Team::getLoseGoal()
{
    return this->numberLoseGoal;
}

String Team::getSizeTeamFromFile()
{
    ifstream f("Team.txt");
    int size = 0;
    if (f.is_open())
    {
        String tmp;
        String::getline(f, tmp);
        while (!f.eof())
        {
            String::getline(f, tmp);
            size++;
        }
    }
    char id[10];
    sprintf(id, "%d", size + 1);
    return String(id);
}

int Team::getMaxIdFromFile()
{
    ifstream f("Team.txt");
    int max = 0;
    if (f.is_open())
    {
        String tmp;
        String::getline(f, tmp);
        while (!f.eof())
        {
            String::getline(f, tmp);
            String s;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i] == ',')
                    break;
                s = s + tmp[i];
            }
            int s1 = String::toint(s);
            if (s1 > max)
                max = s1;
        }
    }
    return max;
}

Team::Team(String nameTeam, Coach coach, int rank, int numberGoal, int numberLoseGoal, int point)
{
    this->nameFootballTeam = nameTeam;
    this->coach = coach;
    this->rank = rank;
    this->numberGoal = numberGoal;
    this->numberLoseGoal = numberLoseGoal;
    this->point = point;
    this->difference = numberGoal - numberLoseGoal;
    this->idTeamFootball = this->getSizeTeamFromFile();
}
void Team::setIdTeam(String id)
{
    this->idTeamFootball = id;
}

String Team::getIdTeam()
{
    return this->idTeamFootball;
}

void Team::showAllMemberOfTeam()
{
    cout << endl
         << "Danh Sach Cau Thu" << endl;
    this->listMember.duyetxuoi();
}
DBLL<Player> Team::getlistMember()
{
    return listMember;
}

void Team::showALLInforOfTeam()
{
    system("cls");
    cout << "LEAGUE MANAGEMENT/Query information for teams, coaches, and players/Query information for a team" << endl
         << endl;
    // this_thread::sleep_for(chrono::milliseconds(100));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    cout << "The team name: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << this->nameFootballTeam << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    cout << "Information of coach:" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    this->coach.show();
    cout << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    cout << "Information of players:" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    String id = "ID", tenct = "The name Player", date = "Date", add = "Address", age = "Age", numberclo = "NumberClother", yl = "YellowCard", r = "RedCard", goal = "Goal", namefb = "The name football";
    int console = 120;
    int colum = (console - id.size() - tenct.size() - date.size() - add.size() - age.size() - numberclo.size() - yl.size() - r.size() - goal.size() - namefb.size()) / 2;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << setw(colum - 4) << id << setw(colum) << tenct << setw(colum) << date << setw(colum) << add << setw(colum) << age << setw(colum) << numberclo << setw(colum) << yl << setw(colum) << r << setw(colum) << goal << setw(colum) << namefb << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    this->listMember.duyetxuoi();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    cout << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    cout << "Rank: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << this->rank << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    cout << "Point: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << this->point << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    cout << "Difference: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << this->difference << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    cout << "NumberGoal: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << this->numberGoal << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    cout << "NumberLoseGoal: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << this->numberLoseGoal << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
// void Team::showHistoryMatch() {
//     this->supportTeam.duyetxuoi(this->head);
// }
void Team::addPlayer(Player &p)
{
    this->listMember.push_back(p);
}

void Team::addCoach(Coach &c)
{
    this->coach = c;
}

String Team::getNameFootballTeam()
{
    return this->nameFootballTeam;
}

void Team::setNameFootballTeam(String name)
{
    this->nameFootballTeam = name;
}

String Team::standardizeName(String s)
{
    String tmp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (i == 0)
            tmp = tmp + toupper(s[0]);
        else
        {
            if (s[i - 1] == ' ')
                tmp = tmp + toupper(s[i]);
            else
                tmp = tmp + tolower(s[i]);
        }
    }
    return tmp;
}

void Team::findPlayerByName()
{
    system("cls");
    cout << "LEAGUE MANAGEMENT/Query information for teams, coaches, and players/Query information for a player/By player name" << endl
         << endl;
    Player p;
    cout << "The league has the following players:" << endl;
    p.showNamePlayer();
    cout << endl;
    cout << "Enter the player name: ";
    String nameFind;
    String::getline(cin, nameFind);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    nameFind = String::standadizeString(nameFind);
    ifstream i("Player.txt");
    bool val = true;
    if (i.is_open())
    {
        String tmp, nameTeam;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, numberClo, yellowCard, redCard, goal;
            nameTeam = "";
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
                if (check > 2 && name != nameFind)
                    break;
            }
            if (name == nameFind)
            {
                Player p(id, name, date, address, nameTeam, String::toint(numberClo), String::toint(goal), String::toint(yellowCard), String::toint(redCard));
                // cout << this->nameFootballTeam << endl;
                p.show1();
                val = false;
            }
            // cout << id << " " << name << " " << date << " " << address << " " <<  age << " " << numberClo << " " << yellowCard << " " << redCard << " " << goal <<  " " << nameTeam << endl;
        }
    }
    if (val)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "The player name " << nameFind << " not found!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << endl;
    cout << "Press the Enter key to continue . .";
    getchar();
}

void Team::findPlayerByNameFootballTeam()
{
    system("cls");
    int k = 1;
    cout << "LEAGUE MANAGEMENT/Query information for teams, coaches, and players/Query information for a player/By team name" << endl
         << endl;
    cout << "The league has the following teams:" << endl;
    showNameTeam();
    cout << endl;
    cout << "Enter the team name: ";
    String nameFB;
    String::getline(cin, nameFB);
    nameFB = this->standardizeName(nameFB);
    bool val = true;
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
                else if (check == 10 && status)
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (nameTeam == nameFB)
            {
                if (k == 1)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
                    printCentered(drawBorder(202));
                    String id = "ID", tenct = "The name Player", date = "Date", add = "Address", age = "Age", numberclo = "NumberClother", yl = "YellowCard", r = "RedCard", goal = "Goal", namefb = "The name football";
                    int console = 120;
                    int colum = (console - id.size() - tenct.size() - date.size() - add.size() - age.size() - numberclo.size() - yl.size() - r.size() - goal.size() - namefb.size()) / 2;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    cout << setw(colum - 4) << id << setw(colum) << tenct << setw(colum) << date << setw(colum) << add << setw(colum) << age << setw(colum) << numberclo << setw(colum) << yl << setw(colum) << r << setw(colum) << goal << setw(colum) << namefb << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                    k++;
                }
                Player p(id, name, date, address, nameTeam, String::toint(numberClo), String::toint(goal), String::toint(yellowCard), String::toint(redCard));
                p.show2();
                val = false;
            }
            // cout << id << " " << name << " " << date << " " << address << " " <<  age << " " << numberClo << " " << yellowCard << " " << redCard << " " << goal <<  " " << nameTeam << endl;
        }
    }
    i.close();
    if (val)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "The team name " << nameFB << " not found!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << endl;
    cout << "Press the Enter key to continue . .";
    getchar();
}

DBLL<Player> Team::getListPlayerByNameFootballTeam(String nameFB)
{
    nameFB = this->standardizeName(nameFB);
    DBLL<Player> v;
    bool val = true;
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
                else if (check == 10 && status)
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            // cout << nameTeam <<" " << nameFB << endl;
            if (nameTeam == nameFB)
            {
                Player p(id, name, date, address, nameTeam, String::toint(numberClo), String::toint(goal), String::toint(yellowCard), String::toint(redCard));
                v.push_back(p);
                //  cout << "Func() : " ;p.show();
            }
            // cout << id << " " << name << " " << date << " " << address << " " <<  age << " " << numberClo << " " << yellowCard << " " << redCard << " " << goal <<  " " << nameTeam << endl;
        }
    }
    i.close();
    return v;
    // if(val) cout << "Khong tim thay ket qua!" << endl;
}

void Team::findPlayerById()
{
    system("cls");
    cout << "LEAGUE MANAGEMENT/Query information for teams, coaches, and players/Query information for a player/By citizen identity number" << endl
         << endl;
    cout << "The league has players with the following citizen identity number:" << endl;
    Player p;
    p.showIDPlayer();
    cout << endl;
    cout << "Enter the citizen identity number: ";
    String idPlayer;
    String::getline(cin, idPlayer);
    bool val = true;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
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
                else if (check == 10 && status)
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (id == idPlayer)
            {
                Player p(id, name, date, address, nameTeam, String::toint(numberClo), String::toint(goal), String::toint(yellowCard), String::toint(redCard));
                p.show1();
                val = false;
            }
            // cout << id << " " << name << " " << date << " " << address << " " <<  age << " " << numberClo << " " << yellowCard << " " << redCard << " " << goal <<  " " << nameTeam << endl;
        }
    }
    else
    {
        cout << "Failed" << endl;
    }
    i.close();
    if (val)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "The player has a citizen identity number of " << idPlayer << " not found!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << endl;
    cout << "Press the Enter key to continue . .";
    getchar();
}
void Team::createNewFootballTeam()
{
    system("cls");
    String nameFootballTeam;
    cout << "CREATE A NEW LEAGUE/Add a new team/Input data from the keyboard" << endl
         << endl;
    cout << "Enter the team name: ";
    String::getline(cin, nameFootballTeam);
    nameFootballTeam = String::standadizeString(nameFootballTeam);
    this->setNameFootballTeam(nameFootballTeam);
    int lc;
    do
    {
        system("cls");
        printCentered("CREATE A NEW LEAGUE/Add a new team/Input data from the keyboard");
        cout << endl;
        printCentered(drawBorder(50));
        printCentered(drawOption("1. Add player.", 50));
        printCentered(drawOption("2. Add coach(Maximum of 1 coach).", 50));
        printCentered(drawOption("0. Back.", 50));
        printCentered(drawBorder(50));
        printCentered("Please enter your choice: ", 0);
        cin >> lc;
        cin.ignore();
        if (lc == 1)
        {
            system("cls");
            Player p;
            p.enterInforPlayer();
            p.setNameFootballTeam(this->nameFootballTeam);
            ofstream o("Player.txt", ios::app);
            p.savePlayerToFile(o);
            this->listMember.push_back(p);
        }
        else if (lc == 2)
        {
            system("cls");
            Coach c;
            c.enterInforCoach();
            c.setNameFootballTeam(this->nameFootballTeam);
            ofstream o("Coach.txt", ios::app);
            c.saveInforIntoFile(o);
            this->coach = c;
        }
        else
        {
            cout << "Are you sure you want to exit(y/n)?";
            String ctn;
            String::getline(cin, ctn);
            if (ctn == "y" || ctn == "Y")
            {
                int s = this->getMaxIdFromFile() + 1;
                this->setIdTeam(String::tostring(s));
                // this->setIdTeam(this->getSizeTeamFromFile());
                ofstream o("Team.txt", ios::app);
                this->saveTeamToFile(o);
                break;
            }
        }
    } while (true);
}

/* void Team::deletePlayerById(ifstream &i, ofstream &tmp2)
{

    cout << "Nhap ID cua cau thu: ";
    String idPlayer;
    String::getline(cin, idPlayer);
    bool check = true;
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
                else if (check == 10 && status)
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (id != idPlayer)
            {
                Player p(id, name, date, address, nameTeam, String::toint(numberClo), String::toint(goal), String::toint(yellowCard), String::toint(redCard));
                p.savePlayerToFile(tmp2, 1);
            }
            // cout << id << " " << name << " " << date << " " << address << " " <<  age << " " << numberClo << " " << yellowCard << " " << redCard << " " << goal <<  " " << nameTeam << endl;
        }
    }
    i.close();
    tmp2.close();
    const char *i1("Player.txt");
    const char *tmp1("Tmp.txt");
    // Xoa file Player.txt chứa dữ liệu cũ
    remove(i1);
    // Đổi file Tmp.txt chứa dữ liệu mới thành file Player.txt
    rename(tmp1, "Player.txt");
} */

void Team::dkcDeleteTeamwithPlayer(String tt)
{
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
            // cout << tt;
            if (tt != nameTeam)
                tempFile << tmp << endl;
        }

        file.close();
        tempFile.close();
        remove("Player.txt");
        rename("tempPlayer.txt", "Player.txt");
    }
    else
        cout << "Failed";
}

void Team::dkcDeleteTeamwithCoach(String tt)
{
    fstream file("Coach.txt", ios::in);
    fstream tempFile("tempCoach.txt", ios::out | ios::app);
    tempFile << left << setw(10) << "ID" << setw(25) << "Ten HLV" << setw(17) << "Ngay sinh" << setw(15) << "Dia chi" << setw(15) << "Tuoi" << setw(15) << "Ten doi bong" << endl;

    if (file.is_open() && tempFile.is_open())
    {
        String tmp;
        String::getline(file, tmp);
        while (!file.eof())
        {
            String::getline(file, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, nameTeam;
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
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }

            if (tt != nameTeam)
                tempFile << tmp << endl;
        }
        file.close();
        tempFile.close();
        remove("Coach.txt");
        rename("tempCoach.txt", "Coach.txt");
    }
    else
    {
        cout << "Failed";
    }
}

void Team::deleteTeamById()
{
    bool ck = true;
    system("cls");
    String ma, thaythe;
    cout << "LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Delete team information" << endl
         << endl;
    showTeam();
    cout << endl;
    cout << "Enter the ID: ";
    String::getline(cin, ma);
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

            if (ma == id)
            {
                thaythe = nameTeam;
                ck = false;
            }

            else
            {
                tempFile << tmp << endl;
                // ck = true;
            }
        }
        file.close();
        tempFile.close();
        remove("Team.txt");
        rename("tempTeam.txt", "Team.txt");
    }
    else
        cout << "Failed";
    if (ck)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "Team has a ID of " << ma << " not found" << endl
             << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    dkcDeleteTeamwithPlayer(thaythe);
    dkcDeleteTeamwithCoach(thaythe);
    cout << "Deleted successfully" << endl;
    cout << "Press the Enter key to continue . .";
    getchar();
}

void Team::saveTeamToFile(ofstream &o, int check)
{
    char arrRank[10], numberGo[10], arrNumMember[10], numberLose[10], numPoint[10], numDiffer[10];
    sprintf(arrRank, "%d", this->rank);
    sprintf(numberGo, "%d", this->numberGoal);
    sprintf(arrNumMember, "%d", this->listMember.size());
    sprintf(numberLose, "%d", this->numberLoseGoal);
    sprintf(numPoint, "%d", this->point);
    sprintf(numDiffer, "%d", this->difference);
    String myRank(arrRank);
    String myGoal(numberGo);
    String myLoseGoal(numberLose);
    String myPoint(numPoint);
    String myDifference(numDiffer);
    String myNumMember(arrNumMember);
    ifstream f("Team.txt");
    f.seekg(0, ios::end);
    if (f.tellg() == 0)
    {
        o << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Cau Thu," << setw(25) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Thu hang";
        f.close();
    }
    if (check == 1)
    {
        o << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Cau Thu," << setw(25) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Thu hang";
    }
    if (o.is_open())
    {
        o << endl
          << left << setw(10) << this->idTeamFootball + "," << setw(20) << this->nameFootballTeam + "," << setw(20) << myNumMember + "," << setw(25) << this->coach.getName() + "," << setw(15) << myGoal + "," << setw(15) << myLoseGoal + "," << setw(15) << myDifference + "," << setw(15) << myPoint + "," << setw(15) << myRank;
    }
    else
    {
        cout << "Failed";
    }
}

Coach Team::getCoachByNameFootballTeam(String nameFB)
{
    ifstream i("Coach.txt");
    if (i.is_open())
    {
        String tmp;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, nameTeam;
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
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (nameFB == nameTeam)
            {
                Coach c(id, name, date, address, nameTeam);
                return c;
            }
        }
    }
    return Coach();
}
void Team::setListMember(DBLL<Player> v)
{
    this->listMember = v;
}

Team Team::findTeamByName()
{
    bool kt = true;
    cout << "LEAGUE MANAGEMENT/Query information for teams, coaches, and players/Query information for a team" << endl
         << endl;
    cout << "The league consists of the following teams:" << endl;
    showNameTeam();
    cout << endl;
    cout << "Enter team name: ";
    String tenDb;
    String::getline(cin, tenDb);
    tenDb = String::standadizeString(tenDb);
    cout << endl;
    ifstream i("Team.txt");
    if (i.is_open())
    {
        String tmp;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
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
            //  cout << nameTeam << " " << tenDb << endl;
            if (nameTeam == tenDb)
            {
                kt = false;
                Coach c = this->getCoachByNameFootballTeam(tenDb);
                Team t(nameTeam, c, String::toint(rank), String::toint(numberGoal), String::toint(numberLoseGoal), String::toint(point));
                t.setIdTeam(id);
                t.setListMember(this->getListPlayerByNameFootballTeam(nameTeam));
                t.showALLInforOfTeam();
                // cout << "Nhan Enter de tiep tuc ..."; getchar();
                // return t;
                // cout << id << " " << name << " " << date << " " << address << " " <<  age << " " << numberClo << " " << yellowCard << " " << redCard << " " << goal <<  " " << nameTeam << endl;
            }
        }
    }
    if (kt)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "Team " << tenDb << " not found!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    cout << "Press the Enter key to continue . .";
    String tmp;
    String::getline(cin, tmp);
    return Team();
}

Team Team::getTeamById(String idF)
{
    ifstream i("Team.txt");
    if (i.is_open())
    {
        String tmp;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
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
            //  cout << nameTeam << " " << tenDb << endl;
            if (id == idF)
            {
                Coach c = this->getCoachByNameFootballTeam(nameTeam);
                Team t(nameTeam, c, String::toint(rank), String::toint(numberGoal), String::toint(numberLoseGoal), String::toint(point));
                t.setIdTeam(id);
                t.setListMember(this->getListPlayerByNameFootballTeam(nameTeam));
                return t;
            }
        }
    }
    return Team();
}
Team Team::getTeamByName(String name)
{
    ifstream i("Team.txt");
    if (i.is_open())
    {
        String tmp;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
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
            //  cout << nameTeam << " " << tenDb << endl;
            if (nameTeam == name)
            {
                Coach c = this->getCoachByNameFootballTeam(nameTeam);
                Team t(nameTeam, c, String::toint(rank), String::toint(numberGoal), String::toint(numberLoseGoal), String::toint(point));
                t.setIdTeam(id);
                t.setListMember(this->getListPlayerByNameFootballTeam(nameTeam));
                return t;
            }
        }
    }
    Team tmp1;
    tmp1.setIdTeam("0");
    return tmp1;
}
String Team::getIdByNameTeam(String name)
{
    ifstream i("Team.txt");
    if (i.is_open())
    {
        String tmp;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
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
            //  cout << nameTeam << " " << tenDb << endl;
            if (nameTeam == name)
            {
                Coach c = this->getCoachByNameFootballTeam(nameTeam);
                Team t(nameTeam, c, String::toint(rank), String::toint(numberGoal), String::toint(numberLoseGoal), String::toint(point));
                t.setIdTeam(id);
                t.setListMember(this->getListPlayerByNameFootballTeam(nameTeam));
                return t.getIdTeam();
            }
        }
    }
    return "0";
}
void Team::showRankOfTeam()
{
    cout << setw(20) << "Doi Bong: " << this->nameFootballTeam << setw(20) << "Rank: " << this->rank << endl;
}

void Team::showInforOfCoach()
{
    this->coach.show();
}

void Team::testFile()
{
    // ifstream f("Player.txt");
    // if(f.is_open()) {
    //     cout << "Mo duoc" << endl;
    // }
    // else {
    //     cout << "Ko mo duoc" << endl;
    // }
    this->findPlayerById();
}
void Team::findCoachByNameFootballTeam()
{
    system("cls");
    bool kt = true;
    cout << "LEAGUE MANAGEMENT/Query information for teams, coaches, and players/Query information for a coach/By team name" << endl
         << endl;
    cout << "The league includes teams with the following names:" << endl;
    showNameTeam();
    cout << endl;
    cout << "Enter team name: ";
    String nameFB;
    String::getline(cin, nameFB);
    nameFB = String::standadizeString(nameFB);
    ifstream i("Coach.txt");
    String tmp;
    String::getline(i, tmp);
    if (i.is_open())
    {
        while (!i.eof())
        {
            String::getline(i, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, nameTeam;
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
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            // cout << nameTeam << " " << nameFB << endl;
            if (nameFB == nameTeam)
            {
                kt = false;
                Coach c(id, name, date, address, nameTeam);
                c.show();
            }
        }
    }
    if (kt)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "Team " << nameFB << " not found!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    cout << "Press the Enter key to continue . .";
    getchar();
}
void Team::findCoachByID()
{
    system("cls");
    bool kt = true;
    cout << "LEAGUE MANAGEMENT/Query information for teams, coaches, and players/Query information for a coach/By citizen identity number" << endl
         << endl;
    cout << "The tournament includes coaches with the following citizen identity numbers: " << endl;
    Coach c;
    c.showIDCoach();
    cout << endl;
    cout << "Enter the citizen identity number: ";
    String idHLV;
    String::getline(cin, idHLV);
    ifstream i("Coach.txt");
    String tmp;
    if (i.is_open())
    {
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, nameTeam;
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
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (idHLV == id)
            {
                kt = false;
                Coach c(id, name, date, address, nameTeam);
                c.show();
            }
        }
    }
    if (kt)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "Coach " << idHLV << " notfound" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    cout << "Press the Enter key to continue . .";
    getchar();
}

void Team::findCoachByName()
{
    system("cls");
    bool kt = true;
    cout << "LEAGUE MANAGEMENT/Query information for teams, coaches, and players/Query information for a coach/By coach name" << endl
         << endl;
    cout << "The league features the following coaches:" << endl;
    Coach t;
    t.showNameCoach();
    cout << endl;
    cout << "Enter coach name: ";
    String tenHLV;
    String::getline(cin, tenHLV);
    tenHLV = String::standadizeString(tenHLV);
    ifstream i("Coach.txt");
    String tmp;
    String::getline(i, tmp);
    if (i.is_open())
    {
        while (!i.eof())
        {
            String::getline(i, tmp);
            int check = 1;
            bool status = false;
            String id, name, date, address, age, nameTeam;
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
                {
                    nameTeam = nameTeam + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (tenHLV == name)
            {
                kt = false;
                Coach c(id, name, date, address, nameTeam);
                c.show();
            }
        }
    }
    if (kt)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "Coach " << tenHLV << " not found" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    cout << "Press the Enter key to continue . .";
    getchar();
}
void Team::updateTeam()
{
    bool ktra = true;
    system("cls");
    String ma;
    cout << "LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Edit team information/Modify team information" << endl
         << endl;
    showTeam();
    cout << endl;
    cout << "Enter the ID: ";
    String::getline(cin, ma);
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
            if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
            {
                break;
            }
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
            if (ma == id)
            {
                ktra = false;
                int u;
                do
                {
                    system("cls");
                    String newnamet, newname;
                    int newgoal, newlgoal, newhso, newpoint, newrank;
                    printCentered("LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Edit team information/Modify team information");
                    cout << endl;
                    printCentered(drawBorder(50));
                    printCentered(drawOption("1. The team name.", 50));
                    printCentered(drawOption("2. Total goal.", 50));
                    printCentered(drawOption("3. Total losegoal.", 50));
                    printCentered(drawOption("4. Number difference.", 50));
                    printCentered(drawOption("5. Score.", 50));
                    printCentered(drawOption("6. Rank.", 50));
                    printCentered(drawOption("0. Back.", 50));
                    printCentered(drawBorder(50));
                    printCentered("Please enter your choice: ", 0);
                    int t;
                    cin >> t;
                    cin.ignore();
                    int kt;
                    bool trangthai;
                    fstream file1("Coach.txt", ios::in);
                    fstream tempFile1("tempCoach.txt", ios::out | ios::app);
                    int kiemtra;
                    bool tt;
                    fstream file2("Player.txt", ios::in);
                    fstream tempFile2("tempPlayer.txt", ios::out | ios::app);
                    String thaythe;
                    switch (t)
                    {
                    case 1:
                        system("cls");
                        thaythe = nameTeam;
                        cout << "LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Edit team information/Modify team information/The team name" << endl
                             << endl;
                        cout << "Enter the team name: ";
                        String::getline(cin, newnamet);
                        newname = standardizeName(newnamet);
                        nameTeam = newname;

                        tempFile1 << left << setw(10) << "ID" << setw(25) << "Ten HLV" << setw(17) << "Ngay sinh" << setw(15) << "Dia chi" << setw(15) << "Tuoi" << setw(15) << "Ten doi bong" << endl;

                        if (file1.is_open() && tempFile1.is_open())
                        {
                            String temp;
                            String::getline(file1, temp);
                            while (!file1.eof())
                            {
                                String::getline(file1, temp);
                                kt = 1;
                                trangthai = false;
                                String idc, namec, datec, addressc, agec, nameTeamc;
                                for (int i = 0; i < temp.size(); i++)
                                {
                                    if (temp[i] != ' ')
                                        trangthai = true;
                                    if (temp[i] == ',')
                                    {
                                        trangthai = false;
                                        kt++;
                                        continue;
                                    }
                                    if (kt == 1 && trangthai)
                                        idc = idc + temp[i];
                                    else if (kt == 2 && trangthai)
                                        namec = namec + temp[i];
                                    else if (kt == 3 && trangthai)
                                        datec = datec + temp[i];
                                    else if (kt == 4 && trangthai)
                                        addressc = addressc + temp[i];
                                    else if (kt == 5 && trangthai)
                                        agec = agec + temp[i];
                                    else if (kt == 6 && trangthai)
                                    {
                                        nameTeamc = nameTeamc + temp[i];
                                        if ((temp[i + 1] == ' ' && temp[i + 2] == ' ') || (temp[i + 1] == ' ' && i + 1 == temp.size() - 1))
                                            break;
                                    }
                                }

                                if (thaythe == nameTeamc)
                                {
                                    nameTeamc = newname;
                                    // Ghi du lieu da sua vo file tam
                                    tempFile1 << left << setw(10) << idc + "," << setw(25) << namec + "," << setw(17) << datec + "," << setw(15) << addressc + "," << setw(15) << agec + "," << setw(15) << nameTeamc << endl;
                                }
                                else
                                {
                                    // Ghi du lieu cua may thang ko cap nhat
                                    tempFile1 << temp << endl;
                                }
                            }
                            file1.close();
                            tempFile1.close();
                            remove("Coach.txt");
                            rename("tempCoach.txt", "Coach.txt");
                        }
                        else
                        {
                            cout << "Failed!";
                        }

                        tempFile2 << left << setw(10) << "ID" << setw(25) << "Ten cau thu" << setw(17) << "Ngay sinh" << setw(15) << "Dia chi" << setw(15) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(15) << "The do" << setw(15) << "Ban thang" << setw(15) << "Ten doi bong" << endl;
                        if (file2.is_open() && tempFile2.is_open())
                        {
                            String tam;
                            String::getline(file2, tam);
                            while (!file2.eof())
                            {
                                String::getline(file2, tam);
                                kiemtra = 1;
                                tt = false;
                                String idp, namep, datep, addressp, agep, numberClop, yellowCardp, redCardp, goalp, nameTeamp;
                                for (int i = 0; i < tam.size(); i++)
                                {
                                    if (tam[i] != ' ')
                                        tt = true;
                                    if (tam[i] == ',')
                                    {
                                        tt = false;
                                        kiemtra++;
                                        continue;
                                    }
                                    if (kiemtra == 1 && tt)
                                        idp = idp + tam[i];
                                    else if (kiemtra == 2 && tt)
                                        namep = namep + tam[i];
                                    else if (kiemtra == 3 && tt)
                                        datep = datep + tam[i];
                                    else if (kiemtra == 4 && tt)
                                        addressp = addressp + tam[i];
                                    else if (kiemtra == 5 && tt)
                                        agep = agep + tam[i];
                                    else if (kiemtra == 6 && tt)
                                        numberClop = numberClop + tam[i];
                                    else if (kiemtra == 7 && tt)
                                        yellowCardp = yellowCardp + tam[i];
                                    else if (kiemtra == 8 && tt)
                                        redCardp = redCardp + tam[i];
                                    else if (kiemtra == 9 && tt)
                                        goalp = goalp + tam[i];
                                    else if (kiemtra == 10 && tt && tam[i] != '\n')
                                    {
                                        nameTeamp = nameTeamp + tam[i];
                                        if ((tam[i + 1] == ' ' && tam[i + 2] == ' ') || (tam[i + 1] == ' ' && i + 1 == tam.size() - 1))
                                            break;
                                    }
                                }
                                if (thaythe == nameTeamp)
                                {
                                    nameTeamp = newname;

                                    tempFile2 << left << setw(10) << idp + "," << setw(25) << namep + "," << setw(17) << datep + "," << setw(15) << addressp + "," << setw(15) << agep + "," << setw(15) << numberClop + "," << setw(15) << yellowCardp + "," << setw(15) << redCardp + "," << setw(15) << goalp + "," << setw(15) << nameTeamp << endl;
                                }
                                else
                                {
                                    tempFile2 << tam << endl;
                                }
                            }
                            file2.close();
                            tempFile2.close();
                            remove("Player.txt");
                            rename("tempPlayer.txt", "Player.txt");
                        }
                        else
                            cout << "Failed";

                        break;
                    // case 2:
                    //     cout << "Nhap Ten HLV: ";
                    //     getline(cin, newhlv);
                    //     nameCoach = newhlv;
                    //     break;
                    case 2:
                        system("cls");
                        cout << "LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Edit team information/Modify team information/Total goal" << endl
                             << endl;
                        cout << "Enter the total goal: ";
                        cin >> newgoal;
                        numberGoal = String::tostring(newgoal);
                        break;
                    case 3:
                        system("cls");
                        cout << "LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Edit team information/Modify team information/Total losegoal" << endl
                             << endl;
                        cout << "Enter the total losegoal: ";
                        cin >> newlgoal;
                        numberLoseGoal = String::tostring(newlgoal);
                        break;
                    case 4:
                        system("cls");
                        cout << "LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Edit team information/Modify team information/Number difference" << endl
                             << endl;
                        cout << "Enter the nummber difference: ";
                        cin >> newhso;
                        difference = String::tostring(newhso);
                        break;
                    case 5:
                        system("cls");
                        cout << "LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Edit team information/Modify team information/Score" << endl
                             << endl;
                        cout << "Enter the score: ";
                        cin >> newpoint;
                        point = String::tostring(newpoint);
                        break;
                    case 6:
                        system("cls");
                        cout << "LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Edit team information/Modify team information/Rank" << endl
                             << endl;
                        cout << "Enter the rank: ";
                        cin >> newrank;
                        rank = String::tostring(newrank);
                        break;
                    case 0:
                        return;
                    default:
                        break;
                    }
                    // cout << "Press key 1 if you want to continue editing, press key 0 if you want to exit: ";
                    // cin >> u;
                } while (false);
                tempFile << left << setw(10) << id + "," << setw(20) << nameTeam + "," << setw(20) << numMember + "," << setw(25) << nameCoach + "," << setw(15) << numberGoal + "," << setw(15) << numberLoseGoal + "," << setw(15) << difference + "," << setw(15) << point + "," << setw(15) << rank << endl;
            }
            else
            {
                tempFile << tmp << endl;
            }
        }
        file.close();
        tempFile.close();
        remove("Team.txt");
        rename("tempTeam.txt", "Team.txt");
    }
    else
        cout << "Failed";
    if (ktra)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "The team has ID " << ma << " not found!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
}
void Team::sortRankAllTeam()
{
    Vector<Team> v;
    ifstream i("Team.txt");
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
            // cout << tmp << " " << tmp.size() << endl;
            Coach c = this->getCoachByNameFootballTeam(nameTeam);
            Team t(nameTeam, c, String::toint(rank), String::toint(numberGoal), String::toint(numberLoseGoal), String::toint(point));
            t.setIdTeam(id);
            t.setListMember(this->getListPlayerByNameFootballTeam(nameTeam));
            v.push_back(t);
        }
    }
    ofstream o("Tmp.txt");
    Vector<Team>::sort(v, cmp);
    o << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Cau Thu," << setw(25) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Thu hang";
    for (int i = 0; i < v.size(); i++)
    {
        v[i].setRank(i + 1);
        v[i].saveTeamToFile(o);
    }
    o.close();
    i.close();
    const char *i1("Team.txt");
    const char *tmp1("Tmp.txt");
    remove(i1);
    rename(tmp1, "Team.txt");
}

void Team::updateTeamAfterMatch(String idCheck, int goal, int loseGoal, int bonusPoint)
{
    ifstream i("Team.txt");
    ofstream o("Tmp.txt");
    o << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Cau Thu," << setw(25) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Thu hang";
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
            Coach c = this->getCoachByNameFootballTeam(nameTeam);
            Team t(nameTeam, c, String::toint(rank), String::toint(numberGoal), String::toint(numberLoseGoal), String::toint(point));
            t.setIdTeam(id);
            t.setListMember(this->getListPlayerByNameFootballTeam(nameTeam));
            if (id == idCheck)
            {
                t.setGoal(String::toint(numberGoal) + goal);
                t.setLoseGoal(String::toint(numberLoseGoal) + loseGoal);
                t.setDifference(t.getGoal() - t.getLoseGoal());
                t.setPoint(String::toint(point) + bonusPoint);
            }
            if (id != ' ')
                t.saveTeamToFile(o);
        }
    }
    o.close();
    i.close();
    const char *i1("Team.txt");
    const char *tmp1("Tmp.txt");
    remove(i1);
    rename(tmp1, "Team.txt");
}

void Team::addTeamFromFile()
{
    char filename[256];
    while (true)
    {
        cout << "Enter the file name containing the teams: ";
        cin.getline(filename, 256);
        ifstream i(filename);
        if (i.is_open())
        {
            String tmp;
            String::getline(i, tmp);
            while (!i.eof())
            {
                String::getline(i, tmp);
                // if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
                // {
                //     break;
                // }
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
                Coach c = this->getCoachByNameFootballTeam(nameTeam);
                Team t(nameTeam, c, String::toint(rank), String::toint(numberGoal), String::toint(numberLoseGoal), String::toint(point));
                int s = this->getMaxIdFromFile() + 1;
                t.setIdTeam(String::tostring(s));
                t.setListMember(this->getListPlayerByNameFootballTeam(nameTeam));
                ofstream o("Team.txt", ios::app);
                t.saveTeamToFile(o);
            }
            cout << "Data added successfully" << endl;
            return;
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "The file does not exist. Please enter again!" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }
    }
}

void Team::increaseNumberOfTeam(String tt, int ofset)
{
    int num;
    ifstream file("Team.txt");
    ofstream tempFile("tempTeam.txt");
    tempFile << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Cau Thu," << setw(25) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Thu hang" << endl;
    // cout << "Dang o day" << endl;
    if (file.is_open() && tempFile.is_open())
    {
        // cout << "Vao roi ne" << endl;
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
            if (tt == id)
            {
                num = String::toint(numMember) + ofset;
                // cout << nameTeam << " " << num << endl;
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
void Team::addPlayerToTeam()
{
    system("cls");
    String idTeam;
    cout << "LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Edit team information/Add players to the team" << endl
         << endl;
    showTeam();
    cout << endl;
    cout << "Enter the ID: ";
    String::getline(cin, idTeam);
    Player p;
    p.enterInforPlayer();
    Team t;
    t = t.getTeamById(idTeam);
    p.setNameFootballTeam(t.getNameFootballTeam());
    t.increaseNumberOfTeam(idTeam);
    ofstream o("Player.txt", ios::app);
    p.savePlayerToFile(o);
    cout << "Add successful players!" << endl;
    cout << "Press the Enter key to continue . .";
    getchar();
}

// int Team::String::toint(String x)
//{
//     char a[x.size()];
//     for (int i = 0; i < x.size(); i++)
//     {
//         a[i] = x[i];
//     }
//     return atoi(a);
// }

String Team::nameTeambyId(String ma)
{
    ifstream file("Team.txt");
    String tmp;
    String::getline(file, tmp);
    String notF = "Khong tim thay Id";
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
        if (ma == id)
        {
            file.close();
            return nameTeam;
        }
    }
    file.close();
    return notF;
}

void Team::showNameTeam()
{
    ifstream f("Team.txt");
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
    ifstream file("Team.txt");
    String tmp;
    String::getline(file, tmp);
    // cout << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Cau Thu," << setw(15) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Thu hang" << endl;
    while (!file.eof())
    {
        String::getline(file, tmp);
        if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
        {
            break;
        }
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
        dem++;
        if (lineCount == dem)
        {
            cout << nameTeam;
        }
        else
            cout << nameTeam << ", ";
    }
    file.close();
}

void Team::showIDTeam()
{
    ifstream f("Team.txt");
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
    ifstream file("Team.txt");
    String tmp;
    String::getline(file, tmp);
    // cout << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Cau Thu," << setw(15) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Thu hang" << endl;
    while (!file.eof())
    {
        String::getline(file, tmp);
        if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
        {
            break;
        }
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
        dem++;
        if (lineCount == dem)
        {
            cout << id;
        }
        else
            cout << id << ", ";
    }
    file.close();
}

void Team::showTeam1()
{
    ifstream file("Team.txt");
    // ofstream save("Savedata.txt", ios::out | ios::app);
    String tmp;
    String::getline(file, tmp);
    String id = "ID", tendb = "The name Team", siz = "Player", tenhlv = "The name Coach", go = "Goal", logo = "LoseGoal", diff = "Difference", poin = "Point", ra = "Rank";
    int console = 110;
    int colum = (console - id.size() - tendb.size() - siz.size() - tenhlv.size() - go.size() - logo.size() - diff.size() - poin.size() - ra.size()) / 2;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    // save << left << setw(colum - 8) << id << setw(colum) << tendb << setw(colum) << siz << setw(colum) << tenhlv << setw(colum) << go << setw(colum) << logo << setw(colum) << diff << setw(colum) << poin << setw(colum) << ra << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << setw(colum - 8) << id << setw(colum) << tendb << setw(colum) << siz << setw(colum) << tenhlv << setw(colum) << go << setw(colum) << logo << setw(colum) << diff << setw(colum) << poin << setw(colum) << ra << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    while (!file.eof())
    {
        String::getline(file, tmp);
        if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
        {
            break;
        }
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
        // save << left << setw(colum - 8) << id << setw(colum) << nameTeam << setw(colum) << numMember << setw(colum) << nameCoach << setw(colum) << numberGoal << setw(colum) << numberLoseGoal << setw(colum) << difference << setw(colum) << point << setw(colum) << rank << endl;
        cout << setw(colum - 8) << id << setw(colum) << nameTeam << setw(colum) << numMember << setw(colum) << nameCoach << setw(colum) << numberGoal << setw(colum) << numberLoseGoal << setw(colum) << difference << setw(colum) << point << setw(colum) << rank << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    file.close();
    // save.close();
}

void Team::showTeam()
{
    ifstream file("Team.txt");
    ofstream save("Savedata.txt", ios::out | ios::app);
    String tmp;
    String::getline(file, tmp);
    String id = "ID", tendb = "The name Team", siz = "Player", tenhlv = "The name Coach", go = "Goal", logo = "LoseGoal", diff = "Difference", poin = "Point", ra = "Rank";
    int console = 110;
    int colum = (console - id.size() - tendb.size() - siz.size() - tenhlv.size() - go.size() - logo.size() - diff.size() - poin.size() - ra.size()) / 2;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    save << left << setw(colum - 8) << id << setw(colum) << tendb << setw(colum) << siz << setw(colum) << tenhlv << setw(colum) << go << setw(colum) << logo << setw(colum) << diff << setw(colum) << poin << setw(colum) << ra << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << setw(colum - 8) << id << setw(colum) << tendb << setw(colum) << siz << setw(colum) << tenhlv << setw(colum) << go << setw(colum) << logo << setw(colum) << diff << setw(colum) << poin << setw(colum) << ra << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    while (!file.eof())
    {
        String::getline(file, tmp);
        if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
        {
            break;
        }
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
        save << left << setw(colum - 8) << id << setw(colum) << nameTeam << setw(colum) << numMember << setw(colum) << nameCoach << setw(colum) << numberGoal << setw(colum) << numberLoseGoal << setw(colum) << difference << setw(colum) << point << setw(colum) << rank << endl;
        cout << setw(colum - 8) << id << setw(colum) << nameTeam << setw(colum) << numMember << setw(colum) << nameCoach << setw(colum) << numberGoal << setw(colum) << numberLoseGoal << setw(colum) << difference << setw(colum) << point << setw(colum) << rank << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    file.close();
    save.close();
}

// void setcolor(int color)
// {
//     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//     SetConsoleTextAttribute(hConsole, color);
// }

// #include <conio.h>
//  void setcolor(int color)
//  {
//      textcolor(color);
//  }

void Team::showchampion()
{
    ifstream file("Team.txt");
    ofstream save("Savedata.txt", ios::out | ios::app);
    String id = "ID", tendb = "The name Team", siz = "Player", tenhlv = "The name Coach", go = "Goal", logo = "LoseGoal", diff = "Difference", poin = "Point", ra = "Rank";
    int console = 110;
    int colum = (console - id.size() - tendb.size() - siz.size() - tenhlv.size() - go.size() - logo.size() - diff.size() - poin.size() - ra.size()) / 2;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    save << left << setw(colum - 8) << id << setw(colum) << tendb << setw(colum) << siz << setw(colum) << tenhlv << setw(colum) << go << setw(colum) << logo << setw(colum) << diff << setw(colum) << poin << setw(colum) << ra << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << setw(colum - 8) << id << setw(colum) << tendb << setw(colum) << siz << setw(colum) << tenhlv << setw(colum) << go << setw(colum) << logo << setw(colum) << diff << setw(colum) << poin << setw(colum) << ra << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    // cout << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Cau Thu," << setw(25) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Thu hang" << endl;
    if (file.is_open())
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
            if (rank == String("1"))
            {
                save << left << setw(colum - 8) << id << setw(colum) << nameTeam << setw(colum) << numMember << setw(colum) << nameCoach << setw(colum) << numberGoal << setw(colum) << numberLoseGoal << setw(colum) << difference << setw(colum) << point << setw(colum) << rank << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                // cout << left << setw(10) << id + "," << setw(20) << nameTeam + "," << setw(20) << numMember + "," << setw(25) << nameCoach + "," << setw(15) << numberGoal + "," << setw(15) << numberLoseGoal + "," << setw(15) << difference + "," << setw(15) << point + "," << setw(15) << rank << endl;
                cout << setw(colum - 8) << id << setw(colum) << nameTeam << setw(colum) << numMember << setw(colum) << nameCoach << setw(colum) << numberGoal << setw(colum) << numberLoseGoal << setw(colum) << difference << setw(colum) << point << setw(colum) << rank << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            else
            {
                save << left << setw(colum - 8) << id << setw(colum) << nameTeam << setw(colum) << numMember << setw(colum) << nameCoach << setw(colum) << numberGoal << setw(colum) << numberLoseGoal << setw(colum) << difference << setw(colum) << point << setw(colum) << rank << endl;
                cout << setw(colum - 8) << id << setw(colum) << nameTeam << setw(colum) << numMember << setw(colum) << nameCoach << setw(colum) << numberGoal << setw(colum) << numberLoseGoal << setw(colum) << difference << setw(colum) << point << setw(colum) << rank << endl;
            }
        }
    }
    file.close();
    save.close();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

Vector<String> Team::nameChampion()
{
    Vector<String> a;
    ifstream file("Team.txt");
    // cout << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Cau Thu," << setw(25) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Thu hang" << endl;
    if (file.is_open())
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
            if (rank == String("1"))
            {
                a.push_back(nameTeam);
            }
        }
    }
    file.close();
    return a;
}

void Team::resetInforOfTeam(String idTeam, int g1, int g2)
{
    ifstream i("Team.txt");
    ofstream o("Tmp.txt");
    o << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Cau Thu," << setw(25) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Thu hang";
    if (i.is_open())
    {
        String tmp;
        String::getline(i, tmp);
        while (!i.eof())
        {
            String::getline(i, tmp);
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
            Coach c = this->getCoachByNameFootballTeam(nameTeam);
            Team t(nameTeam, c, String::toint(rank), String::toint(numberGoal), String::toint(numberLoseGoal), String::toint(point));
            t.setIdTeam(id);
            t.setListMember(this->getListPlayerByNameFootballTeam(nameTeam));
            if (id == idTeam)
            {
                t.setGoal(String::toint(numberGoal) - g1);
                t.setLoseGoal(String::toint(numberLoseGoal) - g2);
                t.setDifference(t.getGoal() - t.getLoseGoal());
                if (g1 > g2)
                {
                    t.setPoint(String::toint(point) - 3);
                }
                else if (g1 == g2)
                {
                    t.setPoint(String::toint(point) - 1);
                }
            }
            if (id != ' ')
                t.saveTeamToFile(o);
        }
    }
    o.close();
    i.close();
    const char *i1("Team.txt");
    const char *tmp1("Tmp.txt");
    remove(i1);
    rename(tmp1, "Team.txt");
}