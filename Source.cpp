#include <iostream>
#include <fstream>
#include <istream>
#include <string.h>
#include <stdlib.h>
#include "login.h"
#include "Staff.h"
#include <ctime>
#include <vector>
#include <ctime>

using namespace std;
vector <staff> stafvec;

int main()
{

	vector <schechule> schechuVec;
	
	ifstream input("shechule.txt");
	
	int size;
	input >> size;
	
	for (int i = 0; i < size; i++) // create vector to store staff schechule
	{
		schechuVec.push_back(schechule());
	}

	for (int i = 0; i < size; i++) // load shechule info vector
	{
		input >> schechuVec[i].id;
		input >> schechuVec[i].montime;
		input >> schechuVec[i].tuestime;
		input >> schechuVec[i].wedtime;
		input >> schechuVec[i].thutime;
		input >> schechuVec[i].fritime;
		input >> schechuVec[i].sattime;
		input >> schechuVec[i].suntime;
		
	}   

	/// //////////////////
	
	ifstream input1("staffinfo.txt");
	vector <staff> staf;
	int size1;
		input1 >> size1;

	for (int i = 0; i < size; i++) // create vector to store staff info with size of all staff
	{
		staf.push_back(staff());
	}

	for (int i = 0; i < size; i++) // load staff info vector
	{
		input1 >> staf[i].id;
		input1 >> staf[i].fname;
		input1 >> staf[i].lname;
		input1 >> staf[i].email;
		input1 >> staf[i].phone;
		input1 >> staf[i].payrate;
		input1 >> staf[i].weeklypayroll;
	}
	
	//////
	ifstream inputclock("clockinTime.txt");
	vector <dayhr> clockin;
	int size2;
	inputclock >> size2;
	cout << size2;
	for (int i = 0; i < size2; i++) // create vector to store clock in time in second
	{
		clockin.push_back(dayhr());
		
	}

	for (int i = 0; i < size2; i++) // load clockin info vector
	{
		inputclock >> clockin[i].id;
		inputclock >> clockin[i].clockin;
	}


	
	int choice;
	cout << "*******LOGIN******* \n";
	cout << "1. LOGIN WITH USERNAME ID \n";
	cout << "2. REGISTER \n";
	cout << "3. FORGOT USERNAME ID OR PASSWORD \n";
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