#pragma once
#include <iostream>
#include <fstream>
#include <istream>
#include <string.h>
#include <stdlib.h>
#include <ctime>
using namespace std;




struct staff
{
	int id;
	string fname, lname, email;
	string phone;
	float weeklypayroll;
	float payrate;
};

struct schechule
{
	int id;
	string montime,tuestime,wedtime,thutime,fritime,sattime,suntime;
};

struct dayhr
{
	int id;
	int clockin ; // time(&current_time) to find current time in second
};
