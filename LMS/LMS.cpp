#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstring>
#include<windows.h>

using namespace std;

void Account_request();
void Accept_acc_req();
void Add_book();
void Admin_account();
void Admin_login();
void Admin_menu();
void Approval();
void Available_books();
void Change_Password();
void Choice();
int Date(int date, int no_month);
void Delete_book();
void Delete_student();
void Exit();
bool Field_check(string field, bool check);
void Issue_requests();
void List_books();
void List_students();
void List_issued();
void Loging_out();
void Login_Try();
void Load();
void Process();
void Request();
void Return_book();
void Student_login();
void Student_menu();
void Search_book();
void Search_student();
void Try_Again();
void Update_book();
void Update_student();
void Welcome();

static bool welcome = true;
static bool EXIT = true;
static string student_id;
static string student_name;
static int IssueRequest = 0;
static int UserRequest = 0;
bool admin, screen;

void gotoxy(int a, int b)
{
	HANDLE console_handle;
	COORD cur_cord;
	console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	cur_cord.X = a;
	cur_cord.Y = b;
	SetConsoleCursorPosition(console_handle, cur_cord);
}

int main()
{
	int login;
	if (welcome)
	{
		welcome = false;
		Welcome();
	}
	do
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\t\t* * * * * * * * * * Welcome to our Library Management System  * * * * * * * * * *" << endl << endl;
		cout << "\t\t\t\t\t* * * * * * Main Menu * * * * * *" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " => Press '1' for Admin Login " << endl;
		cout << " => Press '2' for Student Login " << endl;
		cout << " => Press '3' for Requesting Admin to Create an Account " << endl;
		cout << " => Press '4' to Exit LMS " << endl << endl;
		cout << " -> Enter Your Choice Here: ";
		cin >> login;
		if (login == 1)
		{
			Process();
			system("cls");
			Admin_login();
		}
		else if (login == 2)
		{
			Process();
			system("cls");
			Student_login();
		}
		else if (login == 3)
		{
			Process();
			Account_request();
		}
		else if (login == 4)
		{
			Process();
			Exit();
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n Invalid Input!";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			Sleep(1500);
		}
	} while (login < 1 || login > 3);
	system("pause");
	return 0;
}

void Welcome()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "\n\n\n\n";
	cout << "\t\t                      **            ****        ****    ***  \n"; Sleep(50);
	cout << "\t\t                      **            ** **      ** **   ***** \n"; Sleep(50);
	cout << "\t\t                      **            **  **    **  **  **   **\n"; Sleep(50);
	cout << "\t\t                      **            **    ** **   **  **     \n"; Sleep(50);
	cout << "\t\t                      **            **      *     **  **     \n"; Sleep(50);
	cout << "\t\t                      **            **            **    ***  \n"; Sleep(50);
	cout << "\t\t                      **            **            **    ***  \n"; Sleep(50);
	cout << "\t\t                      **            **            **       **\n"; Sleep(50);
	cout << "\t\t                      **            **            **       **\n"; Sleep(50);
	cout << "\t\t                      **            **            **  **   **\n"; Sleep(50);
	cout << "\t\t                      **********    **            **   ***** \n"; Sleep(50);
	cout << "\t\t                      **********    **            **    ***  \n"; Sleep(50);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	for (int i = 35; i < 79; i++)
	{
		gotoxy(i, 1);
		cout << "*";
		gotoxy(i, 2);
		cout << "*";
		Sleep(5);
		gotoxy(i, 17);
		cout << "*";
		gotoxy(i, 18);
		cout << "*";
		Sleep(5);
	}
	for (int i = 1; i < 19; i++)
	{
		gotoxy(35, i);
		cout << "*";
		gotoxy(36, i);
		cout << "*";
		Sleep(50);
		gotoxy(79, i);
		cout << "*";
		gotoxy(80, i);
		cout << "*";
		Sleep(50);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(40, 20);
	cout << "\t\tLOADING";

	for (int i = 0; i < 4; i++)
	{
		cout << ".";
		Sleep(500);
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	gotoxy(20, 23);
	cout << "****************************************************************************\n";
	gotoxy(20, 24);
	cout << "**\n";
	gotoxy(20, 25);
	cout << "**\n";
	gotoxy(94, 24);
	cout << "**\n";
	gotoxy(94, 25);
	cout << "**\n";
	gotoxy(20, 26);
	cout << "****************************************************************************\n";
	for (int i = 0; i < 70; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		gotoxy(i + 23, 24);
		cout << "!\n";
		gotoxy(i + 23, 25);
		cout << "*\n";
		Sleep(60);
	}
	Sleep(1000);
	system("cls");
}

void Admin_login()
{
	int account, Check = 0;
	bool logintrue = false, check = false;
	char ch;
	string id, pass;
	ifstream verify("Admin_Login.txt");
	while (getline(verify, id, '|'))
	{
		getline(verify, pass);
		Check++;
	}
	if (Check == 0)
	{
		Admin_account();
	}
	verify.close();
	do
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\t\t\t\t\t* * * * * * Admin Login * * * * * *" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " => Press '1' to Login" << endl;
		cout << " => Press '2' to return back to Main Menu" << endl;
		cout << " => Press '3' to Exit LMS" << endl << endl;
		cout << " -> Enter Your Choice Here: ";
		cin >> account;
		Process();
		if (account == 1)
		{
			ifstream login;
			string id, password, ID, PASSWORD;
			login.open("Admin_Login.txt");
			do
			{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t\t* * * * * * Admin Login * * * * * *" << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cout << " -> Enter Your ID number: ";
				cin >> id;
				cout << " -> Enter Your Password: ";
				ch = _getch();
				while (true)
				{
					if (ch == 13)
					{
						break;
					}
					else if (ch == '\b')
					{
						password.pop_back();
						cout << "\b";
						cout << " ";
						cout << "\b";
					}
					else
					{
						password.push_back(ch);
						cout << '*';
					}
					ch = _getch();
				}
				cout << endl;
				Load();
				login >> ID;
				login >> PASSWORD;
				login.close();
				if (id == ID && password == PASSWORD && logintrue == false)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << "\n\n----------WELCOME ADMIN----------" << endl;
					admin = true;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					Sleep(1500);
					logintrue = true;
					Admin_menu();
				}
				else if (id == ID && password != PASSWORD)
				{
					cout << "\n Incorrect Password!" << endl;
					password = "";
					Login_Try();
				}
				else if (id != ID && password == PASSWORD)
				{
					cout << "\n Invalid ID!" << endl;
					password = "";
					Login_Try();
				}
				else if (id != ID && password != PASSWORD)
				{
					cout << "\n Invalid ID and Password!" << endl;
					password = "";
					Login_Try();
				}
			} while (logintrue != true);
		}
		else if (account == 2)
		{
			main();
		}
		else if (account == 3)
		{
			Exit();
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n Invalid Input!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			Sleep(1500);
		}
	} while (account < 1 || account > 3);
}

