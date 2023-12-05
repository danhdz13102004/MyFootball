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
    // String mynameFbTeam(nameFbTeam);
    // cout << this->nameFootballTeam << endl;
    cout << left << setw(10) << "ID" << setw(15) << "Ten cau thu" << setw(15) << "Ngay sinh" << setw(20) << "Dia chi" << setw(10) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(10) << "The do" << setw(10) << "Ban thang" << setw(20) << "Ten doi bong" << endl;
    cout << left << setw(10) << this->id << setw(15) << this->name << setw(15) << this->dateOfBirth << setw(20) << this->address << setw(10) << myage << setw(15) << myNumberClo << setw(15) << myYlCard << setw(10) << myRCard << setw(10) << myGoal << setw(20) << this->nameFootballTeam << endl;
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
    cout << left << setw(10) << this->id << setw(15) << this->name << setw(15) << this->dateOfBirth << setw(20) << this->address << setw(10) << myage << setw(15) << myNumberClo << setw(15) << myYlCard << setw(10) << myRCard << setw(10) << myGoal << setw(20) << this->nameFootballTeam << endl;
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
            o << left << setw(10) << "ID" << setw(15) << "Ten cau thu" << setw(15) << "Ngay sinh" << setw(20) << "Dia chi" << setw(10) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(10) << "The do" << setw(10) << "Ban thang" << setw(20) << "Ten doi bong";
            ;
        }
        f.close();
    }
    if (check == 1)
    {
        o << left << setw(10) << "ID" << setw(15) << "Ten cau thu" << setw(15) << "Ngay sinh" << setw(20) << "Dia chi" << setw(10) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(10) << "The do" << setw(10) << "Ban thang" << setw(20) << "Ten doi bong";
    }

    if (o.is_open())
    {
        o << endl
          << left << setw(10) << this->id + "," << setw(15) << this->name + "," << setw(15) << this->dateOfBirth + "," << setw(20) << this->address + "," << setw(10) << myage + "," << setw(15) << myNumberClo + "," << setw(15) << myYlCard + "," << setw(10) << myRCard + "," << setw(10) << myGoal + "," << setw(20) << this->nameFootballTeam;
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
    cout << "KHOI TAO GIAI DAU/Them mot doi bong/Them doi bong thu cong/Them cau thu vao doi bong" << endl
         << endl;
    cout << "Nhap CCCD cua cau thu: ";
    String::getline(cin, id);
    cout << "Nhap ho va ten cua cau thu: ";
    String::getline(cin, name);
    cout << "Nhap ngay thang nam sinh (dd/mm/yyyy): ";
    String::getline(cin, date);
    if (date[1] == '/')
    {
        String tmp("0");
        date = tmp + date;
    }
    if (date[4] == '/')
        date.String::insert(3, "0");
    cout << "Nhap dia chi cua cau thu: ";
    String::getline(cin, address);
    cout << "Nhap so ao: ";
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
    cout << "QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV/Cap nhat thong tin cau thu" << endl
         << endl;
    cout << "Giai dau co cac cau thu co CCCD sau:" << endl;
    showIDPlayer();
    cout << endl;
    cout << "Nhap CCCD cua cau thu can chinh sua: ";
    String::getline(cin, ma);
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
                    String newname, newdate, tmpnewdate, newadd, newnamefb;
                    int newage, newnum, newyl, newr, newg, d, m, y, year, month, day;
                    time_t ti = time(0);
                    tm *now = localtime(&ti);
                    // cout << "QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV/Cap nhat thong tin cau thu" << endl
                    //      << endl;
                    // cout << "1. Chinh sua Ten cua cau thu" << endl;
                    // cout << "2. Chinh sua Ngay sinh cua cau thu" << endl;
                    // cout << "3. Chinh sua Dia chi cua cau thu" << endl;
                    // // cout << "4. Chinh sua Tuoi cua cau thu" << endl;
                    // cout << "4. Chinh sua So ao cua cau thu" << endl;
                    // cout << "5. Chinh sua The vang cua cau thu" << endl;
                    // cout << "6. Chinh sua The do cua cau thu" << endl;
                    // cout << "7. Chinh sua so ban thang cua cau thu" << endl;
                    // cout << "0. Thoat" << endl;
                    // // cout << "8. Chinh sua ten doi bong cua cau thu" << endl; // chinh sua o day thi ben team cung phai update theo va nguoc lai
                    // cout << "Moi nhap lua chon: ";
                    printCentered("QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV/Cap nhat thong tin cau thu");
                    cout << endl;
                    printCentered(drawBorder(50));
                    printCentered(drawOption("1. Chinh sua Ten cua cau thu.", 50));
                    printCentered(drawOption("2. Chinh sua Ngay sinh cua cau thu.", 50));
                    printCentered(drawOption("3. Chinh sua Dia chi cua cau thu.", 50));
                    printCentered(drawOption("4. Chinh sua So ao cua cau thu.", 50));
                    printCentered(drawOption("5. Chinh sua The vang cua cau thu.", 50));
                    printCentered(drawOption("6. Chinh sua The do cua cau thu.", 50));
                    //printCentered(drawOption("7. Chinh sua so ban thang cua cau thu.", 50));
                    printCentered(drawOption("0. Thoat.", 50));
                    printCentered(drawBorder(50));
                    printCentered("Nhap lua chon cua ban: ", 0);
                    int t;
                    cin >> t;
                    cin.ignore();
                    switch (t)
                    {
                    case 1:
                        system("cls");
                        cout << "QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV/Cap nhat thong tin cau thu/Chinh sua Ten cua cau thu" << endl
                             << endl;
                        cout << "Nhap ten cau thu: ";
                        String::getline(cin, newname);
                        name = newname;
                        break;
                    case 2:
                        system("cls");
                        cout << "QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV/Cap nhat thong tin cau thu/Chinh sua Ngay sinh cua cau thu" << endl
                             << endl;
                        cout << "Nhap ngay sinh cau thu: ";
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
                        cout << "QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV/Cap nhat thong tin cau thu/Chinh sua Dia chi cua cau thu" << endl
                             << endl;
                        cout << "Nhap dia chi cau thu: ";
                        String::getline(cin, newadd);
                        address = newadd;
                        break;
                    case 4:
                        system("cls");
                        cout << "QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV/Cap nhat thong tin cau thu/Chinh sua So ao cua cau thu" << endl
                             << endl;
                        cout << "Nhap so ao cua cau thu: ";
                        cin >> newnum;
                        numberClo = String::tostring(newnum);
                        break;
                    case 5:
                        system("cls");
                        cout << "QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV/Cap nhat thong tin cau thu/Chinh sua so the vang cua cau thu" << endl
                             << endl;
                        cout << "Nhap so the vang cua cau thu: ";
                        cin >> newyl;
                        yellowCard = String::tostring(newyl);
                        break;
                    case 6:
                        system("cls");
                        cout << "QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV/Cap nhat thong tin cau thu/Chinh sua so the do cua cau thu" << endl
                             << endl;
                        cout << "Nhap so the do cua cau thu: ";
                        cin >> newr;
                        redCard = String::tostring(newr);
                        break;
                    // case 7:
                    //     system("cls");
                    //     cout << "QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV/Cap nhat thong tin cau thu/Chinh sua so ban thang cua cau thu" << endl
                    //          << endl;
                    //     cout << "Nhap so ban thang cua cau thu: ";
                    //     cin >> newg;
                    //     goal = String::tostring(newg);
                    //     break;
                    // case 8:
                    //     cout << "Nhap ten doi bong moi cua cau thu: ";
                    //     String::getline(cin, newnamefb);
                    //     nameTeam = newnamefb;
                    //     break;
                    case 0:
                        return;
                    default:
                        break;
                    }

                    cout << "Go 1 ban muon tiep tuc chinh sua, 0 neu muon thoat: ";
                    cin >> u;
                } while (u == 1);
                tempFile << left << setw(10) << id + "," << setw(15) << name + "," << setw(15) << date + "," << setw(20) << address + "," << setw(10) << age + "," << setw(15) << numberClo + "," << setw(15) << yellowCard + "," << setw(10) << redCard + "," << setw(10) << goal + "," << setw(20) << nameTeam << endl;
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
        cout << "Khong mo dc file";
    if (kt)
        cout << "Cau thu co CCCD " << ma << " khong ton tai"
             << endl;
    cout << "Cap nhat thong tin thanh cong" << endl;
    cout << "Nhan Enter de tiep tuc . ." << endl;
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
    o << left << setw(10) << "ID" << setw(15) << "Ten cau thu" << setw(15) << "Ngay sinh" << setw(20) << "Dia chi" << setw(10) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(10) << "The do" << setw(10) << "Ban thang" << setw(20) << "Ten doi bong";
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
    o << left << setw(10) << "ID" << setw(15) << "Ten cau thu" << setw(15) << "Ngay sinh" << setw(20) << "Dia chi" << setw(10) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(10) << "The do" << setw(10) << "Ban thang" << setw(20) << "Ten doi bong";
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
void Player::resetPlayer(String idCheck,int g) {
    ofstream o("Tmp.txt");
    o << left << setw(10) << "ID" << setw(15) << "Ten cau thu" << setw(15) << "Ngay sinh" << setw(20) << "Dia chi" << setw(10) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(10) << "The do" << setw(10) << "Ban thang" << setw(20) << "Ten doi bong";
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
    tempFile << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Cau Thu," << setw(15) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Thu hang" << endl;
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
                tempFile << left << setw(10) << id + "," << setw(20) << nameTeam + "," << setw(20) << numMember + "," << setw(15) << nameCoach + "," << setw(15) << numberGoal + "," << setw(15) << numberLoseGoal + "," << setw(15) << difference + "," << setw(15) << point + "," << setw(15) << rank << endl;
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
        cout << "Khong mo dc file";
}

