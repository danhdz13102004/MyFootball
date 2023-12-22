#include "Coach.h"
#include <iomanip>
#include <iostream>
#include "../PrintCenter.h"
using namespace std;

Coach::Coach(String m, String t, String ns, String ad, String nameTeam)
    : Human(m, t, ns, ad), nameFootballTeam(nameTeam)
{
    // cout << "Call Constructor of Coach" << endl;
}

Coach::~Coach()
{
    // cout << "Call Destructor of Coach" << endl;
}

void Coach::show()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    String id = "ID", tenhlv = "The name Coach", date = "Date", add = "Address", age = "Age", namefb = "The name football";
    int console = 110;
    int colum = (console - id.size() - tenhlv.size() - date.size() - add.size() - age.size() - namefb.size()) / 2;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << setw(colum - 8) << id << setw(colum) << tenhlv << setw(colum) << date << setw(colum) << add << setw(colum) << age << setw(colum) << namefb << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << setw(colum - 8) << this->id << setw(colum) << this->name << setw(colum) << this->dateOfBirth << setw(colum) << this->address << setw(colum) << this->age << setw(colum) << this->nameFootballTeam << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void Coach::setNameFootballTeam(String name)
{
    this->nameFootballTeam = name;
}

String Coach::getNameFootballTeam()
{
    return this->nameFootballTeam;
}

void Coach::enterInforCoach()
{
    system("cls");
    cout << "CREATE A NEW LEAGUE/Add a new team/Input data from the keyboard/Add coach" << endl
         << endl;
    String id, name, date, address;
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
        date.insert(3, "0");
    cout << "Enter the address: ";
    String::getline(cin, address);
    this->setId(id);
    this->setName(String::standadizeString(name));
    this->setDateOfBirth(date);
    this->setAddress(address);
    this->setAgeByDateOfBirth(date);
    this->setNameFootballTeam("ABC");
}

void Coach::saveInforIntoFile(ofstream &o)
{
    char arrAge[10], numberClo[10], ylCard[10], rCard[10], goal[10];
    sprintf(arrAge, "%d", this->age);
    String myage(arrAge);
    ifstream f("Coach.txt");
    if (f)
    {
        f.seekg(0, ios::end);
        if (f.tellg() == 0)
        {
            o << left << setw(10) << "ID" << setw(25) << "Ten HLV" << setw(17) << "Ngay sinh" << setw(15) << "Dia chi" << setw(15) << "Tuoi" << setw(15) << "Ten doi bong";
        }
        f.close();
    }
    else
    {
        cout << "Failed";
    }
    if (o.is_open())
    {
        o << endl 
        << left << setw(10) << this->id + "," << setw(25) << this->name + "," << setw(17) << this->dateOfBirth + "," << setw(15) << this->address + "," << setw(15) << myage + "," << setw(15) << this->nameFootballTeam;
    }
}

Coach Coach::getCoachByNameFootballTeam(String nameFB)
{
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
            if (nameFB == nameTeam)
            {
                Coach c(id, name, date, address, nameTeam);
            }
        }
    }
    return Coach();
}

