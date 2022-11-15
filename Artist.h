//
// Created by makay on 10/2/2022.
//

#ifndef M1OEP_MALBER_ARTIST_H
#define M1OEP_MALBER_ARTIST_H
#include <iostream>
using std::ostream, std::string;

class Artist{
protected:
    string name;
    int age;
public:
    /*Constructors*/
    Artist();
    Artist(string name, int age);

    /*Getters*/
    string getName() const;
    int getAge() const;


    /*setters*/
    void setName(string name);

    /* sets the age to
     * if less than 0 sets to 0*/
    void setAge(int age);


    /*print out label*/
    friend ostream& operator << (ostream& outs, const Artist& artist);

};
#endif //M1OEP_MALBER_ARTIST_H
