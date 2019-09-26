#include "Date.h"

Date::Date(){

}

Date::Date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::~Date() {

}

void Date::setDay(int day) {
	if (day < 0) day *= 1;

	if (day > 30) {
		day = day - 30 * (day / 30);
	}

	this->day = day;
}

void Date::setMonth(int month) {
	if (month < 0) month *= 1;

	if (month > 11) {
		month = month - 11 * (month / 11);
	}

	this->month = month;
}
void Date::setYear(int year) {
	this->year = year;
}

void Date::showDate() {
	cout << day << " " << month;
	cout << " " << year;
	cout << "\n";
}