void Player::deletePlayerById()
{
    bool kt = true;
    system("cls");
    String ma, thaythe;
    cout << "QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV/Xoa cau thu" << endl
         << endl;
    cout << "Giai dau co cac cau thu co CCCD sau:" << endl;
    showIDPlayer();
    cout << endl;
    cout << "Nhap CCCD cua cau thu can xoa: ";
    String::getline(cin, ma);
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
        cout << "Khong mo dc file";
    if (kt)
        cout << "Cau thu co ID " << ma << " khong ton tai" << endl
             << endl;
    dkcdeletePlayer(thaythe);
    cout << "Xoa thong tin thanh cong" << endl;
    cout << "Nhan Enter de tiep tuc . ." << endl;
    getchar();
}
void Player::addPlayerFromFile()
{
    while(true) {
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
            cout << "The file does not exist. Please enter again." << endl;
        }

    }
}

ostream &operator<<(ostream &o, const Player &p)
{
    o << endl
      << left << setw(10) << p.id << setw(15) << p.name << setw(15) << p.dateOfBirth << setw(20) << p.address + "," << setw(10) << p.age << setw(15) << p.numberClothes << setw(15) << p.yellowCard << setw(10) << p.redCard << setw(10) << p.goal << setw(20) << p.nameFootballTeam << endl;
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
    //cout << left << setw(10) << "ID" << setw(15) << "Ten cau thu" << setw(15) << "Ngay sinh" << setw(20) << "Dia chi" << setw(10) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(10) << "The do" << setw(10) << "Ban thang" << setw(20) << "Ten doi bong" << endl;
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
        if(lineCount == dem)
            cout << id;
        else cout << id << ", ";
    }
    file.close();    
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
    //cout << left << setw(10) << "ID" << setw(15) << "Ten cau thu" << setw(15) << "Ngay sinh" << setw(20) << "Dia chi" << setw(10) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(10) << "The do" << setw(10) << "Ban thang" << setw(20) << "Ten doi bong" << endl;
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
        if(lineCount == dem)
            cout << name;
        else cout << name << ", ";
    }
    file.close();    
}

