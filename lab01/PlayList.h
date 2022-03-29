/*
 * PlayList.h declares class PlaList.
* Student name: Seong Chan Cho(sc77)
* Date:2021-02-09
* Begun by: Joel Adams, for CS 112 at Calvin University.
*/

#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include <string>
#include "Song.h"
#include <vector>
using namespace std;

class PlayList {
public:
	PlayList(const string& fileName);
	unsigned getNumSongs() const;
	vector<Song> searchByArtist(const string& artist)const;
private:
	vector<Song> mySongs;
};

#endif /* PLAYLIST_H_ */
