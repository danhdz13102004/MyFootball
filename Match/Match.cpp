#include "Match.h"
#include <iostream>
#include <iomanip>
#include "../PrintCenter.h"
// #include <map>
using namespace std;

Match::Match()
{
}
Match::~Match()
{
}
Match::Match(const Team &a, const Team &b, String address, String time, String date)
{
    cout << "Constructor of Match" << endl;
    this->v.push_back(a);
    this->v.push_back(b);
    this->address = address;
    this->time = time;
    this->date = date;
    cout << "Khoi tao thanh cong" << endl;
}

void Match::showMatch()
{
    this_thread::sleep_for(chrono::milliseconds(100));
    String idR = this->idRound;
    if(idR.size() == 1) idR = String("0") + idR;
    int id = String::toint(idR);
    String tmp("Vong dau so ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), id);
    printCentered(tmp + idR);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    String tmp1("                        ");
    String tmp2("DIEN RA TAI SVD: ");
    String s = tmp2 + this->address;
    printCentered(drawBorder(70));
    printCentered(drawOptionCenter(addSpace(this->v[0].getNameFootballTeam(), this->v[1].getNameFootballTeam(),42),70));
    printCentered(drawOptionCenter(addSpace(this->time,this->date,42),70));
    printCentered(drawOptionCenter(s,70));
    printCentered(drawBorder(70));
    cout << endl;
}

void Match::changeAddress(String newAddress)
{
    this->setAddress(newAddress);
}

void Match::changeTime(String newTime)
{
    this->setTime(newTime);
}

DBLL<Team> Match::getTwoTeam()
{
    return this->v;
}

String Match::getAddress()
{
    return this->address;
}

void Match::setAddress(String address)
{
    this->address = address;
}

String Match::getTime()
{
    return this->time;
}

void Match::setTime(String time)
{
    this->time = time;
}
void Match::addTeam(const Team &t)
{
    this->v.push_back(t);
}
void Match::setDate(String d)
{
    this->date = d;
}
String Match::getDate()
{
    return this->date;
}
void Match::setIdRound(String idr)
{
    this->idRound = idr;
}
String Match::getIdRound()
{
    return this->idRound;
}

DBLL<Match> Match::getAllMatchFromFile()
{
    ifstream f("Schedule.txt");
    DBLL<Match> v;
    if (f.is_open())
    {
        String tmp;
        String::getline(f, tmp);
        while (!f.eof())
        {
            String tmp;
            String::getline(f, tmp);
            if (String::toint(tmp[0]) != 0)
            {
                int check = 1;
                bool status = false;
                String idRound, idTeam1, idTeam2, time, date, address;
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
                        idRound = idRound + tmp[i];
                    else if (check == 2 && status)
                        idTeam1 = idTeam1 + tmp[i];
                    else if (check == 3 && status)
                        idTeam2 = idTeam2 + tmp[i];
                    else if (check == 4 && status)
                        time = time + tmp[i];
                    else if (check == 5 && status)
                        date = date + tmp[i];
                    else if (check == 6 && status)
                    {
                        address = address + tmp[i];
                        if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                            break;
                    }
                }
                Match m;
                m.setAddress(address);
                m.setTime(time);
                m.setDate(date);
                m.setIdRound(idRound);
                Team myT;
                Team t1 = myT.getTeamById(idTeam1);
                Team t2 = myT.getTeamById(idTeam2);
                m.addTeam(t1);
                m.addTeam(t2);
                m.showMatch();
            }
        }
    }
    else
    {
        cout << "Unable to open";
    }
    return v;
}

void Match::findMatchByIdTeam()
{
    system("cls");
    bool kt = true;
    cout << "QUAN LY GIAI DAU/Truy van thong tin tran dau/Truy van thong tin tran dau theo ID doi" << endl
         << endl;
    cout << "Giai dau co cac doi bong co ID sau:" << endl;
    Team t;
    t.showIDTeam();
    cout << endl;
    cout << "Nhap ID doi can tim: ";
    String idFind;
    String::getline(cin, idFind);
    ifstream f("Schedule.txt");
    if (f.is_open())
    {
        String tmp;
        String::getline(f, tmp);
        while (!f.eof())
        {
            String tmp;
            String::getline(f, tmp);
            if (String::toint(tmp[0]) != 0)
            {
                int check = 1;
                bool status = false;
                String idRound, idTeam1, idTeam2, time, date, address;
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
                        idRound = idRound + tmp[i];
                    else if (check == 2 && status)
                        idTeam1 = idTeam1 + tmp[i];
                    else if (check == 3 && status)
                        idTeam2 = idTeam2 + tmp[i];
                    else if (check == 4 && status)
                        time = time + tmp[i];
                    else if (check == 5 && status)
                        date = date + tmp[i];
                    else if (check == 6 && status)
                    {
                        address = address + tmp[i];
                        if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                            break;
                    }
                }
                if (idTeam1 == idFind || idTeam2 == idFind)
                {
                    kt = false;
                    Match m;
                    m.setAddress(address);
                    m.setTime(time);
                    m.setDate(date);
                    m.setIdRound(idRound);
                    Team myT;
                    Team t1 = myT.getTeamById(idTeam1);
                    Team t2 = myT.getTeamById(idTeam2);
                    m.addTeam(t1);
                    m.addTeam(t2);
                    m.showMatch();
                }
            }
        }
    }
    if (kt)
        cout << "Khong tim thay tran dau nao" << endl;
    cout << "Nhan Enter de tiep tuc . .";
    getchar();
}