void Player::showPlayer()
{
    ifstream file("Player.txt");
    String tmp;
    String::getline(file, tmp);
    cout << left << setw(10) << "ID" << setw(15) << "Ten cau thu" << setw(15) << "Ngay sinh" << setw(20) << "Dia chi" << setw(10) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(10) << "The do" << setw(10) << "Ban thang" << setw(20) << "Ten doi bong" << endl;
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
        cout << left << setw(10) << id + "," << setw(15) << name + "," << setw(15) << date + "," << setw(20) << address + "," << setw(10) << age + "," << setw(15) << numberClo + "," << setw(15) << yellowCard + "," << setw(10) << redCard + "," << setw(10) << goal + "," << setw(20) << nameTeam << endl;
    }
    file.close();
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
    String tmp;
    String::getline(file, tmp);
    cout << left << setw(10) << "ID" << setw(15) << "Ten cau thu" << setw(15) << "Ngay sinh" << setw(20) << "Dia chi" << setw(10) << "Tuoi" << setw(15) << "So ao" << setw(15) << "The vang" << setw(10) << "The do" << setw(10) << "Ban thang" << setw(20) << "Ten doi bong" << endl;
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
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << left << setw(10) << id + "," << setw(15) << name + "," << setw(15) << date + "," << setw(20) << address + "," << setw(10) << age + "," << setw(15) << numberClo + "," << setw(15) << yellowCard + "," << setw(10) << redCard + "," << setw(10) << goal + "," << setw(20) << nameTeam << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }
        else cout << left << setw(10) << id + "," << setw(15) << name + "," << setw(15) << date + "," << setw(20) << address + "," << setw(10) << age + "," << setw(15) << numberClo + "," << setw(15) << yellowCard + "," << setw(10) << redCard + "," << setw(10) << goal + "," << setw(20) << nameTeam << endl;
    }
    file.close();
}