void Admin_menu()
{
	screen = false;
	int choice;
	string data;
	IssueRequest = 0;
	UserRequest = 0;
	ifstream in1("Request.txt");
	while (in1 >> data)
	{
		IssueRequest++;
	}
	in1.close();
	ifstream in2("Request_Account.txt");
	while (in2 >> data)
	{
		UserRequest++;
	}
	in2.close();

	do
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\t\t\t\t\t* * * * * * Admin Menu * * * * * *" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " => Press '1' to Add Book" << endl;
		cout << " => Press '2' to Update Book" << endl;
		cout << " => Press '3' to Delete Book" << endl;
		cout << " => Press '4' to Update Student" << endl;
		cout << " => Press '5' to Delete Student" << endl;
		cout << " => Press '6' to view List of Books" << endl;
		cout << " => Press '7' to view List of Students" << endl;
		cout << " => Press '8' to view Book Issue Requests " << "(" << IssueRequest << ")" << endl;
		cout << " => Press '9' to view Sign Up Requests " << "(" << UserRequest << ")" << endl;
		cout << " => Press '10' to Search Book" << endl;
		cout << " => Press '11' to Search Student" << endl;
		cout << " => Press '12' to view List of Issued Books" << endl;
		cout << " => Press '13' to go back to Admin Login" << endl;
		cout << " => Press '14' to go back to Main Menu" << endl;
		cout << " => Press '15' to Exit LMS" << endl << endl;
		cout << " -> Enter Your Choice Here: ";
		cin >> choice;
		if (choice == 1)
		{
			Add_book();
		}
		else if (choice == 2)
		{
			Update_book();
		}
		else if (choice == 3)
		{
			Delete_book();
		}
		else if (choice == 4)
		{
			Update_student();
		}
		else if (choice == 5)
		{
			Delete_student();
		}
		else if (choice == 6)
		{
			Process();
			List_books();
		}
		else if (choice == 7)
		{
			Process();
			List_students();
		}
		else if (choice == 8)
		{
			Process();
			Issue_requests();
		}
		else if (choice == 9)
		{
			Process();
			Accept_acc_req();
		}
		else if (choice == 10)
		{
			Process();
			Search_book();
		}
		else if (choice == 11)
		{
			Process();
			Search_student();
		}
		else if (choice == 12)
		{
			Process();
			List_issued();
		}
		else if (choice == 13)
		{
			Process();
			Admin_login();
		}
		else if (choice == 14)
		{
			Loging_out();
			main();
		}
		else if (choice == 15)
		{
			Loging_out();
			EXIT = false;
			Exit();
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n Invalid Input!";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			Sleep(1500);
		}
	} while (choice < 1 || choice > 15);

}
void Student_login()
{
	bool logintrue = false, control = false;
	int account;
	char ch;
	do
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\t\t\t\t\t* * * * * * Student Login * * * * * *" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " => Press '1' to Login" << endl;
		cout << " => Press '2' to return back to Main Menu" << endl;
		cout << " => Press '3' to Exit LMS" << endl << endl;
		cout << " -> Enter Your Choice Here: ";
		cin >> account;
		if (account == 1)
		{
			Process();
			string id, password, ID, PASSWORD, name, sec;
			do
			{
				bool state = true;
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t\t* * * * * * Student Login * * * * * *" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				ifstream login("Student_Login.txt");
				cout << endl;
				cout << " -> Enter Your ID number: ";
				cin >> id;
				cout << " -> Enter Your Password: ";
				ch = _getch();
				while (true)
				{
					if (ch == 13)
					{
						break;
					}
					else if (ch == '\b')
					{
						password.pop_back();
						cout << "\b";
						cout << " ";
						cout << "\b";
					}
					else
					{
						password.push_back(ch);
						cout << '*';
					}
					ch = _getch();
				}
				cout << endl;
				Load();
				while (getline(login, ID, '|'))
				{
					getline(login, PASSWORD);
					if (id == ID && password == PASSWORD && logintrue == false)
					{
						student_id = id;
						logintrue = true;
						state = false;
						admin = false;
						ifstream name_save("Student_List.txt");

						while (getline(name_save, ID, '|'))
						{
							getline(name_save, name, '|');
							getline(name_save, sec);
							if (ID == id)
							{
								student_name = name;
							}
						}
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
						cout << "\n\n----------WELCOME " << student_name << " ----------" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						Sleep(1500);
						Student_menu();
					}
					else if (id == ID && password != PASSWORD)
					{
						cout << "\n Incorrect Password!" << endl;
						password = "";
						state = false;
						Login_Try();
					}
					else if (id != ID && password == PASSWORD)
					{
						cout << "\n Invalid ID!" << endl;
						state = false;
						password = "";
						Login_Try();
					}
				}
				if (state)
				{
					cout << "\n Invalid ID and Password!" << endl;
					password = "";
					Login_Try();
				}
				login.close();
			} while (logintrue != true);

		}
		else if (account == 2)
		{
			Process();
			main();
		}
		else if (account == 3)
		{
			Process();
			Exit();
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n Invalid Input!";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			Sleep(1500);
		}
	} while (account < 1 || account > 3);
}

void Student_menu()
{
	screen = false;
	int choice;
	do {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\t\t\t\t\t* * * * * * Student Menu * * * * * *" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " => Press '1' to View All Books" << endl;
		cout << " => Press '2' to View Available Books" << endl;
		cout << " => Press '3' for Requesting Admin to issue book" << endl;
		cout << " => Press '4' to Return Book" << endl;
		cout << " => Press '5' to Search Book" << endl;
		cout << " => Press '6' to see Approval from Admin" << endl;
		cout << " => Press '7' to Change your Password" << endl;
		cout << " => Press '8' to return back to Student Login" << endl;
		cout << " => Press '9' to return back to Main Menu" << endl;
		cout << " => Press '10' to Exit LMS" << endl << endl;
		cout << " -> Enter Your Choice Here: ";
		cin >> choice;
		if (choice == 1) {
			Process();
			List_books();
		}
		else if (choice == 2) {
			Process();
			Available_books();
		}
		else if (choice == 3) {
			Process();
			Request();
		}
		else if (choice == 4) {
			Process();
			Return_book();
		}
		else if (choice == 5) {
			Process();
			Search_book();
		}
		else if (choice == 6) {
			Process();
			Approval();
		}
		else if (choice == 7) {
			Process();
			Change_Password();
		}
		else if (choice == 8) {
			Process();
			Student_login();
		}
		else if (choice == 9) {
			Loging_out();
			main();
		}
		else if (choice == 10) {
			Loging_out();
			EXIT = false;
			Exit();
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n Invalid Input!";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			Sleep(1500);
		}
	} while (choice < 1 || choice>10);
}

void Add_book()
{
	ofstream book("Book_List.txt", ios::app);
	char add;
	string name, edition, author, id, Name, Id, Edition, Author;
	ofstream available("Available_Books.txt", ios::app);
	do
	{
		Process();
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\t\t\t\t\t* * * * * * Add Book * * * * * *" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " -> Enter Book's ID: ";
		cin.ignore();
		getline(cin, id);
		bool check = false;
		check = Field_check(id, check);
		if (check)
		{
			Add_book();
		}
		ifstream verify("Book_List.txt");
		while (getline(verify, Id, '|'))
		{
			getline(verify, Name, '|');
			getline(verify, Author, '|');
			getline(verify, Edition);
			if (Id == id)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\n This ID is already assigned to another book! Please enter a different ID..." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				Try_Again();
				Add_book();
			}
		}
		verify.close();
		cout << " -> Enter Book's Name: ";
		getline(cin, name);
		check = Field_check(name, check);
		if (check)
		{
			Add_book();
		}
		cout << " -> Enter Author's Name: ";
		getline(cin, author);
		check = Field_check(author, check);
		if (check)
		{
			Add_book();
		}
		cout << " -> Enter Book's Edition: ";
		getline(cin, edition);
		check = Field_check(edition, check);
		if (check)
		{
			Add_book();
		}
		book << id << "|" << name << "|" << author << "|" << edition << endl;
		available << id << "|" << name << "|" << author << "|" << edition << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << " Book Added Successfully!" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " Do you want to Add another Book? (Y/N): ";
		cin >> add;
	} while (add == 'y' || add == 'Y');
	book.close();
	available.close();
	Admin_menu();
}

