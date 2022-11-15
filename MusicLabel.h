//
// Created by makay on 10/2/2022.
//

#ifndef M1OEP_MALBER_MUSICLABEL_H
#define M1OEP_MALBER_MUSICLABEL_H

#include <iostream>
#include <vector>
#include <iomanip>
#include "Artist.h"
#include <vector>
using std::endl, std::left, std::ostream, std::right, std::setw, std::string, std::vector;



class MusicLabel {
protected:
    string labelName;
    vector<Artist> artists;
public:
    /*Constructors*/
    MusicLabel();
    MusicLabel(string name, vector<Artist> artists);

    /*Getters*/
    string getLabelName() const;
    vector<Artist> getArtists() const;
    
    Artist getArtist(int index) const;
    Artist getArtist(string name) const;

    /*setters*/
    void setLabelName(string name);
    void setArtists(vector<Artist> artists);

    /*add artist*/
    void addArtist(Artist newArtist);

    /* Remove artist either by index or name */
    bool removeArtist(int index);
    bool removeArtist(string name);


    /*print out label*/
    friend ostream& operator << (ostream& outs, const MusicLabel& label);

};
#endif //M1OEP_MALBER_MUSICLABEL_H
