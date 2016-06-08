#include "race.h"
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <fstream>

vector <string> Driver::names;

int randomValue()
{
	return 15+rand()%71;
}

void Driver::init()
{
	ifstream file("names.txt");
	copy(istream_iterator<string>(file),istream_iterator<string>(),back_inserter(names));
	file.close();
}

Driver::Driver()
{
	static int whichOne=(init(),0);
	_name=names[whichOne++];
	_acceleration=randomValue();
	_handling=randomValue();
	_curves=randomValue();
}

void Driver::addTime(int acceleration,int handling,int curves)
{
	_lapTime=acceleration+handling+curves;
	_wholeTime+=_lapTime;
}