void Update_book()
{
	string iD, id, name, author, edition, NEW;
	int option, option2;
	bool state = true;
	char choice;
	do
	{
		Process();
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\t\t\t\t\t* * * * * * Update Book * * * * * *" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " -> Enter the ID of the book you want to Update: ";
		cin >> iD;
		ifstream issue("Issued_Books.txt");
		while (getline(issue, id, '|'))
		{
			getline(issue, name, '|');
			getline(issue, author, '|');
			getline(issue, edition);
			if (iD == id)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\n Sorry! This book is Issued to a Student, please wait until it is returned....\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				Try_Again();
				Update_book();
			}
		}
		issue.close();
		ofstream temp2("book_temp.txt");
		ifstream update2("Book_List.txt");
		ofstream temp("available_temp.txt");
		ifstream update("Available_Books.txt");
		while (getline(update, id, '|'))
		{
			getline(update, name, '|');
			getline(update, author, '|');
			getline(update, edition);
			if (iD == id)
			{
				bool run = true;
				do {
					Process();
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\t\t\t\t\t* * * * * * Update Book * * * * * *" << endl << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					int serial = 1;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
					cout << left << setw(8) << "SR.#" << left << setw(15) << "ID" << left << setw(50) << "BOOK'S NAME" << left << setw(35) << "AUTHOR'S NAME" << left << setw(12) << "EDITION" << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					cout << left << setw(8) << serial << left << setw(15) << id << left << setw(50) << name << left << setw(35) << author << left << setw(12) << edition << endl;
					state = false;
					cout << endl;
					cout << " -> What you want to Update in Book?" << endl;
					cout << " => Press '1' to Update Name" << endl;
					cout << " => Press '2' to Update Author" << endl;
					cout << " => Press '3' to Update Edition" << endl;
					cout << " => Press '4' to Update ID" << endl << endl;
					cout << " -> Enter Your Choice Here: ";
					cin >> option;
					if (option == 1)
					{
						run = false;
						Process();
						system("cls");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\t\t\t\t\t* * * * * * Update Book's Name * * * * * *" << endl << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						cout << "\n -> Enter new Name for the Book: ";
						cin.ignore();
						getline(cin, NEW);
						name = NEW;
						option2 = 1;
					}
					else if (option == 2)
					{
						Process();
						run = false;
						system("cls");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\t\t\t\t\t* * * * * * Update Book's Author * * * * * *" << endl << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						cout << "\n -> Enter new Author for the Book: ";
						cin.ignore();
						getline(cin, NEW);
						author = NEW;
						option2 = 2;
					}
					else if (option == 3)
					{
						Process();
						system("cls");
						run = false;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\t\t\t\t\t* * * * * * Update Book's Edition * * * * * *" << endl << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						cout << "\n -> Enter new Edition for the Book: ";
						cin.ignore();
						getline(cin, NEW);
						edition = NEW;
						option2 = 3;
					}
					else if (option == 4)
					{
						Process();
						system("cls");
						run = false;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\t\t\t\t\t* * * * * * Update Book's ID * * * * * *" << endl << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						cout << "\n -> Enter new ID for the Book: ";
						cin.ignore();
						getline(cin, NEW);
						id = NEW;
						option2 = 4;
					}
					else
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\n Invalid Input!" << endl;
						Sleep(1000);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					}
				} while (run);
			}
			temp << id << "|" << name << "|" << author << "|" << edition << endl;
		}
		while (getline(update2, id, '|'))
		{
			getline(update2, name, '|');
			getline(update2, author, '|');
			getline(update2, edition);
			if (iD == id)
			{
				if (option2 == 1)
				{
					name = NEW;
				}
				else if (option2 == 2)
				{
					author = NEW;
				}
				else if (option2 == 3)
				{
					edition = NEW;
				}
				else if (option2 == 4)
				{
					id = NEW;
				}
			}
			temp2 << id << "|" << name << "|" << author << "|" << edition << endl;
		}
		update.close();
		temp.close();
		update2.close();
		temp2.close();
		if (state)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n No Book Found!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			Try_Again();
			Update_book();
		}
		else
		{
			ofstream updated("Book_List.txt", ios::trunc);
			ifstream in("book_temp.txt");
			while (getline(in, id, '|'))
			{
				getline(in, name, '|');
				getline(in, author, '|');
				getline(in, edition);
				updated << id << "|" << name << "|" << author << "|" << edition << endl;
			}
			ofstream updated2("Available_Books.txt", ios::trunc);
			ifstream in2("available_temp.txt");
			while (getline(in2, id, '|'))
			{
				getline(in2, name, '|');
				getline(in2, author, '|');
				getline(in2, edition);
				updated2 << id << "|" << name << "|" << author << "|" << edition << endl;
			}
			in.close();
			updated2.close();
			in2.close();
			updated.close();
			remove("book_temp.txt");
			remove("available_temp.txt");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n Updated Successfully!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << "\n Do you want to Update another Book? (Y/N): ";
			cin >> choice;
		}
	} while (choice == 'y' || choice == 'Y');
	Process();
	Admin_menu();
}

void Delete_book()
{
	string iD, id, name, author, edition, std_id, book_id;
	bool state = true, exist = false;
	char choice;
	do
	{
		bool ver = true;
		Process();
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\t\t\t\t\t* * * * * * Delete Book * * * * * *" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " -> Enter the ID of the book you want to Delete: ";
		cin >> iD;
		ifstream verify1("Book_List.txt");
		while (getline(verify1, id, '|'))
		{
			getline(verify1, name, '|');
			getline(verify1, author, '|');
			getline(verify1, edition);
			if (id != iD)
			{
				ver = false;
			}
		}
		if (ver)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n No Book Found!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			Try_Again();
			Delete_book();
		}
		ifstream verify("Accepted_Requests.txt");
		while (getline(verify, std_id, '|'))
		{
			getline(verify, book_id);
			if (iD == book_id)
			{
				exist = true;
				break;
			}
		}
		verify.close();
		if (exist)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n Sorry! This book is Issued to a Student, please wait until it is returned....\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			Try_Again();
			Delete_book();
		}
		else
		{
			ofstream temp("book_del_temp.txt");
			ifstream del("Book_List.txt");
			while (getline(del, id, '|'))
			{
				getline(del, name, '|');
				getline(del, author, '|');
				getline(del, edition);
				if (iD == id)
				{
					state = false;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\n Book Deleted Successfully!" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					cout << "\n Do you want to delete another book? (Y/N): ";
					cin >> choice;
				}
				else
				{
					temp << id << "|" << name << "|" << author << "|" << edition << endl;
				}
			}
			if (state)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\n No Book Found!" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				Try_Again();
				Delete_book();
			}
			del.close();
			temp.close();
			ofstream fout("Book_List.txt", ios::trunc);
			ifstream fin("book_del_temp.txt");
			while (getline(fin, id, '|'))
			{
				getline(fin, name, '|');
				getline(fin, author, '|');
				getline(fin, edition);
				fout << id << "|" << name << "|" << author << "|" << edition << endl;
			}
			fout.close();
			fin.close();
			remove("book_del_temp.txt");
			ifstream available("Available_Books.txt");
			ofstream TEMP("available_tmp.txt");
			while (getline(available, id, '|'))
			{
				getline(available, name, '|');
				getline(available, author, '|');
				getline(available, edition);
				if (iD != id) {
					TEMP << id << "|" << name << "|" << author << "|" << edition << endl;
				}
			}
			available.close();
			TEMP.close();
			ofstream Available("Available_Books.txt", ios::trunc);
			ifstream Temp("available_tmp.txt");
			while (getline(Temp, id, '|'))
			{
				getline(Temp, name, '|');
				getline(Temp, author, '|');
				getline(Temp, edition);
				Available << id << "|" << name << "|" << author << "|" << edition << endl;
			}
			Available.close();
			Temp.close();
			remove("available_tmp.txt");
		}

	} while (choice == 'y' || choice == 'Y');
	Process();
	Admin_menu();
}

void Update_student()
{
	string iD, id, id2, name, section, pass;
	bool state = true;
	char choice;
	do
	{
		Process();
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\t\t\t\t\t* * * * * * Update Student's Record * * * * * *" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " -> Enter the ID of the Student you want to Update: ";
		cin >> iD;
		ofstream temp1;
		ifstream update1;
		update1.open("Student_List.txt");
		temp1.open("std_list_temp.txt");
		while (getline(update1, id, '|'))
		{
			getline(update1, name, '|');
			getline(update1, section);
			if (iD == id)
			{
				bool run = true;
				do {
					Process();
					int option, serial = 1;
					string NEW;
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\t\t\t\t\t* * * * * * Update Student's Record * * * * * *" << endl << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
					cout << left << setw(8) << "SR.#" << left << setw(40) << "ID" << left << setw(40) << "STUDENT'S NAME" << left << setw(32) << "SECTION" << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					cout << left << setw(8) << serial << left << setw(40) << id << left << setw(40) << name << left << setw(32) << section << endl;
					cout << endl;
					cout << " -> What you want to Update in Student's Record?" << endl;
					cout << " => Press '1' to Update Name" << endl;
					cout << " => Press '2' to Update Section" << endl;
					cout << " => Press '3' to Update ID" << endl << endl;
					cout << " -> Enter Your Choice Here: ";
					cin >> option;
					if (option == 1)
					{
						Process();
						system("cls");
						run = false;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\t\t\t\t\t* * * * * * Update Student's Name * * * * * *" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						cout << "\n -> Enter new Name for the Student: ";
						cin.ignore();
						getline(cin, NEW);
						name = NEW;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\n Updated Successfully!" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						cout << "\n Do you want to Update another Record? (Y/N): ";
						cin >> choice;
						state = false;
					}
					else if (option == 2)
					{
						Process();
						system("cls");
						run = false;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\t\t\t\t\t* * * * * * Update Student's Section * * * * * *" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						cout << "\n -> Enter new Section for the Student: ";
						cin.ignore();
						getline(cin, NEW);
						section = NEW;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\n Updated Successfully!" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						cout << "\n Do you want to Update another Record? (Y/N): ";
						cin >> choice;
						state = false;
					}
					else if (option == 3)
					{
						Process();
						system("cls");
						run = false;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\t\t\t\t\t* * * * * * Update Student's ID * * * * * *" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						cout << "\n -> Enter new ID for the student: ";
						cin.ignore();
						getline(cin, NEW);
						id = NEW;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\n Updated Successfully!" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						cout << "\n Do you want to Update another Record? (Y/N): ";
						cin >> choice;
						state = false;
					}
					else
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\n Invalid Input!";
						Sleep(1000);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					}
				} while (run);
			}
			temp1 << id << "|" << name << "|" << section << endl;
		}
		if (state)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n No Student Found!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			Try_Again();
			Update_student();
		}
		update1.close();
		temp1.close();
		ofstream updated1;
		ifstream in1;
		updated1.open("Student_List.txt", ios::trunc);
		in1.open("std_list_temp.txt");
		while (getline(in1, id, '|'))
		{
			getline(in1, name, '|');
			getline(in1, section);
			updated1 << id << "|" << name << "|" << section << endl;
		}
		updated1.close();
		in1.close();
	} while (choice == 'y' || choice == 'Y');
	Admin_menu();
}

