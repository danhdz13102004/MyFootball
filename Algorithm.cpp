#include "CTDL/String.h"
#include "CTDL/Vector.h"
#include <iostream>
#include <fstream>
#include "Algorithm.h"
#include <iomanip>
// #include "main.cpp"
//  #include "LapLich/Algorithm.cpp"
using namespace std;

class Date_Time
{
    int minute, hour, day, month, year;
    String place;

public:
    Date_Time() {}
    Date_Time(int mi, int h, int d, int m, int y, String place)
    {
        this->minute = mi;
        this->hour = h;
        this->day = d;
        this->month = m;
        this->year = y;
        this->place = place;
    }
    friend ostream &operator<<(ostream &o, const Date_Time &dt)
    {
        String newday, newmonth;
        String minute = String::tostring(dt.minute);
        if (minute.size() == 1)
        {
            String tmp('0');
            minute = tmp + minute;
        }
        if (dt.day < 10)
            newday = String("0") + String::tostring(dt.day);
        else
            newday = String::tostring(dt.day);
        if (dt.month < 10)
            newmonth = String("0") + String::tostring(dt.month);
        else
            newmonth = String::tostring(dt.month);
        if (dt.hour == 15 || dt.hour == 17)
            o << left << dt.hour << "h" << setw(17) << minute + ",";
        else
            o << left << dt.hour << "h" << setw(18) << minute + ",";
        o << left << newday << "/" << newmonth << "/" << setw(19) << String::tostring(dt.year) + "," << dt.place;
        return o;
    }
    void setHour(int h)
    {
        this->hour = h;
    }
    int getHour()
    {
        return this->hour;
    }
    void increaseTime()
    {
        if (this->hour != 17)
        {
            if (this->hour == 7)
                this->hour = 9;
            else if (this->hour == 9)
                this->hour = 15;
            else if (this->hour == 15)
                this->hour = 17;
        }
        else
        {
            this->hour = 7;
            if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12)
            {
                if (this->day < 31)
                    this->day++;
                else
                {
                    if (this->month < 12)
                    {
                        this->day = 1;
                        this->month++;
                    }
                    else
                    {
                        this->day = 1;
                        this->month = 1;
                        this->year++;
                    }
                }
            }
            else if (this->month == 2)
            {
                if (this->day < 28)
                    this->day++;
                else
                {
                    if (!((this->year % 4 == 0 && this->year % 100 != 0) || this->year % 400 == 0))
                    {
                        this->day = 1;
                        this->month++;
                    }
                    else
                    {
                        if (this->day == 28)
                            this->day++;
                        else
                        {
                            this->day = 1;
                            this->month++;
                        }
                    }
                }
            }
            else
            {
                if (this->day < 30)
                    this->day++;
                else
                {
                    this->day = 1;
                    this->month++;
                }
            }
        }
    }
};
Date_Time d;

void push_val(int a[], int n)
{
    int tmp = a[n - 1];
    for (int i = n - 1; i >= 1; i--)
    {
        if (i > 1)
        {
            a[i] = a[i - 1];
        }
        else
        {
            a[i] = tmp;
        }
    }
}

void Doi_Chan(int a[], int size)
{
    for (int i = 1; i <= size - 1; i++)
    {
        int j = 0;
        if (a[0] == 0)
            j = 1;
        for (j; j < size / 2; j++)
        {

            cout << left << setw(15) << String::tostring(i) + "," << setw(20) << String::tostring(a[j]) + "," << setw(20) << String::tostring(a[size - 1 - j]) + "," << d << endl;
            d.increaseTime();
            // this_thread::sleep_for(chrono::milliseconds(100));
        }
        cout << endl;
        if (d.getHour() != 7)
        {
            d.setHour(17);
            d.increaseTime();
        }
        d.setHour(17);
        d.increaseTime();
        push_val(a, size);
    }
}
void Doi_Le(int a[], int size)
{
    int *b = new int[size + 1];
    for (int i = size - 1; i >= 0; i--)
    {
        b[i + 1] = a[i];
    }
    b[0] = 0;

    Doi_Chan(b, size + 1);

    delete[] b;
}

void writetofile(ofstream &o, int check)
{
    ifstream f("Schedule.txt");
    if (check == 0)
    {
        f.seekg(0, ios::end);
        if (f.tellg() == 0)
        {
            o << left << setw(15) << "Vong" << setw(20) << "ID Doi thu nhat" << setw(20) << "ID Doi thu hai" << setw(20) << "Thoi gian" << setw(25) << "Ngay thang nam" << setw(20) << "Dia diem" << endl;
        }
        f.close();
    }
    if (check == 1)
    {
        o << left << setw(15) << "Vong" << setw(20) << "ID Doi thu nhat" << setw(20) << "ID Doi thu hai" << setw(20) << "Thoi gian" << setw(25) << "Ngay thang nam" << setw(20) << "Dia diem" << endl;
    }
}

void func()
{
    ofstream outFile("Schedule.txt");
    int size = 0;
    Vector<int> v;
    ifstream inf("Team.txt");
    if (inf.is_open())
    {
        String tmp;
        String::getline(inf, tmp);
        while (!inf.eof())
        {
            String::getline(inf, tmp);
            if (tmp[0] == ' ' || tmp.size() <= 1 || tmp[0] == '\n')
            {
                break;
            }
            if (tmp[0] != ' ')
                size++;
            String myId;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i] == ',')
                    break;
                myId = myId + tmp[i];
            }
            v.push_back(String::toint(myId));
        }
    }
    int *a = new int[size];
    for (int i = 0; i < size; i++)
        a[i] = v[i];
    int day, m, y;
    // cout << "CREATE A NEW LEAGUE/Schedule matches" << endl
    //      << endl;
    cout << "Enter the start time and location.\n";
    cout << "Enter the day: ";
    cin >> day;
    cout << "Enter the month: ";
    cin >> m;
    cout << "Enter the year: ";
    cin >> y;
    cout << "Enter the location: ";
    cin.ignore();
    String diadiem;
    String::getline(cin, diadiem);
    if ((!((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) && day == 29 && m == 2) || m > 12 || day > 31)
    {
        cout << "Match scheduling failed!" << endl;
        return;
    }
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(outFile.rdbuf());
    writetofile(outFile, 1);
    Date_Time d1(0, 7, day, m, y, diadiem);
    d = d1;
    // int size = sizeof(a) / sizeof(int);
    if (size % 2 == 0)
        Doi_Chan(a, size);
    else
        Doi_Le(a, size);
    cout.rdbuf(coutbuf);
    outFile.close();
    // cout << "Lap lich thanh cong!" << endl;
    delete[] a;
}