void Coach::updateCoach()
{
    bool kt = true;
    system("cls");
    String ma;
    cout << "LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Edit coach information" << endl
         << endl;
    // cout << "The tournament consists of coaches with the following citizen identification card:" << endl;
    showCoach();
    cout << endl;
    cout << "Enter the citizen identification card: ";
    String::getline(cin, ma);

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
            if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
            {
                break;
            }
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

            if (ma == id)
            {
                kt = false;
                int k, u;
                do
                {
                    system("cls");
                    cout << "LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Edit coach information" << endl
                         << endl;
                    cout << endl;
                    printCentered(drawBorder(50));
                    printCentered(drawOption("1. The coach name.", 50));
                    printCentered(drawOption("2. The date.", 50));
                    printCentered(drawOption("3. The address.", 50));
                    printCentered(drawOption("0. Back.", 50));
                    printCentered(drawBorder(50));
                    printCentered("Please enter your choice: ", 0);
                    cin >> k;
                    cin.ignore();
                    String newName1, newName, newDate, tmpnewdate, newAddress, newNameTeam;
                    time_t ti = time(0);
                    tm *now = localtime(&ti);
                    int newage, d, m, y, day, month, year;
                    String thaythe;
                    int kiemtra;
                    bool trangthai;
                    fstream fileT("Team.txt", ios::in);
                    fstream tempFileT("tempTeam.txt", ios::out | ios::app);
                    switch (k)
                    {
                    case 1:
                        system("cls");
                        cout << "LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Edit coach information/The coach name" << endl
                             << endl;
                        thaythe = name;
                        cout << "Enter the coach name: ";
                        String::getline(cin, newName1);
                        newName = standardizeName(newName1);
                        name = newName;

                        tempFileT << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Cau Thu," << setw(25) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Thu hang" << endl;
                        if (fileT.is_open() && tempFileT.is_open())
                        {
                            String temp;
                            String::getline(fileT, temp);
                            while (!fileT.eof())
                            {
                                String::getline(fileT, temp);
                                kiemtra = 1;
                                trangthai = false;
                                String idT, nameTeamT, numMemberT, nameCoachT, numberGoalT, numberLoseGoalT, differenceT, pointT, rankT;
                                for (int i = 0; i < temp.size(); i++)
                                {
                                    if (temp[i] != ' ')
                                        trangthai = true;
                                    if (temp[i] == ',')
                                    {
                                        trangthai = false;
                                        kiemtra++;
                                        continue;
                                    }
                                    if (kiemtra == 1 && trangthai)
                                        idT = idT + temp[i];
                                    else if (kiemtra == 2 && trangthai)
                                        nameTeamT = nameTeamT + temp[i];
                                    else if (kiemtra == 3 && trangthai)
                                        numMemberT = numMemberT + temp[i];
                                    else if (kiemtra == 4 && trangthai)
                                        nameCoachT = nameCoachT + temp[i];
                                    else if (kiemtra == 5 && trangthai)
                                        numberGoalT = numberGoalT + temp[i];
                                    else if (kiemtra == 6 && trangthai)
                                        numberLoseGoalT = numberLoseGoalT + temp[i];
                                    else if (kiemtra == 7 && trangthai)
                                        differenceT = differenceT + temp[i];
                                    else if (kiemtra == 8 && trangthai)
                                        pointT = pointT + temp[i];
                                    else if (kiemtra == 9 && trangthai && temp[i] != '\n')
                                    {
                                        rankT = rankT + temp[i];
                                        if ((temp[i + 1] == ' ' && temp[i + 2] == ' ') || (temp[i + 1] == ' ' && i + 1 == temp.size() - 1))
                                            break;
                                    }
                                }
                                if (thaythe == nameCoachT)
                                {
                                    nameCoachT = newName;
                                    // tempFileT << left << setw(10) << id + "," << setw(20) << nameTeam + "," << setw(20) << numMember + "," << setw(25) << nameCoach + "," << setw(15) << numberGoal + "," << setw(15) << numberLoseGoal + "," << setw(15) << difference + "," << setw(15) << point + "," << setw(15) << rank << endl;
                                    tempFileT << left << setw(10) << idT + "," << setw(20) << nameTeamT + "," << setw(20) << numMemberT + "," << setw(25) << nameCoachT + "," << setw(15) << numberGoalT + "," << setw(15) << numberLoseGoalT + "," << setw(15) << differenceT + "," << setw(15) << pointT + "," << setw(15) << rankT << endl;
                                }
                                else
                                    tempFileT << temp << endl;
                            }
                            fileT.close();
                            tempFileT.close();
                            remove("Team.txt");
                            rename("tempTeam.txt", "Team.txt");
                        }
                        else
                            cout << "Failed";

                        break;
                    case 2:
                        system("cls");
                        cout << "LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Edit coach information/The date" << endl
                             << endl;
                        cout << "Enter the date: ";
                        String::getline(cin, newDate);
                        if (newDate[1] == '/')
                        {
                            String tmp("0");
                            newDate = tmp + newDate;
                        }
                        if (newDate[4] == '/')
                            newDate.insert(3, "0");
                        date = newDate;
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
                        cout << "LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Edit coach information/The address" << endl
                             << endl;
                        cout << "Enter the address: ";
                        String::getline(cin, newAddress);
                        address = newAddress;
                        break;
                    case 0:
                        return;
                    default:
                        break;
                    }
                    // cout << "Press key 1 if you want to continue editing, press key 0 if you want to exit: ";
                    // cin >> u;

                } while (false);
                tempFile << left << setw(10) << id + "," << setw(25) << name + "," << setw(17) << date + "," << setw(15) << address + "," << setw(15) << age + "," << setw(15) << nameTeam << endl;
            }
            else
            {
                tempFile << tmp << endl;
            }
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
    if (kt)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "The coach has a citizen identification card " << ma << " not found" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    // cout << "Successfully updated" << endl;
    cout << "Press the Enter key to continue . .";
    getchar();
}

void Coach::dkcDeleteCoach(String tendoi, String newname)
{
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
            if (tendoi == nameTeam)
            {
                nameCoach = newname;
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
        cout << "Khong mo dc file";
}

String Coach::nameCoachbynameFB(String tendb)
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

        if (tendb == nameTeam)
        {
            file.close();
            return nameCoach;
        }
    }
    file.close();
    return notf;
}

