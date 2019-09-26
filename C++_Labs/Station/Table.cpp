#include "Table.h"



TableLine::TableLine(Station *departure,Station *arrival, Date *date) {
	this->departure = departure;
	this->arrival = arrival;

	this->date = date;
}

void TableLine::showTableLine() {
	cout << "Departure: ";
	showStation(*departure);

	cout << "Arrival: ";
	showStation(*arrival);

	cout << "At: ";
	date->showDate();
}


const Station * TableLine::getDeparture() {
	return departure;
}


const Station * TableLine::getArrival() {
	return arrival;
}
	
const Date * TableLine::getDate() {
	return date;
}


TableLine::~TableLine() {
	
}



Table::Table(TableLine **tableContent, size_t length) {
	this->tableContent = tableContent;
	this->length = length;
}

Table::~Table() {

}

/*
void Table::showTable() {
	for (int i = 0; i < length; i++)
	{
		*(tableContent + i)->showTableLine;
	}
}
*/
void Table::showTable() {}