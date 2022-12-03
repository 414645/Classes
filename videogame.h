#ifndef Videogame_H
#define Videogame_H

#include <iostream>
#include "media.h"

using namespace std;

class Videogame: public Media {
public:
  Videogame();
  Videogame(int, char*, int, char*, char*);
  ~Videogame(); //deconstructor decleration

  //variables passed in by parent are not needed
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
