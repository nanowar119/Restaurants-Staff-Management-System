#include "console_func.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <string.h>
#include <stdlib.h>
#include "login.h"
#include "Staff.h"


using namespace std;

void adminConsole()
{
	cout << "*******LOGIN******* \n";
	cout << "1. CLOCK IN \n";
	cout << "2. CLOCK OUT \n";
	cout << "3. VIEW SHECHULE \n";
	cout << "3. VIEW ALL EMPLOYEE INFO \n";
	cout << "3. RESET WEEKLY PAYROLL \n";
	cout << "Please enter your choice: ";
	int choice;
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 1:
		clockin();
		break;
	case 2:
		clockout();
		break;
	case 3:
		viewshechule();
		break;
	case4:
		view_employee_info();
		break;
	default:
		resetWP();
		break;
	}
}
void clockin()
{

}

void clockout()
{

}
void viewshechule()
{

}
void view_employee_info()
{

}

void resetWP()
{

}