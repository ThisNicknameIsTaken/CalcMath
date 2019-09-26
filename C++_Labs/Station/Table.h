#pragma once
#include "Station.h"
#include "Date.h"



class TableLine
{
public:
	TableLine(Station *departure, Station *arrival, Date *date);
	~TableLine();

	const Station *getDeparture();
	const Station *getArrival();

	const Date *getDate();

	void showTableLine();

private:
	Station *departure;
	Station *arrival;
	Date *date;
};




class Table
{
public:
	Table(TableLine **tableContent, size_t length);
	~Table();

	void showTable();
private:

	TableLine **tableContent;
	size_t length;

};
