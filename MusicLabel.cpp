//
// Created by makay on 10/2/2022.
//

#include "MusicLabel.h"
using namespace std;

/*Constructors*/
MusicLabel::MusicLabel() : labelName(""), artists({}){};
MusicLabel::MusicLabel(string name, vector<Artist> artists) : labelName(name), artists(artists){};

/*Getters*/
string MusicLabel::getLabelName() const{
    return labelName;
}
vector<Artist> MusicLabel::getArtists() const{
    return artists;
}
Artist MusicLabel::getArtist(int index) const{
    if (index<artists.size() && index >= 0) {
        return artists[index];
    }
    return Artist();
}
Artist MusicLabel::getArtist(string name) const{
    for(int i = 0; i<artists.size(); i++){
        if (name == artists[i].getName()){
            return artists[i];
        }
    }
    return Artist();
}

/*setters*/
void MusicLabel::setLabelName(string name){
    labelName = name;
}
void MusicLabel::setArtists(vector<Artist> artists){
    this -> artists = artists;
}

/*add artist*/
void MusicLabel::addArtist(Artist newArtist){
    artists.push_back(newArtist);
}
/*remove artist*/
bool MusicLabel::removeArtist(int index){
    if (index < 0 || index >= artists.size()) {
        return false;
    }
    artists.erase(artists.begin() + index);
    return true;
}
bool MusicLabel::removeArtist(string name){
    bool removed = false;
    for (int i = 0; i < artists.size(); ++i) {
        if (artists[i].getName() == name) {
            artists.erase(artists.begin() + i);
            --i;
            removed = true;
        }
    }
    return removed;
}


/*print out label*/
ostream& operator << (ostream& outs, const MusicLabel& label){
    outs << setw(15) << left <<label.getLabelName() << endl;
    outs << setw(10) << left << "ARTISTS" << endl;
    for(int i = 0; i<(label.getArtists()).size(); i++){
        outs << setw(30) << (label.getArtists())[i];
    }
    return outs;
}