String Coach::returnnameCoach(String nameteam)
{
    ifstream file("Coach.txt");
    String tmp;
    String notf = "Not found";
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

        if (nameTeam == nameteam)
        {
            file.close();
            return name;
        }
    }
    file.close();
    return notf;
}

String Coach::changeCoach()
{
    cout << "Enter the name of the team that needs to change coach: ";
    String nameteam;
    String::getline(cin, nameteam);
    nameteam = String::standadizeString(nameteam);
    bool kt = true;
    String ma, thaythe;
    fstream file("Coach.txt", ios::in);
    fstream tempFile("tempCoach.txt", ios::out | ios::app);
    tempFile << left << setw(10) << "ID" << setw(25) << "Ten HLV" << setw(17) << "Ngay sinh" << setw(15) << "Dia chi" << setw(15) << "Tuoi" << setw(15) << "Ten doi bong";
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
            if (name == nameCoachbynameFB(nameteam))
            {
                kt = false;
                thaythe = nameTeam;
            }
            else
            {
                tempFile << endl << tmp;
            }
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
    Coach c;
    c.enterInforCoach();
    c.setNameFootballTeam(nameteam);
    ofstream o("Coach.txt", ios::app);
    c.saveInforIntoFile(o);
    return nameteam;
    //dkcDeleteCoach(nameteam, returnnameCoach(nameteam));
}

void Coach::addCoachFromFile()
{
    cout << "CREATE A NEW LEAGUE/Add a new team/Input data from the file" << endl
         << endl;
    while (true)
    {
        char filename[256];
        cout << "Enter the file name containing the coachs: ";
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
                Coach c(id, name, date, address, nameTeam);
                ofstream o("Coach.txt", ios::app);
                c.saveInforIntoFile(o);
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

void Coach::showIDCoach()
{
    ifstream f("Coach.txt");
    int lineCount = 0;
    String line;
    String::getline(f, line);
    while (!f.eof())
    {
        String::getline(f, line);
        lineCount++;
    }
    f.close();
    ifstream file("Coach.txt");
    int dem = 0;
    String tmp;
    String::getline(file, tmp);
    // cout << left << setw(10) << "ID" << setw(20) << "Ten HLV" << setw(20) << "Ngay sinh" << setw(30) << "Dia chi" << setw(20) << "Tuoi" << setw(20) << "Ten doi bong" << endl;
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
        dem++;
        if (lineCount == dem)
            cout << id;
        else
            cout << id << ", ";
    }
    file.close();
}

void Coach::showNameCoach()
{
    ifstream f("Coach.txt");
    int lineCount = 0;
    String line;
    String::getline(f, line);
    while (!f.eof())
    {
        String::getline(f, line);
        lineCount++;
    }
    f.close();
    ifstream file("Coach.txt");
    int dem = 0;
    String tmp;
    String::getline(file, tmp);
    // cout << left << setw(10) << "ID" << setw(20) << "Ten HLV" << setw(20) << "Ngay sinh" << setw(30) << "Dia chi" << setw(20) << "Tuoi" << setw(20) << "Ten doi bong" << endl;
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
        dem++;
        if (lineCount == dem)
            cout << name;
        else
            cout << name << ", ";
    }
    file.close();
}

void Coach::showCoach()
{
    ifstream file("Coach.txt");
    ofstream save("Savedata.txt", ios::out | ios::app);
    String tmp;
    String::getline(file, tmp);
    String id = "ID", tenhlv = "The name Coach", date = "Date", add = "Address", age = "Age", namefb = "The name football";
    int console = 110;
    int colum = (console - id.size() - tenhlv.size() - date.size() - add.size() - age.size() - namefb.size()) / 2;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    save << left << setw(colum - 8) << id << setw(colum) << tenhlv << setw(colum) << date << setw(colum) << add << setw(colum) << age << setw(colum) << namefb << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << setw(colum - 8) << id << setw(colum) << tenhlv << setw(colum) << date << setw(colum) << add << setw(colum) << age << setw(colum) << namefb << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    // cout << left << setw(10) << "ID" << setw(20) << "Ten HLV" << setw(20) << "Ngay sinh" << setw(30) << "Dia chi" << setw(20) << "Tuoi" << setw(20) << "Ten doi bong" << endl;
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
        save << left << setw(colum - 8) << id << setw(colum) << name << setw(colum) << date << setw(colum) << address << setw(colum) << age << setw(colum) << nameTeam << endl;
        cout << setw(colum - 8) << id << setw(colum) << name << setw(colum) << date << setw(colum) << address << setw(colum) << age << setw(colum) << nameTeam << endl;
        // cout << left << setw(10) << id + "," << setw(20) << name + "," << setw(20) << date + "," << setw(30) << address + "," << setw(20) << age + "," << setw(20) << nameTeam << endl;
    }
    file.close();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printCentered(drawBorder(202));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}