void Delete_student()
{
	string iD, id, name, section, password, std_id, book_id;
	bool state = true, exist = false;
	char choice;
	do
	{
		Process();
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\t\t\t\t\t* * * * * * Delete Student's Record * * * * * *" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " -> Enter the ID of the Student you want to Delete: ";
		cin >> iD;
		ifstream verify("Accepted_Requests.txt");
		while (getline(verify, std_id, '|'))
		{
			getline(verify, book_id);
			if (iD == std_id)
			{
				exist = true;
				break;
			}
		}
		verify.close();
		if (exist)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << " Sorry! This student has issued a book. Wait for it's return...";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			Try_Again();
			Delete_book();
		}
		else
		{
			ofstream temp("std_del_temp.txt");
			ifstream del;
			del.open("Student_List.txt");
			while (getline(del, id, '|'))
			{
				getline(del, name, '|');
				getline(del, section);
				if (iD == id)
				{
					state = false;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\n Student's Record Deleted Successfully!" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					cout << "\n Do you want to delete another record? (Y/N): ";
					cin >> choice;
				}
				else
				{
					temp << id << "|" << name << "|" << section << endl;
				}
			}
			if (state)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\n No Student Found!" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				Try_Again();
				Delete_student();
			}
			del.close();
			temp.close();
			ofstream fout("Student_List.txt", ios::trunc);
			ifstream fin("std_del_temp.txt");
			while (getline(fin, id, '|'))
			{
				getline(fin, name, '|');
				getline(fin, section);
				fout << id << "|" << name << "|" << section << endl;
			}
			fout.close();
			fin.close();
			remove("std_del_temp.txt");
			ofstream login_temp("login_temp.txt");
			ifstream in_login("Student_Login.txt");
			while (getline(in_login, id, '|'))
			{
				getline(in_login, password);
				if (id != iD)
				{
					login_temp << id << "|" << password << endl;
				}
			}
			login_temp.close();
			in_login.close();
			ofstream login("Student_Login.txt");
			ifstream In("login_temp.txt");
			while (getline(In, id, '|'))
			{
				getline(In, password);
				login << id << "|" << password << endl;
			}
			login.close();
			In.close();
		}
	} while (choice == 'y' || choice == 'Y');		remove("login_temp.txt");

	Process();
	Admin_menu();
}

void List_books()
{
	system("cls");
	int serial = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "\t\t\t\t\t* * * * * * Books List * * * * * *" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	ifstream list;
	string name, id, edition, author, data;
	list.open("Book_List.txt");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << left << setw(8) << "SR.#" << left << setw(15) << "ID" << left << setw(50) << "BOOK'S NAME" << left << setw(35) << "AUTHOR'S NAME" << left << setw(12) << "EDITION" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	while (getline(list, id, '|'))
	{
		getline(list, name, '|');
		getline(list, author, '|');
		getline(list, edition);
		cout << left << setw(8) << serial << left << setw(15) << id << left << setw(50) << name << left << setw(35) << author << left << setw(12) << edition << endl;
		serial++;
	}
	list.close();
	Choice();
}

void List_students()
{
	int serial = 1;
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "\t\t\t\t\t* * * * * * Students List * * * * * *" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	ifstream list;
	string id, name, section;
	list.open("Student_List.txt");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << left << setw(8) << "SR.#" << left << setw(40) << "ID" << left << setw(40) << "STUDENT'S NAME" << left << setw(32) << "SECTION" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	while (getline(list, id, '|'))
	{
		getline(list, name, '|');
		getline(list, section);
		cout << left << setw(8) << serial << left << setw(40) << id << left << setw(40) << name << left << setw(32) << section << endl;
		serial++;
	}
	cout << endl;
	list.close();
	Choice();
}

void List_issued() {
	string std_id, book_id;
	int serial = 1;
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "\t\t\t\t\t* * * * * * List of Issued Books * * * * * *" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << left << setw(8) << "SR.#" << left << setw(56) << "ISSUED BOOK ID" << left << setw(56) << "ISSUER ID" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	ifstream input("Accepted_Requests.txt");
	while (getline(input, std_id, '|'))
	{
		getline(input, book_id);
		cout << left << setw(8) << serial << left << setw(56) << book_id << left << setw(56) << std_id << endl;
		serial++;
	}
	input.close();
	Choice();
}

void Available_books() {
	int count = 0, serial = 1;
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "\t\t\t\t\t* * * * * * Available Books List * * * * * *" << endl << endl;
	ifstream list;
	string name, id, edition, author, data;
	list.open("Available_books.txt");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << left << setw(8) << "SR.#" << left << setw(15) << "ID" << left << setw(50) << "BOOK'S NAME" << left << setw(35) << "AUTHOR'S NAME" << left << setw(12) << "EDITION" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	while (getline(list, id, '|'))
	{
		getline(list, name, '|');
		getline(list, author, '|');
		getline(list, edition);
		cout << left << setw(8) << serial << left << setw(15) << id << left << setw(50) << name << left << setw(35) << author << left << setw(12) << edition << endl;
		count++;
		serial++;
	}
	if (count == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\n No Books are available!\n\n";
	}
	list.close();
	Choice();
}

void Request()
{
	system("cls");
	bool available1 = false, available2 = false, state = true;
	string std_id, book_id, id, name, author, edition, iD, student, book;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "\t\t\t\t\t* * * * * * Issue Book * * * * * *" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	ifstream verify("Accepted_Requests.txt");
	while (getline(verify, student, '|'))
	{
		getline(verify, book);
		if (student == student_id)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << student_name << "! You don't have permissions for issuing book! Please return the book you issued before requesting for new one..." << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			Choice();
		}
	}
	ifstream verify2("Request.txt");
	while (getline(verify2, student, '|'))
	{
		getline(verify2, book);
		if (student == student_id)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << student_name << "! You have already requested admin. Please wait for admin to respond it..." << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			state = false;
			Choice();
		}
	}
	verify2.close();
	if (state)
	{
		cout << " => Enter Book's ID you want to Issue: ";
		cin >> book_id;
		ifstream verify3("Request.txt");
		while (getline(verify3, student, '|'))
		{
			getline(verify3, book);
			if (book == book_id)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\n " << student_name << "! Some one else has requested for issuing this book! Please wait for admin to respond it..." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				char choice;
				cout << "\n Do you want to try another book? (Y/N): ";
				cin >> choice;
				if (choice == 'n' || choice == 'N')
				{
					Student_menu();
				}
				else if (choice == 'y' || choice == 'Y')
				{
					Request();
				}
			}
		}
		verify3.close();
		ifstream check1("Book_List.txt");
		ifstream check2("Available_Books.txt");
		while (getline(check1, id, '|'))
		{
			getline(check1, name, '|');
			getline(check1, author, '|');
			getline(check1, edition);
			if (book_id == id)
			{
				available1 = true;
			}
		}
		check1.close();
		while (getline(check2, id, '|'))
		{
			getline(check2, name, '|');
			getline(check2, author, '|');
			getline(check2, edition);
			if (book_id == id)
			{
				available2 = true;
			}
		}
		if (available2)
		{
			ofstream request("Request.txt", ios::app);
			request << student_id << "|" << book_id << endl;
			request.close();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n " << student_name << "! Request Sent. Please wiat for Admin's Approval..." << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			Choice();
		}
		else if (!available2 && available1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n " << student_name << "! This book is issued to another student..." << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			Choice();
		}
		else if (!available1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n " << student_name << "! Such a Book does'nt exists..." << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			Try_Again();
			Request();
		}
	}
}