DBLL<Match> Match::getListMatchByIdTeam()
{
    bool val = true;
    cout << "Nhap ID doi can tim: ";
    String idFind;
    String::getline(cin, idFind);
    DBLL<Match> v;
    ifstream f("Schedule.txt");
    if (f.is_open())
    {
        String tmp;
        String::getline(f, tmp);
        while (!f.eof())
        {
            String tmp;
            String::getline(f, tmp);
            if (String::toint(tmp[0]) != 0)
            {
                int check = 1;
                bool status = false;
                String idRound, idTeam1, idTeam2, time, date, address;
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
                        idRound = idRound + tmp[i];
                    else if (check == 2 && status)
                        idTeam1 = idTeam1 + tmp[i];
                    else if (check == 3 && status)
                        idTeam2 = idTeam2 + tmp[i];
                    else if (check == 4 && status)
                        time = time + tmp[i];
                    else if (check == 5 && status)
                        date = date + tmp[i];
                    else if (check == 6 && status)
                    {
                        address = address + tmp[i];
                        if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                            break;
                    }
                }
                if (idTeam1 == idFind || idTeam2 == idFind)
                {
                    Match m;
                    m.setAddress(address);
                    m.setTime(time);
                    m.setDate(date);
                    m.setIdRound(idRound);
                    Team myT;
                    Team t1 = myT.getTeamById(idTeam1);
                    Team t2 = myT.getTeamById(idTeam2);
                    m.addTeam(t1);
                    m.addTeam(t2);
                    // m.showMatch();
                    v.push_back(m);
                    val = false;
                }
            }
        }
    }
    if (val)
        cout << "Khong tim thay tran dau nao! " << endl;
    return v;
}

void Match::showdate()
{
    ifstream file("Schedule.txt");
    String tmp;
    int dem = 0;
    String::getline(file, tmp);
    String kt = " ";
    while (!file.eof())
    {
        String tmp;
        String::getline(file, tmp);
        if (String::toint(tmp[0]) != 0)
        {
            int check = 1;
            bool status = false;
            String idRound, idTeam1, idTeam2, time, date, address;
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
                    idRound = idRound + tmp[i];
                else if (check == 2 && status)
                    idTeam1 = idTeam1 + tmp[i];
                else if (check == 3 && status)
                    idTeam2 = idTeam2 + tmp[i];
                else if (check == 4 && status)
                    time = time + tmp[i];
                else if (check == 5 && status)
                    date = date + tmp[i];
                else if (check == 6 && status)
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
            // else cout << date << ", ";
        }
    }
    file.close();
}

void Match::findMatchByDay()
{
    system("cls");
    bool val = true;
    cout << "QUAN LY GIAI DAU/Truy van thong tin tran dau/Truy van thong tin tran dau theo ngay" << endl
         << endl;
    cout << "Lich thi dau cua cac doi bong dien ra trong cac ngay sau: " << endl;
    showdate();
    cout << endl;
    cout << "Nhap ngay can tim (dd/mm/yyyy): ";
    String dayFind;
    String::getline(cin, dayFind);
    dayFind = String::standadizeDay(dayFind);
    ifstream f("Schedule.txt");
    if (f.is_open())
    {
        String tmp;
        String::getline(f, tmp);
        while (!f.eof())
        {
            String tmp;
            String::getline(f, tmp);
            if (String::toint(tmp[0]) != 0)
            {
                int check = 1;
                bool status = false;
                String idRound, idTeam1, idTeam2, time, date, address;
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
                        idRound = idRound + tmp[i];
                    else if (check == 2 && status)
                        idTeam1 = idTeam1 + tmp[i];
                    else if (check == 3 && status)
                        idTeam2 = idTeam2 + tmp[i];
                    else if (check == 4 && status)
                        time = time + tmp[i];
                    else if (check == 5 && status)
                        date = date + tmp[i];
                    else if (check == 6 && status)
                    {
                        address = address + tmp[i];
                        if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                            break;
                    }
                }
                if (dayFind == date)
                {
                    Match m;
                    m.setAddress(address);
                    m.setTime(time);
                    m.setDate(date);
                    m.setIdRound(idRound);
                    Team myT;
                    Team t1 = myT.getTeamById(idTeam1);
                    Team t2 = myT.getTeamById(idTeam2);
                    m.addTeam(t1);
                    m.addTeam(t2);
                    m.showMatch();
                    val = false;
                }
            }
        }
    }
    if (val)
        cout << "Khong tim thay tran dau nao! " << endl;
    cout << "Nhan Enter de tiep tuc . .";
    getchar();
}

