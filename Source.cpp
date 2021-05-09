#include <iostream>
#include <fstream>
#include <istream>
#include <string.h>
#include <stdlib.h>
#include "login.h"

using namespace std;

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