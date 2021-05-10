#include "Console_fuctions.h"
#include "Login.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void Login_function(vector <login_struc> login_vec)
{
	int pass;
	int level_access;
	int ID;
	cout << "Enter Password: ";
	cin >> pass;
	passcheck(login_vec,pass,level_access, ID);
}

void passcheck(vector<login_struc> login_vec, int pass, int level_access, int ID)
{
	for (int i = 0; i < login_vec.size(); i++)
	{
		if (login_vec[i].password == pass) 
		{
			level_access = login_vec[i].level_access;
			ID = login_vec[i].ID;
		}
	}
}