void Match::findMatchByNameTeam()
{
    system("cls");
    bool val = true;
    cout << "QUAN LY GIAI DAU/Truy van thong tin tran dau/Truy van thong tin tran dau theo ten 1 doi" << endl
         << endl;
    cout << "Giai dau co cac doi bong co ten sau:" << endl;
    Team t;
    t.showNameTeam();
    cout << endl;
    cout << "Nhap ten doi bong can tim: ";
    String nameTeamFind;
    String::getline(cin, nameTeamFind);
    nameTeamFind = String::standadizeString(nameTeamFind);
    ifstream f("Schedule.txt");
    if (f.is_open())
    {
        String tmp;
        String::getline(f, tmp);
        while (!f.eof())
        {
            String tmp;
            String::getline(f, tmp);
            if (String::toint(tmp[0]) != 0)
            {
                int check = 1;
                bool status = false;
                String idRound, idTeam1, idTeam2, time, date, address;
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
                        idRound = idRound + tmp[i];
                    else if (check == 2 && status)
                        idTeam1 = idTeam1 + tmp[i];
                    else if (check == 3 && status)
                        idTeam2 = idTeam2 + tmp[i];
                    else if (check == 4 && status)
                        time = time + tmp[i];
                    else if (check == 5 && status)
                        date = date + tmp[i];
                    else if (check == 6 && status)
                    {
                        address = address + tmp[i];
                        if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                            break;
                    }
                }
                Team myT;
                Team t1 = myT.getTeamById(idTeam1);
                Team t2 = myT.getTeamById(idTeam2);
                if (t1.getNameFootballTeam() == nameTeamFind || t2.getNameFootballTeam() == nameTeamFind)
                {
                    Match m;
                    m.setAddress(address);
                    m.setTime(time);
                    m.setDate(date);
                    m.setIdRound(idRound);
                    m.addTeam(t1);
                    m.addTeam(t2);
                    m.showMatch();
                    val = false;
                }
            }
        }
    }
    if (val)
        cout << "Khong tim thay tran dau nao! " << endl;
    cout << "Nhan Enter de tiep tuc . .";
    getchar();
}