void Issue_requests() {
	system("cls");
	char request;
	int count = 0, serial = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "\t\t\t\t\t* * * * * * Issue Requests * * * * * *" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << left << setw(8) << "SR.#" << left << setw(56) << "STUDENT ID" << left << setw(56) << "BOOK ID" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	string std_id, book_id, id, name, author, edition, Std_Id, Book_Id, student, book;
	ifstream input("Request.txt");
	while (getline(input, std_id, '|'))
	{
		getline(input, book_id);
		cout << left << setw(8) << serial << left << setw(56) << std_id << left << setw(56) << book_id << endl;
		count++;
		serial++;
	}
	input.close();
	if (count > 0)
	{
		do {
			cout << "\n\n -> Do you want to accept any request? (Y/N): ";
			cin >> request;
			if (request == 'y' || request == 'Y') {
				bool check = true;
				cout << "\n -> Enter ID of the Student: ";
				cin >> std_id;
				cout << " -> Enter ID of the Book: ";
				cin >> book_id;
				ifstream verify("Request.txt");
				while (getline(verify, student, '|'))
				{
					getline(verify, book);
					if (student == std_id && book == book_id)
					{
						ofstream accept("Accepted_Requests.txt", ios::app);
						ofstream issued("Issued_Books.txt", ios::app);
						accept << std_id << "|" << book_id << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\n Request Accepted!";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						check = false;
						IssueRequest--;
						ifstream input("Available_Books.txt");
						ofstream output("available_temp.txt");
						while (getline(input, id, '|'))
						{
							getline(input, name, '|');
							getline(input, author, '|');
							getline(input, edition);
							if (book_id != id)
							{
								output << id << "|" << name << "|" << author << "|" << edition << endl;
							}
							else
							{
								issued << id << "|" << name << "|" << author << "|" << edition << endl;
							}
						}
						issued.close();
						output.close();
						ifstream in("available_temp.txt");
						ofstream out("Available_Books.txt", ios::trunc);
						while (getline(in, id, '|'))
						{
							getline(in, name, '|');
							getline(in, author, '|');
							getline(in, edition);
							out << id << "|" << name << "|" << author << "|" << edition << endl;
						}
						out.close();
						in.close();
						remove("available_temp.txt");
						ofstream fout("request_temp.txt");
						ifstream fin("Request.txt");
						while (getline(fin, Std_Id, '|'))
						{
							getline(fin, Book_Id);
							if (Std_Id != std_id && Book_Id != book_id)
							{
								fout << Std_Id << "|" << Book_Id << endl;
							}
						}
						fin.close();
						fout.close();
						ofstream Out("Request.txt", ios::trunc);
						ifstream In("request_temp.txt");
						while (getline(In, Std_Id, '|'))
						{
							getline(In, Book_Id);
							Out << Std_Id << "|" << Book_Id << endl;
						}
						Out.close();
						In.close();
						remove("request_temp.txt");
					}
				}
				if (check)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\n Invalid ID Entered..." << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					Try_Again();
					Issue_requests();
				}
			}
			else if (request == 'n' || request == 'N') {
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "Invalid Input!";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				Try_Again();
				Issue_requests();
			}
		} while (request == 'y' || request == 'Y');
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\n No Request found!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		Choice();
	}
	Process();
	Admin_menu();
}

void Account_request()
{
	screen = true;
	char ch;
	bool field = true, try_again = true;
	ofstream student_request;
	string name, section, id, pass, password, Name, Id, Section, again;
	student_request.open("Request_Account.txt", ios::app);
	do
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\t\t\t\t\t* * * * * * Sign Up * * * * * *" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " -> Enter Student's ID: ";
		cin.ignore();
		getline(cin, id);
		bool check = false;
		check = Field_check(id, check);
		if (check)
		{
			Account_request();
		}
		ifstream verify("Student_Login.txt");
		while (getline(verify, Id, '|'))
		{
			getline(verify, pass);
			if (Id == id)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\n This ID is already assigned to another student! Please enter a different ID..." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				Login_Try();
				Account_request();
			}
		}
		verify.close();
		ifstream verify2("Request_Account.txt");
		while (getline(verify2, Id, '|'))
		{
			getline(verify2, name, '|');
			getline(verify2, section, '|');
			getline(verify2, pass);
			if (Id == id)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\n " << student_name << "! Some one else request for same ID. Please wait for admin to respond it..." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				Login_Try();
				Account_request();
			}
		}
		verify2.close();
		cout << " -> Enter Student's Name: ";
		getline(cin, name);
		check = Field_check(name, check);
		if (check)
		{
			Account_request();
		}
		cout << " -> Enter Student's Section: ";
		getline(cin, section);
		check = Field_check(section, check);
		if (check)
		{
			Account_request();
		}
		cout << " -> Enter Student's Password: ";
		ch = _getch();
		while (true)
		{
			if (ch == 13)
			{
				break;
			}
			else if (ch == '\b')
			{
				password.pop_back();
				cout << "\b";
				cout << " ";
				cout << "\b";
			}
			else
			{
				password.push_back(ch);
				cout << '*';
				field = false;
			}
			ch = _getch();
		}
		if (field)
		{
			cout << "\n\n You cannot leave this field empty!\n\n";
			Login_Try();
		}
		if (!field)
		{
			field = true;
			cout << endl;
			cout << " -> Enter Student's Password again: ";
			ch = _getch();
			while (true)
			{
				if (ch == 13)
				{
					break;
				}
				else if (ch == '\b')
				{
					again.pop_back();
					cout << "\b";
					cout << " ";
					cout << "\b";
				}
				else
				{
					again.push_back(ch);
					cout << '*';
					field = false;
				}
				ch = _getch();
			}
			if (field)
			{
				cout << "\n\n You cannot leave this field empty!\n\n";
				Login_Try();
			}
			cout << endl;
			if (password == again && !field)
			{
				student_request << id << "|" << name << "|" << section << "|" << password << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\n " << name << " ! Your request has been sent successfully. Your account will be created within 24 hours...." << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				try_again = false;
				student_request.close();
				cout << " Press Enter key to go back to Main Menu ";
				cin.get();
				main();
			}
			else if (password != again && !field)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\n Password didn't match!" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				Try_Again();
				Account_request();
			}
		}
	} while (try_again);
}

void Accept_acc_req()
{
	system("cls");
	char request;
	int count = 0, serial = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "\t\t\t\t\t* * * * * * Sign Up Requests * * * * * *" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << left << setw(8) << "SR.#" << left << setw(36) << "ID" << left << setw(40) << "STUDENT'S NAME" << left << setw(36) << "SECTION" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	string std_id, book_id, id, name, author, edition, Std_Id, Book_Id, student, book, section, password;
	ifstream input("Request_Account.txt");
	while (getline(input, std_id, '|'))
	{
		getline(input, name, '|');
		getline(input, section, '|');
		getline(input, password);
		cout << left << setw(8) << serial << left << setw(36) << std_id << left << setw(40) << name << left << setw(36) << section << endl;
		count++;
		serial++;
	}
	input.close();
	if (count > 0)
	{
		do {
			cout << "\n\n -> Do you want to accept any request? (Y/N): ";
			cin >> request;
			if (request == 'y' || request == 'Y')
			{
				bool exist = false;
				cout << "\n -> Enter ID of the Student: ";
				cin >> std_id;
				ifstream verify("Request_Account.txt");
				while (getline(verify, student, '|'))
				{
					getline(verify, name, '|');
					getline(verify, section, '|');
					getline(verify, password);
					if (student == std_id)
					{
						exist = true;
						ofstream student_list, student_login;
						student_list.open("Student_List.txt", ios::app);
						student_login.open("Student_Login.txt", ios::app);
						student_list << std_id << "|" << name << "|" << section << endl;
						student_login << std_id << "|" << password << endl;
						UserRequest--;
						ifstream input("Request_Account.txt");
						ofstream output("request_account_temp.txt");
						while (getline(input, id, '|'))
						{
							getline(input, name, '|');
							getline(input, section, '|');
							getline(input, password);
							if (std_id != id)
							{
								output << id << "|" << name << "|" << section << "|" << password << endl;
							}
						}
						output.close();
						ifstream in("request_account_temp.txt");
						ofstream out("Request_Account.txt", ios::trunc);
						while (getline(in, id, '|'))
						{
							getline(in, name, '|');
							getline(in, section, '|');
							getline(in, password);
							out << id << "|" << name << "|" << section << "|" << password << endl;
						}
						out.close();
						in.close();
						remove("request_account_temp.txt");

						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\n Student Added Successfully!" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					}
				}
				if (!exist)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\n Invalid ID Entered..." << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					Try_Again();
					Accept_acc_req();
				}
			}
			else if (request == 'n' || request == 'N') {
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "Invalid Input!";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				Try_Again();
				Accept_acc_req();
			}
		} while (request == 'y' || request == 'Y');
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\n No Request found!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		Choice();
	}
	Process();
	Admin_menu();
}

