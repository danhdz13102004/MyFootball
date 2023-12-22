#include "HistoryMatch.h"
#include <iostream>
#include <iomanip>
#include "../PrintCenter.h"
using namespace std;

HistoryMatch::HistoryMatch()
{
}
HistoryMatch::HistoryMatch(Match m, int g1, int g2)
    : Match(m)
{
    this->numGoalTeam1 = g1;
    this->numGoalTeam2 = g2;
}
HistoryMatch::~HistoryMatch()
{
}

void HistoryMatch::showHistoryMatch()
{
    ifstream file("HistoryMatch.txt");
    String tmp;
    String::getline(file, tmp);
    // cout << left << setw(7) << "Vong" << setw(10) << "ID doi 1" << setw(17) << "Ten doi 1" << setw(17) << "Ban thang doi 1" << setw(12) << "ID doi 2" << setw(17) << "Ten doi 2" << setw(17) << "Ban thang doi 2" << setw(17) << "Thoi gian" << setw(20) << "Ngay thang nam" << setw(20) << "Dia diem" << endl;
    while (!file.eof())
    {
        String::getline(file, tmp);
        if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
        {
            break;
        }
        int check = 1;
        bool status = false;
        String idr, id1, goal1, id2, goal2, time, date, address;
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
                idr = idr + tmp[i];
            else if (check == 2 && status)
                id1 = id1 + tmp[i];
            else if (check == 3 && status)
                goal1 = goal1 + tmp[i];
            else if (check == 4 && status)
                id2 = id2 + tmp[i];
            else if (check == 5 && status)
                goal2 = goal2 + tmp[i];
            else if (check == 6 && status)
                time = time + tmp[i];
            else if (check == 7 && status)
                date = date + tmp[i];
            else if (check == 8 && status && tmp[i] != '\n')
            {
                address = address + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        Player p;
        Team t;
        String n1, n2, tmp2, tmp4;
        n1 = t.nameTeambyId(id1);
        n2 = t.nameTeambyId(id2);
        String tmp1("Location: ");
        String tmp3("Number round: ");
        tmp2 = tmp1 + address;
        tmp4 = tmp3 + idr;
        String tmp5("-");
        this_thread::sleep_for(chrono::milliseconds(100));
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        printCentered(tmp4);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printCentered(drawBorder(60));
        printCentered(drawOptionCenter(addSpace(n1, n2, 32), 60));
        printCentered(drawOptionCenter(addSpace(goal1, tmp5 + goal2, 3), 60));
        printCentered(drawOptionCenter(tmp2, 60));
        printCentered(drawBorder(60));
        cout << endl;
    }
}

void HistoryMatch::saveHistoryMatchToFile(ofstream &o)
{
    ifstream f("HistoryMatch.txt");
    f.seekg(0, ios::end);
    if (f.tellg() == 0)
    {
        o << left << setw(15) << "Vong" << setw(20) << "ID Doi thu nhat" << setw(20) << "Ban thang doi 1" << setw(20) << "ID Doi thu hai" << setw(20) << "Ban thang doi 2" << setw(20) << "Thoi gian" << setw(25) << "Ngay thang nam" << setw(20) << "Dia diem";
        f.close();
    }
    if (o.is_open())
    {
        o << endl
          << left << setw(15) << this->getIdRound() + "," << setw(20) << this->getIdTeam1() + "," << setw(20) << String::tostring(this->numGoalTeam1) + "," << setw(20) << this->getIdTeam2() + "," << setw(20) << String::tostring(this->numGoalTeam2) + "," << setw(20) << this->getTime() + "," << setw(25) << this->getDate() + "," << setw(20) << this->getAddress();
    }
}

void HistoryMatch::updateGoalandLostGoalandDiffofTeam(String ma, String goal, String lostgoal, String diff)
{
    system("cls");
    fstream file("Team.txt", ios::in);
    fstream tempFile("tempTeam.txt", ios::out | ios::app);
    tempFile << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Thanh Vien," << setw(15) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Thu hang" << endl;
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
                numberGoal = goal;
                numberLoseGoal = lostgoal;
                difference = diff;
                tempFile << left << setw(10) << id + "," << setw(20) << nameTeam + "," << setw(20) << numMember + "," << setw(15) << nameCoach + "," << setw(15) << numberGoal + "," << setw(15) << numberLoseGoal + "," << setw(15) << difference + "," << setw(15) << point + "," << setw(15) << rank << endl;
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
        cout << "Khong mo dc file";
}

String HistoryMatch::getGoal(String ma)
{
    ifstream file("Team.txt");
    String tmp;
    String notf = "Not found";
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
            file.close();
            return numberGoal;
        }
    }
    file.close();
    return notf;
}

String HistoryMatch::getLostGoal(String ma)
{
    ifstream file("Team.txt");
    String tmp;
    String notf = "Not found";
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
            file.close();
            return numberLoseGoal;
        }
    }
    file.close();
    return notf;
}

void HistoryMatch::updatePoint(String ma, String diem)
{
    system("cls");
    fstream file("Team.txt", ios::in);
    fstream tempFile("tempTeam.txt", ios::out | ios::app);
    tempFile << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Thanh Vien," << setw(15) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Thu hang" << endl;
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
                point = diem;
                tempFile << left << setw(10) << id + "," << setw(20) << nameTeam + "," << setw(20) << numMember + "," << setw(15) << nameCoach + "," << setw(15) << numberGoal + "," << setw(15) << numberLoseGoal + "," << setw(15) << difference + "," << setw(15) << point + "," << setw(15) << rank << endl;
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
}

String HistoryMatch::getPoint(String ma)
{
    ifstream file("Team.txt");
    String tmp;
    String notf = "Not found";
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
            file.close();
            return point;
        }
    }
    file.close();
    return notf;
}

String HistoryMatch::getbanthangbyPlayertxt(String ma)
{
    ifstream i("Player.txt");
    String notf = "Not found";
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

            if (ma == id)
            {
                i.close();
                return goal;
            }
        }
    }
    i.close();
    return notf;
}

String HistoryMatch::getgoalSavePlayer(String idv, String idct)
{
    ifstream sp("SavePlayer.txt");
    String notf = "Not found";
    if (sp.is_open())
    {
        String tmp;
        String::getline(sp, tmp);
        while (!sp.eof())
        {
            String::getline(sp, tmp);
            if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
            {
                break;
            }
            int check = 1;
            bool status = false;
            String idround, idteam, tenteam, idplayer, banthangg;
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
                    idround = idround + tmp[i];
                else if (check == 2 && status)
                    idteam = idteam + tmp[i];
                else if (check == 3 && status)
                    tenteam = tenteam + tmp[i];
                else if (check == 4 && status)
                    idplayer = idplayer + tmp[i];
                else if (check == 5 && status && tmp[i] != '\n')
                {
                    banthangg = banthangg + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (idv == idround && idct == idplayer)
            {
                sp.close();
                return banthangg;
            }
        }
    }
    sp.close();
    return notf;
}

void HistoryMatch::editSavePlayer(String idv, String idct, String Goal)
{
    fstream file("SavePlayer.txt", ios::in);
    fstream tempFile("tempSavePlayer.txt", ios::out | ios::app);
    tempFile << left << setw(10) << "IDV," << setw(10) << "ID Doi," << setw(15) << "Ten doi," << setw(10) << "ID CT," << setw(10) << "Goal" << endl;
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
            String idround, idteam, tenteam, idplayer, banthangg;
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
                    idround = idround + tmp[i];
                else if (check == 2 && status)
                    idteam = idteam + tmp[i];
                else if (check == 3 && status)
                    tenteam = tenteam + tmp[i];
                else if (check == 4 && status)
                    idplayer = idplayer + tmp[i];
                else if (check == 5 && status && tmp[i] != '\n')
                {
                    banthangg = banthangg + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (idv == idround && idct == idplayer)
            {
                banthangg = Goal;
                tempFile << left << setw(10) << idround + "," << setw(10) << idteam + "," << setw(15) << tenteam + "," << setw(10) << idplayer + "," << setw(10) << banthangg << endl;
            }
            else
                tempFile << tmp << endl;
        }
        file.close();
        tempFile.close();
        remove("SavePlayer.txt");
        rename("tempSavePlayer.txt", "SavePlayer.txt");
    }
    else
        cout << "Failed";
}

