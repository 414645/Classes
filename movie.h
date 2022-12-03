#ifndef Movie_H
#define Movie_H

#include <iostream>
#include "media.h"

using namespace std;

class Movie: public Media {
public:
  Movie();
  Movie(int, char*, int, char*, char*, char*);
  ~Movie(); //deconstructor decleration
  char* getDirector();
  char* getDuration();
  char* getRating();
private:
  char* director;
  char* duration;
  char* rating;
};

#endif
