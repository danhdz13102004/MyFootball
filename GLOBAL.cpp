#include "FootballTeam/Player.h"
#include "FootballTeam/Coach.h"
#include "FootballTeam/Team.h"
#include "FootballTeam/Human.h"
#include "Match/Match.h"
#include "Match/HistoryMatch.h"
#include "Algorithm.h"
#include <Windows.h>
#include <iomanip>
#include "PrintCenter.h"
using namespace std;

int countLines(const char *filename)
{
	ifstream file(filename);
	if (!file.is_open())
	{
		cerr << "Failer!" << endl;
		return -1;
	}

	int lineCount = 0;
	String line;
	String::getline(file, line);
	while (!file.eof())
	{
		String::getline(file, line);
		lineCount++;
	}
	file.close();
	return lineCount;
}

bool isFileEmpty(const char *filename)
{
	ifstream file(filename);
	if (!file.is_open())
	{
		cerr << "Failed!" << endl;
		return false;
	}
	file.seekg(0, ios::end);
	if (file.tellg() == 0)
	{
		file.close();
		return true;
	}
	file.close();
	return false;
}

int main()
{
	int lc;
	do
	{
		system("cls");
		const char *filename1 = "Team.txt";
		const char *filename2 = "Coach.txt";
		const char *filename3 = "Player.txt";
		const char *filename4 = "HistoryMatch.txt";
		const char *filename5 = "Schedule.txt";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		printCentered("PROJECT BASE LEARNING: FOOTBALL LEAGUE MANAGEMENT");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << endl;
		printCentered("Lecturers guiding implementation: TS. Dang Hoai Phuong");
		printCentered("Student 1: Ngo Van Danh (102220180)");
		printCentered("Student 2: Tran Vu Lam (102220196)");
		cout << endl;
		printCentered(drawBorder(50));
		printCentered(drawOption("1. CREATE A NEW LEAGUE.", 50));
		printCentered(drawOption("2. LEAGUE MANAGEMENT.", 50));
		printCentered(drawOption("0. EXIT.", 50));
		printCentered(drawBorder(50));
		printCentered("Please enter your choice: ", 0);
		cin >> lc;
		cin.ignore();
		if (lc == 1)
		{
			int lc1;
			do
			{
				system("cls");
				printCentered("CREATE A NEW LEAGUE");
				cout << endl;
				printCentered(drawBorder(50));
				printCentered(drawOption("1. Add a new team.", 50));
				printCentered(drawOption("2. Schedule matches.", 50));
				printCentered(drawOption("0. Back.", 50));
				printCentered(drawBorder(50));
				printCentered("Please enter your choice: ", 0);
				cin >> lc1;
				cin.ignore();
				if (lc1 == 1)
				{
					int lc11;
					do
					{
						system("cls");
						printCentered("CREATE A NEW LEAGUE/Add a new team");
						cout << endl;
						printCentered(drawBorder(50));
						printCentered(drawOption("1. Input data from the keyboard.", 50));
						printCentered(drawOption("2. Input data from the file.", 50));
						printCentered(drawOption("0. Back.", 50));
						printCentered(drawBorder(50));
						printCentered("Please enter your choice: ", 0);
						cin >> lc11;
						cin.ignore();
						if (lc11 == 1)
						{
							Team t;
							t.createNewFootballTeam();
							cout << "Successfully added a new team!" << endl;
							cout << "Press the Enter key to continue . .";
							getchar();
						}
						else if (lc11 == 2)
						{
							system("cls");
							Team t;
							Player p;
							Coach c;
							c.addCoachFromFile();
							p.addPlayerFromFile();
							t.addTeamFromFile();
							cout << "Successfully added a new team!" << endl;
							cout << "Press the Enter key to continue . .";
							getchar();
						}
					} while (lc11 != 0);
				}
				else if (lc1 == 2)
				{
					system("cls");
					if (countLines(filename1) <= 1)
					{
						printCentered("CREATE A NEW LEAGUE/Schedule matches");
						cout << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
						cout << "At least 2 teams are required to schedule matches!" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						cout << "Press the Enter key to continue . .";
						getchar();
					}
					else
					{
						func();
						Match m;
						m.getAllMatchFromFile();
						cout << "Press the Enter key to continue . .";
						getchar();
					}
					cout << endl;
				}

			} while (lc1 != 0);
		}
		else if (lc == 2)
		{
			if (isFileEmpty(filename1))
			{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << "Add data to the tournament before executing this feature!" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "Press the Enter key to continue . .";
				getchar();
			}
			else
			{
				int lc2;
				do
				{
					system("cls");
					printCentered("LEAGUE MANAGEMENT");
					cout << endl;
					printCentered(drawBorder(70));
					printCentered(drawOption("1. Query information for teams, coaches, and players.", 70));
					printCentered(drawOption("2. Update information for teams, coaches, and players.", 70));
					printCentered(drawOption("3. Query information for match.", 70));
					printCentered(drawOption("4. Update information for match.", 70));
					printCentered(drawOption("5. Query information for history match.", 70));
					printCentered(drawOption("6. Update information for history match.", 70));
					printCentered(drawOption("7. League summary.", 70));
					printCentered(drawOption("0. Back.", 70));
					printCentered(drawBorder(70));
					printCentered("Please enter your choice: ", 0);
					cin >> lc2;
					cin.ignore();
					if (lc2 == 1)
					{
						int lc21;
						do
						{
							system("cls");
							printCentered("LEAGUE MANAGEMENT/Query information for teams, coaches, and players");
							cout << endl;
							printCentered(drawBorder(50));
							printCentered(drawOption("1. Query information for a team.", 50));
							printCentered(drawOption("2. Query information for a coach.", 50));
							printCentered(drawOption("3. Query information for a player.", 50));
							printCentered(drawOption("0. Back.", 50));
							printCentered(drawBorder(50));
							printCentered("Please enter your choice: ", 0);
							cin >> lc21;
							cin.ignore();
							if (lc21 == 1)
							{
								system("cls");
								Team t;
								t.findTeamByName();
							}
							else if (lc21 == 2)
							{
								int lc212;
								do
								{
									system("cls");
									printCentered("LEAGUE MANAGEMENT/Query information for teams, coaches, and players/Query information for a coach");
									cout << endl;
									printCentered(drawBorder(50));
									printCentered(drawOption("1. By team name.", 50));
									printCentered(drawOption("2. By citizen identity number.", 50));
									printCentered(drawOption("3. By coach name.", 50));
									printCentered(drawOption("0. Back.", 50));
									printCentered(drawBorder(50));
									printCentered("Please enter your choice: ", 0);
									cin >> lc212;
									cin.ignore();
									Team t;
									if (lc212 == 1)
									{
										t.findCoachByNameFootballTeam();
									}
									else if (lc212 == 2)
									{
										t.findCoachByID();
									}
									else if (lc212 == 3)
									{
										t.findCoachByName();
									}
								} while (lc212 != 0);
							}
							else if (lc21 == 3)
							{
								int lc213;
								do
								{
									system("cls");
									printCentered("LEAGUE MANAGEMENT/Query information for teams, coaches, and players/Query information for a player");
									cout << endl;
									printCentered(drawBorder(50));
									printCentered(drawOption("1. By team name.", 50));
									printCentered(drawOption("2. By player name.", 50));
									printCentered(drawOption("3. By citizen identity number.", 50));
									printCentered(drawOption("0. Back.", 50));
									printCentered(drawBorder(50));
									printCentered("Please enter your choice: ", 0);
									cin >> lc213;
									cin.ignore();
									Team t;
									if (lc213 == 1)
									{
										t.findPlayerByNameFootballTeam();
									}
									else if (lc213 == 2)
									{
										t.findPlayerByName();
									}
									else if (lc213 == 3)
									{
										t.findPlayerById();
									}
								} while (lc213 != 0);
							}
						} while (lc21 != 0);
					}
					else if (lc2 == 2)
					{
						int lc22;
						do
						{
							system("cls");
							printCentered("LEAGUE MANAGEMENT/Update information for teams, coaches, and players");
							cout << endl;
							printCentered(drawBorder(50));
							printCentered(drawOption("1. Edit team information.", 50));
							printCentered(drawOption("2. Edit coach information.", 50));
							printCentered(drawOption("3. Edit player information.", 50));
							printCentered(drawOption("4. Delete team information.", 50));
							printCentered(drawOption("5. Change coach information.", 50));
							printCentered(drawOption("6. Delete player information.", 50));
							printCentered(drawOption("0. Back.", 50));
							printCentered(drawBorder(50));
							printCentered("Please enter your choice: ", 0);
							cin >> lc22;
							cin.ignore();
							if (lc22 == 1)
							{
								int lc221;
								do
								{
									system("cls");
									printCentered("LEAGUE MANAGEMENT/Update information for teams, coaches, and players/Edit team information");
									cout << endl;
									printCentered(drawBorder(50));
									printCentered(drawOption("1. Add players to the team.", 50));
									printCentered(drawOption("2. Modify team information.", 50));
									printCentered(drawOption("0. Back.", 50));
									printCentered(drawBorder(50));
									printCentered("Please enter your choice: ", 0);
									cin >> lc221;
									cin.ignore();
									Team t;
									if (lc221 == 1)
									{
										t.addPlayerToTeam();
									}
									else if (lc221 == 2)
									{
										t.updateTeam();
									}
								} while (lc221 != 0);
							}
							else if (lc22 == 2)
							{
								Coach c;
								c.updateCoach();
							}
							else if (lc22 == 3)
							{
								Player p;
								p.updatePlayer();
							}
							else if (lc22 == 4)
							{
								Team t;
								if (isFileEmpty(filename5) && isFileEmpty(filename4))
								{
									t.deleteTeamById();
								}
								else if (!isFileEmpty(filename5) && isFileEmpty(filename4))
								{
									t.deleteTeamById();
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
									cout << endl << "Please schedule matches again!" << endl;
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
									if (countLines(filename1) <= 1)
									{
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
										cout << "At least 2 teams are required to schedule matches!" << endl;
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
										cout << "Press the Enter key to continue . .";
										getchar();
									}
									else
									{
										func();
										Match m;
										m.getAllMatchFromFile();
										cout << "Press the Enter key to continue . .";
										getchar();
									}
									cout << endl;
								}
								else
								{
									system("cls");
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
									cout << "Team cannot be deleted because the season is in progress!" << endl;
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
									cout << "Press the Enter key to continue . .";
									getchar();
								}
							}
							else if (lc22 == 5)
							{
								Coach c;
								String t = c.changeCoach();
								c.dkcDeleteCoach(t, c.returnnameCoach(t));
							}
							else if (lc22 == 6)
							{
								Player p;
								p.deletePlayerById();
							}
						} while (lc22 != 0);
					}
					else if (lc2 == 3)
					{
						if (!isFileEmpty(filename5))
						{
							int lc23;
							Match m;
							do
							{
								system("cls");
								printCentered("LEAGUE MANAGEMENT/Query information for match");
								cout << endl;
								printCentered(drawBorder(60));
								printCentered(drawOption("1. By team ID.", 60));
								printCentered(drawOption("2. By date.", 60));
								printCentered(drawOption("3. By the name of a team.", 60));
								printCentered(drawOption("4. By the names of two teams.", 60));
								printCentered(drawOption("5. Query information for all matches.", 60));
								printCentered(drawOption("0. Back.", 60));
								printCentered(drawBorder(60));
								printCentered("Please enter your choice: ", 0);
								cin >> lc23;
								cin.ignore();
								if (lc23 == 1)
								{
									m.findMatchByIdTeam();
								}
								else if (lc23 == 2)
								{
									m.findMatchByDay();
								}
								else if (lc23 == 3)
								{
									m.findMatchByNameTeam();
								}
								else if (lc23 == 4)
								{
									m.findMatchByTwoNameTeam();
								}
								else if (lc23 == 5)
								{
									system("cls");
									m.findallmatch();
								}

							} while (lc23 != 0);
						}
						else
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
							cout << "Schedule matches before using this feature!" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
							cout << "Press the Enter key to continue . .";
							getchar();
						}
					}
					else if (lc2 == 4)
					{
						if (!isFileEmpty(filename5))
						{
							int lc24;
							do
							{
								system("cls");
								printCentered("LEAGUE MANAGEMENT/Update information for match");
								cout << endl;
								printCentered(drawBorder(50));
								printCentered(drawOption("1. Edit match information.", 50));
								printCentered(drawOption("2. Add results for the match.", 50));
								printCentered(drawOption("0. Back.", 50));
								printCentered(drawBorder(50));
								printCentered("Please enter your choice: ", 0);
								cin >> lc24;
								cin.ignore();
								if (lc24 == 1)
								{
									Match m;
									m.updateInforOfMatch();
								}
								else if (lc24 == 2)
								{
									ofstream f("SavePlayer.txt", std::ios::app);
									f.seekp(0, ios::end);
									if (f.tellp() == 0)
										f << left << setw(10) << "IDV," << setw(10) << "ID Doi," << setw(15) << "Ten doi," << setw(10) << "ID CT," << setw(10) << "Goal" << endl;
									Match m;
									m.enterResultMatch();
								}
							} while (lc24 != 0);
						}
						else
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
							cout << "Schedule matches before using this feature!" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
							cout << "Press the Enter key to continue . .";
							getchar();
						}
					}
					else if (lc2 == 5)
					{
						ifstream f("HistoryMatch.txt");
						f.seekg(0, ios::end);
						if (f.tellg() != 0)
						{
							if (!isFileEmpty(filename5))
							{
								int lc25;
								do
								{
									system("cls");
									printCentered("LEAGUE MANAGEMENT/Query information for history match");
									cout << endl;
									printCentered(drawBorder(70));
									printCentered(drawOption("1. By date.", 70));
									printCentered(drawOption("2. By the name of a team.", 70));
									printCentered(drawOption("3. By the name of two teams.", 70));
									printCentered(drawOption("4. By the ID round.", 70));
									printCentered(drawOption("5. Query all history match information.", 70));
									printCentered(drawOption("0. Back.", 70));
									printCentered(drawBorder(70));
									printCentered("Please enter your choice: ", 0);
									cin >> lc25;
									cin.ignore();
									if (lc25 == 1)
									{
										system("cls");
										String datee;
										HistoryMatch h;
										printCentered("LEAGUE MANAGEMENT/Query information for history match/By date");
										cout << endl;
										cout << "The history of matches that took place on the following dates:" << endl;
										h.showdateHM();
										cout << endl;
										cout << "Please enter date(dd/mm/yyyy): ";
										String::getline(cin, datee);
										if (datee[1] == '/')
										{
											String tmp("0");
											datee = tmp + datee;
										}
										if (datee[4] == '/')
											datee.insert(3, "0");
										h.showHMbydate(datee);
										cout << "Press the Enter key to continue . .";
										getchar();
									}
									else if (lc25 == 2)
									{
										system("cls");
										String id1, name1, name;
										printCentered("LEAGUE MANAGEMENT/Query information for history match/By the name of a team");
										cout << endl;
										cout << "The league includes name teams with the following:" << endl;
										Team t;
										t.showNameTeam();
										cout << endl;
										cout << "Please enter name team: ";
										String::getline(cin, name1);
										name = String::standadizeString(name1);
										HistoryMatch h;
										id1 = t.getIdByNameTeam(name);
										h.showHMbyidoneteam(id1);
										cout << "Press the Enter key to continue . .";
										getchar();
									}
									else if (lc25 == 3)
									{
										system("cls");
										String id1, id2, name1, name2, name1t, name2t;
										printCentered("LEAGUE MANAGEMENT/Query information for history match/By the name of two teams");
										cout << endl;
										cout << "The league includes name teams with the following:" << endl;
										Team t;
										t.showNameTeam();
										cout << endl;
										cout << "Please enter name team 1: ";
										String::getline(cin, name1t);
										cout << "Please enter name team 2: ";
										String::getline(cin, name2t);
										name1 = String::standadizeString(name1t);
										name2 = String::standadizeString(name2t);
										HistoryMatch h;
										id1 = t.getIdByNameTeam(name1);
										id2 = t.getIdByNameTeam(name2);
										h.showHMbyidtwoteam(id1, id2);
										cout << "Press the Enter key to continue . .";
										getchar();
									}
									else if (lc25 == 4)
									{
										system("cls");
										String idv;
										HistoryMatch h;
										printCentered("LEAGUE MANAGEMENT/Query information for history match/By the ID round");
										cout << endl;
										cout << "The history of matches that took place on the following rounds:" << endl;
										h.showidvongHM();
										cout << endl;
										cout << "Please enter ID round: ";
										String::getline(cin, idv);
										h.showHMbyidround(idv);
										cout << "Press the Enter key to continue . .";
										getchar();
									}
									else if (lc25 == 5)
									{
										system("cls");
										HistoryMatch h;
										printCentered("LEAGUE MANAGEMENT/Query information for history match/Query all history match information");
										cout << endl;
										h.showHistoryMatch();
										cout << "Press the Enter key to continue . .";
										getchar();
									}
								} while (lc25 != 0);
							}
							else
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
								cout << "Schedule matches before using this feature!" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
								cout << "Press the Enter key to continue . .";
								getchar();
							}
						}
						else
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
							cout << "Enter result before using this feature!" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
							cout << "Press the Enter key to continue . .";
							getchar();
						}
						f.close();
					}
					else if (lc2 == 6)
					{
						ifstream f("HistoryMatch.txt");
						f.seekg(0, ios::end);
						if (f.tellg() != 0)
						{
							if (!isFileEmpty(filename5))
							{
								system("cls");
								printCentered("LEAGUE MANAGEMENT/Update information for history match");
								cout << endl;
								HistoryMatch h;
								h.updateHistoryMatch1();
							}
							else
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
								cout << "Schedule matches before using this feature!" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
								cout << "Press the Enter key to continue . .";
								getchar();
							}
						}
						else
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
							cout << "Enter result before using this feature!" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
							cout << "Press the Enter key to continue . .";
							getchar();
						}
						f.close();
					}
					else if (lc2 == 7)
					{
						ofstream save("Savedata.txt");
						if (!isFileEmpty(filename5))
						{
							int lc27;
							do
							{
								system("cls");
								printCentered("LEAGUE MANAGEMENT/League summary");
								cout << endl;
								printCentered(drawBorder(70));
								printCentered(drawOption("1. Query Leaderboard.", 70));
								printCentered(drawOption("2. Query top goal scorer.", 70));
								printCentered(drawOption("3. End of the football league.", 70));
								printCentered(drawOption("0. Back.", 70));
								printCentered(drawBorder(70));
								printCentered("Please enter your choice: ", 0);
								cin >> lc27;
								cin.ignore();
								if (lc27 == 1)
								{
									system("cls");
									cout << "LEAGUE MANAGEMENT/League summary/Query Leaderboard" << endl;
									Team doi;
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
									cout << "First team: " << endl;
									Vector<String> a = doi.nameChampion();
									for (int i = 0; i < a.size(); i++)
									{
										cout << a[i] << endl;
									}
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
									cout << endl;
									doi.showchampion();
									cout << "Press the Enter key to continue . . ";
									getchar();
								}
								else if (lc27 == 2)
								{
									system("cls");
									cout << "LEAGUE MANAGEMENT/League summary/Query total number of players/Query top goal scorer" << endl;
									Player ct;
									Vector<String> b = ct.nameKing();
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
									cout << "Top Goal Scorer: " << endl;
									for (int i = 0; i < b.size(); i++)
									{
										cout << b[i] << endl;
									}
									cout << endl;
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
									ct.showKing();
									cout << "Press the Enter key to continue . . ";
									getchar();
								}
								else if (lc27 == 3)
								{
									ofstream outputFile("Savedata.txt", ios::trunc);
									outputFile << "DATA OF FOOTBALL LEAGUE" << endl
											   << endl;
									system("cls");
									printCentered("LEAGUE MANAGEMENT/League summary");
									cout << endl;
									Team doi;
									Player ct;
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
									cout << "Champion team: " << endl;
									Vector<String> a = doi.nameChampion();
									for (int i = 0; i < a.size(); i++)
									{
										cout << a[i] << endl;
									}
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
									doi.showchampion();
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
									outputFile << endl;
									cout << "Top Goal Scorer: " << endl;
									Vector<String> b = ct.nameKing();
									for (int i = 0; i < b.size(); i++)
									{
										cout << b[i] << endl;
									}
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
									ct.showKing();
									cout << endl;
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
									printCentered("== == ==   THE END   == == ==");
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
									cout << endl;
									save.close();
									return 0;
								}
							} while (lc27 != 0);
						}
						else
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
							cout << "Schedule matches before using this feature!" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
							cout << "Press the Enter key to continue . .";
							getchar();
						}
						save.close();
					}
				} while (lc2 != 0);
			}
		}
	} while (lc != 0);
}