void Approval() {
	int date, month, year_issue;
	string std_id, book_id, Std_Id, Book_Id, student;
	bool istrue = true, check = true;
	char choice, ch;
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "\t\t\t\t\t* * * * * * Approval Notification * * * * * *" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	ifstream in("Accepted_Requests.txt");
	ifstream input("Request.txt");
	ifstream verify("Issue_Dates.txt");
	while (verify >> student)
	{
		verify >> date;
		verify >> month;
		verify >> year_issue;
		if (student == student_id)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << " \n -> " << student_name << "! You have issued the book. Please return it in time..." << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			check = false;
		}
	}
	verify.close();
	if (check)
	{
		while (getline(in, std_id, '|'))
		{
			getline(in, book_id);
			if (std_id == student_id)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\n -> " << student_name << "! Admin has accepted your book issue request. You can now issue book from Library..." << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cout << " Do you want to Issue Book now? (Y/N): ";
				cin >> choice;
				if (choice == 'y' || choice == 'Y')
				{
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\t\t\t\t\t* * * * * * Issue Book * * * * * *" << endl << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					cout << " -> Enter Book issue Date (dd/mm/yyyy): ";
					cin >> date;
					cin >> ch;
					cin >> month;
					cin >> ch;
					cin >> year_issue;
					ofstream issueDates("Issue_Dates.txt", ios::app);
					issueDates << student_id << "\t" << date << " " << month << " " << year_issue << endl;
					issueDates.close();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\n Book Issued! Please Return the book within 14 days otherwise Rs. 10 (per day) will be charged after 14 days...";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				}
				istrue = false;
			}
		}
		while (getline(input, Std_Id, '|'))
		{
			getline(input, Book_Id);
			if (Std_Id == student_id)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\n -> " << student_name << "! Your request has not been accepted by Admin yet..." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				istrue = false;
			}
		}
		if (istrue)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "\n -> " << student_name << "! You did not send any request to Admin...." << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		}
		in.close();
		input.close();
	}
	Choice();
}

void Return_book() {
	char ch;
	int count = 0;
	string std_id, book_id, Std_Id, Book_Id, id, name, author, edition, std, student, book;
	bool flag = false, delay_year = false, login = false, check = false, state = true;
	int date, month, no_month, years, year_issue = 0, days_return = 0, total_days, days_issue, year_return, fine = 0, delay;
	do
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\t\t\t\t\t* * * * * * Book Return * * * * * *" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		std_id = student_id;
		ifstream verify("Accepted_Requests.txt");
		while (getline(verify, student, '|'))
		{
			getline(verify, book);
			if (student == student_id)
			{
				count++;
			}
		}
		if (count == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "\n -> " << student_name << "! You did not issue any book from Library..." << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			Choice();
		}
		cout << "\n -> Enter ID of Book you Issued: ";
		cin >> book_id;
		ifstream in("Accepted_Requests.txt");
		while (getline(in, Std_Id, '|'))
		{
			getline(in, Book_Id);
			if (Std_Id == std_id && Book_Id == book_id)
			{
				login = true;
				check = true;
				ifstream inDate("Issue_Dates.txt");
				while (inDate >> std)
				{
					inDate >> date;
					inDate >> month;
					inDate >> year_issue;
					if (std == student_id)
					{
						state = false;
					}
				}
				if (state)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << " Invalid ID!";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					Try_Again();
					Return_book();
				}
				else
				{
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\t\t\t\t\t* * * * * * Book Return * * * * * *" << endl << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					days_issue = Date(date, month);
					cout << " -> Enter Book return Date (dd/mm/yyyy): ";
					cin >> date;
					cin >> ch;
					cin >> month;
					cin >> ch;
					cin >> year_return;
					if (year_return == year_issue)
					{
						days_return = Date(date, month);
					}
					else if (year_return > year_issue)
					{
						years = year_return - year_issue;
						no_month = month + 12 * years;
						days_return = Date(date, no_month);
					}
					total_days = days_return - days_issue;
					if (total_days <= 14)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\n Thank You " << student_name << "! You have returned the book in time..." << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					}
					else if (total_days > 14)
					{
						delay = (total_days - 14);
						fine = delay * 10;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\n Thank You " << student_name << "! You have returned the book... "
							<< "You are " << delay << " days late..." << " Your Fine is Rs. " << fine << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					}
					ofstream out("Available_Books.txt", ios::app);
					ifstream in("Issued_Books.txt");
					while (getline(in, id, '|'))
					{
						getline(in, name, '|');
						getline(in, author, '|');
						getline(in, edition);
						if (id == book_id)
						{
							out << id << "|" << name << "|" << author << "|" << edition << endl;
						}
					}
					out.close();
					in.close();
				}
				ofstream fout("accepted_tmp.txt");
				ifstream fin("Accepted_Requests.txt");
				while (getline(fin, Std_Id, '|'))
				{
					getline(fin, Book_Id);
					if (Book_Id != book_id)
					{
						fout << Std_Id << "|" << Book_Id << endl;
					}
				}
				fout.close();
				fin.close();
				ofstream accept("Accepted_Requests.txt", ios::trunc);
				ifstream input("accepted_tmp.txt");
				while (getline(input, Std_Id, '|'))
				{
					getline(input, Book_Id);
					accept << Std_Id << "|" << Book_Id << endl;
				}
				accept.close();
				input.close();
				remove("accepted_tmp.txt");
				ofstream issue_out("issue_temp.txt");
				ifstream issue_in("Issued_Books.txt");
				while (getline(issue_in, id, '|'))
				{
					(getline(issue_in, name, '|'));
					(getline(issue_in, author, '|'));
					(getline(issue_in, edition));
					if (book_id != id)
					{
						issue_out << id << "|" << name << "|" << author << "|" << edition << endl;
					}
				}
				issue_in.close();
				issue_out.close();
				ofstream issued("Issued_Books.txt");
				ifstream In("issue_temp.txt");
				while (getline(In, id, '|'))
				{
					(getline(In, name, '|'));
					(getline(In, author, '|'));
					(getline(In, edition));
					issued << id << "|" << name << "|" << author << "|" << edition << endl;
				}
				issued.close();
				In.close();
				remove("issue_temp.txt");
				ofstream date_temp("date_temp.txt");
				ifstream in_temp("Issue_Dates.txt");
				while (in_temp >> std)
				{
					in_temp >> date;
					in_temp >> month;
					in_temp >> year_issue;
					if (std != student_id)
					{
						date_temp << std << "\t" << date << " " << month << " " << year_issue << endl;
					}
				}
				date_temp.close();
				in_temp.close();
				ifstream tempIn("date_temp.txt");
				ofstream Dates("Issue_Dates.txt", ios::trunc);
				while (tempIn >> std)
				{
					tempIn >> date;
					tempIn >> month;
					tempIn >> year_issue;
					Dates << std << "\t" << date << " " << month << " " << year_issue << endl;
				}
				tempIn.close();
				Dates.close();
				remove("date_temp.txt");
			}
		}
		if (Std_Id != std_id && Book_Id != book_id && check == false)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n Invalid Book ID!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			Try_Again();
			Return_book();
		}
	} while (login != true);
	Choice();
}

int Date(int date, int no_month)
{
	int days = 0, i = 1, month = i;
	while (i < no_month)
	{
		if (month <= 7)
		{
			if (month % 2 != 0)
				days = days + 31;
			else
				days = days + 30;
			if (month == 2)
				days = days - 2;
		}
		else if (month <= 12 && month >= 8)
		{
			if (month % 2 == 0)
				days = days + 31;
			else
				days = days + 30;
		}
		month++;
		if (month == 12)
		{
			month = 1;
		}
		i++;
	}
	return days = days + date;
}

void Change_Password()
{
	char ch;
	bool state = true, login = true, field = true;
	string password, New, pass, std_id, ID, New_again;
	do
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\t\t\t\t\t* * * * * * Change Password * * * * * *" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		ifstream in("Student_Login.txt");
		ofstream temp("temp.txt");
		cout << " -> Enter your old Password: ";
		ch = _getch();
		while (true)
		{
			if (ch == 13)
			{
				break;
			}
			else if (ch == '\b')
			{
				password.pop_back();
				cout << "\b";
				cout << " ";
				cout << "\b";
			}
			else
			{
				password.push_back(ch);
				cout << '*';
				field = false;
			}
			ch = _getch();
		}
		cout << endl;
		while (getline(in, ID, '|'))
		{
			getline(in, pass);
			if (ID == student_id && password == pass)
			{
				field = true;
				cout << " -> Enter your new Password: ";
				ch = _getch();
				while (true)
				{
					if (ch == 13)
					{
						break;
					}
					else if (ch == '\b')
					{
						New.pop_back();
						cout << "\b";
						cout << " ";
						cout << "\b";
					}
					else
					{
						New.push_back(ch);
						cout << '*';
						field = false;
					}
					ch = _getch();
				}
				if (field)
				{
					cout << "\n\n You cannot leave this field empty!\n\n";
					Try_Again();
					Change_Password();
				}
				else if (!field)
				{
					field = true;
					cout << endl;
					cout << " -> Enter your new Password again: ";
					ch = _getch();
					while (true)
					{
						if (ch == 13)
						{
							break;
						}
						else if (ch == '\b')
						{
							New_again.pop_back();
							cout << "\b";
							cout << " ";
							cout << "\b";
						}
						else
						{
							New_again.push_back(ch);
							cout << '*';
							field = false;
						}
						ch = _getch();
					}
					if (field)
					{
						cout << "\n\n You cannot leave this field empty!\n\n";
						Try_Again();
						Change_Password();
					}
					else if (!field)
					{
						cout << endl;
						if (New == New_again)
						{
							pass = New;
							state = false;
							login = false;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
							cout << "\n Password Updated Successfully!" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						}
						else
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
							cout << "\n Password didn't match!" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
							Try_Again();
							Change_Password();
						}
					}
				}
			}
			temp << ID << "|" << pass << endl;
		}
		temp.close();
		in.close();
		ofstream fout("Student_Login.txt", ios::trunc);
		ifstream fin("temp.txt");
		while (getline(fin, ID, '|'))
		{
			getline(fin, pass);
			fout << ID << "|" << pass << endl;
		}
		fout.close();
		fin.close();
		remove("temp.txt");
		if (state && !field)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n Password didn't match!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			Try_Again();
			Change_Password();
		}
	} while (login);
	Choice();
}

