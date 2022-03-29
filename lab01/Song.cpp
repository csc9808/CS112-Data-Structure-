/*
 * Song.cpp
 * Student name: Seong Chan Cho(sc77)
 * Date:2021-02-09
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "Song.h"
#include <cstdlib>


/* Song default constructor
    * Postcondition: myTitle and myArtist are empty strings
    *            && myYear == 0.
    */
Song::Song() {
	myTitle = myArtist = "";
	myYear = 0;
}
Song::Song(const string& title, const string& artist, unsigned year) {
	myTitle = title;
	myArtist = artist;
	myYear = year;
}
void Song::readFrom(istream& in) {
	getline(in, myTitle);
	getline(in, myArtist);
	string yearString;
	getline(in, yearString);
	myYear = atoi( yearString.c_str() );
}
void Song::writeTo(ostream& out) const {
	out << myTitle << '\n'
	<< myArtist << '\n'
	<< myYear  << '\n';
   }
string Song::getTitle() const {
	return myTitle;
}

string Song::getArtist() const {
	return myArtist;
}

unsigned Song::getYear() const {
	return myYear;
}