void Match::findMatchByTwoNameTeam()
{
    system("cls");
    bool val = true;
    cout << "QUAN LY GIAI DAU/Truy van thong tin tran dau/Truy van thong tin tran dau theo ten 2 doi" << endl
         << endl;
    cout << "Giai dau gom cac doi bong co ten sau: " << endl;
    Team t;
    t.showNameTeam();
    cout << endl;
    cout << "Nhap ten doi thu nhat: ";
    String nameTeam1;
    String::getline(cin, nameTeam1);
    nameTeam1 = String::standadizeString(nameTeam1);
    cout << "Nhap ten doi thu hai: ";
    String nameTeam2;
    String::getline(cin, nameTeam2);
    nameTeam2 = String::standadizeString(nameTeam2);
    ifstream f("Schedule.txt");
    if (f.is_open())
    {
        String tmp;
        String::getline(f, tmp);
        while (!f.eof())
        {
            String tmp;
            String::getline(f, tmp);
            if (String::toint(tmp[0]) != 0)
            {
                int check = 1;
                bool status = false;
                String idRound, idTeam1, idTeam2, time, date, address;
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
                        idRound = idRound + tmp[i];
                    else if (check == 2 && status)
                        idTeam1 = idTeam1 + tmp[i];
                    else if (check == 3 && status)
                        idTeam2 = idTeam2 + tmp[i];
                    else if (check == 4 && status)
                        time = time + tmp[i];
                    else if (check == 5 && status)
                        date = date + tmp[i];
                    else if (check == 6 && status)
                    {
                        address = address + tmp[i];
                        if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                            break;
                    }
                }
                Team myT;
                Team t1 = myT.getTeamById(idTeam1);
                Team t2 = myT.getTeamById(idTeam2);
                if ((t1.getNameFootballTeam() == nameTeam1 && t2.getNameFootballTeam() == nameTeam2) || (t1.getNameFootballTeam() == nameTeam2 && t2.getNameFootballTeam() == nameTeam1))
                {
                    Match m;
                    m.setAddress(address);
                    m.setTime(time);
                    m.setDate(date);
                    m.setIdRound(idRound);
                    m.addTeam(t1);
                    m.addTeam(t2);
                    m.showMatch();
                    val = false;
                }
            }
        }
    }
    if (val)
        cout << "Khong tim thay tran dau nao! " << endl;
    cout << "Nhan Enter de tiep tuc . .";
    getchar();
}
Match Match::getMatchByIdRoundAndIdTwoTeam(String idR, String id1, String id2)
{
    bool val = true;
    ifstream f("Schedule.txt");
    if (f.is_open())
    {
        String tmp;
        String::getline(f, tmp);
        while (!f.eof())
        {
            String tmp;
            String::getline(f, tmp);
            if (String::toint(tmp[0]) != 0)
            {
                int check = 1;
                bool status = false;
                String idRound, idTeam1, idTeam2, time, date, address;
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
                        idRound = idRound + tmp[i];
                    else if (check == 2 && status)
                        idTeam1 = idTeam1 + tmp[i];
                    else if (check == 3 && status)
                        idTeam2 = idTeam2 + tmp[i];
                    else if (check == 4 && status)
                        time = time + tmp[i];
                    else if (check == 5 && status)
                        date = date + tmp[i];
                    else if (check == 6 && status)
                    {
                        address = address + tmp[i];
                        if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                            break;
                    }
                }
                // cout << idRound << " " << idTeam1 << " " << idTeam2 << " " << time << " " << date << " " << address << endl;
                if (idRound == idR && ((idTeam1 == id1 && idTeam2 == id2) || (idTeam1 == id2 && idTeam2 == id1)))
                {
                    Team myT;
                    Team t1 = myT.getTeamById(idTeam1);
                    Team t2 = myT.getTeamById(idTeam2);
                    Match m;
                    m.setAddress(address);
                    m.setTime(time);
                    m.setDate(date);
                    m.setIdRound(idRound);
                    m.addTeam(t1);
                    m.addTeam(t2);
                    // m.showMatch();
                    val = false;
                    return m;
                }
            }
        }
    }
    Match m;
    m.setIdRound("0");
    if (val)
        cout << "Khong tim thay tran dau nao!";
    return m;
}
void Match::updateMatch(String t, Match m1, int checkCase, String td)
{
    ifstream f("Schedule.txt");
    ofstream o("Tmp.txt");
    o << left << setw(15) << "Vong" << setw(20) << "ID Doi thu nhat" << setw(20) << "ID Doi thu hai" << setw(20) << "Thoi gian" << setw(25) << "Ngay thang nam" << setw(20) << "Dia diem" << endl;
    if (f.is_open())
    {
        String tmp;
        String::getline(f, tmp);
        while (!f.eof())
        {
            String tmp;
            String::getline(f, tmp);
            if (String::toint(tmp[0]) != 0)
            {
                int check = 1;
                bool status = false;
                String idRound, idTeam1, idTeam2, time, date, address;
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
                        idRound = idRound + tmp[i];
                    else if (check == 2 && status)
                        idTeam1 = idTeam1 + tmp[i];
                    else if (check == 3 && status)
                        idTeam2 = idTeam2 + tmp[i];
                    else if (check == 4 && status)
                        time = time + tmp[i];
                    else if (check == 5 && status)
                        date = date + tmp[i];
                    else if (check == 6 && status)
                    {
                        address = address + tmp[i];
                        if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                            break;
                    }
                }
                Team myT;
                Team t1 = myT.getTeamById(idTeam1);
                Team t2 = myT.getTeamById(idTeam2);
                Match m;
                m.setAddress(address);
                m.setTime(time);
                m.setDate(date);
                m.setIdRound(idRound);
                m.addTeam(t1);
                m.addTeam(t2);
                if (idRound == m1.getIdRound() && ((idTeam1 == m1.getIdTeam1() && idTeam2 == m1.getIdTeam2()) || (idTeam1 == m1.getIdTeam2() && idTeam2 == m1.getIdTeam1())))
                {
                    if (checkCase == 0)
                        m.setTime(t);
                    else if (checkCase == 1)
                        m.setDate(t);
                    else if (checkCase == 2)
                    {
                        m.setTime(t);
                        m.setDate(td);
                    }
                    else if (checkCase == 3)
                    {
                        m.setAddress(t);
                    }
                    m.showMatch();
                }
                o << left << setw(15) << m.getIdRound() + "," << setw(20) << m.getIdTeam1() + "," << setw(20) << m.getIdTeam2() + "," << setw(20) << m.getTime() + "," << setw(25) << m.getDate() + "," << setw(20) << m.getAddress() << endl;
            }
            else
            {
                o << "                                " << endl;
            }
        }
    }
    f.close();
    o.close();
    const char *i1("Schedule.txt");
    const char *tmp1("Tmp.txt");
    remove(i1);
    rename(tmp1, "Schedule.txt");
}

