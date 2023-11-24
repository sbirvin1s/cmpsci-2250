#include <iostream>

using namespace std;


struct MovieData {
	string title;
	string director;
	int yearReleased;
	int runningTime;
};

int main() {
	
	MovieData movie1{ "2 Guns", "Baltasar Kormakur", 2013, 109 };
	MovieData movie2{ "Shooter", "Antione Fuqua", 2007, 124 };

	cout << "Information on Movie 1: " << endl;
	cout << "Title: " << movie1.title << endl;
	cout << "Director: " << movie1.director << endl;
	cout << "Year Released: " << movie1.yearReleased << endl;
	cout << "Running Time: " << movie1.runningTime << endl << endl;

	cout << "Information on Movie 2: " << endl;
	cout << "Title: " << movie2.title << endl;
	cout << "Director: " << movie2.director << endl;
	cout << "Year Released: " << movie2.yearReleased << endl;
	cout << "Running Time: " << movie2.runningTime << endl << endl;

	return 0;
};