#include "PrintCenter.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "CTDL/String.h"
using namespace std;
int getConsoleWidth()
{
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

void printCentered(String text, int check)
{
   // Lấy độ rộng của màn hình console
   int screenWidth = getConsoleWidth(); // Đặt độ rộng màn hình console của bạn tại đây

   // Tính độ dài của dòng văn bản
   int textLength = static_cast<int>(text.size());

   // Tính toán vị trí để in ra giữa màn hình
   int padding = (screenWidth - textLength) / 2;

   // In ra khoảng trắng đầu tiên để căn giữa
   cout << right << setw(padding + textLength) << text;
   if (check)
      cout << endl;
}
String drawBorder(int size)
{
   String tmp = "";
   for (int i = 1; i <= size; i++)
   {
      tmp = tmp + "-";
   }
   return tmp;
}
String drawOption(String opt, int size)
{
   opt = String("|") + opt;
   String tmp = "";
   for (int i = 1; i < (size - opt.size()); i++)
   {
      tmp = tmp + " ";
   }
   opt = opt + tmp + "|";
   return opt;
}
String drawOptionCenter(String opt, int size)
{
   int spaceNeed = size - opt.size() - 2;
   opt = opt;
   String tmp;
   for (int i = 1; i <= spaceNeed / 2; i++)
      tmp = tmp + " ";
   opt = String("|") + tmp + opt;
   if (spaceNeed % 2 != 0)
      tmp = tmp + " ";
   opt = opt + tmp + String("|");
   return opt;
}
String addSpace(String s1, String s2, int size)
{
   int spaceNeeds = size - s1.size() - s2.size();
   if (spaceNeeds <= 0)
      return s1 + s2;
   String tmp;
   for (int i = 1; i <= spaceNeeds; i++)
   {
      tmp = tmp + " ";
   }
   return s1 + tmp + s2;
}
void printFullScreen(char c)
{
   int screenWidth = getConsoleWidth();
   for (int i = 1; i <= screenWidth; i++)
      cout << c;
   cout << endl;
}