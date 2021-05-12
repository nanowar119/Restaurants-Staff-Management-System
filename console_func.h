#pragma once
#include <vector>
#include "Staff.h"
using namespace std;


class console_func
{
};

void clockin(int ID,vector <dayhr> clockinvec)
;

void clockout(int ID, vector <dayhr> clockinvec, vector <staff> staf);

void viewshechule(int ID,  vector <schechule> schechuVec);

void view_employee_info(int ID, vector <staff> staf);


void resetWP(int ID, vector <staff> staf);

void adminConsole(int id, vector<staff> staf, vector <dayhr> clockinvec, vector <schechule> schechuVec);

