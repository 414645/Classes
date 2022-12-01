#ifndef Videogame_H
#define Videogame_H

#include <iostream>
#include "media.h"

using namespace std;

class Videogame:Media {
public:
  Videogame();
  Videogame(char*, int, char*, char*);
  //char* getTitle();
  //int getYear();
  char* getPublisher();
  char* getRating();
private:
  //char* title;
  //int year;
  char* publisher;
  char* rating;
};

#endif
