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
    cout << left << setw(10) << "ID" << setw(20) << "Ten HLV" << setw(20) << "Ngay sinh" << setw(30) << "Dia chi" << setw(20) << "Tuoi" << setw(20) << "Ten doi bong" << endl;
    cout << left << setw(10) << this->id << setw(20) << this->name << setw(20) << this->dateOfBirth << setw(30) << this->address << setw(20) << this->age << setw(20) << this->nameFootballTeam << endl;
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
    String id, name, date, address;
    cout << "KHOI TAO GIAI DAU/Them mot doi bong/Them doi bong thu cong/Them HLV cho doi bong" << endl
         << endl;
    cout << "Nhap CCCD cua HLV: ";
    String::getline(cin, id);
    cout << "Nhap ho va ten cua HLV: ";
    String::getline(cin, name);
    cout << "Nhap ngay thang nam sinh (dd/mm/yyyy): ";
    String::getline(cin, date);
    if (date[1] == '/')
    {
        String tmp("0");
        date = tmp + date;
    }
    if (date[4] == '/')
        date.insert(3, "0");
    cout << "Nhap dia chi cua hlv: ";
    String::getline(cin, address);
    // cin.ignore();
    // Cap nhat thong tin HLV
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
            o << left << setw(10) << "ID" << setw(20) << "Ten HLV" << setw(20) << "Ngay sinh" << setw(30) << "Dia chi" << setw(20) << "Tuoi" << setw(20) << "Ten doi bong";
        }
        f.close();
    }
    else
    {
        cout << "K mo tep duoc";
    }
    if (o.is_open())
    {
        o << endl
          << left << setw(10) << this->id + "," << setw(20) << this->name + "," << setw(20) << this->dateOfBirth + "," << setw(30) << this->address + "," << setw(20) << myage + "," << setw(20) << this->nameFootballTeam;
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
    cout << "QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV/Cap nhat thong tin HLV" << endl
         << endl;
    cout << "Giai dau co cac HLV co CCCD sau:" << endl;
    showIDCoach();
    cout << endl;
    cout << "Nhap CCCD cua HLV can chinh sua: ";
    String::getline(cin, ma);

    fstream file("Coach.txt", ios::in);
    fstream tempFile("tempCoach.txt", ios::out | ios::app);
    tempFile << left << setw(10) << "ID" << setw(20) << "Ten HLV" << setw(20) << "Ngay sinh" << setw(30) << "Dia chi" << setw(20) << "Tuoi" << setw(20) << "Ten doi bong" << endl;

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

            if (ma == id)
            {
                kt = false;
                int k, u;
                do
                {
                    system("cls");
                    // cout << "QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV/Cap nhat thong tin HLV" << endl
                    //      << endl;
                    // cout << "1. Chinh sua Ten cua HLV" << endl;
                    // cout << "2. Chinh sua Ngay sinh cua HLV" << endl;
                    // cout << "3. Chinh sua Dia chi cua HLV" << endl;
                    // cout << "0. Thoat" << endl;
                    printCentered("QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV/Cap nhat thong tin HLV");
                    cout << endl;
                    printCentered(drawBorder(50));
                    printCentered(drawOption("1. Chinh sua Ten cua HLV.", 50));
                    printCentered(drawOption("2. Chinh sua Ngay sinh cua HLV.", 50));
                    printCentered(drawOption("3. Chinh sua Dia chi cua HLV.", 50));
                    printCentered(drawOption("0. Thoat.", 50));
                    printCentered(drawBorder(50));
                    printCentered("Nhap lua chon cua ban: ", 0);
                    //cout << "Moi nhap lua chon: ";
                    cin >> k;
                    cin.ignore();
                    String newName, newDate, tmpnewdate, newAddress, newNameTeam;
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
                        cout << "QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV/Cap nhat thong tin HLV/Chinh sua Ten cua HLV" << endl
                             << endl;
                        thaythe = name;
                        cout << "Nhap ten HLV: ";
                        String::getline(cin, newName);
                        name = newName;

                        tempFileT << left << setw(10) << "ID," << setw(20) << "Ten Doi Bong," << setw(20) << "So Cau Thu," << setw(15) << "Ten HLV," << setw(15) << "Ban Thang," << setw(15) << "Ban Thua," << setw(15) << "Hieu So," << setw(15) << "Diem," << setw(15) << "Thu hang" << endl;
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
                                    tempFileT << left << setw(10) << idT + "," << setw(20) << nameTeamT + "," << setw(20) << numMemberT + "," << setw(15) << nameCoachT + "," << setw(15) << numberGoalT + "," << setw(15) << numberLoseGoalT + "," << setw(15) << differenceT + "," << setw(15) << pointT + "," << setw(15) << rankT << endl;
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
                            cout << "Khong mo dc file";

                        break;
                    case 2:
                        system("cls");
                        cout << "QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV/Cap nhat thong tin HLV/Chinh sua ngay sinh cua HLV" << endl
                             << endl;
                        cout << "Nhap ngay sinh cua HLV: ";
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
                        cout << "QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV/Cap nhat thong tin HLV/Chinh sua dia chi cua HLV" << endl
                             << endl;
                        cout << "Nhap dia chi cua HLV: ";
                        String::getline(cin, newAddress);
                        address = newAddress;
                        break;
                    // case 4:
                    //     cout << "Nhap doi bong HLV quan ly: ";
                    //     String::getline(cin, newNameTeam);
                    //     nameTeam = newNameTeam;
                    //     break;
                    case 0:
                        return;
                    default:
                        break;
                    }
                    cout << "Nhap 1 neu ban muon tiep tuc chinh sua, 0 neu muon thoat: ";
                    cin >> u;

                } while (u == 1);
                // Ghi du lieu da sua vo file tam
                tempFile << left << setw(10) << id + "," << setw(20) << name + "," << setw(20) << date + "," << setw(30) << address + "," << setw(20) << age + "," << setw(20) << nameTeam << endl;
            }
            else
            {
                // Ghi du lieu cua may thang ko cap nhat
                // kt = false;
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
        cout << "Khong mo dc file";
    }
    if (kt)
        cout << "HLV co CCCD " << ma << " khong ton tai" << endl
             << endl;
    cout << "Cap nhat thong tin thanh cong" << endl;
    cout << "Nhan Enter de tiep tuc . ." << endl;
    getchar();
}

