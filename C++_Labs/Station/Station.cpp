#include "Station.h"

Station::Station() {

	title = (char*)malloc(sizeof(char) * MAX_LENGTH + 1);

	cout << "Input name\n";
	scanf_s("%s", title, MAX_LENGTH);

	cout << "Input longtitude\n";
	cin >> longtitude;

	cout << "Input latitude\n";
	cin >> latitude;

	cout << "\n";
}

Station::Station(const Station& stat) {
	setTitle(stat.getTitle());
	longtitude = stat.getLongtitude();
	latitude = stat.getLatitude();
}


Station::Station(char *title, int longtitude, int latitude) {
	this->setTitle(title);
	this->longtitude = longtitude;
	this->latitude = latitude;
}

Station::~Station() {
	free(title);
}

void showStation(Station st) {
	cout << st.getTitle();
	cout << " Longtitude: " <<st.getLongtitude();
	cout << ", Latitude: " << st.getLatitude() << '\n'; 
}

void Station::setTitle(char *title) {
	//this->title = title;
	// !!!
	this->title = (char *)malloc(sizeof(char) * (strlen(title) + 1));
	strcpy(this->title, title);
}

void Station::setLongtitude(float longtitude) {
	this->longtitude = longtitude;
}

void Station::setLatitude(float latitude) {
	this->latitude = latitude;
}
