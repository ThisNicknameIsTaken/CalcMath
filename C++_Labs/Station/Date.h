#pragma once
#include <iostream>

using namespace std;

class Date
{
public:
	Date(int day, int month, int year);
	Date();

	~Date();


	inline int getDay()   const { return day; };
	inline int getMonth() const { return month; };
	inline int getYear()  const { return year; };

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	void showDate();

private:
	int day;
	int month;
	int year;
};

