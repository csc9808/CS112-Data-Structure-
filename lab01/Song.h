/*
 * Song.h declares a class for storing song information.
* Student name: Seong Chan Cho(sc77)
* Date:2021-02-09
* Begun by: Joel Adams, for CS 112 at Calvin University.
*/

#ifndef SONG_H
#define SONG_H

#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class Song {
public:
	Song();
	Song(const string& title, const string& artist, unsigned year);
	string getTitle() const;
	string getArtist() const;
	unsigned getYear() const;
	void readFrom(istream& in);
	void writeTo(ostream& out) const;


private:
	string myTitle;
	string myArtist;
	unsigned myYear;
};

#endif /* SONG_H_ */
