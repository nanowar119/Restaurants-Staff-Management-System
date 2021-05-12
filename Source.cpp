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
#include "console_func.h"

using namespace std;

using std::vector;


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
	input.close();
	
	
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
	input1.close();
	//////
	ifstream inputclock("clockinTime.txt");
	vector <dayhr> clockinvec;
	int size2;
	inputclock >> size2;
	cout << size2;
	for (int i = 0; i < size2; i++) // create vector to store clock in time in second
	{
		clockinvec.push_back(dayhr());
		
	}

	for (int i = 0; i < size2; i++) // load clockin info vector
	{
		inputclock >> clockinvec[i].id;
		inputclock >> clockinvec[i].clockin;
	}
	inputclock.close();

	
	int choice;
	int levelacc = 0;
	int id = 0;
	cout << "*******LOGIN******* \n";
	cout << "1. LOGIN WITH USERNAME ID \n";
	cout << "2. REGISTER \n";
	cout << "3. FORGOT USERNAME ID OR PASSWORD \n";
	cout << "Please enter your choice: ";

	cin >> choice;
	switch (choice)
	{
	case 1:
		id = userlogin();
		cout << " id after case 1 is: " << id << endl;
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
	cout << " ---------------------------------------------------------------------" << endl;

	
	adminConsole(id, staf, clockinvec, schechuVec);
	











	ofstream output("staffinfo.txt", std::ofstream::trunc);
	output << staf.size() << endl;
	for (int i = 0; i < staf.size(); i++)
	{
		output << staf[i].id << ' ';
		output << staf[i].fname << ' ';
		output << staf[i].lname << ' ';
		output << staf[i].email << ' ';
		output << staf[i].phone << ' ';
		output << staf[i].payrate << ' ';
		output << staf[i].weeklypayroll << ' ';
	}

	output.close();
	return 0;
}