void Search_book()
{
	bool state = true, print = true;
	int choice, option, serial = 0;
	string id, name, edition, author, ID, NAME, AUTHOR;
	do
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\t\t\t\t\t* * * * * * Search Book * * * * * *" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " => Press '1' to search from All Books" << endl;
		cout << " => Press '2' to search from Available Books" << endl;
		cout << " => Press '3' to go back" << endl << endl;
		cout << " -> Enter Your Choice Here: ";
		cin >> choice;
		if (choice == 1)
		{
			Process();
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\t\t\t\t\t* * * * * * Search Book * * * * * *" << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << " => Press '1' to search by ID" << endl;
			cout << " => Press '2' to search by Name" << endl;
			cout << " => Press '3' to search by Author" << endl << endl;
			cout << " -> Enter Your Choice Here: ";
			cin >> option;
			Process();
			if (option == 1)
			{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t\t* * * * * * Search by ID * * * * * *" << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cin.ignore();
				cout << " -> Enter Book's ID: ";
				getline(cin, ID);
				ifstream search("Book_List.txt");
				while (getline(search, id, '|'))
				{
					getline(search, name, '|');
					getline(search, author, '|');
					getline(search, edition);
					if (id == ID)
					{
						if (print)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
							cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
							cout << left << setw(8) << "SR.#" << left << setw(15) << "ID" << left << setw(50) << "BOOK'S NAME" << left << setw(35) << "AUTHOR'S NAME" << left << setw(12) << "EDITION" << endl;
							cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
							print = false;
						}
						serial++;
						cout << left << setw(8) << serial << left << setw(15) << id << left << setw(50) << name << left << setw(35) << author << left << setw(12) << edition << endl;
						state = false;
					}
				}
				search.close();
				if (state)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\n No Book Found!" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					Try_Again();
					Search_book();
				}
			}
			else if (option == 2)
			{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t\t* * * * * * Search by Name * * * * * *" << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cin.ignore();
				cout << " -> Enter Book's Name: ";
				getline(cin, NAME);
				ifstream search("Book_List.txt");
				while (getline(search, id, '|'))
				{
					getline(search, name, '|');
					getline(search, author, '|');
					getline(search, edition);
					if (name == NAME)
					{
						if (print)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
							cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
							cout << left << setw(8) << "SR.#" << left << setw(15) << "ID" << left << setw(50) << "BOOK'S NAME" << left << setw(35) << "AUTHOR'S NAME" << left << setw(12) << "EDITION" << endl;
							cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
							print = false;
						}
						serial++;
						cout << left << setw(8) << serial << left << setw(15) << id << left << setw(50) << name << left << setw(35) << author << left << setw(12) << edition << endl;
						state = false;
					}
				}
				search.close();
				if (state)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\n No Book Found!" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					Try_Again();
					Search_book();
				}
			}
			else if (option == 3)
			{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t\t* * * * * * Search by Author * * * * * *" << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cin.ignore();
				cout << " -> Enter Book's Author's Name: ";
				getline(cin, AUTHOR);
				ifstream search("Book_List.txt");
				while (getline(search, id, '|'))
				{
					getline(search, name, '|');
					getline(search, author, '|');
					getline(search, edition);
					if (author == AUTHOR)
					{
						if (print)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
							cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
							cout << left << setw(8) << "SR.#" << left << setw(15) << "ID" << left << setw(50) << "BOOK'S NAME" << left << setw(35) << "AUTHOR'S NAME" << left << setw(12) << "EDITION" << endl;
							cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
							print = false;
						}
						serial++;
						cout << left << setw(8) << serial << left << setw(15) << id << left << setw(50) << name << left << setw(35) << author << left << setw(12) << edition << endl;						state = false;
					}
				}
				search.close();
				if (state)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\n No Book Found!" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					Try_Again();
					Search_book();
				}
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\n Invalid Input!";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				Sleep(1000);
				Search_book();
			}
		}
		else if (choice == 2)
		{
			Process();
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\t\t\t\t\t* * * * * * Search Book * * * * * *" << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << " => Press '1' to search by ID" << endl;
			cout << " => Press '2' to search by Name" << endl;
			cout << " => Press '3' to search by Author" << endl << endl;
			cout << " -> Enter Your Choice Here: ";
			cin >> option;
			if (option == 1)
			{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t\t* * * * * * Search by ID * * * * * *" << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cin.ignore();
				cout << " -> Enter Book's ID: ";
				getline(cin, ID);
				ifstream search("Available_Books.txt");
				serial = 1;
				while (getline(search, id, '|'))
				{
					getline(search, name, '|');
					getline(search, author, '|');
					getline(search, edition);
					if (id == ID)
					{
						if (print)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
							cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
							cout << left << setw(8) << "SR.#" << left << setw(15) << "ID" << left << setw(50) << "BOOK'S NAME" << left << setw(35) << "AUTHOR'S NAME" << left << setw(12) << "EDITION" << endl;
							cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
							print = false;
						}
						serial++;
						cout << left << setw(8) << serial << left << setw(15) << id << left << setw(50) << name << left << setw(35) << author << left << setw(12) << edition << endl;						state = false;
					}
				}
				search.close();
				if (state)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\n No Book Found!" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					Try_Again();
					Search_book();
				}
			}
			else if (option == 2)
			{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t\t* * * * * * Search by Name * * * * * *" << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cin.ignore();
				cout << " -> Enter Book's Name: ";
				getline(cin, NAME);
				ifstream search("Available_Books.txt");
				while (getline(search, id, '|'))
				{
					getline(search, name, '|');
					getline(search, author, '|');
					getline(search, edition);
					if (name == NAME)
					{
						if (print)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
							cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
							cout << left << setw(8) << "SR.#" << left << setw(15) << "ID" << left << setw(50) << "BOOK'S NAME" << left << setw(35) << "AUTHOR'S NAME" << left << setw(12) << "EDITION" << endl;
							cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
							print = false;
						}
						serial++;
						cout << left << setw(8) << serial << left << setw(15) << id << left << setw(50) << name << left << setw(35) << author << left << setw(12) << edition << endl;						state = false;
					}
				}
				search.close();
				if (state)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\n No Book Found!" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					Try_Again();
					Search_book();
				}
			}
			else if (option == 3)
			{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t\t* * * * * * Search by Author * * * * * *" << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cin.ignore();
				cout << " -> Enter Book's Author's Name: ";
				getline(cin, AUTHOR);
				ifstream search("Available_Books.txt");
				serial = 1;
				while (getline(search, id, '|'))
				{
					getline(search, name, '|');
					getline(search, author, '|');
					getline(search, edition);
					if (author == AUTHOR)
					{
						if (print)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
							cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
							cout << left << setw(8) << "SR.#" << left << setw(15) << "ID" << left << setw(50) << "BOOK'S NAME" << left << setw(35) << "AUTHOR'S NAME" << left << setw(12) << "EDITION" << endl;
							cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
							print = false;
						}
						serial++;
						cout << left << setw(8) << serial << left << setw(15) << id << left << setw(50) << name << left << setw(35) << author << left << setw(12) << edition << endl;						state = false;
					}
				}
				search.close();
				if (state)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\n No Book Found!" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					Try_Again();
					Search_book();
				}
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\n Invalid Input!";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				Sleep(1000);
				Search_book();
			}
		}
		else if (choice == 3)
		{
			if (admin)
			{
				Admin_menu();
			}
			else
			{
				Student_menu();
			}
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n Invalid Input!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			Sleep(1500);
		}
	} while (choice < 1 || choice>3);
	Choice();
}

