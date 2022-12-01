#ifndef Media_H
#define Media_H

#include <iostream>

using namespace std;

class Media {
public:
  Media();
  Media(char*, int);
  char* getTitle();
  int getYear();
private:
  char* title;
  int year;
};

#endif
