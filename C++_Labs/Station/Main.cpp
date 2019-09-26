#include "Table.h"


void main() {
	Station *a = new Station();
	Station *b = new Station();
	Date *date = new Date(24, 10, 2001);

	TableLine *t1 = new TableLine(a, b, date);
	TableLine *t2 = new TableLine(b, a, date);


	TableLine *arrT[2];
	
	arrT[0] = t1;
	arrT[1] = t2;


	arrT[0]->showTableLine();
	arrT[1]->showTableLine();

	system("pause");
}