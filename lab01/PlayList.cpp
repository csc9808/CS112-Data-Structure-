/*
 * PlayList.cpp defines the PlayList methods.
* Student name: Seong Chan Cho(sc77)
* Date:2021-02-09
* Begun by: Joel Adams, for CS 112 at Calvin University.
*/

#include "PlayList.h"
#include <fstream>
#include <cassert>
using namespace std;

PlayList::PlayList(const string& fileName) {
	ifstream fin( fileName.c_str() );
	assert( fin.is_open() );

	Song s;
	string separator;
	while (true) {
	    s.readFrom(fin);
	    if ( !fin ) { break; }
	    getline(fin, separator);
	    mySongs.push_back(s);
	      }

	fin.close();
}

unsigned PlayList::getNumSongs() const {
	return mySongs.size();
}
vector<Song> PlayList::searchByArtist(const string& artist) const {
      vector<Song> v;

      for (unsigned i = 0; i < mySongs.size(); i++) {
         if ( mySongs[i].getArtist().find(artist) != string::npos ) {
            v.push_back( mySongs[i] );
         }
      }

      return v;
   }