void Match::showschedule()
{
    ifstream file("Schedule.txt");
    String tmp;
    int dem = 0;
    String::getline(file, tmp);
    String kt = " ";
    cout << left << setw(15) << "ROUND" << setw(20) << "NAME TEAM 1" << setw(20) << "NAME TEAM 2" << setw(20) << "TIME" << setw(25) << "DATE" << setw(20) << "ADDRESS" << endl;
    while (!file.eof())
    {
        String tmp;
        String::getline(file, tmp);
        if (String::toint(tmp[0]) != 0)
        {
            int check = 1;
            bool status = false;
            String idRound, idTeam1, idTeam2, time, date, address;
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
                    idRound = idRound + tmp[i];
                else if (check == 2 && status)
                    idTeam1 = idTeam1 + tmp[i];
                else if (check == 3 && status)
                    idTeam2 = idTeam2 + tmp[i];
                else if (check == 4 && status)
                    time = time + tmp[i];
                else if (check == 5 && status)
                    date = date + tmp[i];
                else if (check == 6 && status)
                {
                    address = address + tmp[i];
                    if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                        break;
                }
            }
            if(String::toint(idRound)%2!=0) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            }
            else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            Team t1,t2;
            t1 = t1.getTeamById(idTeam1);
            t2 = t2.getTeamById(idTeam2);

            cout << left << setw(15) << idRound  << setw(20) << t1.getNameFootballTeam() << setw(20) << t2.getNameFootballTeam() << setw(20) << time  << setw(25) << date << setw(20) << address << endl;
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    file.close();
}

void Match::updateInforOfMatch()
{
    system("cls");
    String idRound, idTeam1, idTeam2;
    cout << "QUAN LY GIAI DAU/Cap nhat thong tin tran dau/Chinh sua thong tin tran dau" << endl
         << endl;
    showschedule();
    cout << endl;
    cout << "Nhap so vong dau: ";
    String::getline(cin, idRound);
    cout << "Nhap id doi thu nhat: ";
    String::getline(cin, idTeam1);
    cout << "Nhap id doi thu hai: ";
    String::getline(cin, idTeam2);
    if (checkMatch(idRound, idTeam1, idTeam2))
    {
        cout << "Khong tim thay tran dau nao" << endl;
        cout << "Nhan Enter de tiep tuc . .";
        getchar();
        return;
    }
    Match m = Match::getMatchByIdRoundAndIdTwoTeam(idRound, idTeam1, idTeam2);
    int lc;
    do
    {
        system("cls");
        // cout << "QUAN LY GIAI DAU/Cap nhat thong tin tran dau/Chinh sua thong tin tran dau" << endl
        //      << endl;
        // cout << "1. Thay doi thoi gian thi dau." << endl;
        // cout << "2. Thay doi ngay thi dau." << endl;
        // cout << "3. Thay doi thoi gian va ngay thi dau." << endl;
        // cout << "4. Thay doi dia diem thi dau." << endl;
        // cout << "0. Thoat." << endl;
        // cout << "Xin moi nhap lua chon: ";
        printCentered("QUAN LY GIAI DAU/Cap nhat thong tin tran dau/Chinh sua thong tin tran dau");
        cout << endl;
        printCentered(drawBorder(50));
        printCentered(drawOption("1. Thay doi thoi gian thi dau.", 50));
        printCentered(drawOption("2. Thay doi ngay thi dau.", 50));
        printCentered(drawOption("3. Thay doi thoi gian va ngay thi dau.", 50));
        printCentered(drawOption("4. Thay doi dia diem thi dau.", 50));
        printCentered(drawOption("0. Thoat.", 50));
        printCentered(drawBorder(50));
        printCentered("Nhap lua chon cua ban: ", 0);
        cin >> lc;
        cin.ignore();
        system("cls");
        if (lc == 1)
        {
            system("cls");
            cout << "QUAN LY GIAI DAU/Cap nhat thong tin tran dau/Chinh sua thong tin tran dau/Thay doi thoi gian thi dau" << endl
                 << endl;
            cout << "Nhap thoi gian thi dau moi: ";
            String timeNew;
            String::getline(cin, timeNew);
            this->updateMatch(timeNew, m, 0);
        }
        else if (lc == 2)
        {
            system("cls");
            cout << "QUAN LY GIAI DAU/Cap nhat thong tin tran dau/Chinh sua thong tin tran dau/Thay doi ngay thi dau" << endl
                 << endl;
            cout << "Nhap ngay thi dau moi (dd/mm/yyyy): ";
            String dateNew;
            String::getline(cin, dateNew);
            if (dateNew[1] == '/')
            {
                String tmp("0");
                dateNew = tmp + dateNew;
            }
            if (dateNew[4] == '/')
                dateNew.insert(3, "0");
            this->updateMatch(dateNew, m, 1);
        }
        else if (lc == 3)
        {
            system("cls");
            cout << "QUAN LY GIAI DAU/Cap nhat thong tin tran dau/Chinh sua thong tin tran dau/Thay doi thoi gian va ngay thi dau" << endl
                 << endl;
            String timeNew, dateNew;
            cout << "Nhap thoi gian thi dau moi: ";
            String::getline(cin, timeNew);
            cout << "Nhap ngay thi dau moi (dd/mm/yyyy): ";
            String::getline(cin, dateNew);
            if (dateNew[1] == '/')
            {
                String tmp("0");
                dateNew = tmp + dateNew;
            }
            if (dateNew[4] == '/')
                dateNew.insert(3, "0");
            this->updateMatch(timeNew, m, 2, dateNew);
        }
        else if (lc == 4)
        {
            system("cls");
            cout << "QUAN LY GIAI DAU/Cap nhat thong tin tran dau/Chinh sua thong tin tran dau/Thay doi dia diem thi dau" << endl
                 << endl;
            String addressNew;
            cout << "Nhap dia chi thi dau moi: ";
            String::getline(cin, addressNew);
            this->updateMatch(addressNew, m, 3);
        }
        if (lc != 0)
        {
            cout << "Nhan Enter de tiep tuc ..";
            getchar();
        }
    } while (lc != 0);
    cout << "Cap nhat thong tin tran dau thanh cong" << endl;
    cout << "Nhan phim bat ki de tiep tuc .." << endl;
}

