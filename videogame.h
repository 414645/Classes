#ifndef Videogame_H
#define Videogame_H

#include <iostream>
#include "media.h"

using namespace std;

class Videogame: public Media {
public:
  Videogame();
  Videogame(char* newtitle, int newyear,
	    char* newpublisher, char* newrating);
  ~Videogame(); //deconstructor declaration
  //virtual
  virtual char* getTitle();
  virtual int getYear();
  char* getPublisher();
  char* getRating();
private:
  //char* title;
  //int year;
  char* publisher;
  char* rating;
};

#endif
