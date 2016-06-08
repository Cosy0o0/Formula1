#include <stdio.h>
#include <string>
#include <vector>
#pragma once

using namespace std;

class Driver
{
	static vector <string> names;
	int _acceleration, _handling, _curves;
	int _timemin=0, _timesec=0, _timehour=0, _wholeTime=0, _lapTime=0;
	string _name;
	static void init();

public:
	Driver();

	int acceleration() {return _acceleration;}
	int handling() {return _handling;}
	int curves() {return _curves;}
	int wholeTime() {return _wholeTime;}
	int lapTime() {return _lapTime;}
	string name() {return _name;}

	void addTime(int acceleration,int handling, int curves);
};
