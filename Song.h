#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <iomanip>
#include "Artist.h"
using std::ostream, std::string;

class Song{
private:
    string title;
    Artist artist;
    string genre;
    int year;

public:
    //constructors
    Song();
    Song(string title, Artist artist, string genre, int year);

    //getters
    string getTitle() const;

    Artist getArtist() const;

    string getGenre() const;

    int getYear() const;

    //setters
    void setTitle(string title);

    void setArtist(Artist artist);

    void setGenre(string genre);

    void setYear(int year);

    //overloaded operators
    //to print the object
    friend ostream& operator << (ostream& outs, const Song& song);
};

#endif //SONG_H
