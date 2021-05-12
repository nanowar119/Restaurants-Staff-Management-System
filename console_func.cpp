#include "console_func.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <string.h>
#include <stdlib.h>
#include "Staff.h"
#include <vector>


using namespace std;




void adminConsole(int id, vector<staff> staf, vector <dayhr> clockinvec, vector <schechule> schechuVec)
{
	cout << "*******FUNCTION CONSOLE******* \n";
	cout << "1. CLOCK IN \n";
	cout << "2. CLOCK OUT \n";
	cout << "3. VIEW SHECHULE \n";
	cout << "4. VIEW ALL EMPLOYEE INFO \n";
	cout << "5. RESET WEEKLY PAYROLL \n";
	cout << "Please enter your choice: ";
	int choice;
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 1:
		clockin(id, clockinvec);
		break;
	case 2:
		clockout(id, clockinvec, staf);
		break;
	case 3:
		viewshechule(id, schechuVec);
		break;
	case 4:
		view_employee_info(id, staf);
		break;
	default:
		resetWP(id, staf);
		break;
	}
};
	void clockin(int ID, vector <dayhr> clockinvec)
	{
		
		
			time_t currentime;
			time(&currentime);
			clockinvec.push_back(dayhr());
			clockinvec[clockinvec.size() - 1].id = ID;
			clockinvec[clockinvec.size() - 1].clockin = currentime;
			//write clockin second to the clockin file

			ofstream clock("clockinTime.txt", std::ofstream::trunc);
			clock << clockinvec.size()<< endl;
			for (int i = 0; i < clockinvec.size(); i++)
			{
				clock << clockinvec[i].id << ' ';
				clock << clockinvec[i].clockin<< endl;
			}
			clock.close();	
	};

	void clockout(int ID, vector <dayhr> clockinvec, vector <staff> staf)
	{
		int timework = 0;
		for (int i = 0; i < clockinvec.size(); i++)
		{
			if (clockinvec[i].id == ID)
			{

				time_t timework;
				time(&timework);
				timework = timework - clockinvec[i].clockin;
				clockinvec.erase(clockinvec.begin() + i); // delete the clock in record vector afer clock out
			}
			else if (i == (clockinvec.size() - 1))
				cout << "You have not clockin before!" << endl;
		}
		for (int i = 0; i < staf.size(); i++)
		{
			if (staf[i].id == ID)
			{
				staf[i].weeklypayroll += (timework / 60 / 60) * staf[i].payrate;
			}
		}
		ofstream clock("clockinTime.txt", std::ofstream::trunc);
		clock << clockinvec.size() << endl;
		for (int i = 0; i < clockinvec.size(); i++)
		{
			clock << clockinvec[i].id << ' ';
			clock << clockinvec[i].clockin << endl;
		}
		clock.close();
	};
	void viewshechule(int ID, vector <schechule> schechuVec)
	{

		for (int i = 0; i < schechuVec.size(); i++)
		{
			if (schechuVec[i].id == ID)
			{
				cout << " Your schechule for next week:" << endl;
				cout << " ID is: " << schechuVec[i].id <<endl;
				cout << " Monday :" << schechuVec[i].montime << endl;
				cout << " Tuesday :" << schechuVec[i].tuestime << endl;
				cout << " Wednesday :" << schechuVec[i].wedtime << endl;
				cout << " Thurstday :" << schechuVec[i].thutime << endl;
				cout << " Friday :" << schechuVec[i].fritime << endl;
				cout << " Saturday :" << schechuVec[i].sattime << endl;
				cout << " Sunday :" << schechuVec[i].suntime << endl;
			}
		}
	};
	void view_employee_info(int ID, vector <staff> staf)
	{

		for (int i = 0; i < staf.size(); i++)
		{
			if (staf[i].id == ID)
			{
				cout << " Name: " << staf[i].fname << " " << staf[i].lname << endl;
				cout << "Email: " << staf[i].email << endl;
				cout << "Phone number: " << staf[i].id << endl;
				cout << "weekly payroll: " << staf[i].weeklypayroll << endl;
				cout << "Payrate : " << staf[i].payrate << endl;
			}
		}
	};

	void resetWP(int ID, vector <staff> staf)
	{
		for (int i = 0; i < staf.size(); i++)
		{
			staf[i].weeklypayroll = 0;
		}
		cout << " Weekly payroll for all staff have been reset !" << endl;
	};