//
// Created by makay on 9/14/2022.
//

#include "Song.h"
using namespace std;

Song::Song() : title(""), artist(Artist()), genre(""), year(0){};

Song::Song(string title, Artist artist, string genre, int year) : title(title),
                artist(artist), genre(genre), year(year){};


string Song::getTitle() const{
    return title;
}
Artist Song::getArtist() const{
    return artist;
}
string Song::getGenre() const{
    return genre;
}
int Song::getYear() const{
    return year;
}

void Song::setTitle(string title){
    this -> title = title;
}
void Song::setArtist(Artist artist){
    this -> artist = artist;
}
void Song::setGenre(string genre){
    this -> genre = genre;
}
void Song::setYear(int year){
    if (year < 0){
        this -> year = 0;
    }
    else {
        this -> year = year;
    }
}

ostream& operator << (ostream& outs, const Song& song){
    outs << setw(30) << left <<song.getTitle();
    outs << setw(30) << song.getArtist();
    outs << setw(19) << song.getGenre();
    outs << setw(6) << song.getYear();
    return outs;
}