void HistoryMatch::editGoalPlayertxt(String idct, String Goal)
{
    fstream file("Player.txt", ios::in);
    fstream tempFile("tempPlayer.txt", ios::out | ios::app);
    tempFile << left << setw(10) << "ID" << setw(15) << "Ten cau thu" << setw(15) << "Ngay sinh" << setw(20) << "Dia chi" << setw(10) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(10) << "The do" << setw(10) << "Ban thang" << setw(20) << "Ten doi bong" << endl;
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
            if (idct == id)
            {
                goal = Goal;
                tempFile << left << setw(10) << id + "," << setw(15) << name + "," << setw(15) << date + "," << setw(20) << address + "," << setw(10) << age + "," << setw(15) << numberClo + "," << setw(15) << yellowCard + "," << setw(10) << redCard + "," << setw(10) << goal + "," << setw(20) << nameTeam << endl;
            }
            else
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

String HistoryMatch::showPlayerandgoalinsaveplayer(String idv, String idt)
{
    String notf = "Not found";
    ifstream sp("SavePlayer.txt");
    if (sp.is_open())
    {
        String tmp;
        String::getline(sp, tmp);
        while (!sp.eof())
        {
            String::getline(sp, tmp);
            if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
            {
                break;
            }
            int check = 1;
            bool status = false;
            String idround, idteam, tenteam, idplayer, banthangg;
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
                    idround = idround + tmp[i];
                else if (check == 2 && status)
                    idteam = idteam + tmp[i];
                else if (check == 3 && status)
                    tenteam = tenteam + tmp[i];
                else if (check == 4 && status)
                    idplayer = idplayer + tmp[i];
                else if (check == 5 && status && tmp[i] != '\n')
                {
                    banthangg = banthangg + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (idv == idround && idt == idteam)
            {
                sp.close();
                return idplayer;
            }
        }
    }
    sp.close();
    return notf;
}

Vector<int> HistoryMatch::duyetsaveplayer(String idv, String idt)
{
    Vector<int> b;
    ifstream sp("SavePlayer.txt");
    if (sp.is_open())
    {
        String tmp;
        String::getline(sp, tmp);
        while (!sp.eof())
        {
            String::getline(sp, tmp);
            if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
            {
                break;
            }
            int check = 1;
            bool status = false;
            String idround, idteam, tenteam, idplayer, banthangg;
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
                    idround = idround + tmp[i];
                else if (check == 2 && status)
                    idteam = idteam + tmp[i];
                else if (check == 3 && status)
                    tenteam = tenteam + tmp[i];
                else if (check == 4 && status)
                    idplayer = idplayer + tmp[i];
                else if (check == 5 && status && tmp[i] != '\n')
                {
                    banthangg = banthangg + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (idv == idround && idt == idteam)
            {
                b.push_back(String::toint(idplayer));
            }
        }
    }
    sp.close();
    return b;
}

/* Vector<int> HistoryMatch::entergoal(String idvong, String id1, String id2, int g1, int g2)
{
    Vector<int> a;
    int index = 0;
    const int maxplayer = 100;
    int goalsByPlayer[maxplayer][2];
    for (int i = 0; i < maxplayer; ++i)
    {
        goalsByPlayer[i][0] = 0;
        goalsByPlayer[i][1] = 0;
    }
    String name1 = returnNameTeamByID(id1);
    String name2 = returnNameTeamByID(id2);
    String idm, idh, goal1, goal2;
    cout << "Danh sach cau thu cua doi bong co ID la " << id1 << " (" << name1 << ")" << endl;
    showPlayerofTeam(name1);
    cout << endl;
    cout << "Danh sach cau thu cua doi bong co ID la " << id2 << " (" << name2 << ")" << endl;
    showPlayerofTeam(name2);
    int kiemtra = 0;
    int sum = g1 + g2;
    int dem1 = 0, dem2 = 0;
    cout << "Luu y: So ban thang cho tung cau thu phai bang tong so ban thang cua 2 doi da ghi ban trong tran dau!" << endl;
    int goal1Int, goal2Int;
    // ofstream f("SavePlayer.txt", std::ios::app);
    do
    {
        if (g1 > 0 && dem1 < g1)
        {
            do
            {
                cout << "Nhap ID cau thu ghi ban cho doi " << name1 << ": ";
                String::getline(cin, idm);
                if (checkidPlayerofTeam(id1, idm))
                {
                    cout << "Nhap lai so ban thang (toi da " << g1 - dem1 << " ban): ";
                    String::getline(cin, goal1);
                    goal1Int = String::toint(goal1);

                    if (goal1Int <= g1 - dem1 && goal1Int >= 0)
                    {
                        dem1 += goal1Int;
                        kiemtra += goal1Int;
                        goalsByPlayer[String::toint(idm)][0] += goal1Int;
                        // goalsByPlayer[{id1, idm}] += goal1Int;
                    }
                    else
                    {
                        cout << "So ban thang nhap vao khong hop le. Vui long nhap lai." << endl;
                    }
                }
                else
                {
                    cout << "Cau thu co ID " << idm << " khong ton tai trong doi bong " << name1 << ". Vui long nhap lai." << endl;
                }
            } while (!checkidPlayerofTeam(id1, idm));
        }

        if (g2 > 0 && dem2 < g2)
        {
            do
            {
                cout << "Nhap ID cau thu ghi ban cho doi " << name2 << ": ";
                String::getline(cin, idh);
                if (checkidPlayerofTeam(id2, idh))
                {
                    cout << "Nhap lai so ban thang (toi da " << g2 - dem2 << " ban): ";
                    String::getline(cin, goal2);
                    goal2Int = String::toint(goal2);

                    if (goal2Int <= g2 - dem2 && goal2Int >= 0)
                    {
                        dem2 += goal2Int;
                        kiemtra += goal2Int;
                        goalsByPlayer[String::toint(idh)][1] += goal2Int;
                        // goalsByPlayer[{id2, idh}] += goal2Int;
                    }
                    else
                    {
                        cout << "So ban thang nhap vao khong hop le. Vui long nhap lai." << endl;
                    }
                }
                else
                {
                    cout << "Cau thu co ID " << idh << " khong ton tai trong doi bong " << name2 << ". Vui long nhap lai." << endl;
                }
            } while (!checkidPlayerofTeam(id2, idh));
        }
    } while (kiemtra != sum);
    for (int i = 0; i < maxplayer; ++i)
    {
        if (goalsByPlayer[i][0] > 0 || goalsByPlayer[i][1] > 0)
        {
            a.push_back(i);
            int m = max(goalsByPlayer[i][0], goalsByPlayer[i][1]);
            int result = String::toint(getbanthangbyPlayertxt(String::tostring(i))) - String::toint(getgoalSavePlayer(idvong, String::tostring(i))) + m;
            Player::updatePlayerAfterMatch(String::tostring(i), 0, 0, result - String::toint(getbanthangbyPlayertxt(String::tostring(i))));
        }
    }
    Player::sortAllPlayer();
    return a;
} */

/* void HistoryMatch::chuyenhoa(String idct, String Goal)
{
    fstream file("Player.txt", ios::in);
    fstream tempFile("Lamdz.txt", ios::out | ios::app);
    tempFile << left << setw(10) << "ID" << setw(15) << "Ten cau thu" << setw(15) << "Ngay sinh" << setw(20) << "Dia chi" << setw(10) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(10) << "The do" << setw(10) << "Ban thang" << setw(20) << "Ten doi bong" << endl;
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
            if (idct == id)
            {
                goal = Goal;
                tempFile << left << setw(10) << id + "," << setw(15) << name + "," << setw(15) << date + "," << setw(20) << address + "," << setw(10) << age + "," << setw(15) << numberClo + "," << setw(15) << yellowCard + "," << setw(10) << redCard + "," << setw(10) << goal + "," << setw(20) << nameTeam << endl;
            }
        }
        file.close();
        tempFile.close();
    }
    else
        cout << "Khong mo dc file";
} */

/* void HistoryMatch::updateHistoryMatch()
{
    bool kt = true;
    int c[50];
    int index = 0;
    String idvong, idm, idh;
    showHistoryMatch();
    cout << "Nhap ID vong dau: ";
    String::getline(cin, idvong);
    cout << "Nhap ID doi thu nhat: ";
    String::getline(cin, idm);
    cout << "Nhap ID doi thu hai: ";
    String::getline(cin, idh);
    fstream lam("Lamdz.txt");
    fstream file("HistoryMatch.txt", ios::in);
    fstream tempFile("tempHistoryMatch.txt", ios::out | ios::app);
    tempFile << left << setw(15) << "Vong" << setw(20) << "ID Doi thu nhat" << setw(20) << "Ban thang doi 1" << setw(20) << "ID Doi thu hai" << setw(20) << "Ban thang doi 2" << setw(20) << "Thoi gian" << setw(25) << "Ngay thang nam" << setw(20) << "Dia diem" << endl;
    if (file.is_open() && tempFile.is_open())
    {
        String tmp;
        String::getline(file, tmp);
        while (!file.eof())
        {
            if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
            {
                break;
            }
            String::getline(file, tmp);
            int check = 1;
            bool status = false;
            String idr, id1, goal1, id2, goal2, time, date, address;
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
                    idr = idr + tmp[i];
                else if (check == 2 && status)
                    id1 = id1 + tmp[i];
                else if (check == 3 && status)
                    goal1 = goal1 + tmp[i];
                else if (check == 4 && status)
                    id2 = id2 + tmp[i];
                else if (check == 5 && status)
                    goal2 = goal2 + tmp[i];
                else if (check == 6 && status)
                    time = time + tmp[i];
                else if (check == 7 && status)
                    date = date + tmp[i];
                else if (check == 8 && status && tmp[i] != '\n')
                {
                    address = address + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if (idvong == idr && idm == id1 && idh == id2)
            {
                kt = false;
                int lc;
                do
                {
                    system("cls");
                    String banthang1, banthang2;
                    Team t;
                    int intgoal1 = String::toint(goal1);
                    int intgoal2 = String::toint(goal2);
                    printCentered("QUAN LY GIAI DAU/Cap nhat thong tin lich su tran dau");
                    cout << endl;
                    printCentered(drawBorder(50));
                    printCentered(drawOption("1. Chinh sua ti so cua 2 doi.", 50));
                    printCentered(drawOption("0. Thoat.", 50));
                    printCentered(drawBorder(50));
                    printCentered("Nhap lua chon cua ban: ", 0);
                    cin >> lc;
                    cin.ignore();
                    if (lc == 1)
                    {
                        system("cls");
                        cout << "QUAN LY GIAI DAU/Cap nhat thong tin lich su tran dau/Chinh sua ti so cua 2 doi" << endl
                             << endl;
                        cout << "Nhap ban thang doi thu nhat: ";
                        String::getline(cin, banthang1);
                        cout << "Nhap ban thang doi thu hai: ";
                        String::getline(cin, banthang2);
                        // cin.ignore();
                        int intbanthang1 = String::toint(banthang1);
                        int intbanthang2 = String::toint(banthang2);
                        HistoryMatch h;
                        Vector<int> a = h.entergoal(idvong, idm, idh, intbanthang1, intbanthang2); // những thằng được update lưu vô đây, đồng thời đã update xong bên file Player.txt, sai trường hợp đang có bàn thắng thành 0 có bàn thắng nào
                        Vector<int> b = h.duyetsaveplayer();                                       // những thằng trước khi update được lưu vô đây
                        for (int i = 0; i < b.size(); i++)
                        {
                            if (a.find(b[i]) == -1)
                            {
                                c[index] = b[i]; // những thằng đang có bàn thắng thành 0 có bàn thắng nào được lưu vô đây
                                index++;
                            }
                        }
                        for (int i = 0; i < index; i++)
                        {
                            int result = String::toint(getbanthangbyPlayertxt(String::tostring(c[i]))) - String::toint(getgoalSavePlayer(idvong, String::tostring(c[i])));
                            chuyenhoa(String::tostring(c[i]), String::tostring(result)); // đã cập nhật lại bàn thắng những thằng đang có bàn thắng thành 0 có bàn thắng nào ra file Lamdz.txt
                            // làm thế nào để xóa tất cả những cầu thủ có ID là c[i] trong file Player.txt, xong rồi thêm những thằng bên file Lamdz.txt qua là xong
                        }
                        // gọi hàm sort để sort lại file Player.txt sau khi thêm những thằng bên file Lamdz.txt qua
                        // tới đây cập nhật lại thằng SavePlayer.txt sau khi update là xong
                        if (intgoal1 > intgoal2)
                        {
                            if (intbanthang1 > intbanthang2)
                            {
                                int bthang1 = String::toint(getGoal(idm)) - String::toint(goal1) + intbanthang1;
                                int bthua1 = String::toint(getLostGoal(idm)) - String::toint(goal2) + intbanthang2;
                                int hs1 = bthang1 - bthua1;
                                updateGoalandLostGoalandDiffofTeam(idm, String::tostring(bthang1), String::tostring(bthua1), String::tostring(hs1));
                                int bthang2 = String::toint(getGoal(idh)) - String::toint(goal2) + intbanthang2;
                                int bthua2 = String::toint(getLostGoal(idh)) - String::toint(goal1) + intbanthang1;
                                int hs2 = bthang2 - bthua2;
                                updateGoalandLostGoalandDiffofTeam(idh, String::tostring(bthang2), String::tostring(bthua2), String::tostring(hs2));
                            }
                            else if (intbanthang1 < intbanthang2)
                            {
                                int bthang1 = String::toint(getGoal(idm)) - String::toint(goal1) + intbanthang1;
                                int bthua1 = String::toint(getLostGoal(idm)) - String::toint(goal2) + intbanthang2;
                                int hs1 = bthang1 - bthua1;
                                updateGoalandLostGoalandDiffofTeam(idm, String::tostring(bthang1), String::tostring(bthua1), String::tostring(hs1));
                                int bthang2 = String::toint(getGoal(idh)) - String::toint(goal2) + intbanthang2;
                                int bthua2 = String::toint(getLostGoal(idh)) - String::toint(goal1) + intbanthang1;
                                int hs2 = bthang2 - bthua2;
                                updateGoalandLostGoalandDiffofTeam(idh, String::tostring(bthang2), String::tostring(bthua2), String::tostring(hs2));
                                int diem1 = String::toint(getPoint(idm)) - 3;
                                updatePoint(idm, String::tostring(diem1));
                                int diem2 = String::toint(getPoint(idh)) + 3;
                                updatePoint(idh, String::tostring(diem2));
                                Team tt;
                                tt.sortRankAllTeam();
                            }
                            else if (intbanthang1 == intbanthang2)
                            {
                                int bthang1 = String::toint(getGoal(idm)) - String::toint(goal1) + intbanthang1;
                                int bthua1 = String::toint(getLostGoal(idm)) - String::toint(goal2) + intbanthang2;
                                int hs1 = bthang1 - bthua1;
                                updateGoalandLostGoalandDiffofTeam(idm, String::tostring(bthang1), String::tostring(bthua1), String::tostring(hs1));
                                int bthang2 = String::toint(getGoal(idh)) - String::toint(goal2) + intbanthang2;
                                int bthua2 = String::toint(getLostGoal(idh)) - String::toint(goal1) + intbanthang1;
                                int hs2 = bthang2 - bthua2;
                                updateGoalandLostGoalandDiffofTeam(idh, String::tostring(bthang2), String::tostring(bthua2), String::tostring(hs2));
                                int diem1 = String::toint(getPoint(idm)) - 2;
                                updatePoint(idm, String::tostring(diem1));
                                int diem2 = String::toint(getPoint(idh)) + 1;
                                updatePoint(idh, String::tostring(diem2));
                                Team tt;
                                tt.sortRankAllTeam();
                            }
                        }
                        else if (intgoal1 < intgoal2)
                        {
                            if (intbanthang1 > intbanthang2)
                            {
                                int bthang1 = String::toint(getGoal(idm)) - String::toint(goal1) + intbanthang1;
                                int bthua1 = String::toint(getLostGoal(idm)) - String::toint(goal2) + intbanthang2;
                                int hs1 = bthang1 - bthua1;
                                updateGoalandLostGoalandDiffofTeam(idm, String::tostring(bthang1), String::tostring(bthua1), String::tostring(hs1));
                                int bthang2 = String::toint(getGoal(idh)) - String::toint(goal2) + intbanthang2;
                                int bthua2 = String::toint(getLostGoal(idh)) - String::toint(goal1) + intbanthang1;
                                int hs2 = bthang2 - bthua2;
                                updateGoalandLostGoalandDiffofTeam(idh, String::tostring(bthang2), String::tostring(bthua2), String::tostring(hs2));
                                int diem1 = String::toint(getPoint(idm)) + 3;
                                updatePoint(idm, String::tostring(diem1));
                                int diem2 = String::toint(getPoint(idh)) - 3;
                                updatePoint(idh, String::tostring(diem2));
                                Team tt;
                                tt.sortRankAllTeam();
                            }
                            else if (intbanthang1 < intbanthang2)
                            {
                                int bthang1 = String::toint(getGoal(idm)) - String::toint(goal1) + intbanthang1;
                                int bthua1 = String::toint(getLostGoal(idm)) - String::toint(goal2) + intbanthang2;
                                int hs1 = bthang1 - bthua1;
                                updateGoalandLostGoalandDiffofTeam(idm, String::tostring(bthang1), String::tostring(bthua1), String::tostring(hs1));
                                int bthang2 = String::toint(getGoal(idh)) - String::toint(goal2) + intbanthang2;
                                int bthua2 = String::toint(getLostGoal(idh)) - String::toint(goal1) + intbanthang1;
                                int hs2 = bthang2 - bthua2;
                                updateGoalandLostGoalandDiffofTeam(idh, String::tostring(bthang2), String::tostring(bthua2), String::tostring(hs2));
                            }
                            else if (intbanthang1 == intbanthang2)
                            {
                                int bthang1 = String::toint(getGoal(idm)) - String::toint(goal1) + intbanthang1;
                                int bthua1 = String::toint(getLostGoal(idm)) - String::toint(goal2) + intbanthang2;
                                int hs1 = bthang1 - bthua1;
                                updateGoalandLostGoalandDiffofTeam(idm, String::tostring(bthang1), String::tostring(bthua1), String::tostring(hs1));
                                int bthang2 = String::toint(getGoal(idh)) - String::toint(goal2) + intbanthang2;
                                int bthua2 = String::toint(getLostGoal(idh)) - String::toint(goal1) + intbanthang1;
                                int hs2 = bthang2 - bthua2;
                                updateGoalandLostGoalandDiffofTeam(idh, String::tostring(bthang2), String::tostring(bthua2), String::tostring(hs2));
                                int diem1 = String::toint(getPoint(idm)) + 1;
                                updatePoint(idm, String::tostring(diem1));
                                int diem2 = String::toint(getPoint(idh)) - 2;
                                updatePoint(idh, String::tostring(diem2));
                                Team tt;
                                tt.sortRankAllTeam();
                            }
                        }
                        else if (intgoal1 == intgoal2)
                        {
                            if (intbanthang1 > intbanthang2)
                            {
                                int bthang1 = String::toint(getGoal(idm)) - String::toint(goal1) + intbanthang1;
                                int bthua1 = String::toint(getLostGoal(idm)) - String::toint(goal2) + intbanthang2;
                                int hs1 = bthang1 - bthua1;
                                updateGoalandLostGoalandDiffofTeam(idm, String::tostring(bthang1), String::tostring(bthua1), String::tostring(hs1));
                                int bthang2 = String::toint(getGoal(idh)) - String::toint(goal2) + intbanthang2;
                                int bthua2 = String::toint(getLostGoal(idh)) - String::toint(goal1) + intbanthang1;
                                int hs2 = bthang2 - bthua2;
                                updateGoalandLostGoalandDiffofTeam(idh, String::tostring(bthang2), String::tostring(bthua2), String::tostring(hs2));
                                int diem1 = String::toint(getPoint(idm)) + 2;
                                updatePoint(idm, String::tostring(diem1));
                                int diem2 = String::toint(getPoint(idh)) - 1;
                                updatePoint(idh, String::tostring(diem2));
                                Team tt;
                                tt.sortRankAllTeam();
                            }
                            else if (intbanthang1 < intbanthang2)
                            {
                                int bthang1 = String::toint(getGoal(idm)) - String::toint(goal1) + intbanthang1;
                                int bthua1 = String::toint(getLostGoal(idm)) - String::toint(goal2) + intbanthang2;
                                int hs1 = bthang1 - bthua1;
                                updateGoalandLostGoalandDiffofTeam(idm, String::tostring(bthang1), String::tostring(bthua1), String::tostring(hs1));
                                int bthang2 = String::toint(getGoal(idh)) - String::toint(goal2) + intbanthang2;
                                int bthua2 = String::toint(getLostGoal(idh)) - String::toint(goal1) + intbanthang1;
                                int hs2 = bthang2 - bthua2;
                                updateGoalandLostGoalandDiffofTeam(idh, String::tostring(bthang2), String::tostring(bthua2), String::tostring(hs2));
                                int diem1 = String::toint(getPoint(idm)) - 1;
                                updatePoint(idm, String::tostring(diem1));
                                int diem2 = String::toint(getPoint(idh)) + 2;
                                updatePoint(idh, String::tostring(diem2));
                                Team tt;
                                tt.sortRankAllTeam();
                            }
                            else if (intbanthang1 == intbanthang2)
                            {
                                int bthang1 = String::toint(getGoal(idm)) - String::toint(goal1) + intbanthang1;
                                int bthua1 = String::toint(getLostGoal(idm)) - String::toint(goal2) + intbanthang2;
                                int hs1 = bthang1 - bthua1;
                                updateGoalandLostGoalandDiffofTeam(idm, String::tostring(bthang1), String::tostring(bthua1), String::tostring(hs1));
                                int bthang2 = String::toint(getGoal(idh)) - String::toint(goal2) + intbanthang2;
                                int bthua2 = String::toint(getLostGoal(idh)) - String::toint(goal1) + intbanthang1;
                                int hs2 = bthang2 - bthua2;
                                updateGoalandLostGoalandDiffofTeam(idh, String::tostring(bthang2), String::tostring(bthua2), String::tostring(hs2));
                            }
                        }
                        goal1 = banthang1;
                        goal2 = banthang2;
                    }
                } while (lc != 0);
                tempFile << left << setw(15) << idr + "," << setw(20) << id1 + "," << setw(20) << goal1 + "," << setw(20) << id2 + "," << setw(20) << goal2 + "," << setw(20) << time + "," << setw(25) << date + "," << setw(20) << address << endl;
            }
            else
            {
                tempFile << tmp << endl;
            }
        }
        file.close();
        tempFile.close();
        remove("HistoryMatch.txt");
        rename("tempHistoryMatch.txt", "HistoryMatch.txt");
    }
    else
        cout << "Khong mo duoc file";
    if (kt)
        cout << "Khong tim thay tran dau nao!" << endl;
    else
        cout << "Cap nhat thong tin thanh cong!" << endl;
} */

void HistoryMatch::updateHistoryMatch1()
{
    showHistoryMatch();
    String idRound, tmpnameTeam1, tmpnameTeam2, nameTeam1, nameTeam2, id1, id2;
    cout << "Enter ID Round: ";
    String::getline(cin, idRound);
    cout << "Enter Name Team 1: ";
    String::getline(cin, tmpnameTeam1);
    cout << "Enter Name Team 2: ";
    String::getline(cin, tmpnameTeam2);
    Team t;
    nameTeam1 = String::standadizeString(tmpnameTeam1);
    nameTeam2 = String::standadizeString(tmpnameTeam2);
    id1 = t.getIdByNameTeam(nameTeam1);
    id2 = t.getIdByNameTeam(nameTeam2);
    if (HistoryMatch::checkHistoryMatchExist(idRound, id1, id2))
    {
        Match m = Match::getMatchFromHistoryMatch(idRound, id1, id2);
        HistoryMatch::resetPointOfTeamAndDelelteHistoryMatch(idRound, id1, id2);
        HistoryMatch::resetGoalOfPlayerAndDeleteSavePlayer(idRound, id1, id2);
        const int maxplayer = 100;
        int goalsByPlayer[maxplayer][2];
        for (int i = 0; i < maxplayer; ++i)
        {
            goalsByPlayer[i][0] = 0;
            goalsByPlayer[i][1] = 0;
        }
        int lc;
        int g1, g2;
        cout << endl;
        cout << "Enter the goal of team 1: ";
        cin >> g1;
        cout << "Enter the goal of team 2: ";
        cin >> g2;
        cin.ignore();
        String idm, idh, goal1, goal2;
        cout << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        printCentered(drawBorder(202));
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "List of team's players with ID " << id1 << " (" << nameTeam1 << ")" << endl;
        showPlayerofTeam(nameTeam1);
        cout << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        printCentered(drawBorder(202));
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "List of team's players with ID " << id2 << " (" << nameTeam2 << ")" << endl;
        showPlayerofTeam(nameTeam2);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        printCentered(drawBorder(202));
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        int kiemtra = 0;
        int sum = g1 + g2;
        int dem1 = 0, dem2 = 0;
        cout << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        cout << "Note: The number of goals for each player must be equal to the total number of goals scored by the two teams in the match!" << endl
             << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        int goal1Int, goal2Int;
        ofstream f("SavePlayer.txt", std::ios::app);
        do
        {
            if (g1 > 0 && dem1 < g1)
            {
                do
                {
                    cout << "Enter the citizen identification card of the player who scored a goal for the " << nameTeam1 << ": ";
                    String::getline(cin, idm);
                    if (checkidPlayerofTeam(id1, idm))
                    {
                        cout << "Enter the goal (Maximum " << g1 - dem1 << " goal): ";
                        String::getline(cin, goal1);
                        goal1Int = String::toint(goal1);

                        if (goal1Int <= g1 - dem1 && goal1Int >= 0)
                        {
                            dem1 += goal1Int;
                            kiemtra += goal1Int;
                            goalsByPlayer[String::toint(idm)][0] += goal1Int;
                            // goalsByPlayer[{id1, idm}] += goal1Int;
                        }
                        else
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                            cout << "The number of goals entered is invalid. Please re-enter." << endl;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                        }
                    }
                    else
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "Players have citizen identification cards " << idm << " not found " << nameTeam1 << ". Please re-enter." << endl;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                    }
                } while (!checkidPlayerofTeam(id1, idm));
                // for (const auto &entry : goalsByPlayer)
                // {
                //     const auto &playerKey = entry.first;
                //     const String &teamId = playerKey.first;
                //     const String &playerId = playerKey.second;
                //     int goalsScored = entry.second;
                //     cout << "Cau thu " << playerId << " cua doi " << teamId << " ghi duoc " << goalsScored << " ban." << endl;
                //     Player::updatePlayerAfterMatch(playerId, 0, 0, goalsScored);
                // }
            }

            if (g2 > 0 && dem2 < g2)
            {
                do
                {
                    cout << "Enter the citizen identification card of the player who scored a goal for the " << nameTeam2 << ": ";
                    String::getline(cin, idh);
                    if (checkidPlayerofTeam(id2, idh))
                    {
                        cout << "Enter the goal (Maximum " << g2 - dem2 << " goal): ";
                        String::getline(cin, goal2);
                        goal2Int = String::toint(goal2);

                        if (goal2Int <= g2 - dem2 && goal2Int >= 0)
                        {
                            dem2 += goal2Int;
                            kiemtra += goal2Int;
                            goalsByPlayer[String::toint(idh)][1] += goal2Int;
                            // goalsByPlayer[{id2, idh}] += goal2Int;
                        }
                        else
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                            cout << "The number of goals entered is invalid. Please re-enter." << endl;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                        }
                    }
                    else
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "Players have citizen identification cards " << idh << " not found " << nameTeam2 << ". Please re-enter." << endl;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                    }
                } while (!checkidPlayerofTeam(id2, idh));
                // for (const auto &entry : goalsByPlayer)
                // {
                //     const auto &playerKey = entry.first;
                //     const String &teamId = playerKey.first;
                //     const String &playerId = playerKey.second;
                //     int goalsScored = entry.second;
                //     cout << "Cau thu " << playerId << " cua doi " << teamId << " ghi duoc " << goalsScored << " ban." << endl;
                //     Player::updatePlayerAfterMatch(playerId, 0, 0, goalsScored);
                // }
            }
        } while (kiemtra != sum);
        for (int i = 0; i < maxplayer; ++i)
        {
            if (goalsByPlayer[i][0] > 0 || goalsByPlayer[i][1] > 0)
            {
                int m = max(goalsByPlayer[i][0], goalsByPlayer[i][1]);
                Player p;
                cout << "Players have name " << p.getnamebyid(String::tostring(i)) << " score " << m << " goal." << endl;
                if (checkidPlayerofTeam(id1, String::tostring(i)) == true)
                    f << left << setw(10) << idRound + "," << setw(10) << id1 + "," << setw(15) << returnNameTeamByID(id1) + "," << setw(10) << String::tostring(i) + "," << setw(10) << String::tostring(m) << endl;
                else
                    f << left << setw(10) << idRound + "," << setw(10) << id2 + "," << setw(15) << returnNameTeamByID(id2) + "," << setw(10) << String::tostring(i) + "," << setw(10) << String::tostring(m) << endl;
                Player::updatePlayerAfterMatch(String::tostring(i), 0, 0, m);
            }
        }
        Player::sortAllPlayer();
        Team t;
        if (g1 > g2)
        {
            t.updateTeamAfterMatch(id1, g1, g2, 3);
            t.updateTeamAfterMatch(id2, g2, g1, 0);
            t.sortRankAllTeam();
        }
        else if (g1 < g2)
        {
            t.updateTeamAfterMatch(id1, g1, g2, 0);
            t.updateTeamAfterMatch(id2, g2, g1, 3);
            t.sortRankAllTeam();
        }
        else
        {
            t.updateTeamAfterMatch(id1, g1, g2, 1);
            t.updateTeamAfterMatch(id2, g2, g1, 1);
            t.sortRankAllTeam();
        }
        m.deleteMatchByIdRoundAndTwoTeam(m);
        m.saveToHistoryMatch(id1, id2, g1, g2);
        cout << "Press the Enter key to continue . .";
        getchar();
    }
    else
    {
        cout << "No matches could be found!" << endl;
        return;
    }
}
void HistoryMatch::resetPointOfTeamAndDelelteHistoryMatch(String idRound, String idTeam1, String idTeam2)
{
    ifstream file("HistoryMatch.txt");
    ofstream o("Tmp1.txt");
    String tmp;
    String::getline(file, tmp);
    o << left << setw(15) << "Vong" << setw(20) << "ID Doi thu nhat" << setw(20) << "Ban thang doi 1" << setw(20) << "ID Doi thu hai" << setw(20) << "Ban thang doi 2" << setw(20) << "Thoi gian" << setw(25) << "Ngay thang nam" << setw(20) << "Dia diem";
    while (!file.eof())
    {
        String::getline(file, tmp);
        if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
        {
            break;
        }
        int check = 1;
        bool status = false;
        String idr, id1, goal1, id2, goal2, time, date, address;
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
                idr = idr + tmp[i];
            else if (check == 2 && status)
                id1 = id1 + tmp[i];
            else if (check == 3 && status)
                goal1 = goal1 + tmp[i];
            else if (check == 4 && status)
                id2 = id2 + tmp[i];
            else if (check == 5 && status)
                goal2 = goal2 + tmp[i];
            else if (check == 6 && status)
                time = time + tmp[i];
            else if (check == 7 && status)
                date = date + tmp[i];
            else if (check == 8 && status && tmp[i] != '\n')
            {
                address = address + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        if (idRound == idr && ((id1 == idTeam1 && id2 == idTeam2) || id1 == idTeam2 && id2 == idTeam1))
        {
            Team t;
            t.resetInforOfTeam(id1, String::toint(goal1), String::toint(goal2));
            t.resetInforOfTeam(id2, String::toint(goal2), String::toint(goal1));
        }
        else
        {
            o << endl
              << left << setw(15) << idr + "," << setw(20) << id1 + "," << setw(20) << goal1 + "," << setw(20) << id2 + "," << setw(20) << goal2 + "," << setw(20) << time + "," << setw(25) << date + "," << setw(20) << address;
        }
        // cout << endl
        //      << left << setw(15) << idr + "," << setw(20) << id1 + "," << setw(20) << goal1 + "," << setw(20) << id2 + "," << setw(20) << goal2 + "," << setw(20) << time + "," << setw(25) << date + "," << setw(20) << address;
    }
    o.close();
    file.close();
    const char *i1("HistoryMatch.txt");
    const char *tmp1("Tmp1.txt");
    remove(i1);
    rename(tmp1, "HistoryMatch.txt");
}
void HistoryMatch::resetGoalOfPlayerAndDeleteSavePlayer(String idRound, String idTeam1, String idTeam2)
{
    ifstream sp("SavePlayer.txt");
    ofstream o("Tmp2.txt");
    Player p;
    o << left << setw(10) << "IDV," << setw(10) << "ID Doi," << setw(15) << "Ten doi," << setw(10) << "ID CT," << setw(10) << "Goal" << endl;
    if (sp.is_open())
    {
        String tmp;
        String::getline(sp, tmp);
        while (!sp.eof())
        {
            String::getline(sp, tmp);
            if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
            {
                break;
            }
            int check = 1;
            bool status = false;
            String idround, idteam, tenteam, idplayer, banthangg;
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
                    idround = idround + tmp[i];
                else if (check == 2 && status)
                    idteam = idteam + tmp[i];
                else if (check == 3 && status)
                    tenteam = tenteam + tmp[i];
                else if (check == 4 && status)
                    idplayer = idplayer + tmp[i];
                else if (check == 5 && status && tmp[i] != '\n')
                {
                    banthangg = banthangg + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if ((idRound == idround) && (idteam == idTeam1 || idteam == idTeam2))
            {
                p.resetPlayer(idplayer, String::toint(banthangg));
            }
            else
            {
                o << left << setw(10) << idround + "," << setw(10) << idteam + "," << setw(15) << tenteam + "," << setw(10) << idplayer + "," << setw(10) << banthangg << endl;
            }
        }
    }
    o.close();
    sp.close();
    const char *i1("SavePlayer.txt");
    const char *tmp1("Tmp2.txt");
    remove(i1);
    rename(tmp1, "SavePlayer.txt");
}

bool HistoryMatch::checkHistoryMatchExist(String idR, String idTeam1, String idTeam2)
{
    ifstream file("HistoryMatch.txt");
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
        String idr, id1, goal1, id2, goal2, time, date, address;
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
                idr = idr + tmp[i];
            else if (check == 2 && status)
                id1 = id1 + tmp[i];
            else if (check == 3 && status)
                goal1 = goal1 + tmp[i];
            else if (check == 4 && status)
                id2 = id2 + tmp[i];
            else if (check == 5 && status)
                goal2 = goal2 + tmp[i];
            else if (check == 6 && status)
                time = time + tmp[i];
            else if (check == 7 && status)
                date = date + tmp[i];
            else if (check == 8 && status && tmp[i] != '\n')
            {
                address = address + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        if (idR == idr && ((id1 == idTeam1 && id2 == idTeam2) || id1 == idTeam2 && id2 == idTeam1))
        {
            return true;
        }
    }
    return false;
}
void HistoryMatch::showdateHM()
{
    ifstream file("HistoryMatch.txt");
    String tmp;
    String kt = " ";
    String::getline(file, tmp);
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String idr, id1, goal1, id2, goal2, time, date, address;
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
                idr = idr + tmp[i];
            else if (check == 2 && status)
                id1 = id1 + tmp[i];
            else if (check == 3 && status)
                goal1 = goal1 + tmp[i];
            else if (check == 4 && status)
                id2 = id2 + tmp[i];
            else if (check == 5 && status)
                goal2 = goal2 + tmp[i];
            else if (check == 6 && status)
                time = time + tmp[i];
            else if (check == 7 && status)
                date = date + tmp[i];
            else if (check == 8 && status && tmp[i] != '\n')
            {
                address = address + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        if (kt != date)
        {
            cout << date << ", ";
            kt = date;
        }
    }
    file.close();
}

/* void HistoryMatch::showidHM()
{
    const int maxx = 100;
    String uniqueTeamIds[maxx][2];
    ifstream file("HistoryMatch.txt");
    String tmp;
    String kt = " ";
    String::getline(file, tmp);
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String idr, id1, goal1, id2, goal2, time, date, address;
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
                idr = idr + tmp[i];
            else if (check == 2 && status)
                id1 = id1 + tmp[i];
            else if (check == 3 && status)
                goal1 = goal1 + tmp[i];
            else if (check == 4 && status)
                id2 = id2 + tmp[i];
            else if (check == 5 && status)
                goal2 = goal2 + tmp[i];
            else if (check == 6 && status)
                time = time + tmp[i];
            else if (check == 7 && status)
                date = date + tmp[i];
            else if (check == 8 && status && tmp[i] != '\n')
            {
                address = address + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        bool id1Exists = false;
        bool id2Exists = false;
        for (int i = 0; i < maxx; i++)
        {
            if (uniqueTeamIds[i][0] == id1)
            {
                id1Exists = true;
                break;
            }
            if (uniqueTeamIds[i][1] == id2)
            {
                id2Exists = true;
                break;
            }
            if (uniqueTeamIds[i][0].empty())
            {
                uniqueTeamIds[i][0] = id1;
                break;
            }
            if (uniqueTeamIds[i][1].empty())
            {
                uniqueTeamIds[i][1] = id2;
                break;
            }
        }
        if (!id1Exists)
        {
            cout << id1 << ", ";
        }
        if (!id2Exists)
        {
            cout << id2 << ", ";
        }
    }
    file.close();
} */

void HistoryMatch::showidvongHM()
{
    ifstream file("HistoryMatch.txt");
    String tmp;
    String kt = " ";
    String::getline(file, tmp);
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String idr, id1, goal1, id2, goal2, time, date, address;
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
                idr = idr + tmp[i];
            else if (check == 2 && status)
                id1 = id1 + tmp[i];
            else if (check == 3 && status)
                goal1 = goal1 + tmp[i];
            else if (check == 4 && status)
                id2 = id2 + tmp[i];
            else if (check == 5 && status)
                goal2 = goal2 + tmp[i];
            else if (check == 6 && status)
                time = time + tmp[i];
            else if (check == 7 && status)
                date = date + tmp[i];
            else if (check == 8 && status && tmp[i] != '\n')
            {
                address = address + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        if (kt != idr)
        {
            cout << idr << ", ";
            kt = idr;
        }
    }
    file.close();
}

void HistoryMatch::showHMbydate(String ntn)
{
    bool kq = true;
    ifstream file("HistoryMatch.txt");
    String tmp;
    String::getline(file, tmp);
    int kt = 1;
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String idr, id1, goal1, id2, goal2, time, date, address;
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
                idr = idr + tmp[i];
            else if (check == 2 && status)
                id1 = id1 + tmp[i];
            else if (check == 3 && status)
                goal1 = goal1 + tmp[i];
            else if (check == 4 && status)
                id2 = id2 + tmp[i];
            else if (check == 5 && status)
                goal2 = goal2 + tmp[i];
            else if (check == 6 && status)
                time = time + tmp[i];
            else if (check == 7 && status)
                date = date + tmp[i];
            else if (check == 8 && status && tmp[i] != '\n')
            {
                address = address + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        if (ntn == date)
        {
            this_thread::sleep_for(chrono::milliseconds(100));
            kq = false;
            Player p;
            Team t;
            String n1, n2, tmp2, tmp4;
            n1 = t.nameTeambyId(id1);
            n2 = t.nameTeambyId(id2);
            String tmp1("Location: ");
            String tmp3("Number round: ");
            tmp2 = tmp1 + address;
            tmp4 = tmp3 + idr;
            String tmp5("-");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            printCentered(tmp4);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printCentered(drawBorder(60));
            printCentered(drawOptionCenter(addSpace(n1, n2, 32), 60));
            printCentered(drawOptionCenter(addSpace(goal1, tmp5 + goal2, 3), 60));
            printCentered(drawOptionCenter(tmp2, 60));
            printCentered(drawBorder(60));
            cout << endl;
        }
    }
    if (kq)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "Not found!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
}

void HistoryMatch::showHMbyidoneteam(String ma)
{
    bool kq = true;
    int kt = 1;
    ifstream file("HistoryMatch.txt");
    String tmp;
    String::getline(file, tmp);
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String idr, id1, goal1, id2, goal2, time, date, address;
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
                idr = idr + tmp[i];
            else if (check == 2 && status)
                id1 = id1 + tmp[i];
            else if (check == 3 && status)
                goal1 = goal1 + tmp[i];
            else if (check == 4 && status)
                id2 = id2 + tmp[i];
            else if (check == 5 && status)
                goal2 = goal2 + tmp[i];
            else if (check == 6 && status)
                time = time + tmp[i];
            else if (check == 7 && status)
                date = date + tmp[i];
            else if (check == 8 && status && tmp[i] != '\n')
            {
                address = address + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        if (ma == id1 || ma == id2)
        {
            // if (kt == 1)
            // {
            //     cout << left << setw(10) << "Vong" << setw(15) << "ID doi 1" << setw(20) << "Ten doi 1" << setw(20) << "Ban thang doi 1" << setw(15) << "ID doi 2" << setw(20) << "Ten doi 2" << setw(20) << "Ban thang doi 2" << setw(12) << "Thoi gian" << setw(20) << "Ngay thang nam" << setw(20) << "Dia diem" << endl;
            //     kt++;
            // }
            // kq = false;
            // Team t;
            // String n1, n2;
            // n1 = t.nameTeambyId(id1);
            // n2 = t.nameTeambyId(id2);
            // cout << left << setw(10) << idr << setw(15) << id1 << setw(20) << n1 << setw(20) << goal1 << setw(15) << id2 << setw(20) << n2 << setw(20) << goal2 << setw(12) << time << setw(20) << date << setw(20) << address << endl;
            Player p;
            kq = false;
            Team t;
            String n1, n2, tmp2, tmp4;
            n1 = t.nameTeambyId(id1);
            n2 = t.nameTeambyId(id2);
            String tmp1("Location: ");
            String tmp3("Number round: ");
            tmp2 = tmp1 + address;
            tmp4 = tmp3 + idr;
            String tmp5("-");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            printCentered(tmp4);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printCentered(drawBorder(60));
            printCentered(drawOptionCenter(addSpace(n1, n2, 32), 60));
            printCentered(drawOptionCenter(addSpace(goal1, tmp5 + goal2, 3), 60));
            printCentered(drawOptionCenter(tmp2, 60));
            printCentered(drawBorder(60));
            cout << endl;
        }
    }
    if (kq)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "Not found!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
}

void HistoryMatch::showHMbyidtwoteam(String ma1, String ma2)
{
    bool kq = true;
    ifstream file("HistoryMatch.txt");
    String tmp;
    int kt = 1;
    String::getline(file, tmp);
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String idr, id1, goal1, id2, goal2, time, date, address;
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
                idr = idr + tmp[i];
            else if (check == 2 && status)
                id1 = id1 + tmp[i];
            else if (check == 3 && status)
                goal1 = goal1 + tmp[i];
            else if (check == 4 && status)
                id2 = id2 + tmp[i];
            else if (check == 5 && status)
                goal2 = goal2 + tmp[i];
            else if (check == 6 && status)
                time = time + tmp[i];
            else if (check == 7 && status)
                date = date + tmp[i];
            else if (check == 8 && status && tmp[i] != '\n')
            {
                address = address + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        if ((ma1 == id1 && ma2 == id2) || (ma2 == id1 && ma1 == id2))
        {
            // if (kt == 1)
            // {
            //     cout << left << setw(10) << "Vong" << setw(15) << "ID doi 1" << setw(20) << "Ten doi 1" << setw(20) << "Ban thang doi 1" << setw(15) << "ID doi 2" << setw(20) << "Ten doi 2" << setw(20) << "Ban thang doi 2" << setw(12) << "Thoi gian" << setw(20) << "Ngay thang nam" << setw(20) << "Dia diem" << endl;
            //     kt++;
            // }
            // kq = false;
            // Team t;
            // String n1, n2;
            // n1 = t.nameTeambyId(id1);
            // n2 = t.nameTeambyId(id2);
            // cout << left << setw(10) << idr << setw(15) << id1 << setw(20) << n1 << setw(20) << goal1 << setw(15) << id2 << setw(20) << n2 << setw(20) << goal2 << setw(12) << time << setw(20) << date << setw(20) << address << endl;
            Player p;
            this_thread::sleep_for(chrono::milliseconds(100));
            Team t;
            kq = false;
            String n1, n2, tmp2, tmp4;
            n1 = t.nameTeambyId(id1);
            n2 = t.nameTeambyId(id2);
            String tmp1("Location: ");
            String tmp3("Number round: ");
            tmp2 = tmp1 + address;
            tmp4 = tmp3 + idr;
            String tmp5("-");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
            printCentered(tmp4);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printCentered(drawBorder(60));
            printCentered(drawOptionCenter(addSpace(n1, n2, 32), 60));
            printCentered(drawOptionCenter(addSpace(goal1, tmp5 + goal2, 3), 60));
            printCentered(drawOptionCenter(tmp2, 60));
            printCentered(drawBorder(60));
            cout << endl;
        }
    }
    if (kq)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "Not found!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
}

void HistoryMatch::showHMbyidround(String idvong)
{
    bool kq = true;
    int kt = 1;
    ifstream file("HistoryMatch.txt");
    String tmp;
    String::getline(file, tmp);
    while (!file.eof())
    {
        String::getline(file, tmp);
        int check = 1;
        bool status = false;
        String idr, id1, goal1, id2, goal2, time, date, address;
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
                idr = idr + tmp[i];
            else if (check == 2 && status)
                id1 = id1 + tmp[i];
            else if (check == 3 && status)
                goal1 = goal1 + tmp[i];
            else if (check == 4 && status)
                id2 = id2 + tmp[i];
            else if (check == 5 && status)
                goal2 = goal2 + tmp[i];
            else if (check == 6 && status)
                time = time + tmp[i];
            else if (check == 7 && status)
                date = date + tmp[i];
            else if (check == 8 && status && tmp[i] != '\n')
            {
                address = address + tmp[i];
                if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                    break;
            }
        }
        if (idvong == idr)
        {
            // if (kt == 1)
            // {
            //     cout << left << setw(10) << "Vong" << setw(15) << "ID doi 1" << setw(20) << "Ten doi 1" << setw(20) << "Ban thang doi 1" << setw(15) << "ID doi 2" << setw(20) << "Ten doi 2" << setw(20) << "Ban thang doi 2" << setw(12) << "Thoi gian" << setw(20) << "Ngay thang nam" << setw(20) << "Dia diem" << endl;
            //     kt++;
            // }
            // kq = false;
            // Team t;
            // String n1, n2;
            // n1 = t.nameTeambyId(id1);
            // n2 = t.nameTeambyId(id2);
            // cout << left << setw(10) << idr << setw(15) << id1 << setw(20) << n1 << setw(20) << goal1 << setw(15) << id2 << setw(20) << n2 << setw(20) << goal2 << setw(12) << time << setw(20) << date << setw(20) << address << endl;
            Player p;
            this_thread::sleep_for(chrono::milliseconds(100));
            kq = false;
            Team t;
            String n1, n2, tmp2, tmp4;
            n1 = t.nameTeambyId(id1);
            n2 = t.nameTeambyId(id2);
            String tmp1("Location: ");
            String tmp3("Number round: ");
            tmp2 = tmp1 + address;
            tmp4 = tmp3 + idr;
            String tmp5("-");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            printCentered(tmp4);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printCentered(drawBorder(60));
            printCentered(drawOptionCenter(addSpace(n1, n2, 32), 60));
            printCentered(drawOptionCenter(addSpace(goal1, tmp5 + goal2, 3), 60));
            printCentered(drawOptionCenter(tmp2, 60));
            printCentered(drawBorder(60));
            cout << endl;
        }
    }
    if (kq)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "Not found!" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
}
