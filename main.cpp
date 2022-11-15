//
// Created by makay on 9/16/2022.
//
#include "Song.h"
#include "Artist.h"
#include "MusicLabel.h"
#include "Quiz.h"
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    //make vector of songs
    vector<Song> songs;
    songs.push_back(Song("Positions", Artist("Ariana Grande",29), "Pop", 2021));
    songs.push_back(Song("Yours", Artist("Conan Gray",23), "Pop", 2022));
    songs.push_back(Song("Fallin", Artist("Lil Tecca", 20), "Hip-hop", 2022));
    songs.push_back(Song("Love and Lies", Artist("Anthony Ramos", 30), "Pop", 2021));
    songs.push_back(Song("Certified Lover Boy", Artist("Drake", 35), "Hip-Hop", 2021));

    //make vector of artists
    vector<Artist> artists;
    for (int i = 0; i<songs.size(); i++){
        artists.push_back(songs[i].getArtist());
    }

    //make a label object
    MusicLabel label = MusicLabel("Republic Records", artists);

    //print intro
    cout << "Hi! Welcome!" << endl;
    cout << "I have two games for you." << endl;

    bool exit = false;

    //loop till user wants to exit
    //allows them to play as many times as they want
    while (!exit) {
        //print options
        cout << "1. In the first you can guess which artist wrote the song." << endl;
        cout << "2. In the second you guess which artist is apart of Republic records" << endl;
        cout << "If you would like to exit press 0" << endl;
        cout << "Enter the number of the game you would like to play: ";

        string input;

        //validate the input
        bool valid = false;
        while (!valid) {
            getline(cin, input);
            //no input
            if (input.length() == 0) {
                cout << "No input. Please enter a choice (0, 1, or 2): " << endl;
            }
            //input
            else if (input == "1" || input == "2" || input == "0") {
                valid = true;
            } else {
                cout << "Invalid input. Please enter a choice (0, 1, or 2): " << endl;
            }
        }

        //if 1 then play the first game
        if (input == "1") {
            Quiz q1;
            q1.takeQuiz("QuizDataSongs.txt", cout, cin);
            //print songs at the end of the game
            cout << "SONGS" << endl;
            for (int i = 0; i < songs.size(); i++) {
                cout << i + 1;
                cout << ": " << songs[i] << endl;
            }
            cout << endl;
        }
        //if 2 then play second game
        else if (input == "2") {
            Quiz q2;
            q2.takeQuiz("QuizDataLabel.txt", cout, cin);
            cout << endl;
            //print label at the end of game
            cout << label << endl;
        }
        //if 0 exit
        else if (input == "0"){
            exit = true;
        }
    }
    return 0;
}