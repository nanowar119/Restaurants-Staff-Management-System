#include <iostream>
#include <fstream>
#include <istream>
#include <string.h>
#include <stdlib.h>


using namespace std;

void userlogin();
void userregister();
void forgot();

void userlogin()
{
	int exist = 0;
	string user, pass, u, p;

	cout << "Enter your username: ";
	cin >> user;
	cout << "Enter your password: ";
	cin >> pass;

	ifstream input("ownerregister.txt");

	while (input >> u >> p)
	{
		if (u == user && p == pass)
		{
			exist = 1;
		}
	}
	input.close();
	if (exist == 1)
	{
		cout << "Welcome " << user << " to Staff Management System\n";
		cin.get();
		cin.get();
	}
	else
	{
		cout << "Invalid username or password, please try again";
		cin.get();
		cin.get();
		
	}
}

void userregister()
{
	
	string regusername, regpassword;

	cout << "Enter your username: ";
	cin >> regusername;

	cout << "Enter your password";
	cin >> regpassword;

	ofstream reg("ownerregister.txt", ios::app);
	reg << regusername << ' ' << regpassword << endl;

	cout << "Registration is successful \n"; 
	
}

void forgot()
{
	int choice2;
	cout << "1. Search your account by username\n ";
	cout << "2. Search your account by password\n ";
	cout << "3. Mainmenu \n";
	cout << "Please enter your choice: ";
	cin >> choice2;

	switch (choice2)
	{
	case 1:
	{
		int exist1 = 0;
		string searchuser, su, sp;

		cout << "Enter your username: ";
		cin >> searchuser;

		ifstream searchu("ownerregister.txt");
		while (searchu >> su >> sp)
		{
			if (su == searchuser)
			{
				exist1 = 1;
				break;
			}
		}
		searchu.close();
		if (exist1 == 1)
		{
			cout << "Your account found! \n";
			cout << "Your password is: " << sp;
			cin.get();
			cin.get();
		}
		else
		{
			cout << "Your account is not found! \n";
		}
		break;
	}
	case 2:
	{
		int exist2 = 0;
		string searchpass, su2, sp2;

		cout << "Enter your password: ";
		cin >> searchpass;

		ifstream searchp("ownerregister.txt");
		while (searchp >> su2 >> sp2)
		{
			if (sp2 == searchpass)
			{
				exist2 = 1;
				break;
			}
		}
		searchp.close();
		if (exist2 == 1)
		{
			cout << "Your account found! \n";
			cout << "Your username is: " << sp2;
			cin.get();
			cin.get();
		}
		else
		{
			cout << "Your account is not found! \n";
		}
		break;
	}
	case 3:
	{
		forgot();
		break;
	}
	default:
	{
		cout << "Sorry, your account not found! Please try again. ";
		cin.get();
		cin.get();
		forgot();
	}
	}
	
}
int main()
{
	
	int choice;
	cout << "*******LOGIN******* \n";
	cout << "1. LOGIN \n";
	cout << "2. REGISTER \n";
	cout << "3. FORGOT USERNAME OR PASSWORD \n";
	cout << "Please enter your choice: ";

	cin >> choice;
	switch (choice)
	{
		case 1:
			userlogin();
			break;
		case 2:
			userregister();
			break;
		case 3:
			forgot();
			break;
		case4:
			cout << "Thank for using program \n";
			break;
		default:
			cout << "Invalid choice, please try again";
			forgot();
	}
	return 0;
}
