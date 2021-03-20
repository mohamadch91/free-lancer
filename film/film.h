//
// Created by ASUS on 3/20/2021.
//

#ifndef FILM_FILM_H
#define FILM_FILM_H
using namespace std;
#include <iostream>
class film {
public:
        string name;
        int score;
        int date;
        int time;
        string country;
        int id;
        film(string n,int s,int d, int t,string c,int i);
};


#endif //FILM_FILM_H