void Search_student()
{
	int choice, serial = 1;
	bool state = true, print = true;
	string id, name, section, ID, NAME, SECTION;
	do
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\t\t\t\t\t* * * * * * Search Student * * * * * *" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " => Press '1' to search by ID" << endl;
		cout << " => Press '2' to search by Name" << endl;
		cout << " => Press '3' to search by Section" << endl;
		cout << " => Press '4' to go back" << endl << endl;
		cout << " -> Enter Your Choice Here: ";
		cin >> choice;
		if (choice == 1)
		{
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\t\t\t\t\t* * * * * * Search by ID * * * * * *" << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cin.ignore();
			cout << " -> Enter Student's ID: ";
			getline(cin, ID);
			ifstream search("Student_List.txt");
			serial = 1;
			while (getline(search, id, '|'))
			{
				getline(search, name, '|');
				getline(search, section);
				if (id == ID)
				{
					if (print)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
						cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
						cout << left << setw(8) << "SR.#" << left << setw(40) << "ID" << left << setw(40) << "STUDENT'S NAME" << left << setw(32) << "SECTION" << endl;
						cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						print = false;
					}
					cout << left << setw(8) << serial << left << setw(40) << id << left << setw(40) << name << left << setw(32) << section << endl;
					serial++;
					state = false;
				}
			}
			search.close();
			if (state)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\n No Student Found!" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				Try_Again();
				Search_student();
			}
		}
		else if (choice == 2)
		{
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\t\t\t\t\t* * * * * * Search by Name * * * * * *" << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cin.ignore();
			cout << " -> Enter Student's Name: ";
			getline(cin, NAME);
			ifstream search("Student_List.txt");
			serial = 1;
			while (getline(search, id, '|'))
			{
				getline(search, name, '|');
				getline(search, section);
				if (name == NAME)
				{
					if (print)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
						cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
						cout << left << setw(8) << "SR.#" << left << setw(40) << "ID" << left << setw(40) << "STUDENT'S NAME" << left << setw(32) << "SECTION" << endl;
						cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						print = false;
					}
					cout << left << setw(8) << serial << left << setw(40) << id << left << setw(40) << name << left << setw(32) << section << endl;
					serial++;
					state = false;
				}
			}
			search.close();
			if (state)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\n No Student Found!" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				Try_Again();
				Search_student();
			}
		}
		else if (choice == 3)
		{
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\t\t\t\t\t* * * * * * Search by Section * * * * * *" << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cin.ignore();
			cout << " -> Enter Student's Section: ";
			getline(cin, SECTION);
			ifstream search("Student_List.txt");
			serial = 1;
			while (getline(search, id, '|'))
			{
				getline(search, name, '|');
				getline(search, section);
				if (section == SECTION)
				{
					if (print)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
						cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
						cout << left << setw(8) << "SR.#" << left << setw(40) << "ID" << left << setw(40) << "STUDENT'S NAME" << left << setw(32) << "SECTION" << endl;
						cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						print = false;
					}
					cout << left << setw(8) << serial << left << setw(40) << id << left << setw(40) << name << left << setw(32) << section << endl;
					serial++;
					state = false;
				}
			}
			search.close();
			if (state)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\n No Student Found!" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				Try_Again();
				Search_student();
			}
		}
		else if (choice == 4)
		{
			Admin_menu();
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n Invalid Input!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			Sleep(1500);
		}
	} while (choice < 1 || choice>4);
	Choice();
}

bool Field_check(string field, bool check)
{
	if (field == "")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\n You cannot leave this field empty!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		if (screen)
		{
			Login_Try();
		}
		else if (!screen)
		{
			Try_Again();
		}
		check = true;
	}
	return check;
}

void Admin_account()
{
	char ch;
	string password, secret = "bitf17lms";
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "\t\t\t\t\t* * * * * * Create Admin Account * * * * * *" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << " -> Enter Secret Password for LMS: ";
	ch = _getch();
	while (true)
	{
		if (ch == 13)
		{
			break;
		}
		else if (ch == '\b')
		{
			password.pop_back();
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else
		{
			password.push_back(ch);
			cout << '*';
		}
		ch = _getch();
	}
	cout << endl;
	if (password == secret)
	{
		Process();
		string ID, PASSWORD, again;
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\t\t\t\t\t* * * * * * Create Admin Account * * * * * *" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " -> Create Admin ID: ";
		cin.ignore();
		getline(cin, ID);
		cout << " -> Create Admin Password: ";
		ch = _getch();
		while (true)
		{
			if (ch == 13)
			{
				break;
			}
			else if (ch == '\b')
			{
				PASSWORD.pop_back();
				cout << "\b";
				cout << " ";
				cout << "\b";
			}
			else
			{
				PASSWORD.push_back(ch);
				cout << '*';
			}
			ch = _getch();
		}
		cout << endl;
		cout << " -> Enter Admin Password Again: ";
		ch = _getch();
		while (true)
		{
			if (ch == 13)
			{
				break;
			}
			else if (ch == '\b')
			{
				again.pop_back();
				cout << "\b";
				cout << " ";
				cout << "\b";
			}
			else
			{
				again.push_back(ch);
				cout << '*';
			}
			ch = _getch();
		}
		cout << endl;
		if (PASSWORD == again)
		{
			ofstream admin("Admin_Login.txt");
			admin << ID << endl << PASSWORD;
			admin.close();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n Admin Account Created Successfully!" << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << " Press Enter key to go back to Main Menu ";
			cin.get();
			main();
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n Password did'nt match!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			Login_Try();
			Admin_account();
		}
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\n Invalid Password!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		Login_Try();
		Admin_account();
	}
}

void Choice() {
	int choice;
	do
	{
		cout << endl << endl;
		if (admin)
		{
			cout << " => Press '1' to go back to Admin Menu" << endl;
		}
		else if (!admin)
		{
			cout << " => Press '1' to go back to Student Menu" << endl;
		}
		cout << " => Press '2' to go back to Main Menu" << endl;
		cout << " => Press '3' to Exit LMS" << endl << endl;
		cout << " -> Enter Your Choice Here: ";
		cin >> choice;
		if (choice == 1)
		{
			if (admin)
			{
				Process();
				Admin_menu();
			}
			else if (!admin)
			{
				Process();
				Student_menu();
			}
		}
		else if (choice == 2)
		{
			Loging_out();
			main();
		}
		else if (choice == 3)
		{
			Loging_out();
			Exit();
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n Invalid input!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		}
	} while (choice < 1 || choice>3);
}

void Exit()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "\t\t\t   (_   _)( )                  ( )       ( )   ( )              ( )" << endl;
	cout << "\t\t\t     | |  | |__     _ _   ___  | |/')    `\\`\\_/'/' _     _   _  | |" << endl;
	cout << "\t\t\t     | |  |  _ `\\ /'_` )/' _ `\\| , <       `\\ /' /'_`\\  ( ) ( ) | |" << endl;
	cout << "\t\t\t     | |  | | | |( (_| || ( ) || |\\`\\       | | ( (_) ) | (_) | (_)" << endl;
	cout << "\t\t\t     (_)  (_) (_)`\\__,_)(_) (_)(_) (_)      (_) `\\___/' `\\___/' (_)" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "\t\t\t             ~ ~ ~ ~ ~ For Using Our LMS! ~ ~ ~ ~ ~           " << endl << endl;
	Sleep(800);
	cout << "\t\t\t\t\tExiting Library Management System!" << endl << endl;
	cout << "\t\t\t\t\t\t    GOOD BYE! ";
	int close = 0;
	while (close < 5)
	{
		cout << ".";
		Sleep(850);
		close++;
	}
	cout << endl;
	remove("temp.txt");
	remove("std_del_temp");
	remove("std_list_temp");
	remove("std_login_temp");
	exit(0);
}

void Login_Try() {
	char choice;
	cout << "\n Try Again? (Y/N): ";
	cin >> choice;
	if (choice == 'n' || choice == 'N')
	{
		main();
	}
}

void Try_Again() {
	char choice;
	cout << "\n Try Again? (Y/N): ";
	cin >> choice;
	if (choice == 'n' || choice == 'N')
	{
		if (admin)
		{
			Admin_menu();
		}
		else if (!admin)
		{
			Student_menu();
		}
	}
	Process();
}

void Process()
{
	int process = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "\n  PROCESSING";
	while (process < 5)
	{
		cout << ".";
		Sleep(200);
		process++;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << endl;
}

void Load()
{
	int load = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "\n  LOGING IN";
	while (load < 6)
	{
		cout << ".";
		Sleep(500);
		load++;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << endl;
}

void Loging_out()
{
	int load = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "\n  LOGING OUT";
	while (load < 6)
	{
		cout << ".";
		Sleep(500);
		load++;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << endl;
}