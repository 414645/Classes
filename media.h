#ifndef Media_H
#define Media_H

#include <iostream>

using namespace std;

class Media {
public:
  Media();
  Media(int, char*, int);
  ~Media(); //deconstructor decleration
  char* getTitle();
  int getYear();
  int getIdentity();
protected:
  int identity;
  char* title;
  int year;
};

#endif
