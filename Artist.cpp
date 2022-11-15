//
// Created by makay on 10/2/2022.
//
#include "Artist.h"
#include <iomanip>
using namespace std;
using std::left, std::setw;

/*Constructors*/
Artist::Artist() : name(""), age(0){};
Artist::Artist(string name, int age) : name(name), age(age){};

/*Getters*/
string Artist::getName() const {
    return name;
}
int Artist::getAge() const {
    return age;
}

/*setters*/
void Artist::setName(string name){
    this -> name = name;
}
void Artist::setAge(int age){
    if(age < 0){
        this->age = 0;
    }
    else {
        this->age = age;
    }
}

/*print out label*/
ostream& operator << (ostream& outs, const Artist& artist){
    outs << setw(15) << left <<artist.getName()<<"AGE: " << artist.getAge() << endl;
    return outs;
}
