#pragma once
#include <stdlib.h>
#include <iostream>

#define MAX_LENGTH 256

using namespace std;

class Station
{
public:
	Station();
	Station(const Station& stat);

	Station(char *title, int longtitude, int latitude);
	~Station();

	inline int getLongtitude() const { return longtitude; };
	inline int getLatitude() const { return latitude; };
	inline char *getTitle() const { return title;  };

	void setTitle(char *title);
	void setLongtitude(float longtitude);
	void setLatitude(float latitude);

	//void showStation();

private:
	char  *title;
	int longtitude;
	int latitude;
};

void showStation(Station st);