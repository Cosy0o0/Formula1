#include "race.h"
#include <algorithm>
#include <unistd.h>
#define LAPS 30
#define DRIVERS 20

vector <Driver> driver(DRIVERS);

 bool comparing(Driver first,Driver second)
 {
 	return(first.wholeTime()<second.wholeTime());
 }

int main(int argc,char * argv[])
{
	srand(time(NULL));
	int bestLapTime=350;
	string bestlaper;
	for (int lap=0;lap<LAPS;lap++)
	{
		printf("LAP %d\n",lap+1);
		for (int i=0;i<DRIVERS;i++)
		{
			int accelerationTime=20+rand()%(1-driver[i].acceleration());
			int handlingTime=20+rand()%(1-driver[i].handling());
			int curvesTime=20+rand()%(1-driver[i].curves());
			driver[i].addTime(accelerationTime,handlingTime,curvesTime);
			if(driver[i].lapTime()<bestLapTime)
			{
				bestLapTime=driver[i].lapTime();
				bestlaper=driver[i].name();
			}
		}
		sort(driver.begin(),driver.end(),comparing);
		for(int i=0;i<DRIVERS;i++)
		{
			printf("%2d %-34s | %2d:%2d:%2d | %2d:%2d:%2d\n",i+1,driver[i].name().c_str(),driver[i].lapTime()/3600,
				(driver[i].lapTime()/60)%60,driver[i].lapTime()%60,driver[i].wholeTime()/3600,(driver[i].wholeTime()/60)%60,driver[i].wholeTime()%60);
			usleep(1000000);
		}
		printf("Najlepsze okrazenie: %s %2d:%2d:%2d\n",bestlaper.c_str(),bestLapTime/3600,(bestLapTime/60)%60,bestLapTime%60);
		usleep(2000000);
	}
}