void Match::deleteMatchByIdRoundAndTwoTeam(Match &m1)
{
    ifstream f("Schedule.txt");
    ofstream o("Tmp.txt");
    o << left << setw(15) << "Vong" << setw(20) << "ID Doi thu nhat" << setw(20) << "ID Doi thu hai" << setw(20) << "Thoi gian" << setw(25) << "Ngay thang nam" << setw(20) << "Dia diem" << endl;
    if (f.is_open())
    {
        String tmp;
        String::getline(f, tmp);
        while (!f.eof())
        {
            String tmp;
            String::getline(f, tmp);
            if (String::toint(tmp[0]) != 0)
            {
                int check = 1;
                bool status = false;
                String idRound, idTeam1, idTeam2, time, date, address;
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
                        idRound = idRound + tmp[i];
                    else if (check == 2 && status)
                        idTeam1 = idTeam1 + tmp[i];
                    else if (check == 3 && status)
                        idTeam2 = idTeam2 + tmp[i];
                    else if (check == 4 && status)
                        time = time + tmp[i];
                    else if (check == 5 && status)
                        date = date + tmp[i];
                    else if (check == 6 && status)
                    {
                        address = address + tmp[i];
                        if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                            break;
                    }
                }
                Team myT;
                Team t1 = myT.getTeamById(idTeam1);
                Team t2 = myT.getTeamById(idTeam2);
                Match m;
                m.setAddress(address);
                m.setTime(time);
                m.setDate(date);
                m.setIdRound(idRound);
                m.addTeam(t1);
                m.addTeam(t2);
                if (!(idRound == m1.getIdRound() && ((idTeam1 == m1.getIdTeam1() && idTeam2 == m1.getIdTeam2()) || (idTeam1 == m1.getIdTeam2() && idTeam2 == m1.getIdTeam1()))))
                {
                    o << left << setw(15) << m.getIdRound() + "," << setw(20) << m.getIdTeam1() + "," << setw(20) << m.getIdTeam2() + "," << setw(20) << m.getTime() + "," << setw(25) << m.getDate() + "," << setw(20) << m.getAddress() << endl;
                }
            }
            else
            {
                o << "                                " << endl;
            }
        }
    }
    f.close();
    o.close();

    const char *i1("Schedule.txt");
    const char *tmp1("Tmp.txt");
    remove(i1);
    rename(tmp1, "Schedule.txt");
}

bool Match::checkMatch(String idvong, String id1, String id2)
{
    bool kt = true;
    ifstream f("Schedule.txt");
    if (f.is_open())
    {
        String tmp;
        String::getline(f, tmp);
        while (!f.eof())
        {
            String tmp;
            String::getline(f, tmp);
            if (String::toint(tmp[0]) != 0)
            {
                int check = 1;
                bool status = false;
                String idRound, idTeam1, idTeam2, time, date, address;
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
                        idRound = idRound + tmp[i];
                    else if (check == 2 && status)
                        idTeam1 = idTeam1 + tmp[i];
                    else if (check == 3 && status)
                        idTeam2 = idTeam2 + tmp[i];
                    else if (check == 4 && status)
                        time = time + tmp[i];
                    else if (check == 5 && status)
                        date = date + tmp[i];
                    else if (check == 6 && status)
                    {
                        address = address + tmp[i];
                        if ((tmp[i + 1] == ' ' && tmp[i + 2] == ' ') || (tmp[i + 1] == ' ' && i + 1 == tmp.size() - 1))
                            break;
                    }
                }
                if (idRound == idvong && idTeam1 == id1 && idTeam2 == id2)
                {
                    kt = false;
                }
            }
        }
    }
    return kt;
}