void Coach::dkcDeleteCoach(String tt)
{

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
                String str = "NULL";
                nameCoach = str;
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

void Coach::deleteCoachById()
{
    bool kt = true;
    system("cls");
    String ma, thaythe;
    cout << "QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV/Xoa HLV" << endl
         << endl;
    cout << "Giai dau co cac HLV co CCCD sau:" << endl;
    showIDCoach();
    cout << endl;
    cout << "Nhap CCCD cua HLV can xoa: ";
    String::getline(cin, ma);

    fstream file("Coach.txt", ios::in);
    fstream tempFile("tempCoach.txt", ios::out | ios::app);
    tempFile << left << setw(10) << "ID" << setw(20) << "Ten HLV" << setw(20) << "Ngay sinh" << setw(30) << "Dia chi" << setw(20) << "Tuoi" << setw(20) << "Ten doi bong" << endl;

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

            if (ma == id)
            {
                kt = false;
                thaythe = nameTeam;
            }
            else
            {
                // Ghi du lieu cua may thang ko cap nhat
                // kt = true;
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
        cout << "Khong mo dc file";
    }
    if (kt)
        cout << "HLV co ID " << ma << " khong ton tai" << endl
             << endl;
    dkcDeleteCoach(thaythe);
    cout << "Xoa thong tin thanh cong" << endl;
    cout << "Nhan Enter de tiep tuc . ." << endl;
    getchar();
}
void Coach::addCoachFromFile()
{
    while(true) {
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
            return ;
        }
        else
        {
            cout << "The file does not exist. Please enter again." << endl;
        }

    }
}

// int countLines(const char* filename)
// {
// 	ifstream file(filename);
// 	if (!file.is_open())
// 	{
// 		cerr << "Khong the mo file!" << endl;
// 		return -1;
// 	}

// 	int lineCount = 0;
// 	String line;
// 	String::getline(file, line);
// 	while (!file.eof())
// 	{
// 		String::getline(file, line);
// 		lineCount++;
// 	}
// 	file.close();
// 	return lineCount;
// }

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
    //cout << left << setw(10) << "ID" << setw(20) << "Ten HLV" << setw(20) << "Ngay sinh" << setw(30) << "Dia chi" << setw(20) << "Tuoi" << setw(20) << "Ten doi bong" << endl;
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
        if(lineCount == dem)
            cout << id;
        else cout << id << ", ";
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
    //cout << left << setw(10) << "ID" << setw(20) << "Ten HLV" << setw(20) << "Ngay sinh" << setw(30) << "Dia chi" << setw(20) << "Tuoi" << setw(20) << "Ten doi bong" << endl;
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
        if(lineCount == dem)
            cout << name;
        else cout << name << ", ";
    }
    file.close();
}

void Coach::showCoach()
{
    ifstream file("Coach.txt");
    String tmp;
    String::getline(file, tmp);
    cout << left << setw(10) << "ID" << setw(20) << "Ten HLV" << setw(20) << "Ngay sinh" << setw(30) << "Dia chi" << setw(20) << "Tuoi" << setw(20) << "Ten doi bong" << endl;
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
        cout << left << setw(10) << id + "," << setw(20) << name + "," << setw(20) << date + "," << setw(30) << address + "," << setw(20) << age + "," << setw(20) << nameTeam << endl;
    }
    file.close();
}