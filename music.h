#ifndef Music_H
#define Music_H

#include <iostream>
#include "media.h"

using namespace std;

class Music: public Media {
public:
  Music();
  Music(int, char*, int, char*, char*, char*);
  ~Music(); //deconstructor decleration
  char* getPublisher();
  char* getDuration();
  char* getArtist();
private:
  char* artist;
  char* duration;
  char* publisher;
};

#endif