bool Match::checkPlayer(String idcheck)
{
    bool kt = true;
    ifstream file("Player.txt");
    if (file.is_open())
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
            if (idcheck == id)
            {
                kt = false;
            }
        }
    }
    return kt;
}

void Match::showPlayerofTeam(String nameTeam)
{
    Team t;
    t.setListMember(t.getListPlayerByNameFootballTeam(nameTeam));
    cout << left << setw(10) << "ID" << setw(15) << "Ten cau thu" << setw(15) << "Ngay sinh" << setw(20) << "Dia chi" << setw(10) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(10) << "The do" << setw(10) << "Ban thang" << setw(20) << "Ten doi bong" << endl;
    for (int i = 0; i < t.getlistMember().size(); i++)
    {
        t.getlistMember()[i].show2();
    }
}

String Match::returnNameTeamByID(String Id)
{
    ifstream i("Team.txt");
    String a = "Khong tim thay ID doi bong";
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
            if (Id == id)
            {
                i.close();
                return nameTeam;
            }
        }
    }
    return a;
}

bool Match::checkidPlayerofTeam(String idd, String idct)
{
    ifstream file("Player.txt");
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
        if (nameTeam == returnNameTeamByID(idd) && id == idct)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void Match::enterResultMatch()
{
    const int maxplayer = 100;
    int goalsByPlayer[maxplayer][2];
    for (int i = 0; i < maxplayer; ++i)
    {
        goalsByPlayer[i][0] = 0;
        goalsByPlayer[i][1] = 0;
    }
    // map<pair<String, String>, int> goalsByPlayer;
    system("cls");
    String idvong, id1, id2;
    String nameTeam1,nameTeam2;
    Team t1,t2;
    cout << "QUAN LY GIAI DAU/Cap nhat thong tin tran dau/Them ket qua cho tran dau" << endl
         << endl;
    showschedule();
    cout << endl;
    cout << "Enter ID Round: ";
    String::getline(cin, idvong);
    cout << "Enter NameTeam 1: ";
    String::getline(cin, nameTeam1);
    cout << "Enter NameTeam 2: ";
    String::getline(cin, nameTeam2);
    t1 = t1.getTeamByName(nameTeam1);
    t2  = t2.getTeamByName(nameTeam2);
    id1 = t1.getIdTeam();
    id2 = t2.getIdTeam();
    if (checkMatch(idvong, id1, id2))
    {
        cout << "Khong tim thay tran dau nao!" << endl;
        cout << "Nhan Enter de tiep tuc . .";
        getchar();
        return;
    }
    String name1 = returnNameTeamByID(id1);
    String name2 = returnNameTeamByID(id2);
    Match m = Match::getMatchByIdRoundAndIdTwoTeam(idvong, id1, id2);
    int lc;
    int g1, g2;
    cout << "Nhap so ban thang cua doi thu nhat: ";
    cin >> g1;
    cout << "Nhap so ban thang cua doi thu hai: ";
    cin >> g2;
    cin.ignore();
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
    ofstream f("SavePlayer.txt", std::ios::app);
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
                    cout << "Nhap so ban thang (toi da " << g1 - dem1 << " ban): ";
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
                cout << "Nhap ID cau thu ghi ban cho doi " << name2 << ": ";
                String::getline(cin, idh);
                if (checkidPlayerofTeam(id2, idh))
                {
                    cout << "Nhap so ban thang (toi da " << g2 - dem2 << " ban): ";
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
            cout << "Cau thu co ID " << i << " ghi duoc " << m << " ban thang." << endl;
            if (checkidPlayerofTeam(id1, String::tostring(i)) == true)
                f << left << setw(10) << idvong + "," << setw(10) << id1 + "," << setw(15) << returnNameTeamByID(id1) + "," << setw(10) << String::tostring(i) + "," << setw(10) << String::tostring(m) << endl;
            else
                f << left << setw(10) << idvong + "," << setw(10) << id2 + "," << setw(15) << returnNameTeamByID(id2) + "," << setw(10) << String::tostring(i) + "," << setw(10) << String::tostring(m) << endl;
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
    cout << "Nhan Enter de tiep tuc . .";
    getchar();
    do
    {
        system("cls");
        // cout << "QUAN LY GIAI DAU/Cap nhat thong tin tran dau/Them ket qua cho tran dau" << endl
        //      << endl;
        // cout << "1. Nhap the vang cho cau thu" << endl;
        // cout << "2. Nhap the do cho cau thu" << endl;
        // cout << "0. Quay lai" << endl;
        // cout << "Nhap lua chon: ";
        printCentered("QUAN LY GIAI DAU/Cap nhat thong tin tran dau/Them ket qua cho tran dau");
        cout << endl;
        printCentered(drawBorder(50));
        printCentered(drawOption("1. Nhap the vang cho cau thu.", 50));
        printCentered(drawOption("2. Nhap the do cho cau thu.", 50));
        printCentered(drawOption("0. Thoat.", 50));
        printCentered(drawBorder(50));
        printCentered("Nhap lua chon cua ban: ", 0);
        cin >> lc;
        cin.ignore();
        if (lc == 1)
        {
            system("cls");
            String id, numYlCard;
            cout << "QUAN LY GIAI DAU/Cap nhat thong tin tran dau/Them ket qua cho tran dau/Nhap the vang cho cau thu" << endl
                 << endl;
            cout << "Danh sach cau thu cua doi bong co ID la " << id1 << " (" << name1 << ")" << endl;
            showPlayerofTeam(name1);
            cout << endl;
            cout << "Danh sach cau thu cua doi bong co ID la " << id2 << " (" << name2 << ")" << endl;
            showPlayerofTeam(name2);
            cout << "Nhap ID cau thu bi the vang: ";
            String::getline(cin, id);
            if (checkPlayer(id) == false)
            {

                cout << "Nhap so the vang: ";
                String::getline(cin, numYlCard);
                Player::updatePlayerAfterMatch(id, String::toint(numYlCard), 0, 0);
            }
            else
            {
                cout << "Cau thu co ID " << id << " khong ton tai" << endl;
                cout << "Nhan Enter de tiep tuc . .";
                getchar();
            }
        }
        else if (lc == 2)
        {
            system("cls");
            String id;
            cout << "QUAN LY GIAI DAU/Cap nhat thong tin tran dau/Them ket qua cho tran dau/Nhap the do cho cau thu" << endl
                 << endl;
            cout << "Danh sach cau thu cua doi bong co ID la " << id1 << " (" << name1 << ")" << endl;
            showPlayerofTeam(name1);
            cout << endl;
            cout << "Danh sach cau thu cua doi bong co ID la " << id2 << " (" << name2 << ")" << endl;
            showPlayerofTeam(name2);
            cout << "Nhap ID cau thu bi the do: ";
            String::getline(cin, id);
            if (checkPlayer(id) == false)
            {
                Player::updatePlayerAfterMatch(id, 0, 1, 0);
            }
            else
            {
                cout << "Cau thu co ID " << id << " khong ton tai" << endl;
                cout << "Nhan Enter de tiep tuc . .";
                getchar();
            }
        }
    } while (lc != 0);
    cout << "Them ket qua thanh cong" << endl;
    cout << "Nhan Enter de tiep tuc . ." << endl;
    getchar();
}
void Match::saveToHistoryMatch(String idT1, String idT2, int g1, int g2)
{
    ofstream o("HistoryMatch.txt", ios::app);
    ifstream f("HistoryMatch.txt");
    String newdate = this->getDate();
    if (newdate[1] == '/')
    {
        String tmp("0");
        newdate = tmp + newdate;
    }
    if (newdate[4] == '/')
        newdate.insert(3, "0");
    f.seekg(0, ios::end);
    if (f.tellg() == 0)
    {
        o << left << setw(15) << "Vong" << setw(20) << "ID Doi thu nhat" << setw(20) << "Ban thang doi 1" << setw(20) << "ID Doi thu hai" << setw(20) << "Ban thang doi 2" << setw(20) << "Thoi gian" << setw(25) << "Ngay thang nam" << setw(20) << "Dia diem";
        f.close();
    }
    if (o.is_open())
    {
        o << endl
          << left << setw(15) << this->getIdRound() + "," << setw(20) << idT1 + "," << setw(20) << String::tostring(g1) + "," << setw(20) << idT2 + "," << setw(20) << String::tostring(g2) + "," << setw(20) << this->getTime() + "," << setw(25) << newdate + "," << setw(20) << this->getAddress();
    }
}
String Match::getIdTeam1()
{
    return this->v[0].getIdTeam();
}

String Match::getIdTeam2()
{
    return this->v[1].getIdTeam();
}
Match Match::getMatchFromHistoryMatch(String idRound,String idTeam1,String idTeam2) {
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
       if(idRound == idr && ((id1 == idTeam1 && id2 == idTeam2) || id1 == idTeam2 && id2 == idTeam1)){
            Team t1,t2;
            t1 = t1.getTeamById(idTeam1);
            t2 = t2.getTeamById(idTeam2);
            Match m(t1,t2,address,time,date);
            m.setIdRound(idr);
            return m;
       }
    }
}